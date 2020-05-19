#ifndef ParamAmplitude_h_
#define ParamAmplitude_h_

#include <Parameter.h>
#include <Audio.h>
#include <TestAudioSystem.h>
#include <functional>

typedef std::function<void(float)> floatSetterFunction;

class ParamAmplitude : public Parameter
{
private:
  TestAudioSystem* _audioSystem;
  floatSetterFunction setParameterFloatValueFunction;
public:
  ParamAmplitude(String* name, TestAudioSystem* audioSystem, floatSetterFunction setterFunction);
  void increase();
  void decrease();
};

#endif // ParamAmplitude_h_