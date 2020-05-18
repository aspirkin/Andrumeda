#ifndef Parameter_h_
#define Parameter_h_

#include <MenuItem.h>

class Parameter : public MenuItem
{
protected:
  int _value = 50;
  int _limitTop = 100;
  int _limitBottom = 0;
  int _step = 5;
  float _multiplier = 0.01;
public:
  Parameter(String* name);
  virtual void increase();
  virtual void decrease();
};

#endif //Parameter_h_