// generated from file '../src/plugins/ffreak.dsp' by dsp2cc:
// Code generated with Faust (https://faust.grame.fr)

#include "gx_faust_support.h"
#include "gx_plugin.h"
#include <string.h>

namespace pluginlib {
namespace ffreak {

class Dsp: public PluginDef {
private:
	int fSampleRate;
	FAUSTFLOAT fVslider0;
	double fRec0[2];
	double fConst0;
	double fConst3;
	double fConst5;
	FAUSTFLOAT fVslider1;
	double fRec1[2];
	double fConst7;
	double fConst9;
	double fConst11;
	double fConst13;
	double fConst15;
	double fConst17;
	double fConst18;
	double fConst19;
	FAUSTFLOAT fVslider2;
	double fRec2[2];
	double fConst20;
	double fConst21;
	double fConst24;
	double fConst26;
	double fConst29;
	double fConst31;
	double fConst33;
	double fConst35;
	double fConst37;
	double fConst39;
	double fConst40;
	double fConst41;
	double fConst42;
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fConst51;
	double fConst53;
	double fConst55;
	double fConst57;
	double fConst59;
	double fConst61;
	double fConst63;
	double fConst65;
	double fConst67;
	double fConst68;
	double fConst69;
	double fConst70;
	double fConst71;
	double fConst73;
	double fConst75;
	double fConst77;
	double fConst79;
	double fConst81;
	double fConst83;
	double fConst85;
	double fConst87;
	double fConst88;
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;
	double fConst93;
	double fConst94;
	double fConst95;
	double fConst96;
	double fConst97;
	double fConst98;
	double fConst99;
	double fConst100;
	double fConst101;
	double fConst102;
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fConst107;
	double fConst108;
	double fConst109;
	double fConst110;
	double fConst111;
	double fConst112;
	double fConst113;
	double fConst114;
	double fConst115;
	double fRec3[6];
	double fConst117;
	double fConst119;
	double fConst121;
	double fConst123;
	double fConst125;
	double fConst127;
	double fConst129;
	double fConst131;
	double fConst133;
	double fConst135;
	double fConst137;
	double fConst139;
	double fConst141;
	double fConst143;
	double fConst145;
	double fConst147;
	double fConst148;
	double fConst149;
	double fConst150;
	double fConst151;
	double fConst152;
	double fConst153;
	double fConst154;
	double fConst155;
	double fConst156;
	double fConst157;
	double fConst158;
	double fConst159;
	double fConst160;
	double fConst161;
	double fConst162;
	double fConst163;
	double fConst164;
	double fConst165;
	double fConst166;
	double fConst167;
	double fConst168;
	double fConst169;
	double fConst170;
	double fConst171;
	FAUSTFLOAT fVslider3;
	double fRec4[2];

	FAUSTFLOAT fsliderdw0;
	void clear_state_f();
	int load_ui_f(const UiBuilder& b, int form);
	static const char *glade_def;
	void init(unsigned int sample_rate);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);
	int register_par(const ParamReg& reg);

