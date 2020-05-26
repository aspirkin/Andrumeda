#include <Arduino.h>
#include <TestAudioSystem.h>
#include <Controls.h>
#include <parameters/FloatParameter.h>
#include <parameters/StatelessParameter.h>
#include <menus/MenuBranch.h>
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

  FloatParameter* waveform1AmplitudeParam = new FloatParameter(new String("waveform 1"), std::bind(&TestAudioSystem::setWaveform1Amplitude, _ptrAudioSystem, std::placeholders::_1));
  FloatParameter* waveform2AmplitudeParam = new FloatParameter(new String("waveform 2"), std::bind(&TestAudioSystem::setWaveform2Amplitude, _ptrAudioSystem, std::placeholders::_1));
  FloatParameter* pinkNoiseAmplitudeParam = new FloatParameter(new String("pink noise"), std::bind(&TestAudioSystem::setPinkNoiseAmplitude, _ptrAudioSystem, std::placeholders::_1));

  MenuBranch* root = new MenuBranch(new String("/"));
  MenuBranch* synth = new MenuBranch(new String("synth"));
  MenuBranch* synthOscillators = new MenuBranch(new String("oscillators"));
  MenuBranch* synthMixer = new MenuBranch(new String("mixer"));
  MenuBranch* synthADSR = new MenuBranch(new String("ADSR"));

  root->addChild(synth);
    synth->addChild(synthOscillators);
    synth->addChild(synthMixer);
      synthMixer->addChild(waveform1AmplitudeParam);
      synthMixer->addChild(waveform2AmplitudeParam);
      synthMixer->addChild(pinkNoiseAmplitudeParam);
    synth->addChild(synthADSR);

  MenuHandler* menuHandler = new MenuHandler(root, _ptrControls->getEncoderHandler(1));

  StatelessParameter* paramMenuChildrenNavigation =
    new StatelessParameter(std::bind(&MenuHandler::selectNextChild, menuHandler),
                           std::bind(&MenuHandler::selectPreviousChild, menuHandler));


  _ptrControls->getEncoderHandler(0)->setParameter(paramMenuChildrenNavigation);
  _ptrControls->getEncoderHandler(0)->setClickFunction(std::bind(&MenuHandler::escapeToParent, menuHandler));
  _ptrControls->getEncoderHandler(1)->setParameter(waveform2AmplitudeParam);
  _ptrControls->getEncoderHandler(1)->setClickFunction(std::bind(&MenuHandler::enterCurrentChild, menuHandler));
  _ptrControls->getEncoderHandler(2)->setParameter(pinkNoiseAmplitudeParam);
  _ptrControls->getEncoderHandler(3)->setParameter(waveform1AmplitudeParam);

  for (int i = 0; i < 8; i++)
  {
    _ptrControls->getMusicSensorHandler(i)->setNode(_ptrAudioSystem->getMusicNode(i));
  }

}

void loop() {
  //Serial.println("main update");
  _ptrControls->update();
}
