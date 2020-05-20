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

  void setWaveform1Amplitude(float value);
  void setWaveform2Amplitude(float value);
  void setPinkNoiseAmplitude(float value);
};

#endif //TestAudioSystem_h_