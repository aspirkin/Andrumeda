#ifndef VectorParameter_h_
#define VectorParameter_h_

#include <parameters/StatefulParameter.h>
#include <WString.h>
#include <functional>
#include <vector>

typedef std::function<void(int)> SetterFunction;

class VectorParameter : public StatefulParameter
{
protected:
  std::vector<String> _names;
  int _value;

  void handleValueOverTop() {
    if (_isCyclic) _value = 0; else _value = _names.size() - 1;
  }

  void handleValueBelowBottom() {
    if (_isCyclic) _value = _names.size() - 1; else _value = 0;
  }

  void apply() {
    _setterFunction(_value);
  }

public:
  VectorParameter(
    SetterFunction setterFunction,
    std::vector<String> names,
    int initialValue = 0,
    bool isCyclic = false,
    String units = ""
    ) : StatefulParameter(setterFunction, isCyclic, units)
  {
    _names = names;
    _value = initialValue;
    apply();
  }

  void increase() {
    _value++;
    if (_value >= int(_names.size())) handleValueOverTop();
    apply();
  }

  void decrease() {
    _value--;
    if (_value < 0) handleValueBelowBottom();
    apply();
  }

  String getValueString() {
    return String(_names[_value]) + _units;
  }

};

#endif  //VectorParameter_h_