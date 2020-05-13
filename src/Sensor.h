#ifndef Sensor_h_
#define Sensor_h_

#include <Controller.h>
#include <MusicNode.h>
#include <Arduino.h>

class Sensor : public Controller
{
protected:
  int _pin;
  int _value;
  MusicNode* _synthNode;
  //static const int SENSOR_THRESHOLD = ;
public:
  Sensor(int pin);
  void update();
  void setNode(MusicNode &node);
};

#endif //Sensor_h_