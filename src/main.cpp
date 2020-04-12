#include <Arduino.h>
#include <Audio.h>
#include <USBHost_t36.h>
//*************Object Instantiation********
USBHost myusb;
USBHub hub1(myusb);
USBHub hub2(myusb);
MIDIDevice midi1(myusb);

//*************GUI Tool********************
// GUItool: begin automatically generated code from Teensy Audio System Design Tool
AudioSynthWaveform waveform1; //xy=429,378
AudioOutputI2S i2s1;          //xy=747,377
AudioConnection patchCord1(waveform1, 0, i2s1, 0);
AudioConnection patchCord2(waveform1, 0, i2s1, 1);
AudioControlSGTL5000 sgtl5000_1; //xy=588,480
// GUItool: end automatically generated code

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
      Serial.println("a");
    }
    if (ch == 's')
    {
      waveform1.frequency(440);
      waveform1.amplitude(0);
      Serial.println("s");
    }
  }
}