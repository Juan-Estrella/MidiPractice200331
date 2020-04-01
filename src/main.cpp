#include <Arduino.h>
#include <Audio.h>
#include <USBHost_t36.h>
#include "GuiTool.h"
#include "Functions.h"
//*************Object Instantiation********
USBHost myusb;
USBHub hub1(myusb);
USBHub hub2(myusb);
MIDIDevice midi1(myusb);

//*******************Set Up*********************
void setup()
{
  delay(5000); // 3 second delay for recovery
  Serial.begin(115200);
  myusb.begin();
  midi1.setHandleNoteOn(MyNoteOn);
  midi1.setHandleNoteOff(MyNoteOff);
  AudioMemory(20);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.32);
  waveform1.begin(WAVEFORM_SAWTOOTH);
  waveform1.amplitude(0.0);
  waveform1.frequency(50);
  waveform1.pulseWidth(0.15);
}

//********************Loop*********************
void loop()
{
  myusb.Task();
  midi1.read();
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch == 'a')
    {
      waveform1.frequency(440);
      waveform1.amplitude(1);
    }
    if (ch == 's')
    {
      waveform1.frequency(440);
      waveform1.amplitude(0);
    }
  }
}