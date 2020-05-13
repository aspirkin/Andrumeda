#ifndef MusicNode_h_
#define MusicNode_h_

class MusicNode
{
protected:
  bool _isActive = false;
public:
  MusicNode();
  virtual void noteOn();
  virtual void noteOff();
  virtual void setVelocity(int velocity);
  virtual void activate();
  virtual void deactivate();
};

#endif //MusicNode_h_