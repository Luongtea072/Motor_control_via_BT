// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char bt_command;

void setup() {
  Serial.begin(9600);
  bt_command = 'S';
  motorSetspeed(100);
  motorStop();
  delay(2000);
}  

void loop() {
  bt_command = Serial.read();
  switch (bt_command) {
    case 'F':
      forward();
      break;
    case 'B':
      backward();
      break;
    case 'R':
      turnRight();
      break;
    case 'L':
      turnLeft();
      break;
    case 'S':
      motorStop();
      break;
  }
}
void forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);

  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void motorStop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void motorSetspeed(uint8_t sp) {
  motor1.setSpeed(sp);
  motor2.setSpeed(sp);
  motor3.setSpeed(sp);
  motor4.setSpeed(sp);
}
