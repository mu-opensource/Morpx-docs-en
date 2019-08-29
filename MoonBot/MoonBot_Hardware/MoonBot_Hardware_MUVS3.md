# Vision Module

## Brief Introduction

![](./images/render_MUVS3_2.png)

Vision module is a intelligent vision sensor containing AI algorithms.

Vision module can be connected to controller by serial interface, and controlled by pregrammed instructions.
It can also be controlled by mobile phone app through wifi.

## Specification

Size: 37 x 37 x 15 mm

Processor: ESP32

Camera: OV7725

Sight: 85°

On-board Resources: keys, LED

Communications: UART、wifi

Connector: PH2.0 4P

**Pinout**

![](./images/pinout_MUVS3_2.png)

## Usage

### Serial Communication Example

视觉模块可和主控连接，通过主控编程使用指令控制决定视觉模块的识别功能，并通过串口向主控传输数据。

硬件连接：将视觉模块连至主控P9口，作为UART3的串口设备运行。

程序介绍：在初始化中开启主控和视觉模块间串口Serial3，波特率默认115200，初始化视觉模块至Serial3，启用球检测算法。
循环程序中，将主控的亮灯状态配置为和视觉模块的灯相同，即检测到球亮红灯，未检测到球亮蓝灯。

实验现象：先按视觉模块的RESET键初始化视觉模块，板载两个LED灯会常亮进入等待指令状态，然后初始化主控，主控的初始化程序就向视觉模块发送指令，
此时视觉模块进入检测球状态，两个灯闪红色，此时主控进入循环接收状态。当检测到球时，主控和视觉模块的LED都亮蓝色。

![](./images/Mixly_example_MUVS3_balldetect.png)

注意该视觉模块和MU视觉传感器的区别，由于有wifi连接app的功能，视觉模块默认和主控采用串口连接，使用Mixly或Arduino进行开发，初始化程序参考以上示例。

该程序较为简单，主要为了展示MU的连接和程序初始化。更多编程块和示例程序可参考

[MU 3 Mixly Programming Guide](https://morpx-docs.readthedocs.io/en/latest/MUVS3/MUVS3_Mixly/index.html)



### Connect to App through Wifi

Vision mudule contains wifi unit, so it can be connected directly to MU Bot App.Programme or remote control it, please check

[MoonBot Kit MU Bot App Tutorial](https://morpx-docs.readthedocs.io/en/latest/MoonBot/MoonBot_App/index.html)
