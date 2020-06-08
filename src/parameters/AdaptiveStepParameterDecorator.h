#ifndef AdaptiveStepParameterDecorator_h_
#define AdaptiveStepParameterDecorator_h_

#include <parameters/StatefulParameter.h>
#include <parameters/AbstractStatefulParameter.h>

class AdaptiveStepParameterDecorator : public AbstractStatefulParameter
{
protected:
  StatefulParameter* _nestedParameter;
  float _stepMultiplier;
  int _minStep;

  void updateStep() {
    int step = (int)(_nestedParameter->getValue() * _stepMultiplier);
    if (step < _minStep) step = _minStep;
    _nestedParameter->setStep(step);
  }

public:
  AdaptiveStepParameterDecorator(StatefulParameter* nestedParameter, float stepMultiplier, int minStep = 1) : AbstractStatefulParameter()
  {
    _nestedParameter = nestedParameter;
    _stepMultiplier = stepMultiplier;
    _minStep = minStep;
    updateStep();
  }

  virtual void apply() {
    updateStep();
    _nestedParameter->apply();
  }

  virtual void increase() {
    updateStep();
    _nestedParameter->increase();
  }

  virtual void decrease() {
    updateStep();
    _nestedParameter->decrease();
  }

  virtual String getValueString() {
    return _nestedParameter->getValueString();
  }

  virtual int getValue() {
    return _nestedParameter->getValue();
  }
};

#endif //AdaptiveStepParameterDecorator_h_