	static void clear_state_f_static(PluginDef*);
	static int load_ui_f_static(const UiBuilder& b, int form);
	static void init_static(unsigned int sample_rate, PluginDef*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef*);
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
	id = "ffreak";
	name = N_("Fat Furry Freak");
	groups = 0;
	description = N_("Extreme Bass Fuzz Monster"); // description (tooltip)
	category = N_("Fuzz");       // category
	shortname = N_("Fat FFreak");     // shortname
	mono_audio = compute_static;
	stereo_audio = 0;
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
	for (int l0 = 0; l0 < 2; l0 = l0 + 1) fRec0[l0] = 0.0;
	for (int l1 = 0; l1 < 2; l1 = l1 + 1) fRec1[l1] = 0.0;
	for (int l2 = 0; l2 < 2; l2 = l2 + 1) fRec2[l2] = 0.0;
	for (int l3 = 0; l3 < 6; l3 = l3 + 1) fRec3[l3] = 0.0;
	for (int l4 = 0; l4 < 2; l4 = l4 + 1) fRec4[l4] = 0.0;
}

void Dsp::clear_state_f_static(PluginDef *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(unsigned int sample_rate)
{
	fSampleRate = sample_rate;
	fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, double(fSampleRate)));
	double fConst1 = mydsp_faustpower2_f(fConst0);
	double fConst2 = 5.5846598379774e-24 * fConst0;
	fConst3 = (fConst0 * (fConst0 * (fConst2 + 3.42119219586653e-20) + 3.19454127568422e-17) + 2.62717307381708e-15) * fConst1;
	double fConst4 = 5.71839588129828e-24 * fConst0;
	fConst5 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-3.49001694087958e-20 - fConst4) + -3.20489931550843e-17) + -2.65988017960028e-15) + -2.62717307381708e-15);
	double fConst6 = 7.85412319843037e-24 * fConst0;
	fConst7 = fConst1 * (fConst0 * (fConst0 * (-7.55784595381368e-20 - fConst6) + -7.35486357301917e-17) + -3.92585764869989e-15);
	double fConst8 = 8.04220615975415e-24 * fConst0;
	fConst9 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst8 + 7.72040670186403e-20) + 7.37353569889037e-17) + 4.00054450346227e-15) + 3.92585764869989e-15);
	double fConst10 = 6.54379653368279e-24 * fConst0;
	fConst11 = fConst0 * (fConst0 * (fConst0 * (fConst10 + 5.8178250366366e-20) + 1.85568523263077e-17) + 1.66102929456909e-16) + 5.00381548719697e-17;
	double fConst12 = 6.70053233478593e-24 * fConst0;
	fConst13 = fConst0 * (fConst0 * (fConst0 * (-5.95782688271891e-20 - fConst12) + -1.90595008624394e-17) + -1.88638248347695e-16) + -2.17339588935373e-16;
	double fConst14 = 4.65295447579144e-24 * fConst0;
	fConst15 = fConst1 * (fConst0 * (fConst0 * (-2.3734396603456e-20 - fConst14) + -2.32762902199933e-18) + -1.88310920685508e-17);
	double fConst16 = 4.76440117855883e-24 * fConst0;
	fConst17 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst16 + 2.43075314241076e-20) + 2.40711435730575e-18) + 2.16097599157672e-17) + 1.88310920685508e-17);
	fConst18 = fConst1 * (fConst0 * (fConst0 * (fConst10 + 5.62612870500991e-20) + 3.66325429672487e-18) + 2.81398235873665e-17);
	fConst19 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-5.76153907610497e-20 - fConst12) + -3.80725717138185e-18) + -3.24770777204501e-17) + -2.81398235873665e-17);
	fConst20 = fConst0 * (fConst0 * (fConst0 * (-7.78792746651557e-20 - fConst6) + -9.37831383212842e-17) + -2.2395439003671e-14) + -6.9809489892874e-15;
	fConst21 = fConst0 * (fConst0 * (fConst0 * (fConst8 + 7.95599798455062e-20) + 9.44004344622607e-17) + 2.24958749395835e-14) + 2.93784119708285e-14;
	double fConst22 = 1.87753470001801e-18 * fConst0;
	double fConst23 = mydsp_faustpower3_f(fConst0);
	fConst24 = fConst23 * (1.56079959618215e-14 - fConst22);
	double fConst25 = 2.70062186191725e-18 * fConst0;
	fConst26 = fConst1 * (fConst0 * (fConst25 + -2.24522189930002e-14) + 1.56079959618215e-14);
	double fConst27 = 2.79019064029167e-21 * fConst0;
	double fConst28 = mydsp_faustpower4_f(fConst0);
	fConst29 = fConst28 * (fConst27 + -1.39597416617563e-17);
	double fConst30 = 4.01337447559094e-21 * fConst0;
	fConst31 = fConst23 * (fConst0 * (2.00823037773104e-17 - fConst30) + -1.39597416617563e-17);
	double fConst32 = 2.31663605170274e-21 * fConst0;
	fConst33 = fConst28 * (1.15904771305164e-17 - fConst32);
	double fConst34 = 3.33595591445214e-21 * fConst0;
	fConst35 = fConst23 * (fConst0 * (fConst34 + -1.66926037039962e-17) + 1.15904771305164e-17);
	double fConst36 = 1.55887720056646e-18 * fConst0;
	fConst37 = fConst23 * (fConst36 + -1.29589876827223e-14);
	double fConst38 = 2.24478316881583e-18 * fConst0;
	fConst39 = fConst1 * (fConst0 * (1.86625011403217e-14 - fConst38) + -1.29589876827223e-14);
	fConst40 = fConst1 * (fConst0 * (fConst0 * (3.42119219586653e-20 - fConst2) + -3.19454127568422e-17) + 2.62717307381708e-15);
	fConst41 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst4 + -3.49001694087958e-20) + 3.20489931550843e-17) + -2.65988017960028e-15) + 2.62717307381708e-15);
	fConst42 = fConst1 * (fConst0 * (fConst0 * (fConst6 + -7.55784595381368e-20) + 7.35486357301917e-17) + -3.92585764869989e-15);
	fConst43 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (7.72040670186403e-20 - fConst8) + -7.37353569889037e-17) + 4.00054450346227e-15) + -3.92585764869989e-15);
	fConst44 = fConst0 * (fConst0 * (fConst0 * (5.8178250366366e-20 - fConst10) + -1.85568523263077e-17) + 1.66102929456909e-16) + -5.00381548719697e-17;
	fConst45 = fConst0 * (fConst0 * (fConst0 * (fConst12 + -5.95782688271891e-20) + 1.90595008624394e-17) + -1.88638248347695e-16) + 2.17339588935373e-16;
	fConst46 = fConst1 * (fConst0 * (fConst0 * (fConst14 + -2.3734396603456e-20) + 2.32762902199933e-18) + -1.88310920685508e-17);
	fConst47 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (2.43075314241076e-20 - fConst16) + -2.40711435730575e-18) + 2.16097599157672e-17) + -1.88310920685508e-17);
	fConst48 = fConst1 * (fConst0 * (fConst0 * (5.62612870500991e-20 - fConst10) + -3.66325429672487e-18) + 2.81398235873665e-17);
	fConst49 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst12 + -5.76153907610497e-20) + 3.80725717138185e-18) + -3.24770777204501e-17) + 2.81398235873665e-17);
	fConst50 = fConst0 * (fConst0 * (fConst0 * (fConst6 + -7.78792746651557e-20) + 9.37831383212842e-17) + -2.2395439003671e-14) + 6.9809489892874e-15;
	fConst51 = fConst0 * (fConst0 * (fConst0 * (7.95599798455062e-20 - fConst8) + -9.44004344622607e-17) + 2.24958749395835e-14) + -2.93784119708285e-14;
	double fConst52 = 2.7923299189887e-23 * fConst0;
	fConst53 = fConst1 * (fConst0 * (fConst0 * (fConst52 + -1.02635765875996e-19) + 3.19454127568422e-17) + 2.62717307381708e-15);
	double fConst54 = 2.85919794064914e-23 * fConst0;
	fConst55 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (1.04700508226387e-19 - fConst54) + -3.20489931550843e-17) + -2.65988017960028e-15) + 7.88151922145125e-15);
	double fConst56 = 3.92706159921519e-23 * fConst0;
	fConst57 = fConst1 * (fConst0 * (fConst0 * (2.2673537861441e-19 - fConst56) + -7.35486357301917e-17) + -3.92585764869989e-15);
	double fConst58 = 4.02110307987707e-23 * fConst0;
	fConst59 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst58 + -2.31612201055921e-19) + 7.37353569889037e-17) + 4.00054450346227e-15) + -1.17775729460997e-14);
	double fConst60 = 3.27189826684139e-23 * fConst0;
	fConst61 = fConst0 * (fConst0 * (fConst0 * (fConst60 + -1.74534751099098e-19) + 1.85568523263077e-17) + 1.66102929456909e-16) + -1.50114464615909e-16;
	double fConst62 = 3.35026616739297e-23 * fConst0;
	fConst63 = fConst0 * (fConst0 * (fConst0 * (1.78734806481567e-19 - fConst62) + -1.90595008624394e-17) + -1.88638248347695e-16) + 6.52018766806119e-16;
	double fConst64 = 2.32647723789572e-23 * fConst0;
	fConst65 = fConst1 * (fConst0 * (fConst0 * (7.1203189810368e-20 - fConst64) + -2.32762902199933e-18) + -1.88310920685508e-17);
	double fConst66 = 2.38220058927942e-23 * fConst0;
	fConst67 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst66 + -7.29225942723227e-20) + 2.40711435730575e-18) + 2.16097599157672e-17) + -5.64932762056525e-17);
	fConst68 = fConst1 * (fConst0 * (fConst0 * (fConst60 + -1.68783861150297e-19) + 3.66325429672487e-18) + 2.81398235873665e-17);
	fConst69 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (1.72846172283149e-19 - fConst62) + -3.80725717138185e-18) + -3.24770777204501e-17) + 8.44194707620995e-17);
	fConst70 = fConst0 * (fConst0 * (fConst0 * (2.33637823995467e-19 - fConst56) + -9.37831383212842e-17) + -2.2395439003671e-14) + 2.09428469678622e-14;
	fConst71 = fConst0 * (fConst0 * (fConst0 * (fConst58 + -2.38679939536519e-19) + 9.44004344622607e-17) + 2.24958749395835e-14) + -8.81352359124856e-14;
	double fConst72 = 5.5846598379774e-23 * fConst0;
	fConst73 = fConst1 * (fConst0 * (fConst0 * (6.84238439173306e-20 - fConst72) + 6.38908255136844e-17) + -5.25434614763417e-15);
	double fConst74 = 5.71839588129828e-23 * fConst0;
	fConst75 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst74 + -6.98003388175915e-20) + -6.40979863101685e-17) + 5.31976035920056e-15) + 5.25434614763417e-15);
	double fConst76 = 7.85412319843037e-23 * fConst0;
	fConst77 = fConst1 * (fConst0 * (fConst0 * (fConst76 + -1.51156919076274e-19) + -1.47097271460383e-16) + 7.85171529739978e-15);
	double fConst78 = 8.04220615975415e-23 * fConst0;
	fConst79 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (1.54408134037281e-19 - fConst78) + 1.47470713977807e-16) + -8.00108900692453e-15) + -7.85171529739978e-15);
	double fConst80 = 6.54379653368279e-23 * fConst0;
	fConst81 = fConst0 * (fConst0 * (fConst0 * (1.16356500732732e-19 - fConst80) + 3.71137046526153e-17) + -3.32205858913818e-16) + -1.00076309743939e-16;
	double fConst82 = 6.70053233478593e-23 * fConst0;
	fConst83 = fConst0 * (fConst0 * (fConst0 * (fConst82 + -1.19156537654378e-19) + -3.81190017248788e-17) + 3.7727649669539e-16) + 4.34679177870746e-16;
	double fConst84 = 4.65295447579144e-23 * fConst0;
	fConst85 = fConst1 * (fConst0 * (fConst0 * (fConst84 + -4.7468793206912e-20) + -4.65525804399867e-18) + 3.76621841371017e-17);
	double fConst86 = 4.76440117855883e-23 * fConst0;
	fConst87 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (4.86150628482151e-20 - fConst86) + 4.8142287146115e-18) + -4.32195198315344e-17) + -3.76621841371017e-17);
	fConst88 = fConst1 * (fConst0 * (fConst0 * (1.12522574100198e-19 - fConst80) + 7.32650859344974e-18) + -5.6279647174733e-17);
	fConst89 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst82 + -1.15230781522099e-19) + -7.6145143427637e-18) + 6.49541554409002e-17) + 5.6279647174733e-17);
	fConst90 = fConst0 * (fConst0 * (fConst0 * (fConst76 + -1.55758549330311e-19) + -1.87566276642568e-16) + 4.4790878007342e-14) + 1.39618979785748e-14;
	fConst91 = fConst0 * (fConst0 * (fConst0 * (1.59119959691012e-19 - fConst78) + 1.88800868924521e-16) + -4.49917498791669e-14) + -5.87568239416571e-14;
	fConst92 = fConst1 * (fConst0 * (fConst0 * (fConst72 + 6.84238439173306e-20) + -6.38908255136844e-17) + -5.25434614763417e-15);
	fConst93 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-6.98003388175915e-20 - fConst74) + 6.40979863101685e-17) + 5.31976035920056e-15) + -5.25434614763417e-15);
	fConst94 = fConst1 * (fConst0 * (fConst0 * (-1.51156919076274e-19 - fConst76) + 1.47097271460383e-16) + 7.85171529739978e-15);
	fConst95 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst78 + 1.54408134037281e-19) + -1.47470713977807e-16) + -8.00108900692453e-15) + 7.85171529739978e-15);
	fConst96 = fConst0 * (fConst0 * (fConst0 * (fConst80 + 1.16356500732732e-19) + -3.71137046526153e-17) + -3.32205858913818e-16) + 1.00076309743939e-16;
	fConst97 = fConst0 * (fConst0 * (fConst0 * (-1.19156537654378e-19 - fConst82) + 3.81190017248788e-17) + 3.7727649669539e-16) + -4.34679177870746e-16;
	fConst98 = fConst1 * (fConst0 * (fConst0 * (-4.7468793206912e-20 - fConst84) + 4.65525804399867e-18) + 3.76621841371017e-17);
	fConst99 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst86 + 4.86150628482151e-20) + -4.8142287146115e-18) + -4.32195198315344e-17) + 3.76621841371017e-17);
	fConst100 = fConst1 * (fConst0 * (fConst0 * (fConst80 + 1.12522574100198e-19) + -7.32650859344974e-18) + -5.6279647174733e-17);
	fConst101 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-1.15230781522099e-19 - fConst82) + 7.6145143427637e-18) + 6.49541554409002e-17) + -5.6279647174733e-17);
	fConst102 = fConst0 * (fConst0 * (fConst0 * (-1.55758549330311e-19 - fConst76) + 1.87566276642568e-16) + 4.4790878007342e-14) + -1.39618979785748e-14;
	fConst103 = fConst0 * (fConst0 * (fConst0 * (fConst78 + 1.59119959691012e-19) + -1.88800868924521e-16) + -4.49917498791669e-14) + 5.87568239416571e-14;
	fConst104 = fConst1 * (fConst0 * (fConst0 * (-1.02635765875996e-19 - fConst52) + -3.19454127568422e-17) + 2.62717307381708e-15);
	fConst105 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst54 + 1.04700508226387e-19) + 3.20489931550843e-17) + -2.65988017960028e-15) + -7.88151922145125e-15);
	fConst106 = fConst1 * (fConst0 * (fConst0 * (fConst56 + 2.2673537861441e-19) + 7.35486357301917e-17) + -3.92585764869989e-15);
	fConst107 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-2.31612201055921e-19 - fConst58) + -7.37353569889037e-17) + 4.00054450346227e-15) + 1.17775729460997e-14);
	fConst108 = fConst0 * (fConst0 * (fConst0 * (-1.74534751099098e-19 - fConst60) + -1.85568523263077e-17) + 1.66102929456909e-16) + 1.50114464615909e-16;
	fConst109 = fConst0 * (fConst0 * (fConst0 * (fConst62 + 1.78734806481567e-19) + 1.90595008624394e-17) + -1.88638248347695e-16) + -6.52018766806119e-16;
	fConst110 = fConst1 * (fConst0 * (fConst0 * (fConst64 + 7.1203189810368e-20) + 2.32762902199933e-18) + -1.88310920685508e-17);
	fConst111 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (-7.29225942723227e-20 - fConst66) + -2.40711435730575e-18) + 2.16097599157672e-17) + 5.64932762056525e-17);
	fConst112 = fConst1 * (fConst0 * (fConst0 * (-1.68783861150297e-19 - fConst60) + -3.66325429672487e-18) + 2.81398235873665e-17);
	fConst113 = fConst0 * (fConst0 * (fConst0 * (fConst0 * (fConst62 + 1.72846172283149e-19) + 3.80725717138185e-18) + -3.24770777204501e-17) + -8.44194707620995e-17);
	fConst114 = fConst0 * (fConst0 * (fConst0 * (fConst56 + 2.33637823995467e-19) + 9.37831383212842e-17) + -2.2395439003671e-14) + -2.09428469678622e-14;
	fConst115 = fConst0 * (fConst0 * (fConst0 * (-2.38679939536519e-19 - fConst58) + -9.44004344622607e-17) + 2.24958749395835e-14) + 8.81352359124856e-14;
	double fConst116 = 5.63260410005403e-18 * fConst0;
	fConst117 = fConst23 * (fConst116 + -1.56079959618215e-14);
	double fConst118 = 8.10186558575176e-18 * fConst0;
	fConst119 = fConst1 * (fConst0 * (2.24522189930002e-14 - fConst118) + 1.56079959618215e-14);
	double fConst120 = 1.39509532014583e-20 * fConst0;
	fConst121 = fConst28 * (4.18792249852688e-17 - fConst120);
	double fConst122 = 2.00668723779547e-20 * fConst0;
	fConst123 = fConst23 * (fConst0 * (fConst122 + -6.02469113319311e-17) + 1.39597416617563e-17);
	double fConst124 = 1.15831802585137e-20 * fConst0;
	fConst125 = fConst28 * (fConst124 + -3.47714313915491e-17);
	double fConst126 = 1.66797795722607e-20 * fConst0;
	fConst127 = fConst23 * (fConst0 * (5.00778111119886e-17 - fConst126) + -1.15904771305164e-17);
	double fConst128 = 4.67663160169938e-18 * fConst0;
	fConst129 = fConst23 * (1.29589876827223e-14 - fConst128);
	double fConst130 = 6.7343495064475e-18 * fConst0;
	fConst131 = fConst1 * (fConst0 * (fConst130 + -1.86625011403217e-14) + -1.29589876827223e-14);
	double fConst132 = 3.75506940003602e-18 * fConst0;
	fConst133 = fConst23 * (-3.12159919236431e-14 - fConst132);
	double fConst134 = 5.40124372383451e-18 * fConst0;
	fConst135 = fConst1 * (fConst0 * (fConst134 + 4.49044379860004e-14) + -3.12159919236431e-14);
	double fConst136 = 2.79019064029167e-20 * fConst0;
	fConst137 = fConst28 * (fConst136 + -2.79194833235126e-17);
	double fConst138 = 4.01337447559094e-20 * fConst0;
	fConst139 = fConst23 * (fConst0 * (4.01646075546207e-17 - fConst138) + 2.79194833235126e-17);
	double fConst140 = 2.31663605170274e-20 * fConst0;
	fConst141 = fConst28 * (2.31809542610327e-17 - fConst140);
	double fConst142 = 3.33595591445214e-20 * fConst0;
	fConst143 = fConst23 * (fConst0 * (fConst142 + -3.33852074079924e-17) + -2.31809542610327e-17);
	double fConst144 = 3.11775440113292e-18 * fConst0;
	fConst145 = fConst23 * (fConst144 + 2.59179753654445e-14);
	double fConst146 = 4.48956633763166e-18 * fConst0;
	fConst147 = fConst1 * (fConst0 * (-3.73250022806433e-14 - fConst146) + 2.59179753654445e-14);
	fConst148 = fConst23 * (3.12159919236431e-14 - fConst132);
	fConst149 = fConst1 * (fConst0 * (fConst134 + -4.49044379860004e-14) + -3.12159919236431e-14);
	fConst150 = fConst28 * (-2.79194833235126e-17 - fConst136);
	fConst151 = fConst23 * (fConst0 * (fConst138 + 4.01646075546207e-17) + -2.79194833235126e-17);
	fConst152 = fConst28 * (fConst140 + 2.31809542610327e-17);
	fConst153 = fConst23 * (fConst0 * (-3.33852074079924e-17 - fConst142) + 2.31809542610327e-17);
	fConst154 = fConst23 * (fConst144 + -2.59179753654445e-14);
	fConst155 = fConst1 * (fConst0 * (3.73250022806433e-14 - fConst146) + 2.59179753654445e-14);
	fConst156 = fConst23 * (fConst116 + 1.56079959618215e-14);
	fConst157 = fConst1 * (fConst0 * (-2.24522189930002e-14 - fConst118) + 1.56079959618215e-14);
	fConst158 = fConst28 * (fConst120 + 4.18792249852688e-17);
	fConst159 = fConst23 * (fConst0 * (-6.02469113319311e-17 - fConst122) + -1.39597416617563e-17);
	fConst160 = fConst28 * (-3.47714313915491e-17 - fConst124);
	fConst161 = fConst23 * (fConst0 * (fConst126 + 5.00778111119886e-17) + 1.15904771305164e-17);
	fConst162 = fConst23 * (-1.29589876827223e-14 - fConst128);
	fConst163 = fConst1 * (fConst0 * (fConst130 + 1.86625011403217e-14) + -1.29589876827223e-14);
	fConst164 = fConst23 * (-1.56079959618215e-14 - fConst22);
	fConst165 = fConst1 * (fConst0 * (fConst25 + 2.24522189930002e-14) + 1.56079959618215e-14);
	fConst166 = fConst28 * (-1.39597416617563e-17 - fConst27);
	fConst167 = fConst23 * (fConst0 * (fConst30 + 2.00823037773104e-17) + 1.39597416617563e-17);
	fConst168 = fConst28 * (fConst32 + 1.15904771305164e-17);
	fConst169 = fConst23 * (fConst0 * (-1.66926037039962e-17 - fConst34) + -1.15904771305164e-17);
	fConst170 = fConst23 * (fConst36 + 1.29589876827223e-14);
	fConst171 = fConst1 * (fConst0 * (-1.86625011403217e-14 - fConst38) + -1.29589876827223e-14);
	clear_state_f();
}

