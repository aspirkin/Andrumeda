#ifndef FloatParameter_h_
#define FloatParameter_h_

#include <parameters/StatefulParameter.h>
#include <Audio.h>
#include <audio-systems/test/TestAudioSystem.h>
#include <functional>

typedef std::function<void(float)> floatSetterFunction;

class FloatParameter : public StatefulParameter
{
private:
  floatSetterFunction _setterFunction;
  float _multiplier;

public:
  FloatParameter(
    floatSetterFunction setterFunction,
    int limitBottom,
    int initialValue,
    int limitTop,
    float multiplier,
    int step = 1,
    String units = "")
    : StatefulParameter(limitBottom, initialValue, limitTop, step, units)
  {
    _multiplier = multiplier;
    _setterFunction = setterFunction;
  };

  void increase() {
    StatefulParameter::increase();
    _setterFunction(_value * _multiplier);
  };

  void decrease() {
    StatefulParameter::decrease();
    _setterFunction(_value * _multiplier);
  };
};

#endif // FloatParameter_h_