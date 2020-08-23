#ifndef MusicNode_h_
#define MusicNode_h_

#include <Audio.h>

class MusicNode
{
protected:
  bool _isActive = true;
public:
  MusicNode() {};
  virtual void noteOn();
  virtual void noteOff();
  virtual void setVelocity(int velocity);
  virtual void activate();
  virtual void deactivate() {};
  virtual AudioStream* getOutput();
};

#endif //MusicNode_h_