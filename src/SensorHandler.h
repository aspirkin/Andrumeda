#ifndef Sensor_h_
#define Sensor_h_

#include <ControllerHandler.h>
#include <audio-systems/MusicNode.h>
#include <Arduino.h>

class SensorHandler : public ControllerHandler
{
protected:
  int _pin;
  int _value;
  MusicNode* _synthNode;

  int _cooldownCounter = 0;
  int _valueTop = 0;
  const int SENSOR_THRESHOLD = 150;
  const int SENSOR_COOLDOWN_LIMIT = 300;
  int _volumeToSet = 0;
  
public:
  SensorHandler(int pin);
  void update();
  void setNode(MusicNode* node);
};

#endif //Sensor_h_