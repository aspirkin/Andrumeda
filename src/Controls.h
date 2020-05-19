#ifndef Controls_h_
#define Controls_h_

#include <EncoderHandler.h>
#include <SensorHandler.h>

class Controls
{
protected:
  int _numberOfNodes;
  SensorHandler* _ptrMusicSensorHandlers[20];
  EncoderHandler* _ptrEncoderHandlers[5];
public:
  Controls(int numberOfNodes);
  SensorHandler* getMusicSensorHandler(int index);
  EncoderHandler* getEncoderHandler(int index);
  void update();
  // void encoder1cw();
  // void encoder1ccw();
};

#endif //Controls_h_