#ifndef ParamAmplitude_h_
#define ParamAmplitude_h_

#include <AbstractParameter.h>
#include <Audio.h>
#include <TestAudioSystem.h>
#include <functional>

typedef std::function<void(float)> floatSetterFunction;

class ParamAmplitude : public AbstractParameter
{
private:
  TestAudioSystem* _audioSystem;
  floatSetterFunction _setParameterFloatValueFunction;
public:
  ParamAmplitude(String* name, TestAudioSystem* audioSystem, floatSetterFunction setterFunction) : AbstractParameter(name) {
      _value = 50;
      _limitTop = 100;
      _limitBottom = 0;
      _step = 5;
      _multiplier = 0.01;

    _audioSystem = audioSystem;
    _setParameterFloatValueFunction = setterFunction;
  };
  void increase() {
    AbstractParameter::increase();
    _setParameterFloatValueFunction(_value * _multiplier);
  };
  void decrease() {
    AbstractParameter::decrease();
    _setParameterFloatValueFunction(_value * _multiplier);
  };
};

#endif // ParamAmplitude_h_