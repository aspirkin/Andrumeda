#ifndef ControllerHandler_h_
#define ControllerHandler_h_

class ControllerHandler
{
protected:
  bool _isPressed;
  void (ptrPressFunction) (void);
  void (ptrReleaseFunction) (void);
  void (ptrClickFunction) (void);
public:
  ControllerHandler();
  virtual void update();
};

#endif //ControllerHandler_h_