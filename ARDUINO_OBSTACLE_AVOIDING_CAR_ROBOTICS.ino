// Before uploading the code you have to install the necessary library//
//AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install //
//NewPing Library https://github.com/livetronic/Arduino-NewPing// 
//Servo Library https://github.com/arduino-libraries/Servo.git //
// To Install the libraries go to sketch >> Include Library >> Add .ZIP File >> Select the Downloaded ZIP files From the Above links //

#include <AFMotor.h>   
#include <NewPing.h> 
#include <Servo.h>  
 
#define TRIG_PIN A0  
#define ECHO_PIN A1  
#define MAX_DISTANCE 200  
#define MAX_SPEED 190 // sets speed of DC motors 
#define MAX_SPEED_OFFSET 20 
 
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);  
 
AF_DCMotor motor1(1, MOTOR12_1KHZ);  
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor fanMotor(3, MOTOR12_1KHZ); 
Servo myservo; 
 
void setup() { 
  myservo.attach(10);   
  myservo.write(115);  
  delay(2000); 
   
  // Запуск моторов M1 и M2 на движение вперед 
  motor1.setSpeed(100); // Установка скорости (можно изменить) 
  motor2.setSpeed(100); // Установка скорости (можно изменить) 
  motor1.run(FORWARD);  // Вращение вперед 
  motor2.run(FORWARD);  // Вращение вперед 
 
  // Включение вентилятора на M3 
  fanMotor.setSpeed(255); // Максимальная скорость для 12 В 
  fanMotor.run(FORWARD); 
} 
 
void loop() { 
  int distanceR = 0; 
  int distanceL = 0; 
  delay(40); 
  
  if (distance <= 15) { 
    moveStop(); 
    delay(100); 
    moveBackward(); 
    delay(300); 
    moveStop(); 
    delay(200); 
    distanceR = lookRight(); 
    delay(200); 
    distanceL = lookLeft(); 
    delay(200); 
 
    if (distanceR >= distanceL) { 
      turnRight(); 
      moveStop(); 
    } else { 
      turnLeft(); 
      moveStop(); 
    } 
  } else { 
    moveForward(); 
  } 
  distance = readPing(); 
} 
 
int lookRight() { 
  myservo.write(50);  
  delay(500); 
  int distance = readPing(); 
  delay(100); 
  myservo.write(115);  
  return distance; 
} 
 
int lookLeft() { 
  myservo.write(170);  
  delay(500); 
  int distance = readPing(); 
  delay(100); 
  myservo.write(115);  
  return distance; 
} 
 
int readPing() {  
  delay(70); 
  int cm = sonar.ping_cm(); 
  if (cm == 0) { 
    cm = 250; 
  } 
  return cm; 
} 
 
void moveStop() { 
  motor1.run(RELEASE);  
  motor2.run(RELEASE); 
} 
 
void moveForward() { 
  if (!goesForward) { 
    goesForward = true; 
    motor1.run(FORWARD);       
    motor2.run(FORWARD); 
    for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) { 
      motor1.setSpeed(speedSet); 
      motor2.setSpeed(speedSet); 
      delay(5); 
    } 
  } 
} 
 
void moveBackward() { 
  goesForward = false; 
  motor1.run(BACKWARD);       
  motor2.run(BACKWARD); 
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) { 
    motor1.setSpeed(speedSet); 
    motor2.setSpeed(speedSet); 
    delay(5); 
  } 
} 
 
void turnRight() { 
  motor1.run(FORWARD); 
  motor2.run(BACKWARD); 
  delay(500); 
  moveStop(); 
} 
 
void turnLeft() { 
  motor1.run(BACKWARD);      
  motor2.run(FORWARD); 
  delay(500); 
  moveStop(); 
}