#include <audio-systems/test/SimpleMusicNode.h>

SimpleMusicNode::SimpleMusicNode() : MusicNode() {
  _sineModulatorOsc = new AudioSynthWaveform();
  _sineOsc = new AudioSynthWaveformModulated();
  _sawtoothOsc = new AudioSynthWaveformModulated();
  _fmQuantity = new AudioAmplifier();
  _dcAM = new AudioSynthWaveformDc();
  _oscMixer = new AudioMixer4();
  _mixerDcMod = new AudioMixer4();
  _multiplyAM = new AudioEffectMultiply();
  _mixerAM = new AudioMixer4();
  _envelope = new AudioEffectEnvelope();
  _outputMixer = new AudioMixer4();

  //  TODO: Setup mixers etc.
  
  _audioConnections[0] = new AudioConnection(*_dcAM, 0, *_mixerDcMod, 0);
  _audioConnections[1] = new AudioConnection(*_sineModulatorOsc, 0, *_mixerDcMod, 1);
  _audioConnections[2] = new AudioConnection(*_sineModulatorOsc, 0, *_fmQuantity, 0);
  _audioConnections[3] = new AudioConnection(*_fmQuantity, 0, *_sineOsc, 0);
  _audioConnections[4] = new AudioConnection(*_fmQuantity, 0, *_sawtoothOsc, 0);
  _audioConnections[5] = new AudioConnection(*_sineOsc, 0, *_oscMixer, 0);
  _audioConnections[6] = new AudioConnection(*_sawtoothOsc, 0, *_oscMixer, 1);
  _audioConnections[7] = new AudioConnection(*_mixerDcMod, 0, *_multiplyAM, 0);
  _audioConnections[8] = new AudioConnection(*_oscMixer, 0, *_multiplyAM, 1);
  _audioConnections[9] = new AudioConnection(*_multiplyAM, 0, *_mixerAM, 0);
  _audioConnections[10] = new AudioConnection(*_oscMixer, 0, *_mixerAM, 1);
  _audioConnections[11] = new AudioConnection(*_mixerAM, 0, *_envelope, 0);
  _audioConnections[12] = new AudioConnection(*_envelope, 0, *_outputMixer, 0);
  _audioConnections[13] = new AudioConnection(*_mixerAM, 0, *_outputMixer, 1);
  
  noteOff();
}

AudioMixer4* SimpleMusicNode::getOutput() {
  return _outputMixer;
}

void SimpleMusicNode::noteOn() {
  _envelope->noteOn();
}

void SimpleMusicNode::noteOff() {
  _envelope->noteOff();
}

void SimpleMusicNode::setVelocity(int velocity) {}

void SimpleMusicNode::activate() {}

void SimpleMusicNode::deactivate() {}

