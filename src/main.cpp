#include <Arduino.h>
#include <audio-systems/test/TestAudioSystem.h>
#include <Controls.h>
#include <parameters/FloatParameter.h>
#include <parameters/IntegerParameter.h>
#include <parameters/StatelessParameter.h>
#include <parameters/CyclicParameter.h>
#include <parameters/AdaptiveStepParameterDecorator.h>
#include <menus/MenuBranch.h>
#include <menus/MenuLeaf.h>
#include <functional>
#include <vector>

Controls* _ptrControls;
TestAudioSystem* _ptrAudioSystem;
std::vector<String> waveformNames;
std::vector<String> scaleNames;
//TODO: Use std::map
std::vector<String> sampleRateNames;

void setup() {
  Serial.begin(115200);

  _ptrAudioSystem = new TestAudioSystem(8);

  waveformNames.push_back("sine");
  waveformNames.push_back("saw");
  waveformNames.push_back("square");
  waveformNames.push_back("triangle");

  sampleRateNames.push_back("345 Hz");
  sampleRateNames.push_back("689 Hz");
  sampleRateNames.push_back("1378 Hz");
  sampleRateNames.push_back("2756 Hz");
  sampleRateNames.push_back("5513 Hz");
  sampleRateNames.push_back("11025 Hz");
  sampleRateNames.push_back("22050 Hz");
  sampleRateNames.push_back("44100 Hz");

  for (int i = 0; i < _ptrAudioSystem->getNumberOfScales(); i++) scaleNames.push_back(_ptrAudioSystem->getScaleName(i));
  
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
    "attack", new AdaptiveStepParameterDecorator(new IntegerParameter(
    std::bind(&TestAudioSystem::setAttack, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 10000, 1, "ms"), 0.1));

  MenuLeaf* decay = new MenuLeaf(
    "decay", new AdaptiveStepParameterDecorator(new IntegerParameter(
    std::bind(&TestAudioSystem::setDecay, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 10000, 1, "ms"), 0.1));

  MenuLeaf* sustain = new MenuLeaf(
    "sustain", new FloatParameter(
    std::bind(&TestAudioSystem::setSustain, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 0.01, 5, "%"));

  MenuLeaf* release = new MenuLeaf(
    "release", new AdaptiveStepParameterDecorator(new IntegerParameter(
    std::bind(&TestAudioSystem::setRelease, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 10000, 1, "ms"), 0.1));

  MenuLeaf* coarseDetune = new MenuLeaf(
    "detune", new IntegerParameter(
    std::bind(&TestAudioSystem::setCoarseDetune, _ptrAudioSystem, std::placeholders::_1),
    -24, 7, 24, 1, ""));

  MenuLeaf* fineDetune = new MenuLeaf(
    "fine detune", new IntegerParameter(
    std::bind(&TestAudioSystem::setFineDetune, _ptrAudioSystem, std::placeholders::_1),
    -100, 0, 100, 1, "cents"));

  MenuLeaf* waveform1 = new MenuLeaf(
    "o1 waveform", new CyclicParameter(
    std::bind(&TestAudioSystem::setWaveform1, _ptrAudioSystem, std::placeholders::_1), waveformNames, 1));

  MenuLeaf* waveform2 = new MenuLeaf(
    "o2 waveform", new CyclicParameter(
    std::bind(&TestAudioSystem::setWaveform2, _ptrAudioSystem, std::placeholders::_1), waveformNames, 1));

  MenuLeaf* scale = new MenuLeaf(
    "scale", new CyclicParameter(
    std::bind(&TestAudioSystem::setScale, _ptrAudioSystem, std::placeholders::_1), scaleNames));

  MenuLeaf* crushBits = new MenuLeaf(
    "crush bits", new IntegerParameter(
    std::bind(&TestAudioSystem::setBits, _ptrAudioSystem, std::placeholders::_1),
    1, 16, 16, 1, " bits"));
  
  MenuLeaf* sampleRate = new MenuLeaf(
    "sample rate", new CyclicParameter(
    std::bind(&TestAudioSystem::setSampleRate, _ptrAudioSystem, std::placeholders::_1), sampleRateNames, 7));

  MenuLeaf* delayFade = new MenuLeaf(
    "fade", new FloatParameter(
    std::bind(&TestAudioSystem::setDelayFade, _ptrAudioSystem, std::placeholders::_1),
    5, 100, 100, 0.01, 5, "%"));
  
  MenuLeaf* delayTime = new MenuLeaf(
    "delay", new IntegerParameter(
    std::bind(&TestAudioSystem::setDelay, _ptrAudioSystem, std::placeholders::_1),
    0, 0, 1000, 20, " ms"));
  
  MenuBranch* root = new MenuBranch("/");
  MenuBranch* synth = new MenuBranch("synth");
  MenuBranch* synthOscillators = new MenuBranch("oscillators");
  MenuBranch* synthMixer = new MenuBranch("mixer");
  MenuBranch* synthADSR = new MenuBranch("ADSR");
  // MenuBranch* filter = new MenuBranch("filter");
  MenuBranch* effects = new MenuBranch("effects");

  root->addChild(synth);
    synth->addChild(synthOscillators);
      synthOscillators->addChild(scale);
      synthOscillators->addChild(waveform1);
      synthOscillators->addChild(waveform2);
      synthOscillators->addChild(coarseDetune);
      synthOscillators->addChild(fineDetune);
    synth->addChild(synthMixer);
      synthMixer->addChild(wf1Amplitude);
      synthMixer->addChild(wf2Amplitude);
      synthMixer->addChild(pinkNoiseAmplitude);
    synth->addChild(synthADSR);
      synthADSR->addChild(attack);
      synthADSR->addChild(decay);
      synthADSR->addChild(sustain);
      synthADSR->addChild(release);
  root->addChild(effects);
    effects->addChild(crushBits);
    effects->addChild(sampleRate);
    effects->addChild(delayTime);
    effects->addChild(delayFade);

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
