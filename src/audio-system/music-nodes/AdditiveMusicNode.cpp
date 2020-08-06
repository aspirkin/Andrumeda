#include <audio-system/music-nodes/AdditiveMusicNode.h>

AdditiveMusicNode::AdditiveMusicNode() : MusicNode(){
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

  deactivate();
}

AudioStream* AdditiveMusicNode::getOutput() {
  return _envelope;
}

void AdditiveMusicNode::noteOn() {
  if (_isActive) {
    _waveform1->amplitude(_wf1Amp);
    _waveform2->amplitude(_wf2Amp);
    _noisePink->amplitude(_pinkAmp);
    _envelope->noteOn();
  }
}

void AdditiveMusicNode::noteOff() {
  if (_isActive) _envelope->noteOff();
}

void AdditiveMusicNode::setVelocity(int velocity) {}

void AdditiveMusicNode::activate() {
  _isActive = true;
}

void AdditiveMusicNode::deactivate() {
  _isActive = false;
  _waveform1->amplitude(0.00);
  _waveform2->amplitude(0.00);
  _noisePink->amplitude(0.00);
}

void AdditiveMusicNode::setFrequencies(float frequency1, float frequency2) {
  _waveform1->frequency(frequency1);
  _waveform2->frequency(frequency2);
}

void AdditiveMusicNode::setWaveform1(int value) {
  _waveform1->begin(value);
}

void AdditiveMusicNode::setWaveform2(int value) {
  _waveform2->begin(value);
}

void AdditiveMusicNode::setWf1Amplitude(float value) {
  _wf1Amp = value;
  _waveform1->amplitude(_wf1Amp);
}

void AdditiveMusicNode::setWf2Amplitude(float value) {
  _wf2Amp = value;
  _waveform2->amplitude(_wf2Amp);
}

void AdditiveMusicNode::setPinkAmplitude(float value) {
  _pinkAmp = value;
  _noisePink->amplitude(_pinkAmp);
}

void AdditiveMusicNode::setAttack(float value) {
  _envelope->attack(value);
}

void AdditiveMusicNode::setDecay(float value) {
  _envelope->decay(value);
}

void AdditiveMusicNode::setSustain(float value) {
  _envelope->sustain(value);
}

void AdditiveMusicNode::setRelease(float value) {
  _envelope->release(value);
}
