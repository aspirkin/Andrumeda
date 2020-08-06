#include <audio-system/music-nodes/SimpleMusicNode.h>

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
  
  _dcAM->amplitude(0.5);
  _sineOsc->begin(WAVEFORM_SINE);
  // _sineOsc->amplitude(_sineAmp);
  _sawtoothOsc->begin(WAVEFORM_SAWTOOTH);
  // _sawtoothOsc->amplitude(_sawAmp);
  _oscMixer->gain(0, 0.5);
  _oscMixer->gain(1, 0.5);
  // _mixerAM->gain(0, 1);
  // _mixerAM->gain(1, 0);
  // _sineModulatorOsc->amplitude(0.5);
  // _sineModulatorOsc->begin(WAVEFORM_SINE);
  // _fmQuantity->gain(0.00);
  // _mixerDcMod->gain(0, 1);
  // _mixerDcMod->gain(1, 1);

  deactivate();
}

AudioStream* SimpleMusicNode::getOutput() {
  return _envelope;
}

void SimpleMusicNode::noteOn() {
  if (_isActive) {
    _sineOsc->amplitude(_sineAmp);
    _sawtoothOsc->amplitude(_sawAmp);
    _envelope->noteOn();
  }
}

void SimpleMusicNode::noteOff() {
  if (_isActive) _envelope->noteOff();
}

void SimpleMusicNode::setVelocity(int velocity) {}

void SimpleMusicNode::activate() {
  _isActive = true;
}

void SimpleMusicNode::deactivate() {
  _isActive = false;
  _sineOsc->amplitude(0.00);
  _sawtoothOsc->amplitude(0.00);
}

void SimpleMusicNode::setFrequency(float value) {
  _sineOsc->frequency(value);
  _sawtoothOsc->frequency(value);
}

void SimpleMusicNode::setModulatorFrequency(float value) {
  _sineModulatorOsc->frequency(value);
}

void SimpleMusicNode::setSineAmplitude(float value) {
  _sineAmp = value;
  _sineOsc->amplitude(_sineAmp);
}

void SimpleMusicNode::setSawtoothAmplitude(float value) {
  _sawAmp = value;
  _sawtoothOsc->amplitude(_sawAmp);
}

void SimpleMusicNode::setModulatorAmplitude(float value) {
  switch(_synthMode){
    case AM:
      _sineModulatorOsc->amplitude(0.5);
      _mixerAM->gain(1, 1 - value*4);
      _mixerAM->gain(0, value*4);
    break;
    case RING:
      _mixerAM->gain(1, 1 - value*4);
      _mixerAM->gain(0, value*4);
    break;
    default:
      _sineModulatorOsc->amplitude(value);
    break;
  }
  
}

void SimpleMusicNode::setAttack(float value) {
  _envelope->attack(value);
}

void SimpleMusicNode::setDecay(float value) {
  _envelope->decay(value);
}

void SimpleMusicNode::setSustain(float value) {
  _envelope->sustain(value);
}

void SimpleMusicNode::setRelease(float value) {
  _envelope->release(value);
}

void SimpleMusicNode::setModulationMode(int mode) {
  switch(mode){
    case 0 : _synthMode = FM;    break;
    case 1 : _synthMode = AM;    break;
    case 2 : _synthMode = RING;  break;
  }

  switch(_synthMode){
    case FM:
      _fmQuantity->gain(1.00);
      // _mixerAM->gain(0, 0 );
      // _mixerAM->gain(1, 1);
      _mixerDcMod->gain(0, 0);
      _mixerDcMod->gain(1, 0);
    break;
    case AM:
      _fmQuantity->gain(0.00);
      // _mixerAM->gain(0, 1 );
      // _mixerAM->gain(1, 0);
      _mixerDcMod->gain(0, 1);
      _mixerDcMod->gain(1, 1);
    break;
    case RING:
      _fmQuantity->gain(0.00);
      // _mixerAM->gain(0, 1 );
      // _mixerAM->gain(1, 0);
      _mixerDcMod->gain(0, 0);
      _mixerDcMod->gain(1, 1);
    break;
  }
}
