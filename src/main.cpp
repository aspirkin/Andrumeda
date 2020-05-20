#include <Arduino.h>
#include <TestAudioSystem.h>
#include <Controls.h>
#include <parameters/ParamAmplitude.h>
#include <Menu.h>
#include <functional>
#include <MenuHandler.h>

Controls* _ptrControls;
TestAudioSystem* _ptrAudioSystem;

//typedef std::function<void(float)> floatSetterFunction;

void setup() {
  Serial.begin(115200);

  //  TODO: insert actual number of nodes here
  _ptrControls = new Controls(8);
  _ptrAudioSystem = new TestAudioSystem();

  ParamAmplitude* waveform1AmplitudeParam = new ParamAmplitude(new String("waveform 1 amp"), _ptrAudioSystem, std::bind(&TestAudioSystem::setWaveform1Amplitude, _ptrAudioSystem, std::placeholders::_1));
  ParamAmplitude* waveform2AmplitudeParam = new ParamAmplitude(new String("waveform 2 amp"), _ptrAudioSystem, std::bind(&TestAudioSystem::setWaveform2Amplitude, _ptrAudioSystem, std::placeholders::_1));
  ParamAmplitude* pinkNoiseAmplitudeParam = new ParamAmplitude(new String("pink noise amp"), _ptrAudioSystem, std::bind(&TestAudioSystem::setPinkNoiseAmplitude, _ptrAudioSystem, std::placeholders::_1));

  Menu* root = new Menu(new String("/"));
  Menu* synth = new Menu(new String("synth"));
  Menu* sampler = new Menu(new String("sampler"));

  root->addChild(synth);
    synth->addChild(waveform1AmplitudeParam);
    synth->addChild(waveform2AmplitudeParam);
    synth->addChild(pinkNoiseAmplitudeParam);
  root->addChild(sampler);

  new MenuHandler(root);

  _ptrControls->getEncoderHandler(0)->setParameter(waveform1AmplitudeParam);
  _ptrControls->getEncoderHandler(1)->setParameter(waveform2AmplitudeParam);
  _ptrControls->getEncoderHandler(2)->setParameter(pinkNoiseAmplitudeParam);
  _ptrControls->getEncoderHandler(3)->setParameter(pinkNoiseAmplitudeParam);

  for (int i = 0; i < 8; i++)
  {
    _ptrControls->getMusicSensorHandler(i)->setNode(_ptrAudioSystem->getMusicNode(i));
  }

}

void loop() {
  //Serial.println("main update");
  _ptrControls->update();
}
