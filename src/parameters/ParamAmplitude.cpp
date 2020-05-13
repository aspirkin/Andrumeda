#include <parameters\ParamAmplitude.h>

ParamAmplitude::ParamAmplitude(String name, TestAudioSystem* audioSystem, int oscIndex) : Parameter(name) {
  _audioSystem = audioSystem;
  _oscIndex = oscIndex;
}

void ParamAmplitude::increase() {
  Parameter::increase();
  _audioSystem->setAmp(_value * _multiplier, _oscIndex);
}

void ParamAmplitude::decrease() {
  Parameter::decrease();
  _audioSystem->setAmp(_value * _multiplier, _oscIndex);
}
