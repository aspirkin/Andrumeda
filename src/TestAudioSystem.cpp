#include <TestAudioSystem.h>

TestAudioSystem::TestAudioSystem() : AudioSystem(){
  setupConnections();
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

void TestAudioSystem::setupConnections() {
  AudioConnection          patchCord1(pink8, 0, mixer8, 2);
  AudioConnection          patchCord2(pink7, 0, mixer7, 2);
  AudioConnection          patchCord3(pink6, 0, mixer6, 2);
  AudioConnection          patchCord4(waveform15, 0, mixer8, 0);
  AudioConnection          patchCord5(waveform16, 0, mixer8, 1);
  AudioConnection          patchCord6(pink4, 0, mixer4, 2);
  AudioConnection          patchCord7(pink5, 0, mixer5, 2);
  AudioConnection          patchCord8(waveform13, 0, mixer7, 0);
  AudioConnection          patchCord9(waveform14, 0, mixer7, 1);
  AudioConnection          patchCord10(pink3, 0, mixer3, 2);
  AudioConnection          patchCord11(waveform11, 0, mixer6, 0);
  AudioConnection          patchCord12(waveform12, 0, mixer6, 1);
  AudioConnection          patchCord13(pink2, 0, mixer2, 2);
  AudioConnection          patchCord14(waveform7, 0, mixer4, 0);
  AudioConnection          patchCord15(waveform8, 0, mixer4, 1);
  AudioConnection          patchCord16(waveform9, 0, mixer5, 0);
  AudioConnection          patchCord17(waveform10, 0, mixer5, 1);
  AudioConnection          patchCord18(pink1, 0, mixer1, 2);
  AudioConnection          patchCord19(waveform5, 0, mixer3, 0);
  AudioConnection          patchCord20(waveform6, 0, mixer3, 1);
  AudioConnection          patchCord21(waveform3, 0, mixer2, 0);
  AudioConnection          patchCord22(waveform4, 0, mixer2, 1);
  AudioConnection          patchCord23(waveform1, 0, mixer1, 0);
  AudioConnection          patchCord24(waveform2, 0, mixer1, 1);
  AudioConnection          patchCord25(mixer8, 0, mixer10, 3);
  AudioConnection          patchCord26(mixer7, 0, mixer10, 2);
  AudioConnection          patchCord27(mixer6, 0, mixer10, 1);
  AudioConnection          patchCord28(mixer4, 0, mixer9, 3);
  AudioConnection          patchCord29(mixer5, 0, mixer10, 0);
  AudioConnection          patchCord30(mixer3, 0, mixer9, 2);
  AudioConnection          patchCord31(mixer2, 0, mixer9, 1);
  AudioConnection          patchCord32(mixer1, 0, mixer9, 0);
  AudioConnection          patchCord33(mixer10, 0, mixer11, 1);
  AudioConnection          patchCord34(mixer9, 0, mixer11, 0);
  AudioConnection          patchCord35(mixer11, 0, i2s1, 0);
  AudioConnection          patchCord36(mixer11, 0, i2s1, 1);
}

void TestAudioSystem::setupSGTL5000() {
  AudioMemory(512);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
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
  waveform1.pulseWidth(0.15);
  waveform2.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform2.pulseWidth(0.15);
  i = 1;
  waveform3.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform3.pulseWidth(0.15);
  waveform4.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform4.pulseWidth(0.15);
  i = 2;
  waveform5.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform5.pulseWidth(0.15);
  waveform6.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform6.pulseWidth(0.15);
  i = 3;
  waveform7.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform7.pulseWidth(0.15);
  waveform8.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform8.pulseWidth(0.15);
  i = 4;
  waveform9.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform9.pulseWidth(0.15);
  waveform10.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform10.pulseWidth(0.15);
  i = 5;
  waveform11.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform11.pulseWidth(0.15);
  waveform12.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform12.pulseWidth(0.15);
  i = 6;
  waveform13.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform13.pulseWidth(0.15);
  waveform14.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform14.pulseWidth(0.15);
  i = 7;
  waveform15.begin(0.5, NOTE_FREQS[KEY_NOTE + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform15.pulseWidth(0.15);
  waveform16.begin(0.5, NOTE_FREQS[KEY_NOTE + KEY_STEP + SCALE[i]], WAVEFORM_SAWTOOTH);
  waveform16.pulseWidth(0.15);
}

void TestAudioSystem::setWf1Amplitude(float value) {
  for (int i = 0; i < 8; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setWf1Amplitude(value);
  }
}

void TestAudioSystem::setWf2Amplitude(float value) {
  for (int i = 0; i < 8; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setWf2Amplitude(value);
  }
}

void TestAudioSystem::setPinkAmplitude(float value) {
  for (int i = 0; i < 8; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setPinkAmplitude(value);
  }
}

void TestAudioSystem::activateSampler() {};

void TestAudioSystem::activateSynth() {};
