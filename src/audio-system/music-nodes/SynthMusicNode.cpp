#include <audio-system/music-nodes/SynthMusicNode.h>

SynthMusicNode::SynthMusicNode() : MusicNode() {
  _modulationOscillator = new AudioSynthWaveform();
  _oscillator1 = new AudioSynthWaveformModulated();
  _oscillator2 = new AudioSynthWaveformModulated();
  _pinkNoise = new AudioSynthNoisePink();
  _quantityFM = new AudioAmplifier();
  _offsetAM = new AudioSynthWaveformDc();
  _oscillatorsMixer = new AudioMixer4();
  _offsetMixerAM = new AudioMixer4();
  _multiplyAM = new AudioEffectMultiply();
  _mixerAM = new AudioMixer4();
  _envelope = new AudioEffectEnvelope();

  _audioConnections[0] = new AudioConnection(*_offsetAM, 0, *_offsetMixerAM, 0);
  _audioConnections[1] = new AudioConnection(*_modulationOscillator, 0, *_offsetMixerAM, 1);
  _audioConnections[2] = new AudioConnection(*_modulationOscillator, 0, *_quantityFM, 0);
  _audioConnections[3] = new AudioConnection(*_quantityFM, 0, *_oscillator1, 0);
  _audioConnections[4] = new AudioConnection(*_quantityFM, 0, *_oscillator2, 0);
  _audioConnections[5] = new AudioConnection(*_oscillator1, 0, *_oscillatorsMixer, 0);
  _audioConnections[6] = new AudioConnection(*_oscillator2, 0, *_oscillatorsMixer, 1);
  _audioConnections[7] = new AudioConnection(*_pinkNoise, 0, *_oscillatorsMixer, 2);
  _audioConnections[8] = new AudioConnection(*_offsetMixerAM, 0, *_multiplyAM, 0);
  _audioConnections[9] = new AudioConnection(*_oscillatorsMixer, 0, *_multiplyAM, 1);
  _audioConnections[10] = new AudioConnection(*_multiplyAM, 0, *_mixerAM, 0);
  _audioConnections[11] = new AudioConnection(*_oscillatorsMixer, 0, *_mixerAM, 1);
  _audioConnections[12] = new AudioConnection(*_mixerAM, 0, *_envelope, 0);
  
  _offsetAM->amplitude(0.5);
  // _sineOsc->begin(WAVEFORM_SINE);
  // _sawtoothOsc->begin(WAVEFORM_SAWTOOTH);
  _oscillatorsMixer->gain(0, 0.5);
  _oscillatorsMixer->gain(1, 0.5);
}

AudioStream* SynthMusicNode::getOutput() {
  return _envelope;
}

void SynthMusicNode::noteOn() {
  if (_isActive) {
    _oscillator1->amplitude(_oscillator1Amplitude);
    _oscillator2->amplitude(_oscillator2Amplitude);
    _modulationOscillator->amplitude(_modulationAmplitude);
    _pinkNoise->amplitude(_pinkNoiseAmplitude);
    _envelope->noteOn();
  }
}

void SynthMusicNode::noteOff() {
  if (_isActive) _envelope->noteOff();
}

void SynthMusicNode::setVelocity(int velocity) {}

void SynthMusicNode::activate() {
  _isActive = true;
}

void SynthMusicNode::deactivate() {
  _isActive = false;
    _oscillator1->amplitude(0.00);
    _oscillator2->amplitude(0.00);
    _modulationOscillator->amplitude(0.00);
    _pinkNoise->amplitude(0.00);
}

void SynthMusicNode::setOscillator1Frequency(float value) {
  _oscillator1->frequency(value);
}
void SynthMusicNode::setOscillator1Waveform(int value) {
  _oscillator1->begin(value);
}
void SynthMusicNode::setOscillator1Amplitude(float value) {
  _oscillator1Amplitude = value;
  _oscillator1->amplitude(_oscillator1Amplitude);
}

void SynthMusicNode::setOscillator2Frequency(float value) {
  _oscillator2->frequency(value);
}
void SynthMusicNode::setOscillator2Waveform(int value) {
  _oscillator2->begin(value);
}
void SynthMusicNode::setOscillator2Amplitude(float value) {
  _oscillator2Amplitude = value;
  _oscillator2->amplitude(_oscillator2Amplitude);
}

void SynthMusicNode::setPinkNoiseAmplitude(float value) {
  _pinkNoiseAmplitude = value;
  _pinkNoise->amplitude(_pinkNoiseAmplitude);
}

void SynthMusicNode::setModulationMode(int mode) {
  switch(mode){
    case 0 : _modulationMode = FM;    break;
    case 1 : _modulationMode = AM;    break;
    case 2 : _modulationMode = RING;  break;
    case 3 : _modulationMode = AM_FM;  break;
  }

  switch(_modulationMode){
    case FM:
      _quantityFM->gain(1.00);
      _offsetMixerAM->gain(0, 0);
      _offsetMixerAM->gain(1, 0);
    break;
    case AM:
      _quantityFM->gain(0.00);
      _offsetMixerAM->gain(0, 1);
      _offsetMixerAM->gain(1, 1);
    break;
    case AM_FM:
      _offsetMixerAM->gain(0, 1);
      _offsetMixerAM->gain(1, 1);
    break;
    case RING:
      _quantityFM->gain(0.00);
      _offsetMixerAM->gain(0, 0);
      _offsetMixerAM->gain(1, 1);
    break;
  }
  applyModulationAmplitude();
}
void SynthMusicNode::setModulationWaveform(int value) {
  _modulationOscillator->begin(value);
}
void SynthMusicNode::setModulationFrequency(float value) {
  _modulationOscillator->frequency(value);
}
void SynthMusicNode::setModulationAmplitude(float value) {
  _modulationAmplitude = value;
  applyModulationAmplitude();
}
void SynthMusicNode::applyModulationAmplitude() {
  switch(_modulationMode){
    case AM:
      _modulationOscillator->amplitude(0.5);
      _mixerAM->gain(1, 1 - _modulationAmplitude*4);
      _mixerAM->gain(0, _modulationAmplitude*4);
    break;
    case AM_FM:
      _quantityFM->gain(_modulationAmplitude * 2);
      _modulationOscillator->amplitude(0.5);
      _mixerAM->gain(1, 1 - _modulationAmplitude*4);
      _mixerAM->gain(0, _modulationAmplitude*4);
    break;
    case RING:
      _mixerAM->gain(1, 1 - _modulationAmplitude*4);
      _mixerAM->gain(0, _modulationAmplitude*4);
    break;
    default:
      _modulationOscillator->amplitude(_modulationAmplitude);
    break;
  }
}

void SynthMusicNode::setAttack(float value) {
  _envelope->attack(value);
}

void SynthMusicNode::setDecay(float value) {
  _envelope->decay(value);
}

void SynthMusicNode::setSustain(float value) {
  _envelope->sustain(value);
}

void SynthMusicNode::setRelease(float value) {
  _envelope->release(value);
}
