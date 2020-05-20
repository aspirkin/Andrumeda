#include <TestAudioSystem.h>
#include <AudioObjects.h>

TestAudioSystem::TestAudioSystem() : AudioSystem(){
  setupSGTL5000();
  setupMixers();
  setupWaveforms();

  _ptrSynthMusicNodes[0] = new TestMusicNode(waveform1, waveform2, pink1);
  _ptrSynthMusicNodes[1] = new TestMusicNode(waveform3, waveform4, pink2);
  _ptrSynthMusicNodes[2] = new TestMusicNode(waveform5, waveform6, pink3);
  _ptrSynthMusicNodes[3] = new TestMusicNode(waveform7, waveform8, pink4);
  _ptrSynthMusicNodes[4] = new TestMusicNode(waveform9, waveform10, pink5);
  _ptrSynthMusicNodes[5] = new TestMusicNode(waveform11, waveform12, pink6);
  _ptrSynthMusicNodes[6] = new TestMusicNode(waveform13, waveform14, pink7);
  _ptrSynthMusicNodes[7] = new TestMusicNode(waveform15, waveform16, pink8);

  //ParamAmplitude* p = new ParamAmplitude(new String("waveform 1 amplitude"), setWf1Amplitude);
}

void TestAudioSystem::setupSGTL5000() {
  AudioMemory(512);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
  sgtl5000_1.lineOutLevel(31);
}

void TestAudioSystem::setupMixers() {
  mixer1.gain(0, 1.00);
  mixer1.gain(1, 1.00);
  mixer1.gain(2, 1.00);

  mixer2.gain(0, 1.00);
  mixer2.gain(1, 1.00);
  mixer2.gain(2, 1.00);

  mixer3.gain(0, 1.00);
  mixer3.gain(1, 1.00);
  mixer3.gain(2, 1.00);

  mixer4.gain(0, 1.00);
  mixer4.gain(1, 1.00);
  mixer4.gain(2, 1.00);

  mixer5.gain(0, 1.00);
  mixer5.gain(1, 1.00);
  mixer5.gain(2, 1.00);

  mixer6.gain(0, 1.00);
  mixer6.gain(1, 1.00);
  mixer6.gain(2, 1.00);

  mixer7.gain(0, 1.00);
  mixer7.gain(1, 1.00);
  mixer7.gain(2, 1.00);

  mixer8.gain(0, 1.00);
  mixer8.gain(1, 1.00);
  mixer8.gain(2, 1.00);

  mixer9.gain(0, 1.00);
  mixer9.gain(1, 1.00);
  mixer9.gain(2, 1.00);
  mixer9.gain(3, 1.00);

  mixer10.gain(0, 1.00);
  mixer10.gain(1, 1.00);
  mixer10.gain(2, 1.00);
  mixer10.gain(3, 1.00);

  mixer11.gain(0, 1.00);
  mixer11.gain(1, 1.00);
}

void TestAudioSystem::setupWaveforms() {
  int i = 0;
  waveform1.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform2.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  i = 1;
  waveform3.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform4.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  i = 2;
  waveform5.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform6.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  i = 3;
  waveform7.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform8.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  i = 4;
  waveform9.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform10.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  i = 5;
  waveform11.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform12.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  i = 6;
  waveform13.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform14.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  i = 7;
  waveform15.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform16.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
}

void TestAudioSystem::setWaveform1Amplitude(float value) {
  for (int i = 0; i < 8; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setWf1Amplitude(value);
  }
}

void TestAudioSystem::setWaveform2Amplitude(float value) {
  for (int i = 0; i < 8; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setWf2Amplitude(value);
  }
}

void TestAudioSystem::setPinkNoiseAmplitude(float value) {
  for (int i = 0; i < 8; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setPinkAmplitude(value);
  }
}

void TestAudioSystem::activateSampler() {};

void TestAudioSystem::activateSynth() {};
