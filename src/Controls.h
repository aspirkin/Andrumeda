#ifndef Controls_h_
#define Controls_h_

#include <Encoder.h>
#include <Sensor.h>

class Controls
{
protected:
  int _numberOfNodes;
  Sensor* _ptrMusicSensors[20];
  Encoder* _ptrEncoders[5];
public:
  Controls(int numberOfNodes);
  Sensor* getMusicSensor(int index);
  Encoder* getEncoder(int index);
  void update();
  // void encoder1cw();
  // void encoder1ccw();
};

#endif //Controls_h_