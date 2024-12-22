#include <Servo.h>
#include <NewPing.h>

#define TRIG_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;

void setup() {
  myservo.attach(10);
  myservo.write(115); // Начальная позиция серво мотора
  delay(2000);

  motor1.setSpeed(100);
  motor2.setSpeed(100);
}

void loop() {
  int distanceR = lookRight();
  delay(200);
  int distanceL = lookLeft();
  delay(200);

  if (distanceR >= distanceL) {
    moveBackward();
    delay(300);
    turnRight();
  } else {
    moveBackward();
    delay(300);
    turnLeft();
  }
}

int lookRight() {
  myservo.write(50); // Повернуть вправо
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115); // Вернуть в исходное положение
  return distance;
}

int lookLeft() {
  myservo.write(170); // Повернуть влево
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115); // Вернуть в исходное положение
  return distance;
}

int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 250; // Максимальное расстояние
  }
  return cm;
}

void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  delay(300); // Движение назад в течение 0.3 секунды
  moveStop();
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
