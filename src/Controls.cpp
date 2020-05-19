#include <Controls.h>

Controls::Controls(int numberOfNodes) {
  // _ptrMusicSensors.reserve(_numberOfNodes);
  _numberOfNodes = numberOfNodes;
  _ptrMusicSensorHandlers[0] = new SensorHandler(16);
  _ptrMusicSensorHandlers[1] = new SensorHandler(15);
  _ptrMusicSensorHandlers[2] = new SensorHandler(14);
  _ptrMusicSensorHandlers[3] = new SensorHandler(49);
  _ptrMusicSensorHandlers[4] = new SensorHandler(50);
  _ptrMusicSensorHandlers[5] = new SensorHandler(39);
  _ptrMusicSensorHandlers[6] = new SensorHandler(38);
  _ptrMusicSensorHandlers[7] = new SensorHandler(37);

  _ptrEncoderHandlers[0] = new EncoderHandler(2, 1, 0);
  _ptrEncoderHandlers[1] = new EncoderHandler(8, 7, 6);
  _ptrEncoderHandlers[2] = new EncoderHandler(5, 4, 3);
  _ptrEncoderHandlers[3] = new EncoderHandler(27, 26, 25);
}

SensorHandler* Controls::getMusicSensorHandler(int index) {
  return _ptrMusicSensorHandlers[index];
}

EncoderHandler* Controls::getEncoderHandler(int index) {
  return _ptrEncoderHandlers[index];
}

void Controls::update() {
  // Serial.println("controls update");
  for (int i = 0; i < _numberOfNodes; i++)
  {
    _ptrMusicSensorHandlers[i]->update();
  }

  for (int i = 0; i < 4; i++)
  {
    _ptrEncoderHandlers[i]->update();
  }
}