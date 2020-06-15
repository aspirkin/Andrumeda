#ifndef TestAudioSystem_h_
#define TestAudioSystem_h_

#include <audio-systems/AudioSystem.h>
#include <audio-systems/test/TestMusicNode.h>
#include <audio-systems/Scale.h>
#include <WString.h>

/*enum class ParameterTag : int {
  PARAM_WF1_AMP,
  PARAM_WF2_AMP,
  PARAM_PINK_AMP
};*/

class TestAudioSystem : public AudioSystem
{
private:
  static const int NUMBER_OF_SCALES = 9;
  Scale* SCALES[NUMBER_OF_SCALES] = {
    new Scale("major",      new int[9]{0, 2, 4, 5, 7, 9, 11, 12, 14}),
    new Scale("minor",      new int[9]{0, 2, 3, 5, 7, 8, 10, 12, 14}),
    new Scale("maj pent",   new int[9]{0, 2, 5, 7, 10, 12, 14, 17, 19}),
    new Scale("min pent",   new int[9]{0, 3, 5, 7, 10, 12, 15, 17, 19}),
    new Scale("phrygian",   new int[9]{0, 2, 3, 5, 7, 9, 10, 12, 14}),
    new Scale("doric",      new int[9]{0, 2, 3, 5, 7, 9, 10, 12, 14}),
    new Scale("mixolyd.",   new int[9]{0, 2, 3, 5, 7, 9, 10, 12, 14}),
    new Scale("lydian",     new int[9]{0, 1, 3, 5, 6, 8, 10, 12, 13}),
    new Scale("hirajoshi",  new int[9]{0, 1, 5, 6, 10, 12, 13, 17, 18})
  };
  int _keyNote = 20;
  int _coarseDetune = 7;
  int _fineDetune = 0;
  Scale* _scale = SCALES[0];
  void applyFrequencies();
  void setupMixers();
  void setupEffects();
  void setupSGTL5000();
  void setupMusicNodes();
public:
  int getNumberOfScales();
  String getScaleName(int index);

  TestAudioSystem(int numberOfMusicNodes);
  void activateSampler();
  void activateSynth();

  void setVolume(int value);

  void setWaveform1Amplitude(int value);
  void setWaveform2Amplitude(int value);
  void setPinkNoiseAmplitude(int value);

  void setAttack(int value);
  void setDecay(int value);
  void setSustain(int value);
  void setRelease(int value);

  void setWaveform1(int value);
  void setWaveform2(int value);

  void setScale(int value);
  void setCoarseDetune(int value);
  void setFineDetune(int value);

  void setBitcrusherAmount(int value);
  void setBits(int value);
  void setSampleRate(int value);

  void setDelay(int value);
  void setDelayFade(int value);

  void setReverbAmount(int value);
  void setRoomsize(int value);
  void setDamping(int value);
};

#endif //TestAudioSystem_h_