#include <Arduino.h>
#include <audio-systems/test/TestAudioSystem.h>
#include <Controls.h>
#include <parameters/StatelessParameter.h>
#include <parameters/RangeParameter.h>
#include <parameters/VectorParameter.h>
#include <menus/MenuBranch.h>
#include <menus/MenuLeaf.h>
#include <functional>
#include <vector>
#include <map>

typedef std::map<int, String> ValuesMap;

Controls* _ptrControls;
TestAudioSystem* _ptrAudioSystem;
std::vector<String> _waveforms = {"sine", "saw", "square", "triangle"};
std::vector<String> _scales;
std::vector<String> _sampleRates = {"345", "689", "1378", "2756", "5513", "11025", "22050", "44100"};
std::vector<String> _filterModes = {"high pass", "low pass", "band pass", "notch"};
std::vector<String> _noteNames;

void setup() {
  Serial.begin(115200);

  _ptrAudioSystem = new TestAudioSystem(8);

  for (int i = 0; i < _ptrAudioSystem->getNumberOfScales(); i++) _scales.push_back(_ptrAudioSystem->getScaleName(i));
  
  for (int i = 0; i < _ptrAudioSystem->getNumberOfNotes(); i++) _noteNames.push_back(_ptrAudioSystem->getNoteName(i));

  MenuLeaf* wf1Amplitude = new MenuLeaf(
    "waveform 1", new RangeParameter(
    std::bind(&TestAudioSystem::setWaveform1Amplitude, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 5, 0.00, false, "%"));

  MenuLeaf* wf2Amplitude = new MenuLeaf(
    "waveform 2", new RangeParameter(
    std::bind(&TestAudioSystem::setWaveform2Amplitude, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 5, 0.00, false, "%"));

  MenuLeaf* pinkNoiseAmplitude = new MenuLeaf(
    "pink noise", new RangeParameter(
    std::bind(&TestAudioSystem::setPinkNoiseAmplitude, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 5, 0.00, false, "%"));

  MenuLeaf* attack = new MenuLeaf(
    "attack", new RangeParameter(
    std::bind(&TestAudioSystem::setAttack, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 10000, 1, 0.10, false, "ms"));

  MenuLeaf* decay = new MenuLeaf(
    "decay", new RangeParameter(
    std::bind(&TestAudioSystem::setDecay, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 10000, 1, 0.10, false, "ms"));

  MenuLeaf* sustain = new MenuLeaf(
    "sustain", new RangeParameter(
    std::bind(&TestAudioSystem::setSustain, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 5, 0.00, false, "%"));

  MenuLeaf* release = new MenuLeaf(
    "release", new RangeParameter(
    std::bind(&TestAudioSystem::setRelease, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 10000, 1, 0.10, false, "ms"));

  MenuLeaf* coarseDetune = new MenuLeaf(
    "detune", new RangeParameter(
    std::bind(&TestAudioSystem::setCoarseDetune, _ptrAudioSystem, std::placeholders::_1),
    -24, 7, 24, 1));

  MenuLeaf* fineDetune = new MenuLeaf(
    "fine detune", new RangeParameter(
    std::bind(&TestAudioSystem::setFineDetune, _ptrAudioSystem, std::placeholders::_1),
    -100, 0, 100, 1, 0.00, false, "cents"));

  MenuLeaf* waveform1 = new MenuLeaf(
    "o1 waveform", new VectorParameter(
    std::bind(&TestAudioSystem::setWaveform1, _ptrAudioSystem, std::placeholders::_1), _waveforms, 1, true));

  MenuLeaf* waveform2 = new MenuLeaf(
    "o2 waveform", new VectorParameter(
    std::bind(&TestAudioSystem::setWaveform2, _ptrAudioSystem, std::placeholders::_1), _waveforms, 1, true));

  MenuLeaf* scale = new MenuLeaf(
    "scale", new VectorParameter(
    std::bind(&TestAudioSystem::setScale, _ptrAudioSystem, std::placeholders::_1), _scales, 0, true));

  MenuLeaf* bitcrusherAmount = new MenuLeaf(
    "amount", new RangeParameter(
    std::bind(&TestAudioSystem::setBitcrusherAmount, _ptrAudioSystem, std::placeholders::_1),
    0, 0, 100, 5, 0.00, false, "%"));

  MenuLeaf* bits = new MenuLeaf(
    "bits", new RangeParameter(
    std::bind(&TestAudioSystem::setBits, _ptrAudioSystem, std::placeholders::_1),
    1, 16, 16, 1, 0.00, false, " bits"));
  
  MenuLeaf* sampleRate = new MenuLeaf(
    "sample rate", new VectorParameter(
    std::bind(&TestAudioSystem::setSampleRate, _ptrAudioSystem, std::placeholders::_1), _sampleRates, 7, false, " Hz"));

  MenuLeaf* delayFade = new MenuLeaf(
    "fade", new RangeParameter(
    std::bind(&TestAudioSystem::setDelayFade, _ptrAudioSystem, std::placeholders::_1),
    5, 100, 100, 5, 0.00, false, "%"));
  
  MenuLeaf* delayTime = new MenuLeaf(
    "time", new RangeParameter(
    std::bind(&TestAudioSystem::setDelay, _ptrAudioSystem, std::placeholders::_1),
    0, 0, 1000, 20, 0.05, false, " ms"));

  MenuLeaf* reverbAmount = new MenuLeaf(
    "amount", new RangeParameter(
    std::bind(&TestAudioSystem::setReverbAmount, _ptrAudioSystem, std::placeholders::_1),
    0, 0, 100, 5, 0.00, false, "%"));

  MenuLeaf* roomsize = new MenuLeaf(
    "room size", new RangeParameter(
    std::bind(&TestAudioSystem::setRoomsize, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 5, 0.00, false, "%"));

  MenuLeaf* damping = new MenuLeaf(
    "damping", new RangeParameter(
    std::bind(&TestAudioSystem::setDamping, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 5, 0.00, false, "%"));

  MenuLeaf* volume = new MenuLeaf(
    "volume", new RangeParameter(
    std::bind(&TestAudioSystem::setVolume, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 5, 0.00, false, "%"));

  MenuLeaf* keyNote = new MenuLeaf(
    "key note", new VectorParameter(
    std::bind(&TestAudioSystem::setKeyNote, _ptrAudioSystem, std::placeholders::_1), _noteNames, 20));

  //  FILTER PARAMS
  MenuLeaf* filterAmount = new MenuLeaf(
    "amount", new RangeParameter(
    std::bind(&TestAudioSystem::setFilterAmount, _ptrAudioSystem, std::placeholders::_1),
    0, 0, 100, 5, 0.00, false, "%"));

  //  STAGE 1
  MenuLeaf* filterStage1Frequency = new MenuLeaf(
    "frequency", new RangeParameter(
    std::bind(&TestAudioSystem::setFilterFrequency, _ptrAudioSystem, 0, std::placeholders::_1),
    400, 500, 20000, 50, 0.05, false, " Hz"));

  MenuLeaf* filterStage1Q = new MenuLeaf(
    "Q", new RangeParameter(
    std::bind(&TestAudioSystem::setFilterQ, _ptrAudioSystem, 0, std::placeholders::_1),
    5, 50, 70, 5, 0.00, false, "", "0."));

  MenuLeaf* filterStage1Mode = new MenuLeaf(
    "mode", new VectorParameter(
    std::bind(&TestAudioSystem::setFilterMode, _ptrAudioSystem, 0, std::placeholders::_1), _filterModes, 0, true));

  //  STAGE 2
  MenuLeaf* filterStage2Frequency = new MenuLeaf(
    "frequency", new RangeParameter(
    std::bind(&TestAudioSystem::setFilterFrequency, _ptrAudioSystem, 1, std::placeholders::_1),
    400, 500, 20000, 50, 0.05, false, " Hz"));

  MenuLeaf* filterStage2Q = new MenuLeaf(
    "Q", new RangeParameter(
    std::bind(&TestAudioSystem::setFilterQ, _ptrAudioSystem, 1, std::placeholders::_1),
    5, 50, 70, 5, 0.00, false, "", "0."));

  MenuLeaf* filterStage2Mode = new MenuLeaf(
    "mode", new VectorParameter(
    std::bind(&TestAudioSystem::setFilterMode, _ptrAudioSystem, 1, std::placeholders::_1), _filterModes, 0, true));

  //  STAGE 3
  MenuLeaf* filterStage3Frequency = new MenuLeaf(
    "frequency", new RangeParameter(
    std::bind(&TestAudioSystem::setFilterFrequency, _ptrAudioSystem, 2, std::placeholders::_1),
    400, 500, 20000, 50, 0.05, false, " Hz"));

  MenuLeaf* filterStage3Q = new MenuLeaf(
    "Q", new RangeParameter(
    std::bind(&TestAudioSystem::setFilterQ, _ptrAudioSystem, 2, std::placeholders::_1),
    5, 50, 70, 5, 0.00, false, "", "0."));

  MenuLeaf* filterStage3Mode = new MenuLeaf(
    "mode", new VectorParameter(
    std::bind(&TestAudioSystem::setFilterMode, _ptrAudioSystem, 2, std::placeholders::_1), _filterModes, 0, true));

  //  STAGE 4
  MenuLeaf* filterStage4Frequency = new MenuLeaf(
    "frequency", new RangeParameter(
    std::bind(&TestAudioSystem::setFilterFrequency, _ptrAudioSystem, 3, std::placeholders::_1),
    400, 500, 20000, 50, 0.05, false, " Hz"));

  MenuLeaf* filterStage4Q = new MenuLeaf(
    "Q", new RangeParameter(
    std::bind(&TestAudioSystem::setFilterQ, _ptrAudioSystem, 3, std::placeholders::_1),
    5, 50, 70, 5, 0.00, false, "", "0."));

  MenuLeaf* filterStage4Mode = new MenuLeaf(
    "mode", new VectorParameter(
    std::bind(&TestAudioSystem::setFilterMode, _ptrAudioSystem, 3, std::placeholders::_1), _filterModes, 0, true));


  MenuBranch* root = new MenuBranch("/");
  MenuBranch* general = new MenuBranch("general");
  MenuBranch* synth = new MenuBranch("synth");
  MenuBranch* synthOscillators = new MenuBranch("oscillators");
  MenuBranch* synthMixer = new MenuBranch("mixer");
  MenuBranch* synthADSR = new MenuBranch("ADSR");
  MenuBranch* effects = new MenuBranch("effects");
  MenuBranch* filter = new MenuBranch("filter");
  MenuBranch* stage1 = new MenuBranch("stage 1");
  MenuBranch* stage2 = new MenuBranch("stage 2");
  MenuBranch* stage3 = new MenuBranch("stage 3");
  MenuBranch* stage4 = new MenuBranch("stage 4");
  MenuBranch* bitcrusher = new MenuBranch("bitcrusher");
  MenuBranch* delay = new MenuBranch("delay");
  MenuBranch* reverb = new MenuBranch("reverb");

  root->addChild(general);
    general->addChild(volume);
    general->addChild(keyNote);
    general->addChild(scale);
  root->addChild(synth);
    synth->addChild(synthOscillators);
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
    effects->addChild(filter);
      filter->addChild(filterAmount);
      filter->addChild(stage1);
        stage1->addChild(filterStage1Frequency);
        stage1->addChild(filterStage1Q);
        stage1->addChild(filterStage1Mode);
      filter->addChild(stage2);
        stage2->addChild(filterStage2Frequency);
        stage2->addChild(filterStage2Q);
        stage2->addChild(filterStage2Mode);
      filter->addChild(stage3);
        stage3->addChild(filterStage3Frequency);
        stage3->addChild(filterStage3Q);
        stage3->addChild(filterStage3Mode);
      filter->addChild(stage4);
        stage4->addChild(filterStage4Frequency);
        stage4->addChild(filterStage4Q);
        stage4->addChild(filterStage4Mode);
    effects->addChild(bitcrusher);
      bitcrusher->addChild(bitcrusherAmount);
      bitcrusher->addChild(bits);
      bitcrusher->addChild(sampleRate);
    effects->addChild(delay);
      delay->addChild(delayTime);
      delay->addChild(delayFade);
    effects->addChild(reverb);
      reverb->addChild(reverbAmount);
      reverb->addChild(roomsize);
      reverb->addChild(damping);

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
