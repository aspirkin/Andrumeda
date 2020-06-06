#include <audio-systems/test/TestAudioSystem.h>
#include <audio-systems/test/AudioObjects.h>

TestAudioSystem::TestAudioSystem(int numberOfMusicNodes) : AudioSystem(numberOfMusicNodes){
  setupSGTL5000();
  setupMixers();
  setupMusicNodes();
  applyFrequencies();
}

void TestAudioSystem::setupMusicNodes() {
  _ptrSynthMusicNodes.push_back(new TestMusicNode(waveform1, waveform2, pink1, envelope1));
  _ptrSynthMusicNodes.push_back(new TestMusicNode(waveform3, waveform4, pink2, envelope2));
  _ptrSynthMusicNodes.push_back(new TestMusicNode(waveform5, waveform6, pink3, envelope3));
  _ptrSynthMusicNodes.push_back(new TestMusicNode(waveform7, waveform8, pink4, envelope4));
  _ptrSynthMusicNodes.push_back(new TestMusicNode(waveform9, waveform10, pink5, envelope5));
  _ptrSynthMusicNodes.push_back(new TestMusicNode(waveform11, waveform12, pink6, envelope6));
  _ptrSynthMusicNodes.push_back(new TestMusicNode(waveform13, waveform14, pink7, envelope7));
  _ptrSynthMusicNodes.push_back(new TestMusicNode(waveform15, waveform16, pink8, envelope8));
}

void TestAudioSystem::setupSGTL5000() {
  AudioMemory(512);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
  sgtl5000_1.lineOutLevel(31);
}

void TestAudioSystem::setupMixers() {
  mixer1.gain(0, 1.00);
  mixer1.gain(1, 1.00);
  mixer1.gain(2, 1.00);

  mixer2.gain(0, 1.00);
  mixer2.gain(1, 1.00);
  mixer2.gain(2, 1.00);

  mixer3.gain(0, 1.00);
  mixer3.gain(1, 1.00);
  mixer3.gain(2, 1.00);

  mixer4.gain(0, 1.00);
  mixer4.gain(1, 1.00);
  mixer4.gain(2, 1.00);

  mixer5.gain(0, 1.00);
  mixer5.gain(1, 1.00);
  mixer5.gain(2, 1.00);

  mixer6.gain(0, 1.00);
  mixer6.gain(1, 1.00);
  mixer6.gain(2, 1.00);

  mixer7.gain(0, 1.00);
  mixer7.gain(1, 1.00);
  mixer7.gain(2, 1.00);

  mixer8.gain(0, 1.00);
  mixer8.gain(1, 1.00);
  mixer8.gain(2, 1.00);

  mixer9.gain(0, 1.00);
  mixer9.gain(1, 1.00);
  mixer9.gain(2, 1.00);
  mixer9.gain(3, 1.00);

  mixer10.gain(0, 1.00);
  mixer10.gain(1, 1.00);
  mixer10.gain(2, 1.00);
  mixer10.gain(3, 1.00);

  mixer11.gain(0, 1.00);
  mixer11.gain(1, 1.00);
}

void TestAudioSystem::applyFrequencies() {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setFrequencies(
      NOTE_FREQS[_keyNote + _scale->getStep(i)],
      NOTE_FREQS[_keyNote + _coarseDetune + _scale->getStep(i)]
    );
  }
}

int TestAudioSystem::getNumberOfScales() {
  return NUMBER_OF_SCALES;
}

String TestAudioSystem::getScaleName(int index) {
  return SCALES[index]->getName();
}

void TestAudioSystem::setScale(int value) {
  _scale = SCALES[value];
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

void TestAudioSystem::setWaveform1Amplitude(float value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setWf1Amplitude(value);
  }
}

void TestAudioSystem::setWaveform2Amplitude(float value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setWf2Amplitude(value);
  }
}

void TestAudioSystem::setPinkNoiseAmplitude(float value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setPinkAmplitude(value);
  }
}
void TestAudioSystem::setAttack(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setAttack(value);
  }
}

void TestAudioSystem::setDecay(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setDecay(value);
  }
}

void TestAudioSystem::setSustain(float value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setSustain(value);
  }
}

void TestAudioSystem::setRelease(int value) {
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setRelease(value);
  }
}

void TestAudioSystem::activateSampler() {};

void TestAudioSystem::activateSynth() {};
