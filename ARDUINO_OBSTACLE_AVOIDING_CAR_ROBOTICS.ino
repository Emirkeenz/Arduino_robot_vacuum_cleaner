#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);

void setup() {
  motor1.setSpeed(100);
  motor2.setSpeed(100);
}

void loop() {
  moveForward();
  delay(1000); // Двигаться вперед в течение 1 секунды
}

void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}
