#ifndef AudioObjects_h_
#define AudioObjects_h_

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoisePink      pink8;          //xy=87,902
AudioSynthNoisePink      pink7;          //xy=91,789
AudioSynthNoisePink      pink6;          //xy=96,671
AudioSynthWaveform       waveform15;     //xy=96,837
AudioSynthWaveform       waveform16;     //xy=96,870
AudioSynthNoisePink      pink4;          //xy=98,444
AudioSynthNoisePink      pink5;          //xy=99,553
AudioSynthWaveform       waveform13;     //xy=100,724
AudioSynthWaveform       waveform14;     //xy=100,757
AudioSynthNoisePink      pink3;          //xy=102,331
AudioSynthWaveform       waveform11;     //xy=105,606
AudioSynthWaveform       waveform12;     //xy=105,639
AudioSynthNoisePink      pink2;          //xy=107,213
AudioSynthWaveform       waveform7;      //xy=107,379
AudioSynthWaveform       waveform8;      //xy=107,412
AudioSynthWaveform       waveform9;      //xy=108,488
AudioSynthWaveform       waveform10;     //xy=108,521
AudioSynthNoisePink      pink1;          //xy=110,95
AudioSynthWaveform       waveform5;      //xy=111,266
AudioSynthWaveform       waveform6;      //xy=111,299
AudioSynthWaveform       waveform3;      //xy=116,148
AudioSynthWaveform       waveform4;      //xy=116,181
AudioSynthWaveform       waveform1;      //xy=119,30
AudioSynthWaveform       waveform2;      //xy=119,63
AudioMixer4              mixer8;         //xy=248,871
AudioMixer4              mixer7;         //xy=252,758
AudioMixer4              mixer6;         //xy=257,640
AudioMixer4              mixer4;         //xy=259,413
AudioMixer4              mixer5;         //xy=260,522
AudioMixer4              mixer3;         //xy=263,300
AudioMixer4              mixer2;         //xy=268,182
AudioMixer4              mixer1;         //xy=271,64
AudioEffectEnvelope      envelope8;      //xy=412.22222900390625,855.5556030273438
AudioEffectEnvelope      envelope7;      //xy=418.888916015625,746.6666259765625
AudioEffectEnvelope      envelope6;      //xy=427.77777099609375,631.111083984375
AudioEffectEnvelope      envelope1;      //xy=432.2222900390625,72.22222900390625
AudioEffectEnvelope      envelope2;      //xy=432.22222900390625,194.44444274902344
AudioEffectEnvelope      envelope5;      //xy=432.22222222222223,532.2222222222222
AudioEffectEnvelope      envelope3;      //xy=436.6666259765625,300.0000305175781
AudioEffectEnvelope      envelope4;      //xy=442.22222222222223,407.77777777777777
AudioMixer4              mixer10;        //xy=626.2222290039062,573.1111450195312
AudioMixer4              mixer9;         //xy=636.2222290039062,245.11114501953125
AudioMixer4              mixer11;        //xy=860.2222290039062,400.11114501953125
AudioOutputI2S           i2s1;           //xy=1074,166
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
AudioConnection          patchCord25(mixer8, envelope8);
AudioConnection          patchCord26(mixer7, envelope7);
AudioConnection          patchCord27(mixer6, envelope6);
AudioConnection          patchCord28(mixer4, envelope4);
AudioConnection          patchCord29(mixer5, envelope5);
AudioConnection          patchCord30(mixer3, envelope3);
AudioConnection          patchCord31(mixer2, envelope2);
AudioConnection          patchCord32(mixer1, envelope1);
AudioConnection          patchCord33(envelope8, 0, mixer10, 3);
AudioConnection          patchCord34(envelope7, 0, mixer10, 2);
AudioConnection          patchCord35(envelope6, 0, mixer10, 1);
AudioConnection          patchCord36(envelope1, 0, mixer9, 0);
AudioConnection          patchCord37(envelope2, 0, mixer9, 1);
AudioConnection          patchCord38(envelope5, 0, mixer10, 0);
AudioConnection          patchCord39(envelope3, 0, mixer9, 2);
AudioConnection          patchCord40(envelope4, 0, mixer9, 3);
AudioConnection          patchCord41(mixer10, 0, mixer11, 1);
AudioConnection          patchCord42(mixer9, 0, mixer11, 0);
AudioConnection          patchCord43(mixer11, 0, i2s1, 0);
AudioConnection          patchCord44(mixer11, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1145,316
// GUItool: end automatically generated code

#endif //AudioObjects_h_