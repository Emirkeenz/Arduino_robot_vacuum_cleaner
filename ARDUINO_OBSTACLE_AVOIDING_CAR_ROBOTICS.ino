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

void turnRight() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  delay(500); // Вращение в течение 0.5 секунды
  moveStop();
}

void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  delay(500); // Вращение в течение 0.5 секунды
  moveStop();
}

void moveStop() {
  motor1.run(RELEASE); // Остановка моторов
  motor2.run(RELEASE);
}
