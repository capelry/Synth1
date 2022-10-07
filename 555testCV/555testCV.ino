#include <Wire.h>
#include <MMA8453_n0m1.h>
#include <SetupCalculations.h>

MMA8453_n0m1 accel;

#define CVPin 5 // VCC value used (5V arduino pin)

int dutyCycle;
float dutyCycleFloat;
int y;
float yFloat;

int diatonicScaleSteps [7] = {1, 2, 2, 1, 2, 2, 2}; // semitone steps between notes (including step from 7th note to 1st note
float note1, note2, note3;
float cv1, cv2, cv3;
int duty1, duty2, duty3;

float c = 20 * pow(10, -9);
float r1 = 1* pow(10, 6);
float r2 = 1 * pow(10, 3);
float vcc = 5;
float cvMax = 4.15;


void setup() {

  Serial.begin(9600);
  //analogWrite(CVPin, 50);
  //accel.setI2CAddr(0x1D); //change your device address if necessary, default is 0x1C
  //accel.dataMode(true, 2); //enable highRes 10bit, 2g range [2g,4g,8g]
  note1 = 73.42; //d2
  note2 = calNoteF(note1, diatonicScaleSteps[1]);
  note3 = calNoteF(note2, diatonicScaleSteps[2]);

  cv1 = calCV(c, r1, r2, vcc, note1);
  cv2 = calCV(c, r1, r2, vcc, note2);
  cv3 = calCV(c, r1, r2, vcc, note3);

  duty1 = cv2Duty(cv1, cvMax);
  duty2 = cv2Duty(cv2, cvMax);
  duty3 = cv2Duty(cv3, cvMax);
  
  Serial.print("n1: ");
  Serial.print(note1);
  Serial.print("  cv1: ");
  Serial.print(cv1);
  Serial.print("  d1: ");
  Serial.println(duty1);

  Serial.print("n2: ");
  Serial.print(note2);
  Serial.print("  cv2: ");
  Serial.print(cv2);
  Serial.print("  d2: ");
  Serial.println(duty2);

  Serial.print("n3: ");
  Serial.print(note3);
  Serial.print("  cv3: ");
  Serial.print(cv3);
  Serial.print("  d3: ");
  Serial.println(duty3);
  
  
}

void loop() {

  /*
  accel.update();
  y = accel.y();
  yFloat = float(y);
  Serial.print(" y: ");
  Serial.print(y);
  */
  
  dutyCycleFloat = 255;
  dutyCycle = round(dutyCycleFloat);
  Serial.print("duty cycle: ");
  Serial.println(dutyCycle);
  analogWrite(CVPin, dutyCycle);
  delay(5000);
  /*
  dutyCycleFloat = 200;
  dutyCycle = round(dutyCycleFloat);
  Serial.print("duty cycle: ");
  Serial.println(dutyCycle);
  delay(500);
  analogWrite(CVPin, dutyCycle);

  dutyCycleFloat = 150;
  dutyCycle = round(dutyCycleFloat);
  Serial.print("duty cycle: ");
  Serial.println(dutyCycle);
  delay(500);
  analogWrite(CVPin, dutyCycle);

  dutyCycleFloat = 100;
  dutyCycle = round(dutyCycleFloat);
  Serial.print("duty cycle: ");
  Serial.println(dutyCycle);
  delay(500);
  analogWrite(CVPin, dutyCycle);

  dutyCycleFloat = 50;
  dutyCycle = round(dutyCycleFloat);
  Serial.print("duty cycle: ");
  Serial.println(dutyCycle);
  delay(500);
  analogWrite(CVPin, dutyCycle);
  */
  dutyCycleFloat = 0;
  dutyCycle = round(dutyCycleFloat);
  Serial.print("duty cycle: ");
  Serial.println(dutyCycle);
  analogWrite(CVPin, dutyCycle);
  
  delay(5000);
  
  
}


