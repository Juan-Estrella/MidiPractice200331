#include "GuiTool.h"

AudioSynthWaveform waveform1; //xy=429,378
AudioOutputI2S i2s1;          //xy=747,377
AudioControlSGTL5000 sgtl5000_1; //xy=588,480
AudioConnection patchCord1(waveform1, 0, i2s1, 0);
AudioConnection patchCord2(waveform1, 0, i2s1, 1);
  