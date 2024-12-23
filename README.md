# Smart Vacuum Cleaner System

## Description
The **Smart Vacuum Cleaner System** is an Arduino-based robotic project designed for automated cleaning. The system features intelligent navigation, obstacle detection, and dirt collection, making it a compact and efficient cleaning solution.

## Project Overview
This robotic vacuum cleaner operates on a chassis equipped with 6-12V motors for movement. A servo motor mounted on the chassis holds an ultrasonic sensor to assist in obstacle detection and pathfinding. A 50x50x10 mm fan is installed at the back of the robot to suction dirt into a bottle, acting as a dustbin.

## Functionalities
1. **Obstacle Avoidance**:
   - The ultrasonic sensor detects obstacles as the robot moves forward.
   - When an object is detected, the robot reverses slightly and rotates the servo motor to scan distances to the left and right.
   - Based on the comparison of left and right distances, the robot chooses the direction with more space and continues moving.

2. **Cleaning Mechanism**:
   - A fan at the back of the robot sucks in dirt and debris.
   - Collected dirt is stored in a bottle attached to the chassis.

3. **Efficient Navigation**:
   - The combination of ultrasonic sensors and servo motor enables the robot to navigate complex spaces while avoiding collisions.

## Components
- **Arduino Mega/Nano**: Microcontroller for system control.
- **Arduino Motor Shield L293D**
- **Ultrasonic Sensor**: Mounted on the servo motor for obstacle detection and pathfinding.
- **Servo Motor**: Rotates the ultrasonic sensor for scanning left and right.
- **6-12V Motors**: Provide movement for the robot.
- **50x50x10 mm Fan**: Suctions dirt into the attached bottle.
- **Chassis**: Allows to efficiently use energy for driving.
- **Power Supply**: Powers the entire system.

## Features
- **Obstacle Detection and Avoidance**: Ensures safe and efficient movement.
- **Pathfinding**: Dynamically decides the best direction to move based on sensor data.
- **Automatic Cleaning**: Collects dirt and debris while navigating the environment.

## Setup Instructions
1. **Component Connections**
   - Motor Shield L293D:
     - Connect the 6-12V motors to the M1 and M2 terminals.
     - Connect the fan to the M3 terminal.
     - Attach the servo motor to the dedicated servo connector on the motor shield.
     - Connect the ultrasonic sensor:
       - Echo Pin → A1 on the motor shield.
       - Trig Pin → A0 on the motor shield.
   - Power Supply: Provide a stable power input to the motor shield.
2. **Arduino Programming**
   - Install the necessary Arduino IDE on your computer.
   - Download and install required libraries for motor control and ultrasonic sensors.
   - Upload the provided code to the Arduino board.
3. **Assembly**
   - Mount the ultrasonic sensor on the servo motor.
   - Secure the fan at the back of the chassis.
   - Attach a plastic bottle or dustbin to collect debris.
   - Ensure all connections are tight and components are firmly mounted.
4. **Testing**
   - Power on the system and test motor, servo, and ultrasonic functionality.
   - Ensure the robot can detect obstacles, reverse, scan left and right, and move accordingly.

## Video Demonstration
[https://drive.google.com/drive/folders/1QxvwRhOPB-CLZg3yMyL1BGn6rdp75Blx?usp=sharing](url)
Also in that google drive folder 3D model file included.

## Project Purpose
The Smart Vacuum Cleaner System was developed to create an automated, affordable cleaning solution that integrates efficient navigation and dirt collection. The project demonstrates the use of Arduino for robotics, real-time obstacle detection, and practical cleaning functionality.

## Outcomes
1. **Automated Navigation**: The robot successfully avoids obstacles and determines the optimal path.
2. **Effective Cleaning**: The fan-driven suction system collects dirt and debris effectively.
3. **Integration and Modularity**: The project can be scaled or modified for additional features, such as app control or advanced mapping.

## Team Members
- Emir Orozbekov
- Feruz Tursunov
