#include <Arduino.h>
#include <audio-system/AudioSystem.h>
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
AudioSystem* _ptrAudioSystem;
std::vector<String> _waveforms = {"sine", "saw", "square", "triangle"};
std::vector<String> _sampleRates = {"345", "689", "1378", "2756", "5513", "11025", "22050", "44100"};
std::vector<String> _filterModes = {"high pass", "low pass", "band pass", "notch"};
// std::vector<String> _modeNames = {"synth", "sampler"};
std::vector<String> _modulationModes = {"FM", "AM", "RING", "AM+FM"};
std::vector<String> _noteNames;
std::vector<String> _scales;

MenuBranch* setupMenu(AudioSystem* audioSystem) {
  //  Menu branches
  MenuBranch* root = new MenuBranch("/");
  MenuBranch* general = new MenuBranch("general");
  MenuBranch* oscillators = new MenuBranch("OSCs");
  MenuBranch* mixer = new MenuBranch("mixer");
  MenuBranch* modulation = new MenuBranch("modulation");
  MenuBranch* adsr = new MenuBranch("ADSR");
  MenuBranch* filter = new MenuBranch("filter");
  MenuBranch* bitcrusher = new MenuBranch("bitcrusher");
  MenuBranch* delay = new MenuBranch("delay");
  MenuBranch* reverb = new MenuBranch("reverb");

  // audioSystem->addAdditiveMenuBranch(synthOscillators);
  // audioSystem->addAdditiveMenuBranch(synthMixer);

  // audioSystem->addSimpleMenuBranch(modulation);
  // audioSystem->addSimpleMenuBranch(simpleMixer);

  //  Menu leaves
  //  GENERAL
  MenuLeaf* volume = new MenuLeaf(
    "volume", new RangeParameter(
    std::bind(&AudioSystem::setVolume, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 5, 0.00, false, "%"));

  MenuLeaf* scale = new MenuLeaf(
    "scale", new VectorParameter(
    std::bind(&AudioSystem::setScale, _ptrAudioSystem, std::placeholders::_1), _scales, 0, true));

  MenuLeaf* keyNote = new MenuLeaf(
    "key note", new VectorParameter(
    std::bind(&AudioSystem::setKeyNote, _ptrAudioSystem, std::placeholders::_1), _noteNames, 20));


  //  SYNTH
  MenuLeaf* osc1waveform = new MenuLeaf(
    "o1 waveform", new VectorParameter(
    std::bind(&AudioSystem::setOscillator1Waveform, _ptrAudioSystem, std::placeholders::_1), _waveforms, 1, true));

  MenuLeaf* osc2waveform = new MenuLeaf(
    "o2 waveform", new VectorParameter(
    std::bind(&AudioSystem::setOscillator2Waveform, _ptrAudioSystem, std::placeholders::_1), _waveforms, 1, true));

  MenuLeaf* coarseDetune = new MenuLeaf(
    "detune", new RangeParameter(
    std::bind(&AudioSystem::setCoarseDetune, _ptrAudioSystem, std::placeholders::_1),
    -24, 7, 24, 1));

  MenuLeaf* fineDetune = new MenuLeaf(
    "fine detune", new RangeParameter(
    std::bind(&AudioSystem::setFineDetune, _ptrAudioSystem, std::placeholders::_1),
    -100, 0, 100, 1, 0.00, false, "cents"));


  MenuLeaf* osc1Amplitude = new MenuLeaf(
    "osc 1", new RangeParameter(
    std::bind(&AudioSystem::setOscillator1Amplitude, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 5, 0.00, false, "%"));

  MenuLeaf* osc2Amplitude = new MenuLeaf(
    "osc 2", new RangeParameter(
    std::bind(&AudioSystem::setOscillator2Amplitude, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 5, 0.00, false, "%"));

  MenuLeaf* pinkNoiseAmplitude = new MenuLeaf(
    "pink noise", new RangeParameter(
    std::bind(&AudioSystem::setPinkNoiseAmplitude, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 5, 0.00, false, "%"));


  MenuLeaf* modulationMode = new MenuLeaf(
    "mode", new VectorParameter(
    std::bind(&AudioSystem::setModulationMode, _ptrAudioSystem, std::placeholders::_1), _modulationModes, 0, true));
  
  MenuLeaf* modulationWaveform = new MenuLeaf(
    "waveform", new VectorParameter(
    std::bind(&AudioSystem::setModulationWaveform, _ptrAudioSystem, std::placeholders::_1), _waveforms, 1, true));
 
  MenuLeaf* modulationFrequency = new MenuLeaf(
    "frequency", new RangeParameter(
    std::bind(&AudioSystem::setModulationFrequency, _ptrAudioSystem, std::placeholders::_1),
    10, 10, 10000, 1, 0.05, false, "Hz", 1));

  MenuLeaf* modulationAmplitude  = new MenuLeaf(
    "amplitude", new RangeParameter(
    std::bind(&AudioSystem::setModulationAmplitude, _ptrAudioSystem, std::placeholders::_1),
    0, 0, 100, 1, 0.00, false, "%"));


  MenuLeaf* attack = new MenuLeaf(
    "attack", new RangeParameter(
    std::bind(&AudioSystem::setAttack, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 10000, 1, 0.10, false, "ms"));

  MenuLeaf* decay = new MenuLeaf(
    "decay", new RangeParameter(
    std::bind(&AudioSystem::setDecay, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 10000, 1, 0.10, false, "ms"));

  MenuLeaf* sustain = new MenuLeaf(
    "sustain", new RangeParameter(
    std::bind(&AudioSystem::setSustain, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 5, 0.00, false, "%"));

  MenuLeaf* release = new MenuLeaf(
    "release", new RangeParameter(
    std::bind(&AudioSystem::setRelease, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 10000, 1, 0.10, false, "ms"));


  //  FILTER
  MenuLeaf* filterAmount = new MenuLeaf(
    "amount", new RangeParameter(
    std::bind(&AudioSystem::setFilterAmount, _ptrAudioSystem, std::placeholders::_1),
    0, 0, 100, 5, 0.00, false, "%"));

  MenuLeaf* filterStage1Frequency = new MenuLeaf(
    "frequency", new RangeParameter(
    std::bind(&AudioSystem::setFilterFrequency, _ptrAudioSystem, 0, std::placeholders::_1),
    400, 500, 20000, 50, 0.05, false, " Hz"));

  MenuLeaf* filterStage1Q = new MenuLeaf(
    "Q", new RangeParameter(
    std::bind(&AudioSystem::setFilterQ, _ptrAudioSystem, 0, std::placeholders::_1),
    5, 50, 70, 5, 0.00, false, "", 2));

  MenuLeaf* filterStage1Mode = new MenuLeaf(
    "mode", new VectorParameter(
    std::bind(&AudioSystem::setFilterMode, _ptrAudioSystem, 0, std::placeholders::_1), _filterModes, 0, true));


  //  EFFECTS
  MenuLeaf* bitcrusherAmount = new MenuLeaf(
    "amount", new RangeParameter(
    std::bind(&AudioSystem::setBitcrusherAmount, _ptrAudioSystem, std::placeholders::_1),
    0, 0, 100, 5, 0.00, false, "%"));

  MenuLeaf* bits = new MenuLeaf(
    "bits", new RangeParameter(
    std::bind(&AudioSystem::setBits, _ptrAudioSystem, std::placeholders::_1),
    1, 16, 16, 1, 0.00, false, " bits"));
  
  MenuLeaf* sampleRate = new MenuLeaf(
    "sample rate", new VectorParameter(
    std::bind(&AudioSystem::setSampleRate, _ptrAudioSystem, std::placeholders::_1), _sampleRates, 7, false, " Hz"));

  MenuLeaf* delayFade = new MenuLeaf(
    "fade", new RangeParameter(
    std::bind(&AudioSystem::setDelayFade, _ptrAudioSystem, std::placeholders::_1),
    5, 100, 100, 5, 0.00, false, "%"));
  
  MenuLeaf* delayTime = new MenuLeaf(
    "time", new RangeParameter(
    std::bind(&AudioSystem::setDelay, _ptrAudioSystem, std::placeholders::_1),
    0, 0, 1000, 20, 0.05, false, " ms"));

  MenuLeaf* reverbAmount = new MenuLeaf(
    "amount", new RangeParameter(
    std::bind(&AudioSystem::setReverbAmount, _ptrAudioSystem, std::placeholders::_1),
    0, 0, 100, 5, 0.00, false, "%"));

  MenuLeaf* roomsize = new MenuLeaf(
    "room size", new RangeParameter(
    std::bind(&AudioSystem::setRoomsize, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 5, 0.00, false, "%"));

  MenuLeaf* damping = new MenuLeaf(
    "damping", new RangeParameter(
    std::bind(&AudioSystem::setDamping, _ptrAudioSystem, std::placeholders::_1),
    0, 50, 100, 5, 0.00, false, "%"));


  root->addChild(general);
    // general->addChild(mode);
    general->addChild(volume);
    general->addChild(keyNote);
    general->addChild(scale);
  root->addChild(oscillators);
    oscillators->addChild(osc1waveform);
    oscillators->addChild(osc2waveform);
    oscillators->addChild(coarseDetune);
    oscillators->addChild(fineDetune);
  root->addChild(mixer);
    mixer->addChild(osc1Amplitude);
    mixer->addChild(osc2Amplitude);
    mixer->addChild(pinkNoiseAmplitude);
  root->addChild(modulation);
    modulation->addChild(modulationMode);
    modulation->addChild(modulationWaveform);
    modulation->addChild(modulationFrequency);
    modulation->addChild(modulationAmplitude);
  root->addChild(adsr);
    adsr->addChild(attack);
    adsr->addChild(decay);
    adsr->addChild(sustain);
    adsr->addChild(release);
  root->addChild(filter);
    filter->addChild(filterAmount);
    filter->addChild(filterStage1Frequency);
    filter->addChild(filterStage1Q);
    filter->addChild(filterStage1Mode);
  root->addChild(bitcrusher);
    bitcrusher->addChild(bitcrusherAmount);
    bitcrusher->addChild(bits);
    bitcrusher->addChild(sampleRate);
  root->addChild(delay);
    delay->addChild(delayTime);
    delay->addChild(delayFade);
  root->addChild(reverb);
    reverb->addChild(reverbAmount);
    reverb->addChild(roomsize);
    reverb->addChild(damping);
  
  return root;
}

void setup() {
  Serial.begin(115200);

  _ptrAudioSystem = new AudioSystem(8);

  for (int i = 0; i < _ptrAudioSystem->getNumberOfScales(); i++) _scales.push_back(_ptrAudioSystem->getScaleName(i));
  for (int i = 0; i < _ptrAudioSystem->getNumberOfNotes(); i++) _noteNames.push_back(_ptrAudioSystem->getNoteName(i));


  _ptrControls = new Controls(8, 2, setupMenu(_ptrAudioSystem), new ST7735_DisplayHandler());
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

  for (int i = 0; i < 8; i++)
  {
    _ptrControls->getMusicSensorHandler(i)->setSynthNode(_ptrAudioSystem->getSynthNode(i));
  }

}

void loop() {
  // Serial.print("memory: ");
  // Serial.print(AudioMemoryUsage());
  // Serial.print("; cpu: ");
  // Serial.println(AudioProcessorUsage());
  _ptrControls->update();
}
