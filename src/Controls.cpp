#include <Controls.h>

Controls::Controls(int numberOfNodes) {
  // _ptrMusicSensors.reserve(_numberOfNodes);
  _numberOfNodes = numberOfNodes;
  _ptrMusicSensors[0] = new Sensor(16);
  _ptrMusicSensors[1] = new Sensor(15);
  _ptrMusicSensors[2] = new Sensor(14);
  _ptrMusicSensors[3] = new Sensor(49);
  _ptrMusicSensors[4] = new Sensor(50);
  _ptrMusicSensors[5] = new Sensor(39);
  _ptrMusicSensors[6] = new Sensor(38);
  _ptrMusicSensors[7] = new Sensor(37);

  _ptrEncoders[0] = new Encoder(2, 1, 0);
  _ptrEncoders[1] = new Encoder(8, 7, 6);
  _ptrEncoders[2] = new Encoder(5, 4, 3);
  _ptrEncoders[3] = new Encoder(27, 26, 25);
}

Sensor* Controls::getMusicSensor(int index) {
  return _ptrMusicSensors[index];
}

Encoder* Controls::getEncoder(int index) {
  return _ptrEncoders[index];
}

void Controls::update() {
  // Serial.println("controls update");
  for (int i = 0; i < _numberOfNodes; i++)
  {
    _ptrMusicSensors[i]->update();
  }

  for (int i = 0; i < 4; i++)
  {
    _ptrEncoders[i]->update();
  }
}