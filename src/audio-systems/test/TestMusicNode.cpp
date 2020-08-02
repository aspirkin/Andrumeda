#include <audio-systems/test/TestMusicNode.h>

TestMusicNode::TestMusicNode() : MusicNode(){
  _waveform1 = new AudioSynthWaveform();
  _waveform2 = new AudioSynthWaveform();
  _noisePink = new AudioSynthNoisePink();
  _envelope = new AudioEffectEnvelope();
  _mixer = new AudioMixer4();
  _mixer->gain(0, 1.00);
  _mixer->gain(1, 1.00);
  _mixer->gain(2, 1.00);

  _audioConnections[0] = new AudioConnection(*_waveform1, 0, *_mixer, 0);
  _audioConnections[1] = new AudioConnection(*_waveform2, 0, *_mixer, 1);
  _audioConnections[2] = new AudioConnection(*_noisePink, 0, *_mixer, 2);
  _audioConnections[3] = new AudioConnection(*_mixer, 0, *_envelope, 0);

  noteOff();
}

AudioEffectEnvelope* TestMusicNode::getOutput() {
  return _envelope;
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

void TestMusicNode::setAttack(float value) {
  _envelope->attack(value);
}

void TestMusicNode::setDecay(float value) {
  _envelope->decay(value);
}

void TestMusicNode::setSustain(float value) {
  _envelope->sustain(value);
}

void TestMusicNode::setRelease(float value) {
  _envelope->release(value);
}
