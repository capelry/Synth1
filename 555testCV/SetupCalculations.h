float calCV(float c, float r1, float r2, float vcc, float freq);
/*
 *  This functinon is used to calculate the control voltage to be applied to pin 5 of 555 chip for a specified frequency
 */

float calNoteF(float refF, float noteDistance);
/*
 * Calculates the frequency of desired note from reference note.
 * noteDistance: number of semitones the note is from reference note
 */

 int cv2Duty(float cv, float cvMax);