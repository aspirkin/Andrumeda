#ifndef AbstractParameter_h_
#define AbstractParameter_h_

class AbstractParameter
{
public:
  AbstractParameter() {};
  virtual void increase() {};
  virtual void decrease() {};
  virtual void apply() {};
};

#endif //AbstractParameter_h_