#ifndef StatelessParameter_h_
#define StatelessParameter_h_

#include <parameters/AbstractParameter.h>
#include <functional>

typedef std::function<void()> activationFunction;

class StatelessParameter : public AbstractParameter
{
private:
  activationFunction _increaseFunction;
  activationFunction _decreaseFunction;
public:
  StatelessParameter(activationFunction increaseFunction, activationFunction decreaseFunction) : AbstractParameter(new String()) {
    _increaseFunction = increaseFunction;
    _decreaseFunction = decreaseFunction;
  };
  void increase() {
    _increaseFunction();
  };
  void decrease() {
    _decreaseFunction();
  };
};

#endif  //StatelessParameter_h_