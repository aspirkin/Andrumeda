#ifndef AdditiveMusicNode_h_
#define AdditiveMusicNode_h_

#include <audio-system/MusicNode.h>

class AdditiveMusicNode : public MusicNode
{
private:
  float _wf1Amp = 0.5;
  float _wf2Amp = 0.5;
  float _pinkAmp = 0.5;
  AudioSynthWaveform* _waveform1;
  AudioSynthWaveform* _waveform2;
  AudioSynthNoisePink* _noisePink;
  AudioEffectEnvelope* _envelope;
  AudioMixer4* _mixer;
  AudioConnection* _audioConnections[4];

public:
  AdditiveMusicNode();
  AudioStream* getOutput();
  void noteOn();
  void noteOff();
  void setVelocity(int velocity);
  void activate();
  void deactivate();

  void setFrequencies(float frequency1, float frequency2);

  void setWf1Amplitude(float value);
  void setWf2Amplitude(float value);
  void setPinkAmplitude(float value);

  void setAttack(float value);
  void setDecay(float value);
  void setSustain(float value);
  void setRelease(float value);

  void setWaveform1(int value);
  void setWaveform2(int value);
};

#endif //AdditiveMusicNode_h_