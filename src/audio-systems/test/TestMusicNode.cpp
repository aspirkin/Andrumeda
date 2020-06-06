#include <audio-systems/test/TestMusicNode.h>

TestMusicNode::TestMusicNode(AudioSynthWaveform &nodeWaveform1,
                             AudioSynthWaveform &nodeWaveform2,
                             AudioSynthNoisePink &nodeNoisePink,
                             AudioEffectEnvelope &nodeEnvelope) : MusicNode(){
  _waveform1 = &nodeWaveform1;
  _waveform2 = &nodeWaveform2;
  _noisePink = &nodeNoisePink;
  _envelope = &nodeEnvelope;

  noteOff();
}

void TestMusicNode::noteOn() {
  _envelope->noteOn();
}

void TestMusicNode::noteOff() {
  _envelope->noteOff();
}

void TestMusicNode::setVelocity(int velocity) {}

void TestMusicNode::activate() {}

void TestMusicNode::deactivate() {}

void TestMusicNode::setFrequencies(float frequency1, float frequency2) {
  _waveform1->frequency(frequency1);
  _waveform2->frequency(frequency2);
}

void TestMusicNode::setWaveform1(int value) {
  _waveform1->begin(value);
}

void TestMusicNode::setWaveform2(int value) {
  _waveform2->begin(value);
}

void TestMusicNode::setWf1Amplitude(float value) {
  _wf1Amp = value;
  _waveform1->amplitude(_wf1Amp);
}

void TestMusicNode::setWf2Amplitude(float value) {
  _wf2Amp = value;
  _waveform2->amplitude(_wf2Amp);
}

void TestMusicNode::setPinkAmplitude(float value) {
  _pinkAmp = value;
  _noisePink->amplitude(_pinkAmp);
}

void TestMusicNode::setAttack(int value) {
  _envelope->attack(1.00 * value);
}

void TestMusicNode::setDecay(int value) {
  _envelope->decay(1.00 * value);
}

void TestMusicNode::setSustain(float value) {
  _envelope->sustain(value);
}

void TestMusicNode::setRelease(int value) {
  _envelope->release(1.00 * value);
}
