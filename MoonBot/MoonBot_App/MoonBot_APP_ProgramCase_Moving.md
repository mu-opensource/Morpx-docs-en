# APP Programming Block_motion

## motion

![](./images/EMoonBot_APP_Moving.jpg)

### Setting steering angle block

![](./images/EMoonBot_APP_Moving0.jpg)

Steering port：steering1~steering4

Angle：0~180°

### Read steering angle block

![](./images/EMoonBot_APP_Moving1.jpg)

Read the specified steering angle

Parameters: steering gear 1-4

### Forward

![](./images/EMoonBot_APP_Moving2.jpg)

Distance set to advance at specified gear speed

Execution distance：0~999cm

Speed parameters: very fast, fast, medium, slow, very slow

### Back off

![](./images/EMoonBot_APP_Moving3.jpg)

Back-set distance at specified gear speed

Execution distance：0~999cm

Speed parameters: very fast, fast, medium, slow, very slow

### Turn Left

![](./images/EMoonBot_APP_Moving4.jpg)

Turn left at the specified gear speed and set the angle

Execution angle：0~999°

Speed parameters: very fast, fast, medium, slow, very slow

### Turn right

![](./images/EMoonBot_APP_Moving5.jpg)

Turn right at the specified gear speed and set the angle

Execution angle：0~999°

Speed parameters: very fast, fast, medium, slow, very slow

### Stop Motion block

![](./images/EMoonBot_APP_Moving6.jpg)

### Writing speed of Motor block

![](./images/EMoonBot_APP_Moving7.jpg)

Write a certain speed to the motor（-100~+100R／min）

Parameters: Motor 1, Motor 2

### Read motor speed block

![](./images/EMoonBot_APP_Moving8.jpg)

Parameters: Motor 1, Motor 2

### Calibration of alignment migration block

![](./images/EMoonBot_APP_Moving9.jpg)

Calibrate the alignment migration so that it does not migrate in a certain direction.

Parameters: 0-200, > 100 to the right and < 100 to the left

### Calibration of alignment distance block

![](./images/EMoonBot_APP_Moving10.jpg)

Calibrating the inaccuracy of the direct distance caused by external interference

Parameters: > 100 Increase Distance, < 100 Reduce Distance

### Calibration of turning angle block

![](./images/EMoonBot_APP_Moving11.jpg)

Incomplete turning angle caused by calibration external interference

Parameters: > 100 Increase turning angle, < 100 Reduce turning angle

### Calibration of steering angle block

![](./images/EMoonBot_APP_Moving12.jpg)

Calibration of angle error in production and installation by rudder calibration module

Parameters: steering gear 1-4

Increase/decrease（-90~+90°）
