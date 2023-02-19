// generated from file '../src/faust/dattorros_progenitor.dsp' by dsp2cc:
// Code generated with Faust (https://faust.grame.fr)


namespace dattorros_progenitor {
class mydspSIG0 {
	
  private:
	
	int iVec6[2];
	int iRec22[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			iVec6[l15] = 0;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			iRec22[l16] = 0;
		}
	}
	
	void fillmydspSIG0(int count, double* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec6[0] = 1;
			iRec22[0] = (iVec6[1] + iRec22[1]) % 65536;
			table[i1] = std::sin(9.587379924285257e-05 * double(iRec22[0]));
			iVec6[1] = iVec6[0];
			iRec22[1] = iRec22[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static double ftbl0mydspSIG0[65536];


class Dsp: public PluginDef {
private:
	int fSampleRate;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	int IOTA0;
	double fVec0[524288];
	FAUSTFLOAT fHslider4;
	double fConst1;
	double fConst2;
	double fConst3;
	double fRec18[2];
	double fRec19[2];
	double fRec20[2];
	double fRec21[2];
	FAUSTFLOAT fHslider5;
	double fRec17[3];
	double fVec1[1024];
	int iConst4;
	double fRec15[2];
	double fVec2[1024];
	int iConst5;
	double fRec13[2];
	double fVec3[4096];
	int iConst6;
	double fRec11[2];
	double fVec4[2048];
	int iConst7;
	double fRec9[2];
	double fVec5[8192];
	double fConst8;
	double fRec23[2];
	FAUSTFLOAT fHslider6;
	int iConst9;
	double fRec7[2];
	double fRec8[32768];
	int iConst10;
	FAUSTFLOAT fHslider7;
	double fRec6[3];
	FAUSTFLOAT fHslider8;
	double fVec7[16384];
	int iConst11;
	double fRec4[2];
	double fVec8[32768];
	int iConst12;
	double fRec0[2];
	double fVec9[8192];
	int iConst13;
	double fRec27[2];
	double fRec28[32768];
	int iConst14;
	double fRec26[3];
	double fVec10[32768];
	int iConst15;
	double fRec24[2];
	double fVec11[32768];
	int iConst16;
	double fRec1[2];
	FAUSTFLOAT fHslider9;

	void clear_state_f();
	int load_ui_f(const UiBuilder& b, int form);
	static const char *glade_def;
	void init(unsigned int sample_rate);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1);
	int register_par(const ParamReg& reg);

	static void clear_state_f_static(PluginDef*);
	static int load_ui_f_static(const UiBuilder& b, int form);
	static void init_static(unsigned int sample_rate, PluginDef*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1, PluginDef*);
	static int register_params_static(const ParamReg& reg);
	static void del_instance(PluginDef *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginDef() {
	version = PLUGINDEF_VERSION;
	flags = 0;
	id = "dattorros_progenitor";
	name = N_("Plate Reverb");
	groups = 0;
	description = ""; // description (tooltip)
	category = N_("Reverb");       // category
	shortname = "";     // shortname
	mono_audio = 0;
	stereo_audio = compute_static;
	set_samplerate = init_static;
	activate_plugin = 0;
	register_params = register_params_static;
	load_ui = load_ui_f_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; l0 < 524288; l0 = l0 + 1) fVec0[l0] = 0.0;
	for (int l1 = 0; l1 < 2; l1 = l1 + 1) fRec18[l1] = 0.0;
	for (int l2 = 0; l2 < 2; l2 = l2 + 1) fRec19[l2] = 0.0;
	for (int l3 = 0; l3 < 2; l3 = l3 + 1) fRec20[l3] = 0.0;
	for (int l4 = 0; l4 < 2; l4 = l4 + 1) fRec21[l4] = 0.0;
	for (int l5 = 0; l5 < 3; l5 = l5 + 1) fRec17[l5] = 0.0;
	for (int l6 = 0; l6 < 1024; l6 = l6 + 1) fVec1[l6] = 0.0;
	for (int l7 = 0; l7 < 2; l7 = l7 + 1) fRec15[l7] = 0.0;
	for (int l8 = 0; l8 < 1024; l8 = l8 + 1) fVec2[l8] = 0.0;
	for (int l9 = 0; l9 < 2; l9 = l9 + 1) fRec13[l9] = 0.0;
	for (int l10 = 0; l10 < 4096; l10 = l10 + 1) fVec3[l10] = 0.0;
	for (int l11 = 0; l11 < 2; l11 = l11 + 1) fRec11[l11] = 0.0;
	for (int l12 = 0; l12 < 2048; l12 = l12 + 1) fVec4[l12] = 0.0;
	for (int l13 = 0; l13 < 2; l13 = l13 + 1) fRec9[l13] = 0.0;
	for (int l14 = 0; l14 < 8192; l14 = l14 + 1) fVec5[l14] = 0.0;
	for (int l17 = 0; l17 < 2; l17 = l17 + 1) fRec23[l17] = 0.0;
	for (int l18 = 0; l18 < 2; l18 = l18 + 1) fRec7[l18] = 0.0;
	for (int l19 = 0; l19 < 32768; l19 = l19 + 1) fRec8[l19] = 0.0;
	for (int l20 = 0; l20 < 3; l20 = l20 + 1) fRec6[l20] = 0.0;
	for (int l21 = 0; l21 < 16384; l21 = l21 + 1) fVec7[l21] = 0.0;
	for (int l22 = 0; l22 < 2; l22 = l22 + 1) fRec4[l22] = 0.0;
	for (int l23 = 0; l23 < 32768; l23 = l23 + 1) fVec8[l23] = 0.0;
	for (int l24 = 0; l24 < 2; l24 = l24 + 1) fRec0[l24] = 0.0;
	for (int l25 = 0; l25 < 8192; l25 = l25 + 1) fVec9[l25] = 0.0;
	for (int l26 = 0; l26 < 2; l26 = l26 + 1) fRec27[l26] = 0.0;
	for (int l27 = 0; l27 < 32768; l27 = l27 + 1) fRec28[l27] = 0.0;
	for (int l28 = 0; l28 < 3; l28 = l28 + 1) fRec26[l28] = 0.0;
	for (int l29 = 0; l29 < 32768; l29 = l29 + 1) fVec10[l29] = 0.0;
	for (int l30 = 0; l30 < 2; l30 = l30 + 1) fRec24[l30] = 0.0;
	for (int l31 = 0; l31 < 32768; l31 = l31 + 1) fVec11[l31] = 0.0;
	for (int l32 = 0; l32 < 2; l32 = l32 + 1) fRec1[l32] = 0.0;
}

void Dsp::clear_state_f_static(PluginDef *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(unsigned int sample_rate)
{
	mydspSIG0* sig0 = newmydspSIG0();
	sig0->instanceInitmydspSIG0(sample_rate);
	sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
	deletemydspSIG0(sig0);
	fSampleRate = sample_rate;
	double fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, double(fSampleRate)));
	fConst1 = 0.001 * fConst0;
	fConst2 = 1e+01 / fConst0;
	fConst3 = 0.0 - fConst2;
	iConst4 = int(0.004771345048889486 * fConst0);
	iConst5 = int(0.0035953092974026412 * fConst0);
	iConst6 = int(0.01273478713752898 * fConst0);
	iConst7 = int(0.009307482947481604 * fConst0);
	fConst8 = 1.0 / fConst0;
	iConst9 = int(0.022042270085010585 * fConst0);
	iConst10 = int(0.14962534861059776 * fConst0);
	iConst11 = int(0.060481838647894894 * fConst0);
	iConst12 = int(0.12499579987231611 * fConst0);
	iConst13 = int(0.029972111152179026 * fConst0);
	iConst14 = int(0.14169550754342933 * fConst0);
	iConst15 = int(0.08924431302711602 * fConst0);
	iConst16 = int(0.10628003091293975 * fConst0);
	IOTA0 = 0;
	clear_state_f();
}

void Dsp::init_static(unsigned int sample_rate, PluginDef *p)
{
	static_cast<Dsp*>(p)->init(sample_rate);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1)
{
	double fSlow0 = double(fHslider0);
	double fSlow1 = double(fHslider1);
	double fSlow2 = double(fHslider2);
	double fSlow3 = double(fHslider3);
	double fSlow4 = fConst1 * double(fHslider4);
	double fSlow5 = double(fHslider5);
	double fSlow6 = 1.0 - fSlow5;
	double fSlow7 = 0.5 * double(fHslider6);
	double fSlow8 = double(fHslider7);
	double fSlow9 = 1.0 - fSlow8;
	double fSlow10 = double(fHslider8);
	double fSlow11 = double(fHslider9);
	double fSlow12 = 1.0 - fSlow11;
	for (int i0 = 0; i0 < count; i0 = i0 + 1) {
		double fTemp0 = 0.5 * fRec1[1];
		double fTemp1 = double(input1[i0]);
		double fTemp2 = double(input0[i0]);
		double fTemp3 = fTemp2 + fTemp1;
		fVec0[IOTA0 & 524287] = fTemp3;
		double fTemp4 = ((fRec18[1] != 0.0) ? (((fRec19[1] > 0.0) & (fRec19[1] < 1.0)) ? fRec18[1] : 0.0) : (((fRec19[1] == 0.0) & (fSlow4 != fRec20[1])) ? fConst2 : (((fRec19[1] == 1.0) & (fSlow4 != fRec21[1])) ? fConst3 : 0.0)));
		fRec18[0] = fTemp4;
		fRec19[0] = std::max<double>(0.0, std::min<double>(1.0, fRec19[1] + fTemp4));
		fRec20[0] = (((fRec19[1] >= 1.0) & (fRec21[1] != fSlow4)) ? fSlow4 : fRec20[1]);
		fRec21[0] = (((fRec19[1] <= 0.0) & (fRec20[1] != fSlow4)) ? fSlow4 : fRec21[1]);
		double fTemp5 = fVec0[(IOTA0 - int(std::min<double>(262144.0, std::max<double>(0.0, fRec20[0])))) & 524287];
		fRec17[0] = fSlow6 * fRec17[2] + fSlow5 * (0.5 * fTemp5 + fRec19[0] * (0.0 - 0.5 * (fTemp5 - fVec0[(IOTA0 - int(std::min<double>(262144.0, std::max<double>(0.0, fRec21[0])))) & 524287])));
		double fTemp6 = fRec17[0] - fSlow3 * fRec15[1];
		fVec1[IOTA0 & 1023] = fTemp6;
		fRec15[0] = fVec1[(IOTA0 - iConst4) & 1023];
		double fRec16 = fSlow3 * fTemp6;
		double fTemp7 = fRec16 + fRec15[1] - fSlow3 * fRec13[1];
		fVec2[IOTA0 & 1023] = fTemp7;
		fRec13[0] = fVec2[(IOTA0 - iConst5) & 1023];
		double fRec14 = fSlow3 * fTemp7;
		double fTemp8 = fRec14 + fRec13[1] - fSlow2 * fRec11[1];
		fVec3[IOTA0 & 4095] = fTemp8;
		fRec11[0] = fVec3[(IOTA0 - iConst6) & 4095];
		double fRec12 = fSlow2 * fTemp8;
		double fTemp9 = fRec12 + fRec11[1] - fSlow2 * fRec9[1];
		fVec4[IOTA0 & 2047] = fTemp9;
		fRec9[0] = fVec4[(IOTA0 - iConst7) & 2047];
		double fRec10 = fSlow2 * fTemp9;
		double fTemp10 = 0.3 * (fRec10 + fRec9[1]);
		double fTemp11 = fTemp10 + fSlow1 * fRec7[1] + fTemp0;
		fVec5[IOTA0 & 8191] = fTemp11;
		fRec23[0] = fConst8 + (fRec23[1] - std::floor(fConst8 + fRec23[1]));
		double fTemp12 = fSlow7 * (ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0 * fRec23[0]), 65535))] + 1.0);
		int iTemp13 = int(fTemp12);
		int iTemp14 = std::min<int>(18, std::max<int>(0, iTemp13 + 1));
		double fTemp15 = std::floor(fTemp12);
		double fTemp16 = fTemp12 - fTemp15;
		double fTemp17 = fTemp15 + (1.0 - fTemp12);
		int iTemp18 = std::min<int>(18, std::max<int>(0, iTemp13));
		fRec7[0] = fVec5[(IOTA0 - (iConst9 + iTemp18)) & 8191] * fTemp17 + fTemp16 * fVec5[(IOTA0 - (iConst9 + iTemp14)) & 8191];
		fRec8[IOTA0 & 32767] = fRec7[1] - (fTemp0 + fTemp10);
		fRec6[0] = fSlow8 * fRec6[2] + fSlow9 * fRec8[(IOTA0 - iConst10) & 32767];
		double fTemp19 = fSlow10 * fRec6[0] - fSlow0 * fRec4[1];
		fVec7[IOTA0 & 16383] = fTemp19;
		fRec4[0] = fVec7[(IOTA0 - iConst11) & 16383];
		double fRec5 = fSlow0 * fTemp19;
		fVec8[IOTA0 & 32767] = fRec5 + fRec4[1];
		fRec0[0] = fSlow10 * fVec8[(IOTA0 - iConst12) & 32767];
		double fTemp20 = 0.5 * fRec0[1];
		double fTemp21 = fTemp20 + fTemp10 + fSlow1 * fRec27[1];
		fVec9[IOTA0 & 8191] = fTemp21;
		fRec27[0] = fTemp17 * fVec9[(IOTA0 - (iConst13 + iTemp18)) & 8191] + fTemp16 * fVec9[(IOTA0 - (iConst13 + iTemp14)) & 8191];
		fRec28[IOTA0 & 32767] = fRec27[1] - (fTemp10 + fTemp20);
		fRec26[0] = fSlow8 * fRec26[2] + fSlow9 * fRec28[(IOTA0 - iConst14) & 32767];
		double fTemp22 = fSlow10 * fRec26[0] - fSlow0 * fRec24[1];
		fVec10[IOTA0 & 32767] = fTemp22;
		fRec24[0] = fVec10[(IOTA0 - iConst15) & 32767];
		double fRec25 = fSlow0 * fTemp22;
		fVec11[IOTA0 & 32767] = fRec25 + fRec24[1];
		fRec1[0] = fSlow10 * fVec11[(IOTA0 - iConst16) & 32767];
		double fRec2 = fRec8[IOTA0 & 32767];
		double fRec3 = fRec28[IOTA0 & 32767];
		output0[i0] = FAUSTFLOAT(fSlow12 * fTemp2 + fSlow11 * (fRec0[0] + fRec2));
		output1[i0] = FAUSTFLOAT(fSlow12 * fTemp1 + fSlow11 * (fRec1[0] + fRec3));
		IOTA0 = IOTA0 + 1;
		fRec18[1] = fRec18[0];
		fRec19[1] = fRec19[0];
		fRec20[1] = fRec20[0];
		fRec21[1] = fRec21[0];
		fRec17[2] = fRec17[1];
		fRec17[1] = fRec17[0];
		fRec15[1] = fRec15[0];
		fRec13[1] = fRec13[0];
		fRec11[1] = fRec11[0];
		fRec9[1] = fRec9[0];
		fRec23[1] = fRec23[0];
		fRec7[1] = fRec7[0];
		fRec6[2] = fRec6[1];
		fRec6[1] = fRec6[0];
		fRec4[1] = fRec4[0];
		fRec0[1] = fRec0[0];
		fRec27[1] = fRec27[0];
		fRec26[2] = fRec26[1];
		fRec26[1] = fRec26[0];
		fRec24[1] = fRec24[0];
		fRec1[1] = fRec1[0];
	}
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1, PluginDef *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, input1, output0, output1);
}

