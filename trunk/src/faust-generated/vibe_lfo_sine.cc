// generated from file '../src/faust/vibe_lfo_sine.dsp' by dsp2cc:
// Code generated with Faust (https://faust.grame.fr)

namespace vibe_lfo_sine {
static int iVec0[2];
FAUSTFLOAT fVslider0;
FAUSTFLOAT	*fVslider0_;
static double fConst0;
static double fRec0[2];
static double fRec1[2];
FAUSTFLOAT fVslider1;
FAUSTFLOAT	*fVslider1_;
static int	fSampleRate;

static void clear_state_f(PluginDef* = 0)
{
	for (int l0 = 0; l0 < 2; l0 = l0 + 1) iVec0[l0] = 0;
	for (int l1 = 0; l1 < 2; l1 = l1 + 1) fRec0[l1] = 0.0;
	for (int l2 = 0; l2 < 2; l2 = l2 + 1) fRec1[l2] = 0.0;
}

static void init(unsigned int sample_rate, PluginDef* = 0)
{
	fSampleRate = sample_rate;
	fConst0 = 100.53096491487338 / std::min<double>(1.92e+05, std::max<double>(1.0, double(fSampleRate)));
	clear_state_f();
}

void compute(int count, FAUSTFLOAT *output0, FAUSTFLOAT *output1)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
	double fSlow0 = fConst0 * double(fVslider0);
	double fSlow1 = std::cos(fSlow0);
	double fSlow2 = std::sin(fSlow0);
	double fSlow3 = 6.283185307179586 * double(fVslider1);
	double fSlow4 = std::sin(fSlow3);
	double fSlow5 = std::cos(fSlow3);
	for (int i0 = 0; i0 < count; i0 = i0 + 1) {
		iVec0[0] = 1;
		fRec0[0] = fSlow2 * fRec1[1] + fSlow1 * fRec0[1];
		fRec1[0] = double(1 - iVec0[1]) + fSlow1 * fRec1[1] - fSlow2 * fRec0[1];
		output0[i0] = FAUSTFLOAT(0.5 * (fRec0[0] + 1.0));
		output1[i0] = FAUSTFLOAT(0.5 * (fSlow5 * fRec0[0] + fSlow4 * fRec1[0] + 1.0));
		iVec0[1] = iVec0[0];
		fRec0[1] = fRec0[0];
		fRec1[1] = fRec1[0];
	}
#undef fVslider0
#undef fVslider1
}

static int register_params(const ParamReg& reg)
{
	fVslider0_ = reg.registerFloatVar("univibe.freq",N_("Tempo"),"SA",N_("LFO frequency (Hz)"),&fVslider0, 4.4, 0.1, 1e+01, 0.1, 0);
	fVslider1_ = reg.registerFloatVar("univibe.stereo",N_("Phase"),"SA",N_("LFO phase shift between left and right channels"),&fVslider1, 0.11, -0.5, 0.5, 0.01, 0);
	return 0;
}

} // end namespace vibe_lfo_sine
