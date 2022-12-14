/*
 * Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
 * Copyright (C) 2011 Pete Shorthose
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * --------------------------------------------------------------------------
 */

/* ------- This is the JACK namespace ------- */

#pragma once

#ifndef SRC_HEADERS_GX_JACK_H_
#define SRC_HEADERS_GX_JACK_H_

#include <atomic>

#ifndef GUITARIX_AS_PLUGIN

#include <jack/jack.h>          // NOLINT
#include <jack/midiport.h>
#include <jack/ringbuffer.h>

#ifdef HAVE_JACK_SESSION
#include <jack/session.h>
#endif

namespace gx_engine {
class GxEngine;
}

namespace gx_jack {

/****************************************************************
 ** port connection callback
 */

struct PortConnData {
public:
    PortConnData() {} // no init
    PortConnData(const char *a, const char *b, bool conn)
	: name_a(a), name_b(b), connect(conn) {}
    ~PortConnData() {}
    const char *name_a;
    const char *name_b;
    bool connect;
};

class PortConnRing {
private:
    jack_ringbuffer_t *ring;
    bool send_changes;
    int overflow;  // should be bool but gives compiler error
    void set_overflow() { gx_system::atomic_set(&overflow, true); }
    void clear_overflow()  { gx_system::atomic_set(&overflow, false); }
    bool is_overflow() { return gx_system::atomic_get(overflow); }
public:
    Glib::Dispatcher new_data;
    Glib::Dispatcher portchange;
    void push(const char *a, const char *b, bool conn);
    bool pop(PortConnData*);
    void set_send(bool v) { send_changes = v; }
    PortConnRing();
    ~PortConnRing();
};


/****************************************************************
 ** class GxJack
 */

class PortConnection {
public:
    jack_port_t *port;
    list<string> conn;
};

class JackPorts {
public:
    PortConnection input;
    PortConnection midi_input;
    PortConnection insert_out;
    PortConnection midi_output;
    PortConnection insert_in;
    PortConnection output1;
    PortConnection output2;
};

#ifdef HAVE_JACK_SESSION
extern "C" {
    typedef int (*jack_set_session_callback_type)(
	jack_client_t *, JackSessionCallback, void *arg);
    typedef char *(*jack_get_uuid_for_client_name_type)(
	jack_client_t *, const char *);
    typedef char *(*jack_client_get_uuid_type)(jack_client_t *);
}
#endif


class MidiCC {
private:
    gx_engine::GxEngine& engine;
    static const int max_midi_cc_cnt = 25;
    std::atomic<bool> send_cc[max_midi_cc_cnt];
    int cc_num[max_midi_cc_cnt];
    int pg_num[max_midi_cc_cnt];
    int bg_num[max_midi_cc_cnt];
    int me_num[max_midi_cc_cnt];
public:
    MidiCC(gx_engine::GxEngine& engine_);
    bool send_midi_cc(int _cc, int _pg, int _bgn, int _num);
    inline int next(int i = -1) const;
    inline int size(int i)  const { return me_num[i]; }
    inline void fill(unsigned char *midi_send, int i);
};

inline int MidiCC::next(int i) const {
    while (++i < max_midi_cc_cnt) {
        if (send_cc[i].load(std::memory_order_acquire)) {
            return i;
        }
    }
    return -1;
}

inline void MidiCC::fill(unsigned char *midi_send, int i) {
    if (size(i) == 3) {
        midi_send[2] =  bg_num[i];
    }
    midi_send[1] = pg_num[i];    // program value
    midi_send[0] = cc_num[i];    // controller+ channel
    send_cc[i].store(false, std::memory_order_release);
}

class GxJack: public sigc::trackable {
 private:
    gx_engine::GxEngine& engine;
    bool                jack_is_down;
    bool                jack_is_exit;
    bool                bypass_insert;
    MidiCC              mmessage;
    static int          gx_jack_srate_callback(jack_nframes_t, void* arg);
    static int          gx_jack_xrun_callback(void* arg);
    static int          gx_jack_buffersize_callback(jack_nframes_t, void* arg);
    static int          gx_jack_process(jack_nframes_t, void* arg);
    static int          gx_jack_insert_process(jack_nframes_t, void* arg);

