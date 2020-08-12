#ifndef SynthMusicNode_h_
#define SynthMusicNode_h_

#include <audio-system/MusicNode.h>

enum modulationModes {FM, AM, RING, AM_FM};

class SynthMusicNode : public MusicNode
{
private:
  float _oscillator1Amplitude;
  float _oscillator2Amplitude;
  float _pinkNoiseAmplitude;
  float _modulationAmplitude;
  
  int _modulationMode;

  AudioSynthWaveform* _modulationOscillator;
  AudioSynthWaveformModulated* _oscillator1;
  AudioSynthWaveformModulated* _oscillator2;
  AudioSynthNoisePink* _pinkNoise;
  AudioAmplifier* _quantityFM;
  AudioSynthWaveformDc* _offsetAM;
  AudioMixer4* _oscillatorsMixer;
  AudioMixer4* _offsetMixerAM;
  AudioEffectMultiply* _multiplyAM;
  AudioMixer4* _mixerAM;
  AudioEffectEnvelope* _envelope;
  AudioConnection* _audioConnections[13];

public:
  SynthMusicNode();
  AudioStream* getOutput();
  void noteOn();
  void noteOff();
  void setVelocity(int velocity);
  void activate();
  void deactivate();

  void setOscillator1Frequency(float value);
  void setOscillator1Waveform(int value);
  void setOscillator1Amplitude(float value);

  void setOscillator2Frequency(float value);
  void setOscillator2Waveform(int value);
  void setOscillator2Amplitude(float value);

  void setPinkNoiseAmplitude(float value);

  void setModulationMode(int mode);
  void setModulationWaveform(int value);
  void setModulationFrequency(float value);
  void setModulationAmplitude(float value);
  void applyModulationAmplitude();

  void setAttack(float value);
  void setDecay(float value);
  void setSustain(float value);
  void setRelease(float value);
};


#endif //SynthMusicNode_h_