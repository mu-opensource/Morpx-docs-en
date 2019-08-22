# Import Mixly Library for MU Vision Sensor

Open Mixly，click ‘Import’

![](./images/MUVS3_Mixly_hardware.png)

Locate the ‘MuVisionSensorIII.xml’ file , select and open it.

![](./images/MUVS3_Mixly_import.png)

Locate the ‘MuVisionSensorIII.xml’ file , select and open it.

![](./images/MUVS3_Mixly_file.png)

Then the nether information window prompts” import custom Library successfully ”, and you will find ‘MuVisionSensor3’ library in the ‘Blocks’ window.

![](./images/MUVS3_Mixly_imported.png)

# Connect to Arduino

MU Vision Sensor 3 periphrals and ports：

![](./images/MUVS3_pinout.png)

## I2C Mode (recommended)

(1) Output Protocol Switch: set switch 1 downwards and switch 2 upwards.

(2) Connect the output SDA pin of MU to the SDA pin of Arduino, and SCL pin of MU to SCL pin of Arduino.

(3) Choose the I2C address of MU by setting Address Switch. Both switches are downwards and the address is set to 0x60 on default.
 (Changing this setting is not recommended).

## Serial Mode*

(1) Output Protocol Switch: set both switchs downward.

(2) Connect the output RX pin of MU to TX pin of Arduino and TX pin of MU to RX pin of Arduino.

(3) Change the UART address of MU sensor by resetting Address Switch. Both switches are downwards and the address is 0x60 on default. (Changing this setting is not recommended)

* Arduino UNO cannot send messages to PC when MuVisionSensor is running in hardware serial mode, due to a communication conflict.

# Instruction of the Programming Blocks

## Block Introduction

**Initialization**

(1)Hardware Serial Mode：视觉传感器使用串口模式，连接主控的硬件串口时主控初始化，该串口为主控和电脑端的串口通信，用于视觉会占用，电脑端打印字符会错乱或通信异常；

![](./images/Mixly_block_serial_init.png)

(2)Software Serial Mode：视觉传感器使用串口模式，连接主控的软件串口时主控初始化，主控可自定义RX和TX引脚，实际环境软串口速度太快可能不稳定，波特率不建议超过9600；

![](./images/Mixly_block_softserial_init.png)

(3)Hardware I2C Mode：视觉传感器使用I2C模式，连接主控I2C引脚时主控初始化。

![](./images/Mixly_block_i2c_init.png)

**Enable Vision Algorithms**

![](./images/Mixly_block_enable_algorithm.png)

**Algorithm performance level**

![](./images/Mixly_block_algorithm_performance.png)

**Enable/Disable the High FPS Mode**

识别速度增加，同时功耗、发热量增加。

![](./images/Mixly_block_highFPS.png)

**Set White Balance Mode**

调节因为外界光源变化而引起的图像偏色。

![](./images/Mixly_block_setWB.png)

**LED Settings**

![](./images/Mixly_block_setLED.png)

**Restore Default Settings**
关闭所有算法，重置所有硬件设置。

![](./images/Mixly_block_setdefault.png)

**Get Detect Results**

(1) Ball/Body Detection

![](./images/Mixly_block_ball_detect.png)

(2) Card Detection

![](./images/Mixly_block_card_detect.png)

(3) Color Block Detection

![](./images/Mixly_block_color_recognition.png)

(4) Color Recognition

![](./images/Mixly_block_color_block.png)

## Examples

**Color Recognition**

![](./images/Mixly_example_color_recognition.png)

**Ball Detection**

![](./images/Mixly_example_ball_detect.png)

**Card Detection**

![](./images/Mixly_example_card_detect.png)

# FAQs

1.Q: What should I do if I can’t open programming blocks or blocks are black boxes ?

A: Please download the latest Mixly program file and import the library again.

2.Q: What should I do when I import the library and download the examples correctly, but the vision sensor doesn’t respond and the serial port output nothing？

A: Check whether the cable is correctly and tightly connected .

Check whether the white light on the back side is on. If this light is not on ,this means something wrong with power supply.

Check whether the output mode switch and address switch are correctly setted.

It takes MU sensor a period of time to initialize after power-on , we suggested to add a delay of not less than 500 ms before calling ‘setup’ block in your program.

After reset, the two LEDs on the front side of MU vision sensor will flicker once. Red light indicates that the current mode is serial mode, green light indicates that the current mode is I2C mode. If the color does not go with the setting of output mode switch, please reset this switch.

3.Q: What should I do if I download the program and the serial port output correctly, but the LED does not light?

A: When the color recognition algorithm runs, the LED lights will be shut down in order not to interfere with the recognition results.  

Calling the LED setting block and alter the brightness parameter with non-zero number.

4.Q: Why there are some fuctions which can be found in the datasheet while are not listed in Mixly library?

A: In order to make the library easy to understand and operate, some uncommon functions are removed from the Mixly library, and some parameter setting methods are simplified. If these functions are needed, please email to support@morpx.com.

5.Q: Why the previously downloaded recongnition algorithms have impact on the current running program? For example download ball detection algorithm after running color recognition algorithm ,you will find the LEDs are still on even if the ball is not recognized, but this will not occur when only ball recognition algorithm was downloaded. 

A: Because the previous algorithm is not terminated even if the program ends, you can add ‘setDefault’ block when calling ‘setup’ block or restart MU vision sensor.