int Dsp::register_par(const ParamReg& reg)
{
	reg.registerFloatVar("dattorros_progenitor.bandwidth",N_("Bandwidth"),"S","",&fHslider5, 0.9, 0.1, 0.95, 0.0005, 0);
	reg.registerFloatVar("dattorros_progenitor.damping",N_("HF Damp"),"S","",&fHslider7, 0.1, 0.1, 0.95, 0.0005, 0);
	reg.registerFloatVar("dattorros_progenitor.decay diff 1",N_("Decay 1"),"S","",&fHslider1, 0.1, 0.0, 0.7, 0.01, 0);
	reg.registerFloatVar("dattorros_progenitor.decay diff 2",N_("Decay 2"),"S","",&fHslider0, 0.1, 0.0, 0.5, 0.01, 0);
	reg.registerFloatVar("dattorros_progenitor.decay",N_("Decay"),"S","",&fHslider8, 0.1, 0.0, 0.5, 0.01, 0);
	reg.registerFloatVar("dattorros_progenitor.dry/wet",N_("Dry/Wet"),"S","",&fHslider9, 0.5, 0.0, 1.0, 0.05, 0);
	reg.registerFloatVar("dattorros_progenitor.excursion",N_("Excursion"),"S","",&fHslider6, 0.0, 0.0, 16.0, 0.5, 0);
	reg.registerFloatVar("dattorros_progenitor.input diff 1",N_("Input 1"),"S","",&fHslider3, 0.1, 0.0, 0.75, 0.01, 0);
	reg.registerFloatVar("dattorros_progenitor.input diff 2",N_("Input 2"),"S","",&fHslider2, 0.1, 0.0, 0.625, 0.01, 0);
	reg.registerFloatVar("dattorros_progenitor.predelay ms",N_("Predelay"),"S","",&fHslider4, 0.0, 0.0, 2e+02, 1e+01, 0);
	return 0;
}

