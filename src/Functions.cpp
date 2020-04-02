#include <Arduino.h>
#include <Audio.h>
#include "GuiTool.h"
#include "Functions.h"

//**************Functions****************************
void InitializeAudio()
{
  AudioMemory(20);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.3);
  waveform1.begin(WAVEFORM_SAWTOOTH);
  waveform1.amplitude(0.0);
  waveform1.frequency(50);
  waveform1.pulseWidth(0.15); 
}
void MyNoteOn(byte channel, byte note, byte velocity)
{
  waveform1.frequency(440);
  waveform1.amplitude(1);
}

void MyNoteOff(byte channel, byte note, byte velocity)
{
  waveform1.frequency(440);
  waveform1.amplitude(0);
}
