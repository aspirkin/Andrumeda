#ifndef FloatParameter_h_
#define FloatParameter_h_

#include <parameters/AbstractParameter.h>
#include <Audio.h>
#include <TestAudioSystem.h>
#include <functional>

typedef std::function<void(float)> floatSetterFunction;

class FloatParameter : public AbstractParameter
{
private:
  floatSetterFunction _setParameterFloatValueFunction;
public:
  FloatParameter(String* name, floatSetterFunction setterFunction) : AbstractParameter(name) {
      _value = 50;
      _limitTop = 100;
      _limitBottom = 0;
      _step = 5;
      _multiplier = 0.01;

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

#endif // FloatParameter_h_