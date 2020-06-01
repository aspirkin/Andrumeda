#include <Arduino.h>
#include <audio-systems/test/TestAudioSystem.h>
#include <Controls.h>
#include <parameters/FloatParameter.h>
#include <parameters/IntegerParameter.h>
#include <parameters/StatelessParameter.h>
#include <menus/MenuBranch.h>
#include <menus/MenuLeaf.h>
#include <functional>

Controls* _ptrControls;
TestAudioSystem* _ptrAudioSystem;

//TODO: Add switch parameter, implement logarithmic parameter scaling

void setup() {
  Serial.begin(115200);

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

  MenuLeaf* attack = new MenuLeaf(
    "attack", new IntegerParameter(
    std::bind(&TestAudioSystem::setAttack, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 10000, 50, "ms"));

  MenuLeaf* decay = new MenuLeaf(
    "decay", new IntegerParameter(
    std::bind(&TestAudioSystem::setDecay, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 10000, 50, "ms"));

  MenuLeaf* sustain = new MenuLeaf(
    "sustain", new FloatParameter(
    std::bind(&TestAudioSystem::setPinkNoiseAmplitude, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 0.01, 5, "%"));

  MenuLeaf* release = new MenuLeaf(
    "release", new IntegerParameter(
    std::bind(&TestAudioSystem::setRelease, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 10000, 50, "ms"));

  MenuBranch* root = new MenuBranch("/");
  MenuBranch* synth = new MenuBranch("synth");
  MenuBranch* synthOscillators = new MenuBranch("hot settings");
  MenuBranch* synthMixer = new MenuBranch("mixer");
  MenuBranch* synthADSR = new MenuBranch("ADSR");

  root->addChild(synth);
    synth->addChild(synthOscillators);
      synthOscillators->addChild(attack);
      synthOscillators->addChild(pinkNoiseAmplitude);
    synth->addChild(synthMixer);
      synthMixer->addChild(wf1Amplitude);
      synthMixer->addChild(wf2Amplitude);
      synthMixer->addChild(pinkNoiseAmplitude);
    synth->addChild(synthADSR);
      synthADSR->addChild(attack);
      synthADSR->addChild(decay);
      synthADSR->addChild(sustain);
      synthADSR->addChild(release);

  _ptrControls = new Controls(8, 2, root, new ST7735_DisplayHandler());
  _ptrControls->addMusicSensor(16);
  _ptrControls->addMusicSensor(15);
  _ptrControls->addMusicSensor(14);
  _ptrControls->addMusicSensor(49);
  _ptrControls->addMusicSensor(50);
  _ptrControls->addMusicSensor(39);
  _ptrControls->addMusicSensor(38);
  _ptrControls->addMusicSensor(37);
  _ptrControls->addNavigationEncoder(2, 1, 0);
  _ptrControls->addConfigurationEncoder(8, 7, 6);
  _ptrControls->addCommonEncoder(5, 4, 3);
  _ptrControls->addCommonEncoder(27, 26, 25);

  for (int i = 0; i < 8; i++)
  {
    _ptrControls->getMusicSensorHandler(i)->setNode(_ptrAudioSystem->getMusicNode(i));
  }
  
}

void loop() {
  //Serial.println("main update");
  _ptrControls->update();
}
