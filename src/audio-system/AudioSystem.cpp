#include <audio-system/AudioSystem.h>

AudioSystem::AudioSystem(int numberOfMusicNodes) {
  _numberOfMusicNodes = numberOfMusicNodes;
  _ptrAdditiveMusicNodes.reserve(_numberOfMusicNodes);
  _ptrSimpleMusicNodes.reserve(_numberOfMusicNodes);
  
  _biquad = new AudioFilterBiquad();
  _filterMixer = new AudioMixer4();
  _bitcrusher = new AudioEffectBitcrusher();
  _delayMixer = new AudioMixer4();
  _delay = new AudioEffectDelay();
  _freeverb = new AudioEffectFreeverb();
  _reverbMixer = new AudioMixer4();
  _outputAmp = new AudioAmplifier();
  _i2s1 = new AudioOutputI2S();
  _sgtl5000 = new AudioControlSGTL5000();

  _nodesMixer1 = new AudioMixer4();
  _nodesMixer2 = new AudioMixer4();
  _nodesMixer3 = new AudioMixer4();
  _nodesMixer4 = new AudioMixer4();
  _nodesOutputMixer = new AudioMixer4();

  _audioConnections[0] = new AudioConnection(*_nodesMixer1, 0, *_nodesOutputMixer, 0);
  _audioConnections[1] = new AudioConnection(*_nodesMixer2, 0, *_nodesOutputMixer, 1);
  _audioConnections[2] = new AudioConnection(*_nodesMixer3, 0, *_nodesOutputMixer, 2);
  _audioConnections[3] = new AudioConnection(*_nodesMixer4, 0, *_nodesOutputMixer, 3);
  _audioConnections[4] = new AudioConnection(*_nodesOutputMixer, 0, *_filterMixer, 0);
  _audioConnections[5] = new AudioConnection(*_nodesOutputMixer, 0, *_biquad, 0);
  _audioConnections[6] = new AudioConnection(*_biquad, 0, *_filterMixer, 1);
  _audioConnections[7] = new AudioConnection(*_filterMixer, 0, *_bitcrusher, 0);
  _audioConnections[8] = new AudioConnection(*_filterMixer, 0, *_delayMixer, 0);
  _audioConnections[9] = new AudioConnection(*_bitcrusher, 0, *_delayMixer, 1);
  _audioConnections[10] = new AudioConnection(*_delayMixer, 0, *_delay, 0);
  _audioConnections[11] = new AudioConnection(*_delay, 1, *_delayMixer, 3);
  _audioConnections[12] = new AudioConnection(*_delay, 0, *_reverbMixer, 0);
  _audioConnections[13] = new AudioConnection(*_delay, 0, *_freeverb, 0);
  _audioConnections[14] = new AudioConnection(*_freeverb, 0, *_reverbMixer, 1);
  _audioConnections[15] = new AudioConnection(*_reverbMixer, 0, *_outputAmp, 0);
  _audioConnections[16] = new AudioConnection(*_outputAmp, 0, *_i2s1, 0);
  _audioConnections[17] = new AudioConnection(*_outputAmp, 0, *_i2s1, 1);

  setupSGTL5000();
  setupMixers();
  setupEffects();
  setupMusicNodes();
  applyFrequencies();
}
void AudioSystem::setModulationMode(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((SimpleMusicNode*)_ptrSimpleMusicNodes[i])->setModulationMode(value);
  }
}

void AudioSystem::setModulatorFrequency(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((SimpleMusicNode*)_ptrSimpleMusicNodes[i])->setModulatorFrequency(value * 0.10);
  }
}

void AudioSystem::setModulatorAmplitude(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((SimpleMusicNode*)_ptrSimpleMusicNodes[i])->setModulatorAmplitude(value * 0.01);
  }
}

void AudioSystem::setSineAmplitude(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((SimpleMusicNode*)_ptrSimpleMusicNodes[i])->setSineAmplitude(value * 0.01);
  }
}

void AudioSystem::setSawtoothAmplitude(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((SimpleMusicNode*)_ptrSimpleMusicNodes[i])->setSawtoothAmplitude(value * 0.01);
  }
}

void AudioSystem::setupMusicNodes() {
  AdditiveMusicNode* testNode;
  for (int i = 0; i < 4; i++)
  {
    testNode = new AdditiveMusicNode();
    _ptrAdditiveMusicNodes.push_back(testNode);
    _audioConnections[18 + i] = new AudioConnection(*testNode->getOutput(), 0, *_nodesMixer1, i);
  }
  for (int i = 0; i < 4; i++)
  {
    testNode = new AdditiveMusicNode();
    _ptrAdditiveMusicNodes.push_back(testNode);
    _audioConnections[22 + i] = new AudioConnection(*testNode->getOutput(), 0, *_nodesMixer2, i);
  }
  
  SimpleMusicNode* simpleNode;
  for (int i = 0; i < 4; i++)
  {
    simpleNode = new SimpleMusicNode();
    _ptrSimpleMusicNodes.push_back(simpleNode);
    _audioConnections[26 + i] = new AudioConnection(*simpleNode->getOutput(), 0, *_nodesMixer3, i);
  }
  for (int i = 0; i < 4; i++)
  {
    simpleNode = new SimpleMusicNode();
    _ptrSimpleMusicNodes.push_back(simpleNode);
    _audioConnections[30 + i] = new AudioConnection(*simpleNode->getOutput(), 0, *_nodesMixer4, i);
  }
  
}

