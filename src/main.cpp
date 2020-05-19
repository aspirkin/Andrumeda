#include <Arduino.h>
#include <TestAudioSystem.h>
#include <Controls.h>
#include <parameters/ParamAmplitude.h>
#include <Menu.h>
#include <functional>

Controls* _ptrControls;
TestAudioSystem* _ptrAudioSystem;

typedef std::function<void(float)> floatSetterFunction;

void setup() {
  Serial.begin(115200);

  //  TODO: insert actual number of nodes here
  _ptrControls = new Controls(8);
  _ptrAudioSystem = new TestAudioSystem();

  

  ParamAmplitude* pa1 = new ParamAmplitude(new String("waveform 1 amp"), _ptrAudioSystem, std::bind(&TestAudioSystem::setWf1Amplitude, _ptrAudioSystem, std::placeholders::_1));
  ParamAmplitude* pa2 = new ParamAmplitude(new String("waveform 2 amp"), _ptrAudioSystem, std::bind(&TestAudioSystem::setWf2Amplitude, _ptrAudioSystem, std::placeholders::_1));
  ParamAmplitude* pa3 = new ParamAmplitude(new String("pink noise amp"), _ptrAudioSystem, std::bind(&TestAudioSystem::setPinkAmplitude, _ptrAudioSystem, std::placeholders::_1));

  Menu* root = new Menu(new String("main"));
  root->addChild(pa1);
  root->addChild(pa2);
  root->addChild(pa3);

  _ptrControls->getEncoderHandler(0)->setParameter(pa1);
  _ptrControls->getEncoderHandler(1)->setParameter(pa2);
  _ptrControls->getEncoderHandler(2)->setParameter(pa3);
  _ptrControls->getEncoderHandler(3)->setParameter(pa3);

  for (int i = 0; i < 8; i++)
  {
    _ptrControls->getMusicSensorHandler(i)->setNode(_ptrAudioSystem->getMusicNode(i));
  }

}

void loop() {
  //Serial.println("main update");
  _ptrControls->update();
}
