#include <audio-systems/test/TestAudioSystem.h>

TestAudioSystem::TestAudioSystem(int numberOfMusicNodes) : AudioSystem(numberOfMusicNodes){
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
  _nodesOutputMixer = new AudioMixer4();

  _audioConnections[0] = new AudioConnection(*_nodesMixer1, 0, *_nodesOutputMixer, 0);
  _audioConnections[1] = new AudioConnection(*_nodesMixer2, 0, *_nodesOutputMixer, 1);
  _audioConnections[2] = new AudioConnection(*_nodesOutputMixer, 0, *_filterMixer, 0);
  _audioConnections[3] = new AudioConnection(*_nodesOutputMixer, 0, *_biquad, 0);
  _audioConnections[4] = new AudioConnection(*_biquad, 0, *_filterMixer, 1);
  _audioConnections[5] = new AudioConnection(*_filterMixer, 0, *_bitcrusher, 0);
  _audioConnections[6] = new AudioConnection(*_filterMixer, 0, *_delayMixer, 0);
  _audioConnections[7] = new AudioConnection(*_bitcrusher, 0, *_delayMixer, 1);
  _audioConnections[8] = new AudioConnection(*_delayMixer, 0, *_delay, 0);
  _audioConnections[9] = new AudioConnection(*_delay, 1, *_delayMixer, 3);
  _audioConnections[10] = new AudioConnection(*_delay, 0, *_reverbMixer, 0);
  _audioConnections[11] = new AudioConnection(*_delay, 0, *_freeverb, 0);
  _audioConnections[12] = new AudioConnection(*_freeverb, 0, *_reverbMixer, 1);
  _audioConnections[13] = new AudioConnection(*_reverbMixer, 0, *_outputAmp, 0);
  _audioConnections[14] = new AudioConnection(*_outputAmp, 0, *_i2s1, 0);
  _audioConnections[15] = new AudioConnection(*_outputAmp, 0, *_i2s1, 1);

  setupSGTL5000();
  setupMixers();
  setupEffects();
  setupMusicNodes();
  applyFrequencies();
}

void TestAudioSystem::setupMusicNodes() {
  TestMusicNode* currentNode;
  for (int i = 0; i < 4; i++)
  {
    currentNode = new TestMusicNode();
    _ptrSynthMusicNodes.push_back(currentNode);
    _audioConnections[16 + i] = new AudioConnection(*currentNode->getOutput(), 0, *_nodesMixer1, i);
  }
  for (int i = 0; i < 4; i++)
  {
    currentNode = new TestMusicNode();
    _ptrSynthMusicNodes.push_back(currentNode);
    _audioConnections[20 + i] = new AudioConnection(*currentNode->getOutput(), 0, *_nodesMixer2, i);
  }
  
}

void TestAudioSystem::setupSGTL5000() {
  AudioMemory(512);
  _sgtl5000->enable();
  _sgtl5000->volume(0.5);
  _sgtl5000->lineOutLevel(31);
}

void TestAudioSystem::setupEffects() {
  for (int i = 2; i < 8; i++)
  {
    _delay->disable(i);
  }
  _delay->delay(0, 0.00);
}

void TestAudioSystem::setupMixers() {
  _nodesMixer1->gain(0, 1.00);
  _nodesMixer1->gain(1, 1.00);
  _nodesMixer1->gain(2, 1.00);
  _nodesMixer1->gain(3, 1.00);

  _nodesMixer2->gain(0, 1.00);
  _nodesMixer2->gain(1, 1.00);
  _nodesMixer2->gain(2, 1.00);
  _nodesMixer2->gain(3, 1.00);

  _nodesOutputMixer->gain(0, 1.00);
  _nodesOutputMixer->gain(1, 1.00);

  _filterMixer->gain(0, 1.00);
  _filterMixer->gain(1, 0.00);

  _delayMixer->gain(0, 1.00);
  _delayMixer->gain(1, 0.00);

  _reverbMixer->gain(0, 1.00);
  _reverbMixer->gain(1, 0.00);

  _outputAmp->gain(1.00);
}