void AudioSystem::setupSGTL5000() {
  AudioMemory(512);
  _sgtl5000->enable();
  _sgtl5000->volume(0.5);
  _sgtl5000->lineOutLevel(31);
}

void AudioSystem::setupEffects() {
  for (int i = 2; i < 8; i++)
  {
    _delay->disable(i);
  }
  _delay->delay(0, 0.00);
}

void AudioSystem::setupMixers() {
  _nodesMixer1->gain(0, 1.00);
  _nodesMixer1->gain(1, 1.00);
  _nodesMixer1->gain(2, 1.00);
  _nodesMixer1->gain(3, 1.00);

  _nodesMixer2->gain(0, 1.00);
  _nodesMixer2->gain(1, 1.00);
  _nodesMixer2->gain(2, 1.00);
  _nodesMixer2->gain(3, 1.00);

  _nodesMixer3->gain(0, 1.00);
  _nodesMixer3->gain(1, 1.00);
  _nodesMixer3->gain(2, 1.00);
  _nodesMixer3->gain(3, 1.00);

  _nodesMixer4->gain(0, 1.00);
  _nodesMixer4->gain(1, 1.00);
  _nodesMixer4->gain(2, 1.00);
  _nodesMixer4->gain(3, 1.00);

  _nodesOutputMixer->gain(0, 1.00);
  _nodesOutputMixer->gain(1, 1.00);
  _nodesOutputMixer->gain(2, 1.00);
  _nodesOutputMixer->gain(3, 1.00);

  _filterMixer->gain(0, 1.00);
  _filterMixer->gain(1, 0.00);

  _delayMixer->gain(0, 1.00);
  _delayMixer->gain(1, 0.00);

  _reverbMixer->gain(0, 1.00);
  _reverbMixer->gain(1, 0.00);

  _outputAmp->gain(1.00);
}

void AudioSystem::applyFrequencies() {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((AdditiveMusicNode*)_ptrAdditiveMusicNodes[i])->setFrequencies(
      NOTE_FREQS[_keyNote + _scale->getStep(i)],
      NOTE_FREQS[_keyNote + _coarseDetune + _scale->getStep(i)] * pow(2.00, _fineDetune/1200.00)
    );

    ((SimpleMusicNode*)_ptrSimpleMusicNodes[i])->setFrequency(NOTE_FREQS[_keyNote + _scale->getStep(i)]);
  }
}
MusicNode* AudioSystem::getAdditiveNode(int index) {
  return (_ptrAdditiveMusicNodes[index]);
}

MusicNode* AudioSystem::getSimpleNode(int index) {
  return (_ptrSimpleMusicNodes[index]);
}

int AudioSystem::getNumberOfMusicNodes() {
  return _numberOfMusicNodes;
}

int AudioSystem::getNumberOfNotes() {
  return NUMBER_OF_NOTES;
}

String AudioSystem::getNoteName(int index) {
  return NOTE_NAMES[index];
}

int AudioSystem::getNumberOfScales() {
  return NUMBER_OF_SCALES;
}

String AudioSystem::getScaleName(int index) {
  return SCALES[index]->getName();
}

void AudioSystem::applyFilter(int stage) {
  switch (_filterModes[stage])
  {
  case 0:
    _biquad->setHighpass(stage, 1.00 * _filterFrequencies[stage], 0.01 * _filterQs[stage]);
    break;
  case 1:
    _biquad->setLowpass(stage, 1.00 * _filterFrequencies[stage], 0.01 * _filterQs[stage]);
    break;
  case 2:
    _biquad->setBandpass(stage, 1.00 * _filterFrequencies[stage], 0.01 * _filterQs[stage]);
    break;
  case 3:
    _biquad->setNotch(stage, 1.00 * _filterFrequencies[stage], 0.01 * _filterQs[stage]);
    break;
  default:
    break;
  }
}

void AudioSystem::setFilterMode(int stage, int value) {
  _filterModes[stage] = value;
  applyFilter(stage);
}

void AudioSystem::setFilterFrequency(int stage, int value) {
  _filterFrequencies[stage] = value;
  applyFilter(stage);
}

void AudioSystem::setFilterQ(int stage, int value) {
  _filterQs[stage] = value;
  applyFilter(stage);
}

void AudioSystem::setFilterAmount(int value) {
  _filterMixer->gain(0, 1.00 - value * 0.01);
  _filterMixer->gain(1, value * 0.01);
}

