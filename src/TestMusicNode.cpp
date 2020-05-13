#include <TestMusicNode.h>

TestMusicNode::TestMusicNode(AudioSynthWaveform &nodeWaveform1,
                             AudioSynthWaveform &nodeWaveform2,
                             AudioSynthNoisePink &nodeNoisePink) {
  _waveform1 = &nodeWaveform1;
  _waveform2 = &nodeWaveform2;
  _noisePink = &nodeNoisePink;

  noteOff();
}

void TestMusicNode::noteOn() {
  _isActive = true;
  printAmps();
  _waveform1->amplitude(_wf1Amp);
  _waveform1->pulseWidth(_pulseWidth);
  _waveform2->amplitude(_wf2Amp);
  _waveform2->pulseWidth(_pulseWidth);
  _noisePink->amplitude(_pinkAmp);
}

void TestMusicNode::noteOff() {
  _isActive = false;
  _waveform1->amplitude(0.00);
  _waveform2->amplitude(0.00);
  _noisePink->amplitude(0.00);
}

void TestMusicNode::setVelocity(int velocity) {}

void TestMusicNode::activate() {}

void TestMusicNode::deactivate() {}

void TestMusicNode::setAmp(float value, int index) {

  switch (index)
  {
  case 0:
    _wf1Amp = value;
    break;
  case 1:
    _wf2Amp = value;
    break;
  case 2:
    _pinkAmp = value;
    break;
  case 3:
    _pulseWidth = value;
    break;
  default:
    break;
  }

  if (_isActive) {
    _waveform1->amplitude(_wf1Amp);
    _waveform1->pulseWidth(_pulseWidth);
    _waveform2->amplitude(_wf2Amp);
    _waveform2->pulseWidth(_pulseWidth);
    _noisePink->amplitude(_pinkAmp);
  }

  printAmps();
}

void TestMusicNode::printAmps() {
  Serial.print("_wf1Amp = ");
  Serial.print(_wf1Amp);
  Serial.print("; _wf2Amp = ");
  Serial.print(_wf2Amp);
  Serial.print("; _pinkAmp = ");
  Serial.print(_pinkAmp);
  Serial.print("; _pulseWidth = ");
  Serial.println(_pulseWidth);
}