void Dsp::init_static(unsigned int sample_rate, PluginDef *p)
{
	static_cast<Dsp*>(p)->init(sample_rate);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
	double 	fSlowdw0 = (0.01 * fsliderdw0);
	double 	fSlowdw1 = (1 - fSlowdw0);
	FAUSTFLOAT 	dryinput[count];
	memcpy(&dryinput, input0, count * sizeof(float));

	double fSlow0 = 0.007000000000000006 * double(fVslider0);
	double fSlow1 = 0.007000000000000006 * double(fVslider1);
	double fSlow2 = 0.007000000000000006 * double(fVslider2);
	double fSlow3 = 0.0003500000000000003 * (double(fVslider3) + 0.01);
	for (int i0 = 0; i0 < count; i0 = i0 + 1) {
		fRec0[0] = fSlow0 + 0.993 * fRec0[1];
		fRec1[0] = fSlow1 + 0.993 * fRec1[1];
		fRec2[0] = fSlow2 + 0.993 * fRec2[1];
		double fTemp0 = fConst0 * (fConst21 + fConst20 * fRec0[0]) + fRec2[0] * (fRec1[0] * (fConst19 + fConst18 * fRec0[0] + fRec1[0] * (fConst17 + fConst15 * fRec0[0])) + fConst0 * (fConst13 + fConst11 * fRec0[0]) + -5.00381548719697e-17) + fRec1[0] * (fConst9 + fConst7 * fRec0[0] + fRec1[0] * (fConst5 + fConst3 * fRec0[0])) + 6.9809489892874e-15;
		fRec3[0] = double(input0[i0]) - (fRec3[1] * (fConst0 * (fConst115 + fConst114 * fRec0[0]) + fRec2[0] * (fRec1[0] * (fConst113 + fConst112 * fRec0[0] + fRec1[0] * (fConst111 + fConst110 * fRec0[0])) + fConst0 * (fConst109 + fConst108 * fRec0[0]) + -2.50190774359849e-16) + fRec1[0] * (fConst107 + fConst106 * fRec0[0] + fRec1[0] * (fConst105 + fConst104 * fRec0[0])) + 3.4904744946437e-14) + fRec3[2] * (fConst0 * (fConst103 + fConst102 * fRec0[0]) + fRec2[0] * (fRec1[0] * (fConst101 + fConst100 * fRec0[0] + fRec1[0] * (fConst99 + fConst98 * fRec0[0])) + fConst0 * (fConst97 + fConst96 * fRec0[0]) + -5.00381548719697e-16) + fRec1[0] * (fConst95 + fConst94 * fRec0[0] + fRec1[0] * (fConst93 + fConst92 * fRec0[0])) + 6.9809489892874e-14) + fRec3[3] * (fConst0 * (fConst91 + fConst90 * fRec0[0]) + fRec2[0] * (fRec1[0] * (fConst89 + fConst88 * fRec0[0] + fRec1[0] * (fConst87 + fConst85 * fRec0[0])) + fConst0 * (fConst83 + fConst81 * fRec0[0]) + -5.00381548719697e-16) + fRec1[0] * (fConst79 + fConst77 * fRec0[0] + fRec1[0] * (fConst75 + fConst73 * fRec0[0])) + 6.9809489892874e-14) + fRec3[4] * (fConst0 * (fConst71 + fConst70 * fRec0[0]) + fRec2[0] * (fRec1[0] * (fConst69 + fConst68 * fRec0[0] + fRec1[0] * (fConst67 + fConst65 * fRec0[0])) + fConst0 * (fConst63 + fConst61 * fRec0[0]) + -2.50190774359849e-16) + fRec1[0] * (fConst59 + fConst57 * fRec0[0] + fRec1[0] * (fConst55 + fConst53 * fRec0[0])) + 3.4904744946437e-14) + fRec3[5] * (fConst0 * (fConst51 + fConst50 * fRec0[0]) + fRec2[0] * (fRec1[0] * (fConst49 + fConst48 * fRec0[0] + fRec1[0] * (fConst47 + fConst46 * fRec0[0])) + fConst0 * (fConst45 + fConst44 * fRec0[0]) + -5.00381548719697e-17) + fRec1[0] * (fConst43 + fConst42 * fRec0[0] + fRec1[0] * (fConst41 + fConst40 * fRec0[0])) + 6.9809489892874e-15)) / fTemp0;
		fRec4[0] = fSlow3 + 0.993 * fRec4[1];
		output0[i0] = FAUSTFLOAT(0.3183098861837907 * std::atan(fRec4[0] * (fRec3[0] * (fRec2[0] * (fConst171 + fConst170 * fRec0[0] + fRec1[0] * (fConst169 + fConst168 * fRec0[0])) + fRec1[0] * (fConst167 + fConst166 * fRec0[0]) + fConst165 + fConst164 * fRec0[0]) + fRec3[1] * (fRec2[0] * (fConst163 + fConst162 * fRec0[0] + fRec1[0] * (fConst161 + fConst160 * fRec0[0])) + fRec1[0] * (fConst159 + fConst158 * fRec0[0]) + fConst157 + fConst156 * fRec0[0]) + fRec3[2] * (fRec2[0] * (fConst155 + fConst154 * fRec0[0] + fRec1[0] * (fConst153 + fConst152 * fRec0[0])) + fRec1[0] * (fConst151 + fConst150 * fRec0[0]) + fConst149 + fConst148 * fRec0[0]) + fRec3[3] * (fRec2[0] * (fConst147 + fConst145 * fRec0[0] + fRec1[0] * (fConst143 + fConst141 * fRec0[0])) + fRec1[0] * (fConst139 + fConst137 * fRec0[0]) + fConst135 + fConst133 * fRec0[0]) + fRec3[4] * (fRec2[0] * (fConst131 + fConst129 * fRec0[0] + fRec1[0] * (fConst127 + fConst125 * fRec0[0])) + fRec1[0] * (fConst123 + fConst121 * fRec0[0]) + fConst119 + fConst117 * fRec0[0]) + fRec3[5] * (fRec2[0] * (fConst39 + fConst37 * fRec0[0] + fRec1[0] * (fConst35 + fConst33 * fRec0[0])) + fRec1[0] * (fConst31 + fConst29 * fRec0[0]) + fConst26 + fConst24 * fRec0[0])) / fTemp0));
		fRec0[1] = fRec0[0];
		fRec1[1] = fRec1[0];
		fRec2[1] = fRec2[0];
		for (int j0 = 5; j0 > 0; j0 = j0 - 1) {
			fRec3[j0] = fRec3[j0 - 1];
		}
		fRec4[1] = fRec4[0];
	}
	for (int i=0; i<count; i++) {
		output0[i] = ((fSlowdw1 * (double)dryinput[i]) + (fSlowdw0 * (double)output0[i]));
	}

}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}

