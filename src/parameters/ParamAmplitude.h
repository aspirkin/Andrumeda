#ifndef ParamAmplitude_h_
#define ParamAmplitude_h_

#include <Parameter.h>
#include <Audio.h>
#include <TestAudioSystem.h>

class ParamAmplitude : public Parameter
{
private:
  TestAudioSystem* _audioSystem;
  int _oscIndex;
public:
  ParamAmplitude(String name, TestAudioSystem* audioSystem, int oscIndex);
  void increase();
  void decrease();
};

#endif // ParamAmplitude_h_