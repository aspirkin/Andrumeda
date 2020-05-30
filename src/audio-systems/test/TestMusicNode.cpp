#include <audio-systems/test/TestMusicNode.h>

TestMusicNode::TestMusicNode(AudioSynthWaveform &nodeWaveform1,
                             AudioSynthWaveform &nodeWaveform2,
                             AudioSynthNoisePink &nodeNoisePink) : MusicNode(){
  _waveform1 = &nodeWaveform1;
  _waveform2 = &nodeWaveform2;
  _noisePink = &nodeNoisePink;

  noteOff();
}

void TestMusicNode::noteOn() {
  _isActive = true;
  printAmps();
  _waveform1->amplitude(_wf1Amp);
  _waveform2->amplitude(_wf2Amp);
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

void TestMusicNode::setWf1Amplitude(float value) {
  _wf1Amp = value;
  if (_isActive) _waveform1->amplitude(_wf1Amp);
  //printAmps();
}

void TestMusicNode::setWf2Amplitude(float value) {
  _wf2Amp = value;
  if (_isActive) _waveform2->amplitude(_wf2Amp);
}

void TestMusicNode::setPinkAmplitude(float value) {
  _pinkAmp = value;
  if (_isActive) _noisePink->amplitude(_pinkAmp);
}

void TestMusicNode::printAmps() {
  Serial.print("_wf1Amp = ");
  Serial.print(_wf1Amp);
  Serial.print("; _wf2Amp = ");
  Serial.print(_wf2Amp);
  Serial.print("; _pinkAmp = ");
  Serial.print(_pinkAmp);
}