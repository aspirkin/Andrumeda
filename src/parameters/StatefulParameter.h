#ifndef StatefulParameter_h_
#define StatefulParameter_h_

#include <parameters/AbstractParameter.h>
#include <WString.h>
#include <functional>

typedef std::function<void(int)> SetterFunction;

class StatefulParameter : public AbstractParameter
{
protected:
  String _units;
  bool _isCyclic;
  SetterFunction _setterFunction;

  virtual void handleValueOverTop() {};
  virtual void handleValueBelowBottom() {};
  virtual void apply() {};

public:
  StatefulParameter(SetterFunction setterFunction,  bool isCyclic = false, String units = "") : AbstractParameter() {
    _units = units;
    _isCyclic = isCyclic;
    _setterFunction = setterFunction;
  };
  virtual void increase() {};
  virtual void decrease() {};
  virtual String getValueString() {return "";};
};

#endif  //StatefulParameter_h_