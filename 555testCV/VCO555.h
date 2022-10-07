#pragma once
#include <cmath>

class VCO555
{
    /*
    Implements control vontage part of voltage controlled 555 oscillator, with control voltage connected to 555 pin

    Main code to class
        input: controller movement amount as percentage
        output: control voltage for arduino to send
    */
   public:
   float c, r1, r2;
   VCO555(float capacitor, float resistor1, float resistor2);
   float calCV(float c, float r1, float r2, float vcc, float freq);
   float calNoteF(float refF, float noteDistance);
};