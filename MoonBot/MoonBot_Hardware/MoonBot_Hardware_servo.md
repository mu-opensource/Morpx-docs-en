# Servo Module

## Brief Introduction

![](./images/render_servo.png)

Servo is an angle-control actuator based on PWM signal.It contains DC motor, reducer,feedback circuit and current control circuit.

## Specification

Size: 54 x 20 x 47.2 mm

Servo Type: 55g metal-gear servo

Torque: 9.4kg.cm

Rated Current: 250mA

Blocked Circuit: 1A

Connector: PH2.0 3P

## Usage

### Servo Calibration

Servo can rotate from 0 to 180 degree. Degree increases clockwise and decreases CCW. Initial degree is 90 degree, with a red mark pointing forward.

Servo is an angle-control device and it uses potentiometer to get the degree.
Servo initial degree may has a devistion due to precision of the potentiometer,usually smaller than 10 degrees.
Just programme to calibrate the servo.

Code introduction: In initial part,Servo is initialize to 90 degree.Check the actual degree and change the correct value to set the servo to right angle.

Pay attention that this value is the correct value of servo rather than port S1. If the servo changes port, and programme should be changed too.

![](./images/Mixly_example_servo_calibrate.png)

### Servo Rotation

There are two ways to rotate servo.One for setting degree and time, and the other for setting degree and speed and moving together.
The first way is often used for single servo rotation, and the second is for multiple servos.

Code introduction: In initial part, servo is calibrated and direction is set. 
In loop part, control degree and time to move servo for 30 degrees, and then move servos fastly to 150 degree.

![](./images/Mixly_example_servo_move.png)