    static void         shutdown_callback_client(void* arg);
    static void         shutdown_callback_client_insert(void* arg);
    void                gx_jack_shutdown_callback();
    static void         gx_jack_portreg_callback(jack_port_id_t, int, void* arg);
    static void         gx_jack_portconn_callback(jack_port_id_t a, jack_port_id_t b, int connect, void* arg);
#ifdef HAVE_JACK_SESSION
    jack_session_event_t *session_event;
    jack_session_event_t *session_event_ins;
    int                 session_callback_seen;
    static void         gx_jack_session_callback(jack_session_event_t *event, void *arg);
    static void         gx_jack_session_callback_ins(jack_session_event_t *event, void *arg);
    static jack_set_session_callback_type jack_set_session_callback_fp;
    static jack_get_uuid_for_client_name_type jack_get_uuid_for_client_name_fp;
    static jack_client_get_uuid_type jack_client_get_uuid_fp;
#endif
    void                cleanup_slot(bool otherthread);
    void                fetch_connection_data();
    PortConnRing        connection_queue;
    sigc::signal<void,string,string,bool> connection_changed;
    Glib::Dispatcher    buffersize_change;

    Glib::Dispatcher    client_change_rt;
    sigc::signal<void>  client_change;
    string              client_instance;
    jack_nframes_t      jack_sr;   // jack sample rate
    jack_nframes_t      jack_bs;   // jack buffer size
    float               *insert_buffer;
    Glib::Dispatcher    xrun;
    float               last_xrun;
    bool                xrun_msg_blocked;
    void report_xrun_clear();
    void report_xrun();
    void write_jack_port_connections(
	gx_system::JsonWriter& w, const char *key, const PortConnection& pc, bool replace=false);
    std::string make_clientvar(const std::string& s);
    std::string replace_clientvar(const std::string& s);
    int is_power_of_two (unsigned int x);
    bool                gx_jack_init(bool startserver, int wait_after_connect,
				     const gx_system::CmdlineOptions& opt);
    void                gx_jack_init_port_connection(const gx_system::CmdlineOptions& opt);
    void                gx_jack_callbacks();
    void                gx_jack_cleanup();
    inline void         check_overload();
    void                process_midi_cc(void *buf, jack_nframes_t nframes);

 public:
    JackPorts           ports;

    jack_client_t*      client;
    jack_client_t*      client_insert;
    
    jack_position_t      current;
    jack_transport_state_t transport_state;
    jack_transport_state_t old_transport_state;

    jack_nframes_t      get_jack_sr() { return jack_sr; }
    jack_nframes_t      get_jack_bs() { return jack_bs; }
    float               get_jcpu_load() { return client ? jack_cpu_load(client) : -1; }
    bool                get_is_rt() { return client ? jack_is_realtime(client) : false; }
    jack_nframes_t      get_time_is() { return client ? jack_frame_time(client) : 0; }

public:
    GxJack(gx_engine::GxEngine& engine_);
    ~GxJack();

    void                set_jack_down(bool v) { jack_is_down = v; }
    void                set_jack_exit(bool v) { jack_is_exit = v; }

    void                set_jack_insert(bool v) { bypass_insert = v;}
    bool                gx_jack_connection(bool connect, bool startserver,
					   int wait_after_connect, const gx_system::CmdlineOptions& opt);
    float               get_last_xrun() { return last_xrun; }
    void*               get_midi_buffer(jack_nframes_t nframes);
    bool                send_midi_cc(int cc_num, int pgm_num, int bgn, int num);

    void                read_connections(gx_system::JsonParser& jp);
    void                write_connections(gx_system::JsonWriter& w);
    static string       get_default_instancename();
    const string&       get_instancename() { return client_instance; }
    string              client_name;
    string              client_insert_name;
    Glib::Dispatcher    session;
    Glib::Dispatcher    session_ins;
    Glib::Dispatcher    shutdown;
    bool                is_jack_down() { return jack_is_down; }
    Glib::Dispatcher    connection;
    bool                is_jack_exit() { return jack_is_exit; }
    sigc::signal<void>& signal_client_change() { return client_change; }
    sigc::signal<void,string,string,bool>& signal_connection_changed() { return connection_changed; }
    Glib::Dispatcher&   signal_portchange() { return connection_queue.portchange; }
    Glib::Dispatcher&   signal_buffersize_change() { return buffersize_change; }
    void                send_connection_changes(bool v) { connection_queue.set_send(v); }
    static void         rt_watchdog_set_limit(int limit);
    gx_engine::GxEngine& get_engine() { return engine; }
    bool                single_client;
#ifdef HAVE_JACK_SESSION
    jack_session_event_t *get_last_session_event() {
	return gx_system::atomic_get(session_event);
    }
    jack_session_event_t *get_last_session_event_ins() {
	return gx_system::atomic_get(session_event_ins);
    }
    int                 return_last_session_event();
    int                 return_last_session_event_ins();
    string              get_uuid_insert();
#endif
};

inline bool GxJack::send_midi_cc(int cc_num, int pgm_num, int bgn, int num) {
    if (!client) {
        return false;
    }
    return mmessage.send_midi_cc(cc_num, pgm_num, bgn, num);
}

} /* end of jack namespace */

#endif  // SRC_HEADERS_GX_JACK_H_
#endif
