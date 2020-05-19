#include <parameters\ParamAmplitude.h>

ParamAmplitude::ParamAmplitude(String* name, TestAudioSystem * audioSystem, floatSetterFunction setterFunction) : Parameter(name) {
  _audioSystem = audioSystem;
  setParameterFloatValueFunction = setterFunction;
}

void ParamAmplitude::increase() {
  Parameter::increase();
  setParameterFloatValueFunction(_value * _multiplier);
  Serial.println(_value);
}

void ParamAmplitude::decrease() {
  Parameter::decrease();
  setParameterFloatValueFunction(_value * _multiplier);
}
