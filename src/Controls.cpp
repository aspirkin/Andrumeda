#include <Controls.h>

Controls::Controls(int numberOfMusicNodes, int numberOfEncoders) {
  _numberOfMusicNodes = numberOfMusicNodes;
  //_ptrMusicSensorHandlers.reserve(_numberOfMusicNodes);
  _numberOfEncoders = numberOfEncoders;
}

void Controls::addEncoder(int pinS, int pinA, int pinB){
  _ptrEncoderHandlers.push_back(new EncoderHandler(pinS, pinA, pinB));
}

void Controls::addMusicSensor(int pin) {
  _ptrMusicSensorHandlers.push_back(new SensorHandler(pin));
}

SensorHandler* Controls::getMusicSensorHandler(int index) {
  return _ptrMusicSensorHandlers[index];
}

EncoderHandler* Controls::getEncoderHandler(int index) {
  return _ptrEncoderHandlers[index];
}

void Controls::update() {
  //Serial.println("controls update");
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    _ptrMusicSensorHandlers[i]->update();
  }

  for (int i = 0; i < _numberOfEncoders; i++)
  {
    _ptrEncoderHandlers[i]->update();
  }
}