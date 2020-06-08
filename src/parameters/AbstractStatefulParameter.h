#ifndef AbstractStatefulParameter_h_
#define AbstractStatefulParameter_h_

#include <parameters/AbstractParameter.h>
#include <WString.h>

class AbstractStatefulParameter : public AbstractParameter
{
public:
  AbstractStatefulParameter() : AbstractParameter() {};
  virtual void apply() {};
  virtual void increase() {};
  virtual void decrease() {};
  virtual String getValueString() {return "";};
  virtual int getValue() {return 0;};
};

#endif  //AbstractStatefulParameter_h_