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
  int _fractionalDigitsNumber;

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
    String units = "",
    int fractionalDigitsNumber = 0
    ) : StatefulParameter(setterFunction, isCyclic, units)
  {
    _value = initialValue;
    _limitTop = limitTop;
    _limitBottom = limitBottom;
    _step = step;
    _stepAdaptiveness = stepAdaptiveness;
    _fractionalDigitsNumber = fractionalDigitsNumber;
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
    String numericalResult = String(_value/(pow(10, _fractionalDigitsNumber)));
    if (_fractionalDigitsNumber < 2) {
      numericalResult.remove(numericalResult.length() - 1);
      if (_fractionalDigitsNumber < 1) {
        numericalResult.remove(numericalResult.length() - 2, 2);
      }
    }

    return numericalResult + _units;
  }

};

#endif  //RangeParameter_h_