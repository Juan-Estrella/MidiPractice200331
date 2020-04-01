#include "Functions.h"
#include <Arduino.h>
#include <Audio.h>
#include "GuiTool.h"

//**************Functions****************************
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