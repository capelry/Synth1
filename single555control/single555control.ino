#include <Wire.h>
#include <MMA8453_n0m1.h>

MMA8453_n0m1 accel;

#define CVPin 5 // VCC value used (5V arduino pin)

int dutyCycle;
float dutyCycleFloat;
int y;
float yFloat;

int diatonicScaleSteps [7] = {1, 2, 2, 1, 2, 2, 2} // semitone steps between notes (including step from 7th note to 1st note

void setup() {

  Serial.begin(9600);
  //analogWrite(CVPin, 50);
  accel.setI2CAddr(0x1D); //change your device address if necessary, default is 0x1C
  accel.dataMode(true, 2); //enable highRes 10bit, 2g range [2g,4g,8g]
  
}

void loop() {

  accel.update();
  y = accel.y();
  yFloat = float(y);
  Serial.print(" y: ");
  Serial.print(y);
  
  dutyCycleFloat = (yFloat + 360) *100 /720;
  dutyCycle = round(dutyCycleFloat);
  Serial.print("duty cycle: ");
  Serial.println(dutyCycle);
  delay(10);
  
  analogWrite(CVPin, dutyCycle);
  
  
}

float calcF(float c, float r1, float r2, float vcc, float cv)
/*
 *  This functinon is used to calculate the frequency corresponding to a control voltage applied to pin 5 of 555 chip
 */
{
  return 1/(c*(r1 + r2) * log(1 - (vcc/(2*vcc - cv))) + c*r2*log(2)); // https://electronics.stackexchange.com/questions/101530/what-is-the-equation-for-the-555-timer-control-voltage
}

float calcNoteF(float refF, float noteDistance)
/*
 * Calculates the frequency of desired note from reference note.
 * noteDistance: number of semitones the note is from reference note
 */
 {
  return refF * pow(2, (noteDistance / 12)); // http://techlib.com/reference/musical_note_frequencies.htm#:~:text=Starting%20at%20any%20note%20the,away%20from%20the%20starting%20note.
 }