int Dsp::register_par(const ParamReg& reg)
{
	reg.registerFloatVar("ffreak.wet_dry",N_("Dry/Wet"),"S",N_("percentage of processed signal in output signal"),&fsliderdw0, 1e+02, 0.0, 1e+02, 1.0, 0);
	reg.registerFloatVar("ffreak.Fuzz",N_("Fuzz"),"S","",&fVslider0, 0.5, 0.0, 1.0, 0.01, 0);
	reg.registerFloatVar("ffreak.Gate",N_("Gate"),"S","",&fVslider2, 0.5, 0.0, 1.0, 0.01, 0);
	reg.registerFloatVar("ffreak.Level",N_("Level"),"S","",&fVslider3, 0.5, 0.0, 1.0, 0.01, 0);
	reg.registerFloatVar("ffreak.Tone",N_("Tone"),"S","",&fVslider1, 0.5, 0.0, 1.0, 0.01, 0);
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
              <object class=\"GtkBox\" id=\"hbox1\">\n\
                <property name=\"visible\">True</property>\n\
                <property name=\"can_focus\">False</property>\n\
                <property name=\"spacing\">10</property>\n\
                <child>\n\
                  <object class=\"GtkBox\" id=\"vbox2\">\n\
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
                        <property name=\"var_id\">ffreak.Gate</property>\n\
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
                  <object class=\"GtkBox\" id=\"vbox3\">\n\
                    <property name=\"visible\">True</property>\n\
                    <property name=\"can_focus\">False</property>\n\
                    <property name=\"orientation\">vertical</property>\n\
                    <child>\n\
                      <object class=\"GtkLabel\" id=\"label2:rack_label\">\n\
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
                      <object class=\"GxSmallKnobR\" id=\"gxbigknob2\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">True</property>\n\
                        <property name=\"receives_default\">True</property>\n\
                        <property name=\"var_id\">ffreak.Fuzz</property>\n\
                        <property name=\"label_ref\">label2:rack_label</property>\n\
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
                  <object class=\"GtkBox\" id=\"vbox4\">\n\
                    <property name=\"visible\">True</property>\n\
                    <property name=\"can_focus\">False</property>\n\
                    <property name=\"orientation\">vertical</property>\n\
                    <child>\n\
                      <object class=\"GtkLabel\" id=\"label3:rack_label\">\n\
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
                      <object class=\"GxSmallKnobR\" id=\"gxbigknob3\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">True</property>\n\
                        <property name=\"receives_default\">True</property>\n\
                        <property name=\"var_id\">ffreak.Tone</property>\n\
                        <property name=\"label_ref\">label3:rack_label</property>\n\
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
                  <object class=\"GtkBox\" id=\"vbox5\">\n\
                    <property name=\"visible\">True</property>\n\
                    <property name=\"can_focus\">False</property>\n\
                    <property name=\"orientation\">vertical</property>\n\
                    <child>\n\
                      <object class=\"GtkLabel\" id=\"label4:rack_label\">\n\
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
                      <object class=\"GxMidKnob\" id=\"gxbigknob4\">\n\
                        <property name=\"visible\">True</property>\n\
                        <property name=\"can_focus\">True</property>\n\
                        <property name=\"receives_default\">True</property>\n\
                        <property name=\"var_id\">ffreak.Level</property>\n\
                        <property name=\"label_ref\">label4:rack_label</property>\n\
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
                <child>\n\
                  <object class=\"GtkBox\" id=\"vbox6\">\n\
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
                        <property name=\"var_id\">ffreak.wet_dry</property>\n\
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
                    <property name=\"position\">4</property>\n\
                  </packing>\n\
                </child>\n\
              </object>\n\
              <packing>\n\
                <property name=\"expand\">True</property>\n\
                <property name=\"fill\">False</property>\n\
                <property name=\"pack_type\">end</property>\n\
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
                <property name=\"var_id\">ffreak.Level</property>\n\
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
                <property name=\"label\" translatable=\"yes\">Level</property>\n\
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
#define PARAM(p) ("ffreak" "." p)

b.openHorizontalhideBox("");
    b.create_master_slider(PARAM("Fuzz"), "Fuzz");
b.closeBox();
b.openHorizontalBox("");

    b.create_small_rackknobr(PARAM("Fuzz"), "Fuzz");

    b.create_small_rackknobr(PARAM("Tone"), "Tone");

    b.create_small_rackknobr(PARAM("Gate"), "Gate");

    b.create_small_rackknobr(PARAM("Level"), "Level");
    b.create_small_rackknobr(PARAM("wet_dry"), "dry/wet");
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

} // end namespace ffreak
} // end namespace pluginlib