int Dsp::register_params_static(const ParamReg& reg)
{
	return static_cast<Dsp*>(reg.plugin)->register_par(reg);
}

const char *Dsp::glade_def = "\
<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\
<!-- Generated with glade 3.22.1 -->\n\
<interface>\n\
  <requires lib=\"gtk+\" version=\"3.20\"/>\n\
  <requires lib=\"gxwidgets\" version=\"0.0\"/>\n\
  <object class=\"GtkWindow\" id=\"window1\">\n\
    <property name=\"can_focus\">False</property>\n\
    <child>\n\
      <placeholder/>\n\
    </child>\n\
    <child>\n\
      <object class=\"GtkBox\" id=\"vbox1\">\n\
        <property name=\"visible\">True</property>\n\
        <property name=\"can_focus\">False</property>\n\
        <property name=\"orientation\">vertical</property>\n\
        <child>\n\
          <object class=\"GtkBox\" id=\"rackbox\">\n\
            <property name=\"visible\">True</property>\n\
            <property name=\"can_focus\">False</property>\n\
            <property name=\"spacing\">4</property>\n\
            <child>\n\
              <object class=\"GtkBox\" id=\"vbox13\">\n\
                <property name=\"visible\">True</property>\n\
                <property name=\"can_focus\">False</property>\n\
                <property name=\"orientation\">vertical</property>\n\
                <child>\n\
                  <object class=\"GtkBox\" id=\"hbox3\">\n\
                    <property name=\"visible\">True</property>\n\
                    <property name=\"can_focus\">False</property>\n\
                    <child>\n\
                      <object class=\"GtkBox\" id=\"vbox4\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">False</property>\n\
                        <property name=\"orientation\">vertical</property>\n\
                        <child>\n\
                          <object class=\"GtkLabel\" id=\"label1\">\n\
                            <property name=\"visible\">True</property>\n\
                            <property name=\"can_focus\">False</property>\n\
                          </object>\n\
                          <packing>\n\
                            <property name=\"expand\">True</property>\n\
                            <property name=\"fill\">True</property>\n\
                            <property name=\"position\">0</property>\n\
                          </packing>\n\
                        </child>\n\
                        <child>\n\
                          <object class=\"GtkLabel\" id=\"label2:rack_label\">\n\
                            <property name=\"visible\">True</property>\n\
                            <property name=\"can_focus\">False</property>\n\
                            <property name=\"label\" translatable=\"yes\">label</property>\n\
                          </object>\n\
                          <packing>\n\
                            <property name=\"expand\">False</property>\n\
                            <property name=\"fill\">False</property>\n\
                            <property name=\"position\">1</property>\n\
                          </packing>\n\
                        </child>\n\
                        <child>\n\
                          <object class=\"GxMidKnob\" id=\"gxmidknob1\">\n\
                            <property name=\"visible\">True</property>\n\
                            <property name=\"can_focus\">True</property>\n\
                            <property name=\"receives_default\">True</property>\n\
                            <property name=\"var_id\">dattorros_progenitor.decay</property>\n\
                            <property name=\"label_ref\">label2:rack_label</property>\n\
                          </object>\n\
                          <packing>\n\
                            <property name=\"expand\">False</property>\n\
                            <property name=\"fill\">False</property>\n\
                            <property name=\"position\">2</property>\n\
                          </packing>\n\
                        </child>\n\
                        <child>\n\
                          <object class=\"GtkLabel\" id=\"label2\">\n\
                            <property name=\"visible\">True</property>\n\
                            <property name=\"can_focus\">False</property>\n\
                          </object>\n\
                          <packing>\n\
                            <property name=\"expand\">True</property>\n\
                            <property name=\"fill\">True</property>\n\
                            <property name=\"position\">3</property>\n\
                          </packing>\n\
                        </child>\n\
                      </object>\n\
                      <packing>\n\
                        <property name=\"expand\">False</property>\n\
                        <property name=\"fill\">False</property>\n\
                        <property name=\"position\">0</property>\n\
                      </packing>\n\
                    </child>\n\
                    <child>\n\
                      <object class=\"GtkBox\" id=\"vbox2\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">False</property>\n\
                        <property name=\"orientation\">vertical</property>\n\
                        <property name=\"spacing\">6</property>\n\
                        <child>\n\
                          <object class=\"GtkBox\" id=\"hbox2\">\n\
                            <property name=\"visible\">True</property>\n\
                            <property name=\"can_focus\">False</property>\n\
                            <property name=\"spacing\">3</property>\n\
                            <child>\n\
                              <object class=\"GtkBox\" id=\"vbox3\">\n\
                                <property name=\"visible\">True</property>\n\
                                <property name=\"can_focus\">False</property>\n\
                                <property name=\"orientation\">vertical</property>\n\
                                <child>\n\
                                  <object class=\"GtkLabel\" id=\"label1:rack_label\">\n\
                                    <property name=\"visible\">True</property>\n\
                                    <property name=\"can_focus\">False</property>\n\
                                    <property name=\"label\" translatable=\"yes\">label</property>\n\
                                  </object>\n\
                                  <packing>\n\
                                    <property name=\"expand\">False</property>\n\
                                    <property name=\"fill\">False</property>\n\
                                    <property name=\"position\">0</property>\n\
                                  </packing>\n\
                                </child>\n\
                                <child>\n\
                                  <object class=\"GxSmallKnobR\" id=\"gxbigknob1\">\n\
                                    <property name=\"visible\">True</property>\n\
                                    <property name=\"can_focus\">True</property>\n\
                                    <property name=\"receives_default\">True</property>\n\
                                    <property name=\"var_id\">dattorros_progenitor.predelay ms</property>\n\
                                    <property name=\"label_ref\">label1:rack_label</property>\n\
                                  </object>\n\
                                  <packing>\n\
                                    <property name=\"expand\">False</property>\n\
                                    <property name=\"fill\">False</property>\n\
                                    <property name=\"position\">1</property>\n\
                                  </packing>\n\
                                </child>\n\
                              </object>\n\
                              <packing>\n\
                                <property name=\"expand\">False</property>\n\
                                <property name=\"fill\">False</property>\n\
                                <property name=\"position\">0</property>\n\
                              </packing>\n\
                            </child>\n\
                            <child>\n\
                              <object class=\"GtkBox\" id=\"vbox8\">\n\
                                <property name=\"visible\">True</property>\n\
                                <property name=\"can_focus\">False</property>\n\
                                <property name=\"orientation\">vertical</property>\n\
                                <child>\n\
                                  <object class=\"GtkLabel\" id=\"label11:rack_label\">\n\
                                    <property name=\"visible\">True</property>\n\
                                    <property name=\"can_focus\">False</property>\n\
                                    <property name=\"label\" translatable=\"yes\">label</property>\n\
                                  </object>\n\
                                  <packing>\n\
                                    <property name=\"expand\">False</property>\n\
                                    <property name=\"fill\">False</property>\n\
                                    <property name=\"position\">0</property>\n\
                                  </packing>\n\
                                </child>\n\
                                <child>\n\
                                  <object class=\"GxSmallKnobR\" id=\"gxbigknob6\">\n\
                                    <property name=\"visible\">True</property>\n\
                                    <property name=\"can_focus\">True</property>\n\
                                    <property name=\"receives_default\">True</property>\n\
                                    <property name=\"var_id\">dattorros_progenitor.bandwidth</property>\n\
                                    <property name=\"label_ref\">label11:rack_label</property>\n\
                                  </object>\n\
                                  <packing>\n\
                                    <property name=\"expand\">False</property>\n\
                                    <property name=\"fill\">False</property>\n\
                                    <property name=\"position\">1</property>\n\
                                  </packing>\n\
                                </child>\n\
                              </object>\n\
                              <packing>\n\
                                <property name=\"expand\">False</property>\n\
                                <property name=\"fill\">False</property>\n\
                                <property name=\"position\">1</property>\n\
                              </packing>\n\
                            </child>\n\
                            <child>\n\
                              <object class=\"GtkBox\" id=\"vbox9\">\n\
                                <property name=\"visible\">True</property>\n\
                                <property name=\"can_focus\">False</property>\n\
                                <property name=\"orientation\">vertical</property>\n\
                                <child>\n\
                                  <object class=\"GtkLabel\" id=\"label21:rack_label\">\n\
                                    <property name=\"visible\">True</property>\n\
                                    <property name=\"can_focus\">False</property>\n\
                                    <property name=\"label\" translatable=\"yes\">label</property>\n\
                                  </object>\n\
                                  <packing>\n\
                                    <property name=\"expand\">False</property>\n\
                                    <property name=\"fill\">False</property>\n\
                                    <property name=\"position\">0</property>\n\
                                  </packing>\n\
                                </child>\n\
                                <child>\n\
                                  <object class=\"GxSmallKnobR\" id=\"gxbigknob7\">\n\
                                    <property name=\"visible\">True</property>\n\
                                    <property name=\"can_focus\">True</property>\n\
                                    <property name=\"receives_default\">True</property>\n\
                                    <property name=\"var_id\">dattorros_progenitor.damping</property>\n\
                                    <property name=\"label_ref\">label21:rack_label</property>\n\
                                  </object>\n\
                                  <packing>\n\
                                    <property name=\"expand\">False</property>\n\
                                    <property name=\"fill\">False</property>\n\
                                    <property name=\"position\">1</property>\n\
                                  </packing>\n\
                                </child>\n\
                              </object>\n\
                              <packing>\n\
                                <property name=\"expand\">False</property>\n\
                                <property name=\"fill\">False</property>\n\
                                <property name=\"position\">2</property>\n\
                              </packing>\n\
                            </child>\n\
                            <child>\n\
                              <object class=\"GtkBox\" id=\"vbox7\">\n\
                                <property name=\"visible\">True</property>\n\
                                <property name=\"can_focus\">False</property>\n\
                                <property name=\"orientation\">vertical</property>\n\
                                <child>\n\
                                  <object class=\"GtkLabel\" id=\"label5:rack_label\">\n\
                                    <property name=\"visible\">True</property>\n\
                                    <property name=\"can_focus\">False</property>\n\
                                    <property name=\"label\" translatable=\"yes\">label</property>\n\
                                  </object>\n\
                                  <packing>\n\
                                    <property name=\"expand\">False</property>\n\
                                    <property name=\"fill\">False</property>\n\
                                    <property name=\"position\">0</property>\n\
                                  </packing>\n\
                                </child>\n\
                                <child>\n\
                                  <object class=\"GxSmallKnobR\" id=\"gxbigknob5\">\n\
                                    <property name=\"visible\">True</property>\n\
                                    <property name=\"can_focus\">True</property>\n\
                                    <property name=\"receives_default\">True</property>\n\
                                    <property name=\"var_id\">dattorros_progenitor.excursion</property>\n\
                                    <property name=\"label_ref\">label5:rack_label</property>\n\
                                  </object>\n\
                                  <packing>\n\
                                    <property name=\"expand\">False</property>\n\
                                    <property name=\"fill\">False</property>\n\
                                    <property name=\"position\">1</property>\n\
                                  </packing>\n\
                                </child>\n\
                              </object>\n\
                              <packing>\n\
                                <property name=\"expand\">False</property>\n\
                                <property name=\"fill\">False</property>\n\
                                <property name=\"position\">3</property>\n\
                              </packing>\n\
                            </child>\n\
                          </object>\n\
                          <packing>\n\
                            <property name=\"expand\">False</property>\n\
                            <property name=\"fill\">False</property>\n\
                            <property name=\"position\">0</property>\n\
                          </packing>\n\
                        </child>\n\
                        <child>\n\
                          <object class=\"GtkFrame\" id=\"frame1:frame_inversed\">\n\
                            <property name=\"visible\">True</property>\n\
                            <property name=\"can_focus\">False</property>\n\
                            <property name=\"label_xalign\">0</property>\n\
                            <child>\n\
                              <object class=\"GtkBox\" id=\"hbox4\">\n\
                                <property name=\"visible\">True</property>\n\
                                <property name=\"can_focus\">False</property>\n\
                                <child>\n\
                                  <object class=\"GtkBox\" id=\"vbox5\">\n\
                                    <property name=\"visible\">True</property>\n\
                                    <property name=\"can_focus\">False</property>\n\
                                    <property name=\"orientation\">vertical</property>\n\
                                    <child>\n\
                                      <object class=\"GxSmallKnob\" id=\"gxbigknob3\">\n\
                                        <property name=\"visible\">True</property>\n\
                                        <property name=\"can_focus\">True</property>\n\
                                        <property name=\"receives_default\">True</property>\n\
                                        <property name=\"var_id\">dattorros_progenitor.input diff 1</property>\n\
                                        <property name=\"label_ref\">label3:rack_label_inverse</property>\n\
                                      </object>\n\
                                      <packing>\n\
                                        <property name=\"expand\">False</property>\n\
                                        <property name=\"fill\">False</property>\n\
                                        <property name=\"position\">0</property>\n\
                                      </packing>\n\
                                    </child>\n\
                                    <child>\n\
                                      <object class=\"GtkLabel\" id=\"label3:rack_label_inverse\">\n\
                                        <property name=\"visible\">True</property>\n\
                                        <property name=\"can_focus\">False</property>\n\
                                        <property name=\"label\" translatable=\"yes\">label</property>\n\
                                      </object>\n\
                                      <packing>\n\
                                        <property name=\"expand\">False</property>\n\
                                        <property name=\"fill\">False</property>\n\
                                        <property name=\"position\">1</property>\n\
                                      </packing>\n\
                                    </child>\n\
                                  </object>\n\
                                  <packing>\n\
                                    <property name=\"expand\">True</property>\n\
                                    <property name=\"fill\">True</property>\n\
                                    <property name=\"position\">0</property>\n\
                                  </packing>\n\
                                </child>\n\
                                <child>\n\
                                  <object class=\"GtkBox\" id=\"vbox6\">\n\
                                    <property name=\"visible\">True</property>\n\
                                    <property name=\"can_focus\">False</property>\n\
                                    <property name=\"orientation\">vertical</property>\n\
                                    <child>\n\
                                      <object class=\"GxSmallKnob\" id=\"gxbigknob4\">\n\
                                        <property name=\"visible\">True</property>\n\
                                        <property name=\"can_focus\">True</property>\n\
                                        <property name=\"receives_default\">True</property>\n\
                                        <property name=\"var_id\">dattorros_progenitor.input diff 2</property>\n\
                                        <property name=\"label_ref\">label4:rack_label_inverse</property>\n\
                                      </object>\n\
                                      <packing>\n\
                                        <property name=\"expand\">False</property>\n\
                                        <property name=\"fill\">False</property>\n\
                                        <property name=\"position\">0</property>\n\
                                      </packing>\n\
                                    </child>\n\
                                    <child>\n\
                                      <object class=\"GtkLabel\" id=\"label4:rack_label_inverse\">\n\
                                        <property name=\"visible\">True</property>\n\
                                        <property name=\"can_focus\">False</property>\n\
                                        <property name=\"label\" translatable=\"yes\">label</property>\n\
                                      </object>\n\
                                      <packing>\n\
                                        <property name=\"expand\">False</property>\n\
                                        <property name=\"fill\">False</property>\n\
                                        <property name=\"position\">1</property>\n\
                                      </packing>\n\
                                    </child>\n\
                                  </object>\n\
                                  <packing>\n\
                                    <property name=\"expand\">True</property>\n\
                                    <property name=\"fill\">True</property>\n\
                                    <property name=\"position\">1</property>\n\
                                  </packing>\n\
                                </child>\n\
                                <child>\n\
                                  <object class=\"GtkBox\" id=\"vbox10\">\n\
                                    <property name=\"visible\">True</property>\n\
                                    <property name=\"can_focus\">False</property>\n\
                                    <property name=\"orientation\">vertical</property>\n\
                                    <child>\n\
                                      <object class=\"GxSmallKnob\" id=\"gxbigknob8\">\n\
                                        <property name=\"visible\">True</property>\n\
                                        <property name=\"can_focus\">True</property>\n\
                                        <property name=\"receives_default\">True</property>\n\
                                        <property name=\"var_id\">dattorros_progenitor.decay diff 1</property>\n\
                                        <property name=\"label_ref\">label31:rack_label_inverse</property>\n\
                                      </object>\n\
                                      <packing>\n\
                                        <property name=\"expand\">False</property>\n\
                                        <property name=\"fill\">False</property>\n\
                                        <property name=\"position\">0</property>\n\
                                      </packing>\n\
                                    </child>\n\
                                    <child>\n\
                                      <object class=\"GtkLabel\" id=\"label31:rack_label_inverse\">\n\
                                        <property name=\"visible\">True</property>\n\
                                        <property name=\"can_focus\">False</property>\n\
                                        <property name=\"label\" translatable=\"yes\">label</property>\n\
                                      </object>\n\
                                      <packing>\n\
                                        <property name=\"expand\">False</property>\n\
                                        <property name=\"fill\">False</property>\n\
                                        <property name=\"position\">1</property>\n\
                                      </packing>\n\
                                    </child>\n\
                                  </object>\n\
                                  <packing>\n\
                                    <property name=\"expand\">True</property>\n\
                                    <property name=\"fill\">True</property>\n\
                                    <property name=\"position\">2</property>\n\
                                  </packing>\n\
                                </child>\n\
                                <child>\n\
                                  <object class=\"GtkBox\" id=\"vbox11\">\n\
                                    <property name=\"visible\">True</property>\n\
                                    <property name=\"can_focus\">False</property>\n\
                                    <property name=\"orientation\">vertical</property>\n\
                                    <child>\n\
                                      <object class=\"GxSmallKnob\" id=\"gxbigknob9\">\n\
                                        <property name=\"visible\">True</property>\n\
                                        <property name=\"can_focus\">True</property>\n\
                                        <property name=\"receives_default\">True</property>\n\
                                        <property name=\"var_id\">dattorros_progenitor.decay diff 2</property>\n\
                                        <property name=\"label_ref\">label41:rack_label_inverse</property>\n\
                                      </object>\n\
                                      <packing>\n\
                                        <property name=\"expand\">False</property>\n\
                                        <property name=\"fill\">False</property>\n\
                                        <property name=\"position\">0</property>\n\
                                      </packing>\n\
                                    </child>\n\
                                    <child>\n\
                                      <object class=\"GtkLabel\" id=\"label41:rack_label_inverse\">\n\
                                        <property name=\"visible\">True</property>\n\
                                        <property name=\"can_focus\">False</property>\n\
                                        <property name=\"label\" translatable=\"yes\">label</property>\n\
                                      </object>\n\
                                      <packing>\n\
                                        <property name=\"expand\">False</property>\n\
                                        <property name=\"fill\">False</property>\n\
                                        <property name=\"position\">1</property>\n\
                                      </packing>\n\
                                    </child>\n\
                                  </object>\n\
                                  <packing>\n\
                                    <property name=\"expand\">True</property>\n\
                                    <property name=\"fill\">True</property>\n\
                                    <property name=\"position\">3</property>\n\
                                  </packing>\n\
                                </child>\n\
                              </object>\n\
                            </child>\n\
                            <child type=\"label\">\n\
                              <object class=\"GtkLabel\" id=\"label300:rack_label_inverse\">\n\
                                <property name=\"visible\">True</property>\n\
                                <property name=\"can_focus\">False</property>\n\
                                <property name=\"label\" translatable=\"yes\">Diffusion</property>\n\
                                <property name=\"use_markup\">True</property>\n\
                              </object>\n\
                            </child>\n\
                          </object>\n\
                          <packing>\n\
                            <property name=\"expand\">True</property>\n\
                            <property name=\"fill\">True</property>\n\
                            <property name=\"position\">1</property>\n\
                          </packing>\n\
                        </child>\n\
                      </object>\n\
                      <packing>\n\
                        <property name=\"expand\">True</property>\n\
                        <property name=\"fill\">False</property>\n\
                        <property name=\"position\">1</property>\n\
                      </packing>\n\
                    </child>\n\
                    <child>\n\
                      <object class=\"GtkBox\" id=\"vbox12\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">False</property>\n\
                        <property name=\"orientation\">vertical</property>\n\
                        <child>\n\
                          <object class=\"GtkLabel\" id=\"label3\">\n\
                            <property name=\"visible\">True</property>\n\
                            <property name=\"can_focus\">False</property>\n\
                          </object>\n\
                          <packing>\n\
                            <property name=\"expand\">True</property>\n\
                            <property name=\"fill\">True</property>\n\
                            <property name=\"position\">0</property>\n\
                          </packing>\n\
                        </child>\n\
                        <child>\n\
                          <object class=\"GtkLabel\" id=\"label51:rack_label\">\n\
                            <property name=\"visible\">True</property>\n\
                            <property name=\"can_focus\">False</property>\n\
                            <property name=\"label\" translatable=\"yes\">label</property>\n\
                          </object>\n\
                          <packing>\n\
                            <property name=\"expand\">False</property>\n\
                            <property name=\"fill\">False</property>\n\
                            <property name=\"position\">1</property>\n\
                          </packing>\n\
                        </child>\n\
                        <child>\n\
                          <object class=\"GxMidKnob\" id=\"gxmidknob2\">\n\
                            <property name=\"visible\">True</property>\n\
                            <property name=\"can_focus\">True</property>\n\
                            <property name=\"receives_default\">True</property>\n\
                            <property name=\"var_id\">dattorros_progenitor.dry/wet</property>\n\
                            <property name=\"label_ref\">label51:rack_label</property>\n\
                          </object>\n\
                          <packing>\n\
                            <property name=\"expand\">True</property>\n\
                            <property name=\"fill\">True</property>\n\
                            <property name=\"position\">2</property>\n\
                          </packing>\n\
                        </child>\n\
                        <child>\n\
                          <object class=\"GtkLabel\" id=\"label4\">\n\
                            <property name=\"visible\">True</property>\n\
                            <property name=\"can_focus\">False</property>\n\
                          </object>\n\
                          <packing>\n\
                            <property name=\"expand\">True</property>\n\
                            <property name=\"fill\">True</property>\n\
                            <property name=\"position\">3</property>\n\
                          </packing>\n\
                        </child>\n\
                      </object>\n\
                      <packing>\n\
                        <property name=\"expand\">False</property>\n\
                        <property name=\"fill\">False</property>\n\
                        <property name=\"position\">2</property>\n\
                      </packing>\n\
                    </child>\n\
                  </object>\n\
                  <packing>\n\
                    <property name=\"expand\">True</property>\n\
                    <property name=\"fill\">True</property>\n\
                    <property name=\"position\">0</property>\n\
                  </packing>\n\
                </child>\n\
              </object>\n\
              <packing>\n\
                <property name=\"expand\">True</property>\n\
                <property name=\"fill\">False</property>\n\
                <property name=\"position\">0</property>\n\
              </packing>\n\
            </child>\n\
          </object>\n\
          <packing>\n\
            <property name=\"expand\">False</property>\n\
            <property name=\"fill\">False</property>\n\
            <property name=\"position\">0</property>\n\
          </packing>\n\
        </child>\n\
        <child>\n\
          <object class=\"GtkBox\" id=\"minibox\">\n\
            <property name=\"visible\">True</property>\n\
            <property name=\"can_focus\">False</property>\n\
            <property name=\"spacing\">4</property>\n\
            <child>\n\
              <object class=\"GxHSlider\" id=\"gxhslider1\">\n\
                <property name=\"visible\">True</property>\n\
                <property name=\"can_focus\">True</property>\n\
                <property name=\"receives_default\">True</property>\n\
                <property name=\"round_digits\">0</property>\n\
                <property name=\"var_id\">dattorros_progenitor.dry/wet</property>\n\
                <property name=\"show_value\">False</property>\n\
                <property name=\"value_position\">right</property>\n\
                <property name=\"value_xalign\">0.52000000000000002</property>\n\
                <property name=\"label_ref\">label0:rack_label</property>\n\
              </object>\n\
              <packing>\n\
                <property name=\"expand\">False</property>\n\
                <property name=\"fill\">False</property>\n\
                <property name=\"position\">0</property>\n\
              </packing>\n\
            </child>\n\
            <child>\n\
              <object class=\"GtkLabel\" id=\"label0:rack_label\">\n\
                <property name=\"visible\">True</property>\n\
                <property name=\"can_focus\">False</property>\n\
                <property name=\"label\" translatable=\"yes\">Dry/Wet</property>\n\
                <property name=\"xalign\">0</property>\n\
              </object>\n\
              <packing>\n\
                <property name=\"expand\">False</property>\n\
                <property name=\"fill\">False</property>\n\
                <property name=\"position\">1</property>\n\
              </packing>\n\
            </child>\n\
          </object>\n\
          <packing>\n\
            <property name=\"expand\">True</property>\n\
            <property name=\"fill\">True</property>\n\
            <property name=\"position\">1</property>\n\
          </packing>\n\
        </child>\n\
      </object>\n\
    </child>\n\
  </object>\n\
</interface>\n\
";

