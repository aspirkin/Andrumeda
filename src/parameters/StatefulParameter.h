#ifndef StatefulParameter_h_
#define StatefulParameter_h_

#include <parameters/AbstractStatefulParameter.h>
#include <WString.h>

class StatefulParameter : public AbstractStatefulParameter
{
protected:
  int _value;
  int _limitTop;
  int _limitBottom;
  int _step;
  String _units;

public:
  StatefulParameter(int limitBottom, int initialValue, int limitTop, int step = 1, String units = "") : AbstractStatefulParameter() {
    _value = initialValue;
    _limitBottom = limitBottom;
    _limitTop = limitTop;
    _step = step;
    _units = units;
  };

  virtual void apply() {};
  
  virtual void increase() {
    _value += _step;
    if (_value > _limitTop) _value = _limitTop;
  };

  virtual void decrease() {
    _value -= _step;
    if (_value < _limitBottom) _value = _limitBottom;
  };

  virtual String getValueString() {
    return (String)_value + _units;
  };

  int getValue() {
    return _value;
  }

  void setStep(int step) {
    _step = step;
  }
  
};

#endif  //StatefulParameter_h_