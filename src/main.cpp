#include <Arduino.h>
#include <TestAudioSystem.h>
#include <Controls.h>
#include <parameters/FloatParameter.h>
#include <parameters/StatelessParameter.h>
#include <menus/MenuBranch.h>
#include <menus/MenuLeaf.h>
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


  MenuLeaf* wf1Amplitude = new MenuLeaf(
    "waveform 1", new FloatParameter(
    std::bind(&TestAudioSystem::setWaveform1Amplitude, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 0.01, 5, "%"));

  MenuLeaf* wf2Amplitude = new MenuLeaf(
    "waveform 2", new FloatParameter(
    std::bind(&TestAudioSystem::setWaveform2Amplitude, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 0.01, 5, "%"));

  MenuLeaf* pinkNoiseAmplitude = new MenuLeaf(
    "pink noise", new FloatParameter(
    std::bind(&TestAudioSystem::setPinkNoiseAmplitude, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 0.01, 5, "%"));

  MenuBranch* root = new MenuBranch("/");
  MenuBranch* synth = new MenuBranch("synth");
  MenuBranch* synthOscillators = new MenuBranch("oscillators");
  MenuBranch* synthMixer = new MenuBranch("mixer");
  MenuBranch* synthADSR = new MenuBranch("ADSR");

  root->addChild(synth);
    synth->addChild(synthOscillators);
    synth->addChild(synthMixer);
      synthMixer->addChild(wf1Amplitude);
      synthMixer->addChild(wf2Amplitude);
      synthMixer->addChild(pinkNoiseAmplitude);
    synth->addChild(synthADSR);

  MenuHandler* menuHandler = new MenuHandler(root, _ptrControls->getEncoderHandler(1));

  StatelessParameter* paramMenuChildrenNavigation =
    new StatelessParameter(std::bind(&MenuHandler::selectNextChild, menuHandler),
                           std::bind(&MenuHandler::selectPreviousChild, menuHandler));


  _ptrControls->getEncoderHandler(0)->setParameter(paramMenuChildrenNavigation);
  _ptrControls->getEncoderHandler(0)->setClickFunction(std::bind(&MenuHandler::escapeToParent, menuHandler));
  // _ptrControls->getEncoderHandler(1)->setParameter(waveform2AmplitudeParam);
  _ptrControls->getEncoderHandler(1)->setClickFunction(std::bind(&MenuHandler::enterCurrentChild, menuHandler));
  // _ptrControls->getEncoderHandler(2)->setParameter(pinkNoiseAmplitudeParam);
  // _ptrControls->getEncoderHandler(3)->setParameter(waveform1AmplitudeParam);

  for (int i = 0; i < 8; i++)
  {
    _ptrControls->getMusicSensorHandler(i)->setNode(_ptrAudioSystem->getMusicNode(i));
  }

}

void loop() {
  //Serial.println("main update");
  _ptrControls->update();
}
