#ifndef Encoder_h_
#define Encoder_h_

#include <Arduino.h>
#include <MusicNode.h>
#include <Parameter.h>
// #include <parameters\ParamAmplitude.h>

class Encoder
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

  Parameter* _parameter;
  void rotateClockwise();
  void rotateCounterclockwise();
public:
  Encoder(int pinS, int pinA, int pinB);
  void update();
  void setParameter(Parameter* parameter);
};

#endif //Encoder_h_