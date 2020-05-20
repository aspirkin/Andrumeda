#ifndef AbstractParameter_h_
#define AbstractParameter_h_

#include <MenuItem.h>

class AbstractParameter : public MenuItem
{
protected:
  int _value,
      _limitTop,
      _limitBottom,
      _step;
  float _multiplier;
  
public:
  AbstractParameter(String* name) : MenuItem(name) {

  };
  virtual void increase() {
    _value += _step;
    if (_value > _limitTop) _value = _limitTop;
  };
  virtual void decrease() {
    _value -= _step;
    if (_value < _limitBottom) _value = _limitBottom;
  };
};

#endif //AbstractParameter_h_