inline int Dsp::load_ui_f(const UiBuilder& b, int form)
{
    if (form & UI_FORM_GLADE) {
        b.load_glade(glade_def);
        return 0;
    }
    if (form & UI_FORM_STACK) {
#define PARAM(p) ("dattorros_progenitor" "." p)
// dattorros progenitor (Plate reverb)

b.openHorizontalhideBox("");
b.create_master_slider(PARAM("dry/wet"), _("dry/wet"));
b.closeBox();

b.openHorizontalBox("");
b.openVerticalBox("");
b.openHorizontalBox("");
{
	b.create_small_rackknob(PARAM("predelay ms"),  _("predelay ms"));
	b.create_small_rackknob(PARAM("bandwidth"),    _(" bandwidth "));
	b.create_small_rackknob(PARAM("input diff 1"), _(" in diff 1 "));
	b.create_small_rackknob(PARAM("input diff 2"), _(" in diff 2 "));
	b.create_small_rackknob(PARAM("excursion"),    _(" excursion "));

	
}
b.closeBox();
b.openHorizontalBox("");
{
	b.create_small_rackknob(PARAM("decay"),        _("  decay   "));
	b.create_small_rackknob(PARAM("decay diff 1"), _("dec diff 1"));
	b.create_small_rackknob(PARAM("decay diff 2"), _("dec diff 2"));
	b.create_small_rackknob(PARAM("damping"),      _("HF damping"));
	b.create_small_rackknobr(PARAM("dry/wet"),     _("  dry/wet "));
}
b.closeBox();
b.closeBox();
b.closeBox();

#undef PARAM
        return 0;
    }
	return -1;
}

int Dsp::load_ui_f_static(const UiBuilder& b, int form)
{
	return static_cast<Dsp*>(b.plugin)->load_ui_f(b, form);
}
PluginDef *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginDef *p)
{
	delete static_cast<Dsp*>(p);
}

} // end namespace dattorros_progenitor
