#ifndef TestAudioSystem_h_
#define TestAudioSystem_h_

#include <AudioSystem.h>
#include <TestMusicNode.h>


/*enum class ParameterTag : int {
  PARAM_WF1_AMP,
  PARAM_WF2_AMP,
  PARAM_PINK_AMP
};*/

class TestAudioSystem : public AudioSystem
{
private:
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
  AudioControlSGTL5000     sgtl5000_1;     //xy=1218,356
  // GUItool: end automatically generated code

  const int SCALE[8] = {0, 2, 4, 5, 7, 9, 11, 12};
  const int KEY_NOTE = 20;
  const int KEY_STEP = 7;
  void setupWaveforms();
  void setupMixers();
  void setupSGTL5000();
  void setupConnections();
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