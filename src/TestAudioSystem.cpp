#include <TestAudioSystem.h>

// GUItool: begin automatically generated code
AudioSynthNoisePink      pink8; //xy=160,942
AudioSynthNoisePink      pink7; //xy=164,829
AudioSynthNoisePink      pink6; //xy=169,711
AudioSynthWaveform       waveform15; //xy=169,877
AudioSynthWaveform       waveform16; //xy=169,910
AudioSynthNoisePink      pink4; //xy=171,484
AudioSynthNoisePink      pink5; //xy=172,593
AudioSynthWaveform       waveform13; //xy=173,764
AudioSynthWaveform       waveform14; //xy=173,797
AudioSynthNoisePink      pink3; //xy=175,371
AudioSynthWaveform       waveform11; //xy=178,646
AudioSynthWaveform       waveform12; //xy=178,679
AudioSynthNoisePink      pink2; //xy=180,253
AudioSynthWaveform       waveform7; //xy=180,419
AudioSynthWaveform       waveform8; //xy=180,452
AudioSynthWaveform       waveform9; //xy=181,528
AudioSynthWaveform       waveform10; //xy=181,561
AudioSynthNoisePink      pink1;          //xy=183,135
AudioSynthWaveform       waveform5; //xy=184,306
AudioSynthWaveform       waveform6; //xy=184,339
AudioSynthWaveform       waveform3; //xy=189,188
AudioSynthWaveform       waveform4; //xy=189,221
AudioSynthWaveform       waveform1;      //xy=192,70
AudioSynthWaveform       waveform2;      //xy=192,103
AudioMixer4              mixer8; //xy=321,911
AudioMixer4              mixer7; //xy=325,798
AudioMixer4              mixer6; //xy=330,680
AudioMixer4              mixer4; //xy=332,453
AudioMixer4              mixer5; //xy=333,562
AudioMixer4              mixer3; //xy=336,340
AudioMixer4              mixer2; //xy=341,222
AudioMixer4              mixer1;         //xy=344,104
AudioMixer4              mixer10; //xy=577,622
AudioMixer4              mixer9; //xy=587,294
AudioMixer4              mixer11; //xy=811,449
AudioOutputI2S           i2s1;           //xy=1147,206
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
AudioControlSGTL5000     sgtl5000_1;     //xy=1218,356
// GUItool: end automatically generated code

const float NOTE_FREQS[88] = {27.5, 29.1353, 30.8677, 32.7032, 34.6479, 36.7081, 38.8909, 41.2035, 43.6536, 46.2493, 48.9995, 51.913, 55, 58.2705, 61.7354, 65.4064, 69.2957, 73.4162, 77.7817, 82.4069, 87.3071, 92.4986, 97.9989, 103.826, 110, 116.541, 123.471, 130.813, 138.591, 146.832, 155.563, 164.814, 174.614, 184.997, 195.998, 207.652, 220, 233.082, 246.942, 261.626, 277.183, 293.665, 311.127, 329.628, 349.228, 369.994, 391.995, 415.305, 440, 466.164, 493.883, 523.251, 554.365, 587.33, 622.254, 659.255, 698.456, 739.989, 783.991, 830.609, 880, 932.328, 987.767, 1046.5, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22, 1760, 1864.66, 1975.53, 2093, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44, 3520, 3729.31, 3951.07, 4186.01};

const int SCALE[8] = {0, 2, 4, 5, 7, 9, 11, 12};

const int KEY_NOTE = 20;
const int KEY_STEP = 7;

TestAudioSystem::TestAudioSystem(Controls* ptrControls) : AudioSystem(ptrControls){

  AudioMemory(512);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
  //  mixers
  {
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
  //  waveforms
  {
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
  _ptrSynthMusicNodes[0] = new TestMusicNode(waveform1, waveform2, pink1);
  _ptrSynthMusicNodes[1] = new TestMusicNode(waveform3, waveform4, pink2);
  _ptrSynthMusicNodes[2] = new TestMusicNode(waveform5, waveform6, pink3);
  _ptrSynthMusicNodes[3] = new TestMusicNode(waveform7, waveform8, pink4);
  _ptrSynthMusicNodes[4] = new TestMusicNode(waveform9, waveform10, pink5);
  _ptrSynthMusicNodes[5] = new TestMusicNode(waveform11, waveform12, pink6);
  _ptrSynthMusicNodes[6] = new TestMusicNode(waveform13, waveform14, pink7);
  _ptrSynthMusicNodes[7] = new TestMusicNode(waveform15, waveform16, pink8);

}

void TestAudioSystem::setAmp(float value, int index) {
  for (int i = 0; i < 8; i++)
  {
    ((TestMusicNode*)_ptrSynthMusicNodes[i])->setAmp(value, index);
  }
}

void TestAudioSystem::activateSampler() {};

void TestAudioSystem::activateSynth() {};
