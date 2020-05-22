#ifndef Controls_h_
#define Controls_h_

#include <EncoderHandler.h>
#include <SensorHandler.h>
#include <vector>

class Controls
{
protected:
  int _numberOfMusicNodes;
  int _numberOfEncoders;
  std::vector <SensorHandler*> _ptrMusicSensorHandlers;
  std::vector <EncoderHandler*> _ptrEncoderHandlers;
public:
  Controls(int numberOfMusicNodes, int numberOfEncoders);
  SensorHandler* getMusicSensorHandler(int index);
  EncoderHandler* getEncoderHandler(int index);
  void addMusicSensor(int pin);
  void addEncoder(int pinA, int pinB, int pinS);
  void update();
};

#endif //Controls_h_