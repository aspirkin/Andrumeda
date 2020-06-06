#ifndef IntegerParameter_h_
#define IntegerParameter_h_

#include <parameters/StatefulParameter.h>
#include <WString.h>
#include <functional>

typedef std::function<void(int)> intSetterFunction;

class IntegerParameter : public StatefulParameter
{
protected:
  intSetterFunction _setterFunction;

public:
  IntegerParameter(
    intSetterFunction setterFunction,
    int limitBottom,
    int initialValue,
    int limitTop,
    int step = 1,
    String units = "")
    : StatefulParameter(limitBottom, initialValue, limitTop, step, units)
  {
    _setterFunction = setterFunction;
    apply();
  }

  virtual void apply() {
    _setterFunction(_value);
  }

  virtual void increase() {
    StatefulParameter::increase();
    apply();
  }

  virtual void decrease() {
    StatefulParameter::decrease();
    apply();
  }

};

#endif //IntegerParameter_h_