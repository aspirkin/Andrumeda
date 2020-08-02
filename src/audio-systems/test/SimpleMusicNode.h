#ifndef SimpleMusicNode_h_
#define SimpleMusicNode_h_

#include <audio-systems/MusicNode.h>
#include <Audio.h>

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
  AudioMixer4* _outputMixer;
  AudioConnection* _audioConnections[14];

public:
  SimpleMusicNode();
  AudioMixer4 * getOutput();
  void noteOn();
  void noteOff();
  void setVelocity(int velocity);
  void activate();
  void deactivate();

  // void setFrequencies(float frequency1, float frequency2);

  // void setWf1Amplitude(float value);
  // void setWf2Amplitude(float value);
  // void setPinkAmplitude(float value);

  // void setAttack(float value);
  // void setDecay(float value);
  // void setSustain(float value);
  // void setRelease(float value);

  // void setWaveform1(int value);
  // void setWaveform2(int value);
};

#endif  //SimpleMusicNode_h_