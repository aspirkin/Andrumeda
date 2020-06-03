#ifndef CyclicParameter_h_
#define CyclicParameter_h_

#include <parameters/IntegerParameter.h>
#include <WString.h>

class CyclicParameter : public IntegerParameter
{
public:
  CyclicParameter(intSetterFunction setterFunction, int range, int initialValue) :
  IntegerParameter(setterFunction, 0, initialValue, range) {
  };

  void increase() {
    _value += _step;
    if (_value > _limitTop) _value = _limitBottom;
  };

  void decrease() {
    _value -= _step;
    if (_value < _limitBottom) _value = _limitTop;
  };
  
};

#endif  //CyclicParameter_h_