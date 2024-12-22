#include <Servo.h>
#include <NewPing.h>

#define TRIG_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;

void setup() {
  myservo.attach(10);
  myservo.write(115); // Начальная позиция серво мотора
  delay(2000);
}

void loop() {
  int distanceR = lookRight();
  delay(200);
  int distanceL = lookLeft();
  delay(200);
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
