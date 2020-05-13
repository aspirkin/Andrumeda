#ifndef AudioSystem_h_
#define AudioSystem_h_

#include <MusicNode.h>
#include <Audio.h>
#include <Controls.h>
#include <Parameter.h>

class AudioSystem
{
protected:
  MusicNode* _ptrSynthMusicNodes[20];
  Controls* _ptrControls;
public:
  static const int NUMBER_OF_MUSIC_NODES = 8;
  // vector <MusicNode*> _ptrActiveMusicNodes;
  // vector <MusicNode*> _ptrSamplerMusicNodes;

  AudioSystem(Controls* ptrControls);
  MusicNode* getMusicNode(int index);
  virtual void activateSampler() = 0;
  virtual void activateSynth() = 0;
  int getNumberOfMusicNodes();
};

#endif //AudioSystem_h_