#ifndef AudioSystem_h_
#define AudioSystem_h_

#include <MusicNode.h>
#include <Audio.h>
#include <Parameter.h>

class AudioSystem
{
protected:
  MusicNode* _ptrSynthMusicNodes[20];
  //Controls* _ptrControls;
  const float NOTE_FREQS[88] = {27.5, 29.1353, 30.8677, 32.7032,  34.6479, 36.7081, 38.8909, 41.2035, 43.6536, 46.2493, 48.9995, 51.913,
                                55,   58.2705, 61.7354, 65.4064,  69.2957, 73.4162, 77.7817, 82.4069, 87.3071, 92.4986, 97.9989, 103.826,
                                110,  116.541, 123.471, 130.813,  138.591, 146.832, 155.563, 164.814, 174.614, 184.997, 195.998, 207.652,
                                220,  233.082, 246.942, 261.626,  277.183, 293.665, 311.127, 329.628, 349.228, 369.994, 391.995, 415.305,
                                440,  466.164, 493.883, 523.251,  554.365, 587.33,  622.254, 659.255, 698.456, 739.989, 783.991, 830.609,
                                880,  932.328, 987.767, 1046.5,   1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22,
                                1760, 1864.66, 1975.53, 2093,     2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44,
                                3520, 3729.31, 3951.07, 4186.01};

public:
  static const int NUMBER_OF_MUSIC_NODES = 8;
  // vector <MusicNode*> _ptrActiveMusicNodes;
  // vector <MusicNode*> _ptrSamplerMusicNodes;

  AudioSystem();
  MusicNode* getMusicNode(int index);
  virtual void activateSampler() = 0;
  virtual void activateSynth() = 0;
  int getNumberOfMusicNodes();
};

#endif //AudioSystem_h_