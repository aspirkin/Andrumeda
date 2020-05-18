#include <Parameter.h>

Parameter::Parameter(String* name) : MenuItem(name) {

}

void Parameter::increase() {
  _value += _step;
  if (_value > _limitTop) _value = _limitTop;
}

void Parameter::decrease() {
  _value -= _step;
  if (_value < _limitBottom) _value = _limitBottom;
}
