#ifndef TestAudioSystem_h_
#define TestAudioSystem_h_

#include <AudioSystem.h>
#include <TestMusicNode.h>

class TestAudioSystem : public AudioSystem
{
private:
  /* data */
public:
  TestAudioSystem(Controls* ptrControls);
  void activateSampler();
  void activateSynth();

  void setAmp(float value, int index);
};

#endif //TestAudioSystem_h_