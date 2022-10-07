#pragma once
#include <SetupCalculations.h>

float calCV(float c, float r1, float r2, float vcc, float freq)
{
  float a = (1/freq - (c * r2 * log(2))) / (c * (r1+r2));
  return 2*vcc*(exp(a) - 1) / (2 * exp(a) - 1); // https://electronics.stackexchange.com/questions/101530/what-is-the-equation-for-the-555-timer-control-voltage see correction answer
}

float calNoteF(float refF, float noteDistance)
 {
  return refF * pow(2, (noteDistance / 12)); // http://techlib.com/reference/musical_note_frequencies.htm#:~:text=Starting%20at%20any%20note%20the,away%20from%20the%20starting%20note.
 }

 int cv2Duty(float cv, float cvMax)
 {
  return round(cv/cvMax) * 255; // 255 max value for pwm for some reason
 }