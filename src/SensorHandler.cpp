#include <SensorHandler.h>

SensorHandler::SensorHandler(int pin) {
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
}

void SensorHandler::update() {
  //Serial.println("sensor update");
  _value = 1023 - analogRead(_pin);
  if (_value > 150 && !_isPressed)
  {
    _synthNode->noteOn();
    Serial.println("note on");
    _isPressed = true;
  }
  else if (_value < 150 && _isPressed)
  {
    _synthNode->noteOff();
    Serial.println("note off");
    _isPressed = false;
  }
}

void SensorHandler::setNode(MusicNode * node) {
  _synthNode = node;
}