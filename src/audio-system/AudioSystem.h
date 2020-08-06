#ifndef AudioSystem_h_
#define AudioSystem_h_

#include <audio-system/music-nodes/AdditiveMusicNode.h>
#include <audio-system/music-nodes/SimpleMusicNode.h>
#include <audio-system/Scale.h>
#include <menus/MenuBranch.h>
#include <WString.h>
#include <vector>

class AudioSystem
{
private:
  std::vector <MusicNode*> _ptrAdditiveMusicNodes;
  std::vector <MusicNode*> _ptrSimpleMusicNodes;
  std::vector <MenuBranch*> _ptrAdditiveMenuBranches;
  std::vector <MenuBranch*> _ptrSimpleMenuBranches;
  int _numberOfMusicNodes;

  const static int NUMBER_OF_NOTES = 88;

  const float NOTE_FREQS[NUMBER_OF_NOTES] = { 27.5, 29.1353, 30.8677, 32.7032,  34.6479, 36.7081, 38.8909, 41.2035, 43.6536, 46.2493, 48.9995, 51.913,
                                              55,   58.2705, 61.7354, 65.4064,  69.2957, 73.4162, 77.7817, 82.4069, 87.3071, 92.4986, 97.9989, 103.826,
                                              110,  116.541, 123.471, 130.813,  138.591, 146.832, 155.563, 164.814, 174.614, 184.997, 195.998, 207.652,
                                              220,  233.082, 246.942, 261.626,  277.183, 293.665, 311.127, 329.628, 349.228, 369.994, 391.995, 415.305,
                                              440,  466.164, 493.883, 523.251,  554.365, 587.33,  622.254, 659.255, 698.456, 739.989, 783.991, 830.609,
                                              880,  932.328, 987.767, 1046.5,   1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22,
                                              1760, 1864.66, 1975.53, 2093,     2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44,
                                              3520, 3729.31, 3951.07, 4186.01};
  const String NOTE_NAMES[NUMBER_OF_NOTES] = {"A0", "A#0", "B0", "C1", "C#1", "D1", "D#1", "E1", "F1", "F#1", "G1", "G#1",
                                              "A1", "A#1", "B1", "C2", "C#2", "D2", "D#2", "E2", "F2", "F#2", "G2", "G#2",
                                              "A2", "A#2", "B2", "C3", "C#3", "D3", "D#3", "E3", "F3", "F#3", "G3", "G#3",
                                              "A3", "A#3", "B3", "C4", "C#4", "D4", "D#4", "E4", "F4", "F#4", "G4", "G#4",
                                              "A4", "A#4", "B4", "C5", "C#5", "D5", "D#5", "E5", "F5", "F#5", "G5", "G#5",
                                              "A5", "A#5", "B5", "C6", "C#6", "D6", "D#6", "E6", "F6", "F#6", "G6", "G#6",
                                              "A6", "A#6", "B6", "C7", "C#7", "D7", "D#7", "E7", "F7", "F#7", "G7", "G#7",
                                              "A7", "A#7", "B7", "C8"};

  AudioMixer4* _nodesMixer1;
  AudioMixer4* _nodesMixer2;
  AudioMixer4* _nodesMixer3;
  AudioMixer4* _nodesMixer4;
  AudioMixer4* _nodesOutputMixer;

  AudioFilterBiquad* _biquad;
  AudioMixer4* _filterMixer;
  AudioEffectBitcrusher* _bitcrusher;
  AudioMixer4* _delayMixer;
  AudioEffectDelay* _delay;
  AudioEffectFreeverb* _freeverb;
  AudioMixer4* _reverbMixer;
  AudioAmplifier* _outputAmp;
  AudioOutputI2S* _i2s1;
  AudioControlSGTL5000* _sgtl5000;
  AudioConnection* _audioConnections[34];

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

  int _filterModes[4] = {0, 0, 0, 0};
  int _filterFrequencies[4] = {500, 500, 500, 500};
  int _filterQs[4] = {50, 50, 50, 50};

  void applyFrequencies();
  void applyFilter(int stage);
  void setupMixers();
  void setupEffects();
  void setupSGTL5000();
  void setupMusicNodes();
public:
  int getNumberOfScales();
  int getNumberOfMusicNodes();
  int getNumberOfNotes();
  String getNoteName(int index);
  String getScaleName(int index);
  MusicNode* getAdditiveNode(int index);
  MusicNode* getSimpleNode(int index);

  AudioSystem(int numberOfMusicNodes);
  void activateAdditiveSynth();
  void activateSimpleSynth();
  void addAdditiveMenuBranch(MenuBranch* branch);
  void addSimpleMenuBranch(MenuBranch* branch);

  //  COMMON
  void setMode(int value);
  void setVolume(int value);
  void setScale(int value);
  void setKeyNote(int value);

  void setAttack(int value);
  void setDecay(int value);
  void setSustain(int value);
  void setRelease(int value);

  //  SIMPLE SYNTH
  void setModulationMode(int value);
  void setModulatorFrequency(int value);
  void setModulatorAmplitude(int value);

  void setSineAmplitude(int value);
  void setSawtoothAmplitude(int value);

  //  ADDITIVE SYNTH
  void setWaveform1Amplitude(int value);
  void setWaveform2Amplitude(int value);
  void setPinkNoiseAmplitude(int value);

  void setWaveform1(int value);
  void setWaveform2(int value);

  void setCoarseDetune(int value);
  void setFineDetune(int value);

  //  EFFECTS
  void setFilterAmount(int value);
  void setFilterMode(int stage, int value);
  void setFilterFrequency(int stage, int value);
  void setFilterQ(int stage, int value);

  void setBitcrusherAmount(int value);
  void setBits(int value);
  void setSampleRate(int value);

  void setDelay(int value);
  void setDelayFade(int value);

  void setReverbAmount(int value);
  void setRoomsize(int value);
  void setDamping(int value);
};

#endif //AudioSystem_h_