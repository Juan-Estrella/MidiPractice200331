#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <Arduino.h>

void MyNoteOn(byte channel, byte note, byte velocity);
void MyNoteOff(byte channel, byte note, byte velocity);
void InitializeAudio();


#endif