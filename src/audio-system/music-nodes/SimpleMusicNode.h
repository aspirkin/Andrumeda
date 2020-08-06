#ifndef SimpleMusicNode_h_
#define SimpleMusicNode_h_

#include <audio-system/MusicNode.h>

enum synthModes {FM, AM, RING};

class SimpleMusicNode : public MusicNode
{
private:
  AudioSynthWaveform* _sineModulatorOsc;
  AudioSynthWaveformModulated* _sineOsc;
  AudioSynthWaveformModulated* _sawtoothOsc;
  AudioAmplifier* _fmQuantity;
  AudioSynthWaveformDc* _dcAM;
  AudioMixer4* _oscMixer;
  AudioMixer4* _mixerDcMod;
  AudioEffectMultiply* _multiplyAM;
  AudioMixer4* _mixerAM;
  AudioEffectEnvelope* _envelope;
  AudioConnection* _audioConnections[12];

  int _synthMode;
  float _sineAmp = 1.00;
  float _sawAmp = 1.00;

public:
  SimpleMusicNode();
  AudioStream * getOutput();
  void noteOn();
  void noteOff();
  void setVelocity(int velocity);
  void activate();
  void deactivate();

  void setFrequency(float value);
  void setSineAmplitude(float value);
  void setSawtoothAmplitude(float value);

  void setModulationMode(int mode);
  void setModulatorFrequency(float value);
  void setModulatorAmplitude(float value);

  void setAttack(float value);
  void setDecay(float value);
  void setSustain(float value);
  void setRelease(float value);
};

#endif  //SimpleMusicNode_h_