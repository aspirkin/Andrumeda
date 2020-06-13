#ifndef RangeParameter_h_
#define RangeParameter_h_

#include <parameters/StatefulParameter.h>
#include <WString.h>
#include <functional>

typedef std::function<void(int)> SetterFunction;

class RangeParameter : public StatefulParameter
{
protected:
  int _value;
  int _limitTop;
  int _limitBottom;
  int _step;
  float _stepAdaptiveness;

  void handleValueOverTop() {
    if (_isCyclic) _value = _limitBottom; else _value = _limitTop;
  }

  void handleValueBelowBottom() {
    if (_isCyclic) _value = _limitTop; else _value = _limitBottom;
  }

  void apply() {
    _setterFunction(_value);
  }

  void updateStep() {
    if (_stepAdaptiveness > 0.00) {
      _step = int(_value * _stepAdaptiveness);
      if (_step < 1) _step = 1;
    }
  }

public:
  RangeParameter(
    SetterFunction setterFunction,
    int limitBottom,
    int initialValue,
    int limitTop,
    int step = 1,
    float stepAdaptiveness = 0.00, 
    bool isCyclic = false,
    String units = ""
    ) : StatefulParameter(setterFunction, isCyclic, units)
  {
    _value = initialValue;
    _limitTop = limitTop;
    _limitBottom = limitBottom;
    _step = step;
    _stepAdaptiveness = stepAdaptiveness;
    apply();
  }

  void increase() {
    updateStep();
    _value += _step;
    if (_value > _limitTop) handleValueOverTop();
    apply();
  }

  void decrease() {
    updateStep();
    _value -= _step;
    if (_value < _limitBottom) handleValueBelowBottom();
    apply();
  }

  String getValueString() {
    return String(_value) + _units;
  }

};

#endif  //RangeParameter_h_