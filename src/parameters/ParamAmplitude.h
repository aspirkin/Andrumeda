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
  void (TestAudioSystem::* setValueFunctionPtr)(float);
public:
  ParamAmplitude(String* name, TestAudioSystem* audioSystem, void (TestAudioSystem::* setValueFunction)(float));
  void increase();
  void decrease();
};

#endif // ParamAmplitude_h_