#ifndef Controller_h_
#define Controller_h_

class Controller
{
protected:
  bool _isPressed;
  void (ptrPressFunction) (void);
  void (ptrReleaseFunction) (void);
  void (ptrClickFunction) (void);
public:
  Controller();
  virtual void update();
};

#endif //Controller_h_