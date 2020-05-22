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

  _ptrControls = new Controls(8, 2);
  _ptrControls->addMusicSensor(16);
  _ptrControls->addMusicSensor(15);
  _ptrControls->addMusicSensor(14);
  _ptrControls->addMusicSensor(49);
  _ptrControls->addMusicSensor(50);
  _ptrControls->addMusicSensor(39);
  _ptrControls->addMusicSensor(38);
  _ptrControls->addMusicSensor(37);
  _ptrControls->addEncoder(2, 1, 0);
  _ptrControls->addEncoder(8, 7, 6);
  _ptrControls->addEncoder(5, 4, 3);
  _ptrControls->addEncoder(27, 26, 25);

  _ptrAudioSystem = new TestAudioSystem(8);

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

  MenuHandler* menuHandler = new MenuHandler(root);

  _ptrControls->getEncoderHandler(0)->setParameter(waveform1AmplitudeParam);
  _ptrControls->getEncoderHandler(0)->setClickFunction(std::bind(&MenuHandler::escapeToParent, menuHandler));
  _ptrControls->getEncoderHandler(1)->setParameter(waveform2AmplitudeParam);
  _ptrControls->getEncoderHandler(1)->setClickFunction(std::bind(&MenuHandler::enterCurrentChild, menuHandler));
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
