#ifndef IntegerParameter_h_
#define IntegerParameter_h_

#include <parameters/StatefulParameter.h>
#include <WString.h>
#include <functional>

typedef std::function<void(int)> intSetterFunction;

class IntegerParameter : public StatefulParameter
{
private:
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
  };

  void increase() {
    StatefulParameter::increase();
    _setterFunction(_value);
  };

  void decrease() {
    StatefulParameter::decrease();
    _setterFunction(_value);
  };

};

#endif //IntegerParameter_h_