void AudioSystem::setDelay(int value) {
  _delay->delay(1, value * 1.00);
}

void AudioSystem::setDelayFade(int value) {
  _delayMixer->gain(3, 1.00 - value * 0.01);
}

void AudioSystem::setBitcrusherAmount(int value) {
  _delayMixer->gain(0, 1.00 - value * 0.01);
  _delayMixer->gain(1, value * 0.01);
}

void AudioSystem::setBits(int value) {
  _bitcrusher->bits(value);
}

void AudioSystem::setSampleRate(int value) {
  _bitcrusher->sampleRate(44100.00 / pow(2.00, 7 - value));
}

void AudioSystem::setReverbAmount(int value) {
  _reverbMixer->gain(0, 1.00 - value * 0.01);
  _reverbMixer->gain(1, value * 0.01);
}
void AudioSystem::setRoomsize(int value) {
  _freeverb->roomsize(value * 0.01);
}

void AudioSystem::setDamping(int value) {
  _freeverb->damping(value * 0.01);
}

void AudioSystem::setKeyNote(int value) {
  _keyNote = value;
  applyFrequencies();
}

void AudioSystem:: setMode(int value) {
  switch (value)
  {
  case 0: activateAdditiveSynth(); break;
  case 1: activateSimpleSynth(); break;
  default: break;
  }
}

void AudioSystem:: setScale(int value) {
  _scale = SCALES[value];
  applyFrequencies();
}

void AudioSystem::setCoarseDetune(int value) {
  _coarseDetune = value;
  applyFrequencies();
}

void AudioSystem::setFineDetune(int value) {
  _fineDetune = value;
  applyFrequencies();
}

void AudioSystem::setWaveform1(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((AdditiveMusicNode*)_ptrAdditiveMusicNodes[i])->setWaveform1(value);
  }
}

void AudioSystem::setWaveform2(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((AdditiveMusicNode*)_ptrAdditiveMusicNodes[i])->setWaveform2(value);
  }
}

void AudioSystem::setWaveform1Amplitude(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((AdditiveMusicNode*)_ptrAdditiveMusicNodes[i])->setWf1Amplitude(value * 0.01);
  }
}

void AudioSystem::setWaveform2Amplitude(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((AdditiveMusicNode*)_ptrAdditiveMusicNodes[i])->setWf2Amplitude(value * 0.01);
  }
}

void AudioSystem::setPinkNoiseAmplitude(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((AdditiveMusicNode*)_ptrAdditiveMusicNodes[i])->setPinkAmplitude(value * 0.01);
  }
}
void AudioSystem::setAttack(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((AdditiveMusicNode*)_ptrAdditiveMusicNodes[i])->setAttack(value * 1.00);
    ((SimpleMusicNode*)_ptrSimpleMusicNodes[i])->setAttack(value * 1.00);    
  }
}

void AudioSystem::setDecay(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((AdditiveMusicNode*)_ptrAdditiveMusicNodes[i])->setDecay(value * 1.00);
    ((SimpleMusicNode*)_ptrSimpleMusicNodes[i])->setDecay(value * 1.00);    
  }
}

void AudioSystem::setSustain(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((AdditiveMusicNode*)_ptrAdditiveMusicNodes[i])->setSustain(value * 0.01);
    ((SimpleMusicNode*)_ptrSimpleMusicNodes[i])->setSustain(value * 0.01);    
  }
}

void AudioSystem::setRelease(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((AdditiveMusicNode*)_ptrAdditiveMusicNodes[i])->setRelease(value * 1.00);
    ((SimpleMusicNode*)_ptrSimpleMusicNodes[i])->setRelease(value * 1.00);    
  }
}

void AudioSystem::setVolume(int value) {
  _outputAmp->gain(value * 0.01);
}

void AudioSystem::addAdditiveMenuBranch(MenuBranch* branch) {
  _ptrAdditiveMenuBranches.push_back(branch);
}

void AudioSystem::addSimpleMenuBranch(MenuBranch* branch) {
  _ptrSimpleMenuBranches.push_back(branch);
}

void AudioSystem::activateAdditiveSynth() {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    _ptrSimpleMusicNodes[i]->deactivate();
    _ptrAdditiveMusicNodes[i]->activate();
  }
  for (int i = 0; i < (int)_ptrSimpleMenuBranches.size(); i++) _ptrSimpleMenuBranches[i]->hide();
  for (int i = 0; i < (int)_ptrAdditiveMenuBranches.size(); i++) _ptrAdditiveMenuBranches[i]->unHide();
}

void AudioSystem::activateSimpleSynth() {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    _ptrAdditiveMusicNodes[i]->deactivate();
    _ptrSimpleMusicNodes[i]->activate();
  }
  for (int i = 0; i < (int)_ptrAdditiveMenuBranches.size(); i++) _ptrAdditiveMenuBranches[i]->hide();
  for (int i = 0; i < (int)_ptrSimpleMenuBranches.size(); i++) _ptrSimpleMenuBranches[i]->unHide();
}