/*
   Created by ArduinoGetStarted.com

   This example code is in the public domain

   Tutorial page: https://arduinogetstarted.com/tutorials/ar duino-servo-motor-controlled-by-potentiometer
*/

#include <Servo.h>

Servo myServo01;  // create servo object to control a servo
Servo myServo02;  // create servo object to control a servo
Servo myServo03;  // create servo object to control a servo
int angle01 = 90;
int angle02 = 90;
int angle03 = 90;



void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  myServo01.attach(9);  // attaches the servo on pin 9 to the servo object
  myServo02.attach(10);  // attaches the servo on pin 10 to the servo object
  myServo03.attach(11);  // attaches the servo on pin 10 to the servo object
}

void loop() {

  // check if data has been sent from the computer:
  while (Serial.available() > 0) {
    // read the most recent byte (which will be from 0 to 255):
    //angle01 = Serial.read();
    angle01 = Serial.parseInt();
    // do it again:
    angle02 = Serial.parseInt();
    // do it again:
    angle03 = Serial.parseInt();

    if (Serial.read() == '\n') {
      angle01 = constrain(angle01, 5, 175);
      angle02 = constrain(angle02, 5, 175);
      angle03 = constrain(angle03, 5, 175);

      myServo01.write(angle01);
      myServo02.write(angle02);
      myServo03.write(angle03);
      delay(50);
    }

  }



}
