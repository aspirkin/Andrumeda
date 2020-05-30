#ifndef EncoderHandler_h_
#define EncoderHandler_h_

#include <Arduino.h>
#include <audio-systems/MusicNode.h>
#include <parameters/AbstractParameter.h>
#include <functional>

typedef std::function<void()> activationFunction;

class EncoderHandler
{
private:
  int _pinA;
  int _pinB;
  int _pinS;

  int _valueA = 0;
  int _valueS = 0;
  int _valueAPrev = 0;
  int _valueSPrev = 0;
  int _position = 0;

  int counter = 0;
  int encoderProcessingDelayCounter = 0;
  const int ENCODER_PROCESSING_DELAY = 1;

  activationFunction _clickFunction;

  AbstractParameter* _parameter;
  void rotateClockwise();
  void rotateCounterclockwise();
  void click();
public:
  EncoderHandler(int pinS, int pinA, int pinB);
  void update();
  void setParameter(AbstractParameter* parameter);
  void setClickFunction(activationFunction clickFunction);
};

#endif //EncoderHandler_h_