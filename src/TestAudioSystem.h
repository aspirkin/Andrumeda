#ifndef TestAudioSystem_h_
#define TestAudioSystem_h_

#include <AudioSystem.h>
#include <TestMusicNode.h>

// GUItool: begin automatically generated code
AudioSynthNoisePink      pink8; //xy=160,942
AudioSynthNoisePink      pink7; //xy=164,829
AudioSynthNoisePink      pink6; //xy=169,711
AudioSynthWaveform       waveform15; //xy=169,877
AudioSynthWaveform       waveform16; //xy=169,910
AudioSynthNoisePink      pink4; //xy=171,484
AudioSynthNoisePink      pink5; //xy=172,593
AudioSynthWaveform       waveform13; //xy=173,764
AudioSynthWaveform       waveform14; //xy=173,797
AudioSynthNoisePink      pink3; //xy=175,371
AudioSynthWaveform       waveform11; //xy=178,646
AudioSynthWaveform       waveform12; //xy=178,679
AudioSynthNoisePink      pink2; //xy=180,253
AudioSynthWaveform       waveform7; //xy=180,419
AudioSynthWaveform       waveform8; //xy=180,452
AudioSynthWaveform       waveform9; //xy=181,528
AudioSynthWaveform       waveform10; //xy=181,561
AudioSynthNoisePink      pink1;          //xy=183,135
AudioSynthWaveform       waveform5; //xy=184,306
AudioSynthWaveform       waveform6; //xy=184,339
AudioSynthWaveform       waveform3; //xy=189,188
AudioSynthWaveform       waveform4; //xy=189,221
AudioSynthWaveform       waveform1;      //xy=192,70
AudioSynthWaveform       waveform2;      //xy=192,103
AudioMixer4              mixer8; //xy=321,911
AudioMixer4              mixer7; //xy=325,798
AudioMixer4              mixer6; //xy=330,680
AudioMixer4              mixer4; //xy=332,453
AudioMixer4              mixer5; //xy=333,562
AudioMixer4              mixer3; //xy=336,340
AudioMixer4              mixer2; //xy=341,222
AudioMixer4              mixer1;         //xy=344,104
AudioMixer4              mixer10; //xy=577,622
AudioMixer4              mixer9; //xy=587,294
AudioMixer4              mixer11; //xy=811,449
AudioOutputI2S           i2s1;           //xy=1147,206
AudioConnection          patchCord1(pink8, 0, mixer8, 2);
AudioConnection          patchCord2(pink7, 0, mixer7, 2);
AudioConnection          patchCord3(pink6, 0, mixer6, 2);
AudioConnection          patchCord4(waveform15, 0, mixer8, 0);
AudioConnection          patchCord5(waveform16, 0, mixer8, 1);
AudioConnection          patchCord6(pink4, 0, mixer4, 2);
AudioConnection          patchCord7(pink5, 0, mixer5, 2);
AudioConnection          patchCord8(waveform13, 0, mixer7, 0);
AudioConnection          patchCord9(waveform14, 0, mixer7, 1);
AudioConnection          patchCord10(pink3, 0, mixer3, 2);
AudioConnection          patchCord11(waveform11, 0, mixer6, 0);
AudioConnection          patchCord12(waveform12, 0, mixer6, 1);
AudioConnection          patchCord13(pink2, 0, mixer2, 2);
AudioConnection          patchCord14(waveform7, 0, mixer4, 0);
AudioConnection          patchCord15(waveform8, 0, mixer4, 1);
AudioConnection          patchCord16(waveform9, 0, mixer5, 0);
AudioConnection          patchCord17(waveform10, 0, mixer5, 1);
AudioConnection          patchCord18(pink1, 0, mixer1, 2);
AudioConnection          patchCord19(waveform5, 0, mixer3, 0);
AudioConnection          patchCord20(waveform6, 0, mixer3, 1);
AudioConnection          patchCord21(waveform3, 0, mixer2, 0);
AudioConnection          patchCord22(waveform4, 0, mixer2, 1);
AudioConnection          patchCord23(waveform1, 0, mixer1, 0);
AudioConnection          patchCord24(waveform2, 0, mixer1, 1);
AudioConnection          patchCord25(mixer8, 0, mixer10, 3);
AudioConnection          patchCord26(mixer7, 0, mixer10, 2);
AudioConnection          patchCord27(mixer6, 0, mixer10, 1);
AudioConnection          patchCord28(mixer4, 0, mixer9, 3);
AudioConnection          patchCord29(mixer5, 0, mixer10, 0);
AudioConnection          patchCord30(mixer3, 0, mixer9, 2);
AudioConnection          patchCord31(mixer2, 0, mixer9, 1);
AudioConnection          patchCord32(mixer1, 0, mixer9, 0);
AudioConnection          patchCord33(mixer10, 0, mixer11, 1);
AudioConnection          patchCord34(mixer9, 0, mixer11, 0);
AudioConnection          patchCord35(mixer11, 0, i2s1, 0);
AudioConnection          patchCord36(mixer11, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1218,356
// GUItool: end automatically generated code

enum class ParameterTag : int {
  PARAM_WF1_AMP,
  PARAM_WF2_AMP,
  PARAM_PINK_AMP
};

class TestAudioSystem : public AudioSystem
{
private:
  const int SCALE[8] = {0, 2, 4, 5, 7, 9, 11, 12};
  const int KEY_NOTE = 20;
  const int KEY_STEP = 7;
  void setupWaveforms();
  void setupMixers();
  void setupSGTL5000();
public:
  TestAudioSystem();
  void activateSampler();
  void activateSynth();

  //void setAmp(float value, int index);
  void setWf1Amplitude(float value);
  void setWf2Amplitude(float value);
  void setPinkAmplitude(float value);
};

#endif //TestAudioSystem_h_