#ifndef AbstractParameter_h_
#define AbstractParameter_h_

#include <menus/MenuItem.h>

class AbstractParameter : public MenuItem
{
protected:
  int _value,
      _limitTop,
      _limitBottom,
      _step;
  float _multiplier;
  String _units = "%";

public:
  AbstractParameter(String* name) : MenuItem(name) {
    _isMenu = false;
  };

  virtual void increase() {
    _value += _step;
    if (_value > _limitTop) _value = _limitTop;
  };

  virtual void decrease() {
    _value -= _step;
    if (_value < _limitBottom) _value = _limitBottom;
  };

  int getValue() {
    return _value;
  };
  
};

#endif //AbstractParameter_h_