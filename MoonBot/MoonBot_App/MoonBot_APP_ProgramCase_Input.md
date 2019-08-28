# APP Programming Block_Input

## Input

![](./images/MoonBot_APP_Input.jpg)

### Read button pressed status

![](./images/MoonBot_APP_Input0.jpg)

Parameter：A、B、A+B

Return: button pressed / not pressed

### Initialization of Touch Sensor Port

![](./images/MoonBot_APP_Input1.jpg)

Parameter：Port3、Port5、Port7、Port8

### Initialize the infrared sensor port and read infrared sensors

![](./images/MoonBot_APP_Input2.jpg)

Port Parameter:Port3、Port5、Port7、Port8

infrared sensor IR1:IR2 Parameter：0:0、0:1、1:0、1:1

0 means undetected , 1 means detected

### Read the compass toward(0~360°)

![](./images/MoonBot_APP_Input3.jpg)

Return: The compass faces the angle

### Read acceleration value（1024/g）

![](./images/MoonBot_APP_Input4.jpg)

Parameter：X direction, y direction, Z direction, strength value

Return: Acceleration value

### Reading rotation angle（°）

![](./images/MoonBot_APP_Input5.jpg)

Parameters: pitch (x), roll (y), read the main control tilt angle

Return: Angle value（-180°~+180°）

### Read thermometer values

![](./images/MoonBot_APP_Input6.jpg)

Return: Temperature value

### Read IMU actions

![](./images/MoonBot_APP_Input7.jpg)

Parameters: vibration, free falling, X-axis up, X-axis down, Y-axis up, Y-axis down, Z-axis up, Z-axis down, 3g, 6g, 8g

### Calibration compass

![](./images/MoonBot_APP_Input8.jpg)

Compass calibration module, the main control in calibration needs to be flipped in the shape of ”∞“