void TestAudioSystem::applyFrequencies() {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setFrequencies(
      NOTE_FREQS[_keyNote + _scale->getStep(i)],
      NOTE_FREQS[_keyNote + _coarseDetune + _scale->getStep(i)] * pow(2.00, _fineDetune/1200.00)
    );
  }
}

int TestAudioSystem::getNumberOfScales() {
  return NUMBER_OF_SCALES;
}

String TestAudioSystem::getScaleName(int index) {
  return SCALES[index]->getName();
}

void TestAudioSystem::applyFilter(int stage) {
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

void TestAudioSystem::setFilterMode(int stage, int value) {
  _filterModes[stage] = value;
  applyFilter(stage);
}

void TestAudioSystem::setFilterFrequency(int stage, int value) {
  _filterFrequencies[stage] = value;
  applyFilter(stage);
}

void TestAudioSystem::setFilterQ(int stage, int value) {
  _filterQs[stage] = value;
  applyFilter(stage);
}

void TestAudioSystem::setFilterAmount(int value) {
  _filterMixer->gain(0, 1.00 - value * 0.01);
  _filterMixer->gain(1, value * 0.01);
}

void TestAudioSystem::setDelay(int value) {
  _delay->delay(1, value * 1.00);
}

void TestAudioSystem::setDelayFade(int value) {
  _delayMixer->gain(3, 1.00 - value * 0.01);
}

void TestAudioSystem::setBitcrusherAmount(int value) {
  _delayMixer->gain(0, 1.00 - value * 0.01);
  _delayMixer->gain(1, value * 0.01);
}

void TestAudioSystem::setBits(int value) {
  _bitcrusher->bits(value);
}

void TestAudioSystem::setSampleRate(int value) {
  _bitcrusher->sampleRate(44100.00 / pow(2.00, 7 - value));
}

void TestAudioSystem::setReverbAmount(int value) {
  _reverbMixer->gain(0, 1.00 - value * 0.01);
  _reverbMixer->gain(1, value * 0.01);
}
void TestAudioSystem::setRoomsize(int value) {
  _freeverb->roomsize(value * 0.01);
}

void TestAudioSystem::setDamping(int value) {
  _freeverb->damping(value * 0.01);
}

void TestAudioSystem::setKeyNote(int value) {
  _keyNote = value;
  applyFrequencies();
}

void TestAudioSystem::setScale(int value) {
  _scale = SCALES[value];
  applyFrequencies();
}

void TestAudioSystem::setCoarseDetune(int value) {
  _coarseDetune = value;
  applyFrequencies();
}

void TestAudioSystem::setFineDetune(int value) {
  _fineDetune = value;
  applyFrequencies();
}

void TestAudioSystem::setWaveform1(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setWaveform1(value);
  }
}

void TestAudioSystem::setWaveform2(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setWaveform2(value);
  }
}

void TestAudioSystem::setWaveform1Amplitude(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setWf1Amplitude(value * 0.01);
  }
}

void TestAudioSystem::setWaveform2Amplitude(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setWf2Amplitude(value * 0.01);
  }
}

void TestAudioSystem::setPinkNoiseAmplitude(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setPinkAmplitude(value * 0.01);
  }
}
void TestAudioSystem::setAttack(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setAttack(value * 1.00);
  }
}

void TestAudioSystem::setDecay(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setDecay(value * 1.00);
  }
}

void TestAudioSystem::setSustain(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setSustain(value * 0.01);
  }
}

void TestAudioSystem::setRelease(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setRelease(value * 1.00);
  }
}

void TestAudioSystem::setVolume(int value) {
  _outputAmp->gain(value * 0.01);
}

void TestAudioSystem::activateSampler() {};

void TestAudioSystem::activateSynth() {};
