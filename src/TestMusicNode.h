#ifndef TestMusicNode_h_
#define TestMusicNode_h_

#include <MusicNode.h>
#include <Audio.h>

class TestMusicNode : public MusicNode
{
private:
  float _wf1Amp = 0.5;
  float _wf2Amp = 0.5;
  float _pinkAmp = 0.5;
  AudioSynthWaveform* _waveform1;
  AudioSynthWaveform* _waveform2;
  AudioSynthNoisePink* _noisePink;

public:
  TestMusicNode(AudioSynthWaveform &nodeWaveform1,
                AudioSynthWaveform &nodeWaveform2,
                AudioSynthNoisePink &nodeNoisePink);
  void noteOn();
  void noteOff();
  void setVelocity(int velocity);
  void activate();
  void deactivate();

  void setWf1Amplitude(float value);
  void setWf2Amplitude(float value);
  void setPinkAmplitude(float value);

  void printAmps();
};

#endif //TestMusicNode_h_