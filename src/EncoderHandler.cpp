#include <EncoderHandler.h>

EncoderHandler::EncoderHandler(int pinS, int pinB, int pinA) {
  _pinA = pinA;
  _pinB = pinB;
  _pinS = pinS;

  pinMode(_pinA, INPUT_PULLUP);
  pinMode(_pinB, INPUT_PULLUP);
  pinMode(_pinS, INPUT_PULLUP);

  _valueAPrev = digitalRead(_pinA);
  _valueSPrev = digitalRead(_pinS);
}

void EncoderHandler::setParameter(AbstractParameter* parameter) {
  _parameter = parameter;
}

void EncoderHandler::rotateClockwise() {
  _parameter->increase();
}

void EncoderHandler::rotateCounterclockwise() {
  _parameter->decrease();
}

void EncoderHandler::click() {
  _clickFunction();
}

void EncoderHandler::setClickFunction(activationFunction clickFunction) {
  _clickFunction = clickFunction;
}


void EncoderHandler::update() {
  if (encoderProcessingDelayCounter > 0) {
    encoderProcessingDelayCounter--;
    return;
  } else {
    encoderProcessingDelayCounter = ENCODER_PROCESSING_DELAY;
  }
  
  _valueA = digitalRead(_pinA);
  if (_valueA != _valueAPrev){
    if (digitalRead(_pinB) != _valueA) {
      counter++;
    } else {
      counter--;
    }
    if ((counter / 2.00) == (counter / 2)){
      if ((counter / 2) != _position) {
        if ((counter / 2) > _position) {
          rotateClockwise();
        } else {
          rotateCounterclockwise();
        }
        _position = (counter / 2);
      }
    } 
  }
  _valueAPrev = _valueA;
  
  _valueS = digitalRead(_pinS);
  if (_valueS != _valueSPrev) {
    // process encoder 1 button behavior here
    if (_valueS) {
      Serial.println("Encoder 1 is released");
      //  TODO: make distinction between click, press and release
      click();
    } else {
      Serial.println("Encoder 1 is pushed down");
    }
  }
  _valueSPrev = _valueS;

}
