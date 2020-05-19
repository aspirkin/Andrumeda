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

  

  Menu* root = new Menu(new String("main"));
  ParamAmplitude* pa = new ParamAmplitude(new String("wf1 amp"), _ptrAudioSystem, std::bind(&TestAudioSystem::setWf1Amplitude, _ptrAudioSystem, std::placeholders::_1));
  root->addChild(pa);
  _ptrControls->getEncoderHandler(0)->setParameter(pa);
  /*Parameter* _ptrParameter;
  _ptrParameter = new ParamAmplitude("wf1 amp", (TestAudioSystem*)_ptrAudioSystem, 0);
  _ptrControls->getEncoder(0)->setParameter(_ptrParameter);
  _ptrParameter = new ParamAmplitude("wf2 amp", (TestAudioSystem*)_ptrAudioSystem, 1);
  _ptrControls->getEncoder(1)->setParameter(_ptrParameter);
  _ptrParameter = new ParamAmplitude("noise amp", (TestAudioSystem*)_ptrAudioSystem, 2);
  _ptrControls->getEncoder(2)->setParameter(_ptrParameter);
  _ptrParameter = new ParamAmplitude("pulse width", (TestAudioSystem*)_ptrAudioSystem, 3);
  _ptrControls->getEncoder(3)->setParameter(_ptrParameter);*/

  for (int i = 0; i < 8; i++)
  {
  }

}

void loop() {
  // Serial.println("main update");
  _ptrControls->update();
}
