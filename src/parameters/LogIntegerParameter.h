#ifndef LogIntegerParameter_h_
#define LogIntegerParameter_h_

#include <parameters/IntegerParameter.h>
#include <WString.h>
#include <functional>

typedef std::function<void(int)> intSetterFunction;

class LogIntegerParameter : public IntegerParameter
{
protected:
  intSetterFunction _setterFunction;

public:
  LogIntegerParameter(
    intSetterFunction setterFunction,
    int limitBottom,
    int initialValue,
    int limitTop,
    String units = "")
    : IntegerParameter(setterFunction, limitBottom, initialValue, limitTop, 1, units)
  {
    updateStep();
  }

  void updateStep() {
    _step = (int)(_value * 0.05);
    if (_step < 1) _step = 1;
  }

  virtual void apply() {
    IntegerParameter::apply();
  }

  virtual void increase() {
    IntegerParameter::increase();
    updateStep();
  }

  virtual void decrease() {
    IntegerParameter::decrease();
    updateStep();
  }

};

#endif //LogIntegerParameter_h_