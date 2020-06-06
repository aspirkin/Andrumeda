#ifndef CyclicParameter_h_
#define CyclicParameter_h_

#include <parameters/IntegerParameter.h>
#include <WString.h>
#include <vector>

class CyclicParameter : public IntegerParameter
{
private:
  std::vector<String> _valueNames;

public:
  CyclicParameter(intSetterFunction setterFunction, int range, std::vector<String> valueNames, int initialValue = 0) :
  IntegerParameter(setterFunction, 0, initialValue, range - 1) {
    _valueNames = valueNames;
    apply();
  }

  void apply() {
    _setterFunction(_value);
  }

  void increase() {
    _value += _step;
    if (_value > _limitTop) _value = _limitBottom;
    apply();
  }

  void decrease() {
    _value -= _step;
    if (_value < _limitBottom) _value = _limitTop;
    apply();
  }
  
  virtual String getValueString() {
    return _valueNames[_value];
  }
};

#endif  //CyclicParameter_h_