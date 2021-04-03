#include <SharpIR.h>
SharpIR sensor(SharpIR::GP2Y0A41SK0F, A0);
#include <Servo.h>
Servo motor;
const int motionpin = (3);
const int red = (5);
const int ylw = (6);
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode (red, OUTPUT);
  pinMode (ylw, OUTPUT);
  pinMode (motionpin, INPUT);
  Serial.begin (9600);
  motor.attach (4);
  motor.write (180);
  digitalWrite (red, LOW);
  digitalWrite (ylw, LOW);
}
void loop() {
  int motion = digitalRead (motionpin);
  int fullness = sensor.getDistance();
  if (motion == 1) {
    delay (500);
    if (motion == 1) {
      motor.write (90);
      Serial.println ("Motion Detected!");
      digitalWrite (LED_BUILTIN, 0);
      digitalWrite (ylw, 1);
      delay (7500);
    }
    else {
      motor.write (180);
      Serial.println ("No Motion Detected!");
      digitalWrite (ylw, 0);
      delay(50);
    }
  }
  else {
    motor.write (180);
    Serial.println ("No Motion Detected!");
    digitalWrite (ylw, 0);
    delay(50);
  } 
  Serial.println("");
  delay (200);
  if (fullness <= 6) {
    delay(1000);
    fullness = sensor.getDistance();
    if (fullness <= 6) {
      Serial.println("Full!");
      digitalWrite (LED_BUILTIN, 0);
      digitalWrite (LED_BUILTIN, 1);
      digitalWrite (red, 1);
      delay(25);
      digitalWrite (LED_BUILTIN, 0);
      digitalWrite (red, 1);
      delay(25);
    }
    else {
      Serial.println("Not Full!");
      digitalWrite (LED_BUILTIN, 0);
      digitalWrite (LED_BUILTIN, 1);
      delay(50);
      digitalWrite (LED_BUILTIN, 0);
    }
  }
  else {
    Serial.println("Empty!");
    digitalWrite (LED_BUILTIN, 1);
    digitalWrite (red, 0);
  }
  Serial.println("");
  digitalWrite (LED_BUILTIN, 1);
}
