#include <parameters\ParamAmplitude.h>

ParamAmplitude::ParamAmplitude(String* name, TestAudioSystem * audioSystem, void (TestAudioSystem::* setValueFunction)(float)) : Parameter(name) {
  _audioSystem = audioSystem;
  void (TestAudioSystem::*setValueFunctionPtr)(float) { setValueFunction };
}

void ParamAmplitude::increase() {
  Parameter::increase();
  ((*_audioSystem).*setValueFunctionPtr)(_value * _multiplier);
}

void ParamAmplitude::decrease() {
  Parameter::decrease();
  ((*_audioSystem).*setValueFunctionPtr)(_value * _multiplier);
}
