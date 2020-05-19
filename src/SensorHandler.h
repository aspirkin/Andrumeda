#ifndef Sensor_h_
#define Sensor_h_

#include <ControllerHandler.h>
#include <MusicNode.h>
#include <Arduino.h>

class SensorHandler : public ControllerHandler
{
protected:
  int _pin;
  int _value;
  MusicNode* _synthNode;
  //static const int SENSOR_THRESHOLD = ;
public:
  SensorHandler(int pin);
  void update();
  void setNode(MusicNode &node);
};

#endif //Sensor_h_