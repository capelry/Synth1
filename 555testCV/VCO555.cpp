#pragma once
#include <VCO555.h>

class VCO555
{
    public:

    int numNotes;
    float c, r1, r2;

    VCO555(float capacitor, float resistor1, float resistor2, int numberNotes)
    {
        c = capacitor;
        r1 = resistor1;
        r2 = resistor2;
        numNotes = numberNotes;
    }

    float calCV(float c, float r1, float r2, float vcc, float freq)
    /*
    *  This functinon is used to calculate the control voltage to be applied to pin 5 of 555 chip for a specified frequency
    */
    {
        float a = (1/freq - (c * r2 * log(2))) / (c * (r1+r2));
        return 2*vcc*(exp(a) - 1) / (2 * exp(a) - 1); // https://electronics.stackexchange.com/questions/101530/what-is-the-equation-for-the-555-timer-control-voltage see correction answer
    }

    float calNoteF(float refF, float noteDistance)
    /*
    * Calculates the frequency of desired note from reference note.
    * noteDistance: number of semitones the note is from reference note
    */
    {
        return refF * pow(2, (noteDistance / 12)); // http://techlib.com/reference/musical_note_frequencies.htm#:~:text=Starting%20at%20any%20note%20the,away%20from%20the%20starting%20note.
    }

    
   void buildScale(int scaleSteps[], int numSteps, float baseNoteFrequency)
   /*
   Builds array of frequency values for the given scale
   */
   {
        for (int i = 0; i < numNotes; i++)
        {
            
        }
   }
};