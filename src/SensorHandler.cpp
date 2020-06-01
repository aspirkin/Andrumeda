#include <SensorHandler.h>

SensorHandler::SensorHandler(int pin) {
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
}

void SensorHandler::update() {
  //Serial.println("sensor update");
  _value = 1023 - analogRead(_pin);

  if (_cooldownCounter > 0)
  {
    _cooldownCounter--;
  }
  else
  {
    if (_value > SENSOR_THRESHOLD)
    {
      if (_valueTop == 0)
      {
        _synthNode->noteOn();
        _cooldownCounter = SENSOR_COOLDOWN_LIMIT;
      }
      if (_value > _valueTop)
      {
        _valueTop = _value;
        _volumeToSet = _valueTop;
      }
    }
    else if (_valueTop > 0)
    {
      _valueTop = 0;
      _synthNode->noteOff();
      _cooldownCounter = SENSOR_COOLDOWN_LIMIT;
    }
  }

  // if (_valueTop > 0 && _value > _valueTop && _value > SENSOR_THRESHOLD)
  // {
  //   _valueTop = _value;
  //   _volumeToSet = _valueTop;
  // }
  //set volume
}

void SensorHandler::setNode(MusicNode * node) {
  _synthNode = node;
}