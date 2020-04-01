#ifndef GUITOOL_H
#define GUITOOL_H
#include <Audio.h>

//*************GUI Tool********************
// GUItool: begin automatically generated code from Teensy Audio System Design Tool
AudioSynthWaveform waveform1; //xy=429,378
AudioOutputI2S i2s1;          //xy=747,377
AudioConnection patchCord1(waveform1, 0, i2s1, 0);
AudioConnection patchCord2(waveform1, 0, i2s1, 1);
AudioControlSGTL5000 sgtl5000_1; //xy=588,480
// GUItool: end automatically generated code

#endif