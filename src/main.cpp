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
  InitializeAudio(); 
  delay(1000);
  Serial.println("Start up Complete");
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
      //waveform1.frequency(330);
      //waveform1.amplitude(1);
      MyNoteOn(1, 1, 1);
      Serial.println("on");
    }
    if (ch == 's')
    {
      //waveform1.frequency(330);
      //waveform1.amplitude(0);
      MyNoteOff(1, 1, 1);
      Serial.println("off");
    }
  }
   
}