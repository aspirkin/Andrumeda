#ifndef AudioObjects_h_
#define AudioObjects_h_

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoisePink      pink8;          //xy=85,923
AudioSynthNoisePink      pink7;          //xy=89,810
AudioSynthNoisePink      pink6;          //xy=94,692
AudioSynthWaveform       waveform15;     //xy=94,858
AudioSynthWaveform       waveform16;     //xy=94,891
AudioSynthNoisePink      pink4;          //xy=96,465
AudioSynthNoisePink      pink5;          //xy=97,574
AudioSynthWaveform       waveform13;     //xy=98,745
AudioSynthWaveform       waveform14;     //xy=98,778
AudioSynthNoisePink      pink3;          //xy=100,352
AudioSynthWaveform       waveform11;     //xy=103,627
AudioSynthWaveform       waveform12;     //xy=103,660
AudioSynthNoisePink      pink2;          //xy=105,234
AudioSynthWaveform       waveform7;      //xy=105,400
AudioSynthWaveform       waveform8;      //xy=105,433
AudioSynthWaveform       waveform9;      //xy=106,509
AudioSynthWaveform       waveform10;     //xy=106,542
AudioSynthNoisePink      pink1;          //xy=108,116
AudioSynthWaveform       waveform5;      //xy=109,287
AudioSynthWaveform       waveform6;      //xy=109,320
AudioSynthWaveform       waveform3;      //xy=114,169
AudioSynthWaveform       waveform4;      //xy=114,202
AudioSynthWaveform       waveform1;      //xy=117,51
AudioSynthWaveform       waveform2;      //xy=117,84
AudioMixer4              mixer3;         //xy=261,321
AudioMixer4              mixer4; //xy=261,434
AudioMixer4              mixer5; //xy=263,543
AudioMixer4              mixer6;         //xy=264,658
AudioMixer4              mixer2;         //xy=266,203
AudioMixer4              mixer7;         //xy=266,779
AudioMixer4              mixer1;         //xy=269,85
AudioMixer4              mixer8;         //xy=266,881
AudioEffectEnvelope      envelope7;      //xy=416,767
AudioEffectEnvelope      envelope8;      //xy=424,872
AudioEffectEnvelope      envelope6;      //xy=425,652
AudioEffectEnvelope      envelope1;      //xy=430,93
AudioEffectEnvelope      envelope2;      //xy=430,215
AudioEffectEnvelope      envelope5;      //xy=430,553
AudioEffectEnvelope      envelope3;      //xy=434,321
AudioEffectEnvelope      envelope4;      //xy=440,428
AudioMixer4              mixer10;        //xy=624,594
AudioMixer4              mixer9;         //xy=634,266
AudioMixer4              mixer11;        //xy=756,414
AudioFilterBiquad        biquad1;        //xy=908,446
AudioMixer4              mixer12;        //xy=1087,431
AudioEffectBitcrusher    bitcrusher1;    //xy=1242,461
AudioMixer4              delayMixer;         //xy=1428,449
AudioEffectDelay         delay1;         //xy=1428,613
AudioEffectFreeverb      freeverb;      //xy=1579,601
AudioMixer4              reverbMixer;         //xy=1727,587
AudioAmplifier           OutputAmp;           //xy=1874,587
AudioOutputI2S           i2s1;           //xy=2006,586
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
AudioConnection          patchCord25(mixer3, envelope3);
AudioConnection          patchCord26(mixer4, envelope4);
AudioConnection          patchCord27(mixer5, envelope5);
AudioConnection          patchCord28(mixer6, envelope6);
AudioConnection          patchCord29(mixer2, envelope2);
AudioConnection          patchCord30(mixer7, envelope7);
AudioConnection          patchCord31(mixer1, envelope1);
AudioConnection          patchCord32(mixer8, envelope8);
AudioConnection          patchCord33(envelope7, 0, mixer10, 2);
AudioConnection          patchCord34(envelope8, 0, mixer10, 3);
AudioConnection          patchCord35(envelope6, 0, mixer10, 1);
AudioConnection          patchCord36(envelope1, 0, mixer9, 0);
AudioConnection          patchCord37(envelope2, 0, mixer9, 1);
AudioConnection          patchCord38(envelope5, 0, mixer10, 0);
AudioConnection          patchCord39(envelope3, 0, mixer9, 2);
AudioConnection          patchCord40(envelope4, 0, mixer9, 3);
AudioConnection          patchCord41(mixer10, 0, mixer11, 1);
AudioConnection          patchCord42(mixer9, 0, mixer11, 0);
AudioConnection          patchCord43(mixer11, biquad1);
AudioConnection          patchCord44(mixer11, 0, mixer12, 0);
AudioConnection          patchCord45(biquad1, 0, mixer12, 1);
AudioConnection          patchCord46(mixer12, 0, delayMixer, 0);
AudioConnection          patchCord47(mixer12, bitcrusher1);
AudioConnection          patchCord48(bitcrusher1, 0, delayMixer, 1);
AudioConnection          patchCord49(delayMixer, delay1);
AudioConnection          patchCord50(delay1, 0, reverbMixer, 0);
AudioConnection          patchCord51(delay1, 0, freeverb, 0);
AudioConnection          patchCord52(delay1, 1, delayMixer, 3);
AudioConnection          patchCord53(freeverb, 0, reverbMixer, 1);
AudioConnection          patchCord54(reverbMixer, OutputAmp);
AudioConnection          patchCord55(OutputAmp, 0, i2s1, 0);
AudioConnection          patchCord56(OutputAmp, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=2001,633
// GUItool: end automatically generated code

#endif //AudioObjects_h_