# 视觉模块

## 简介

![](./images/render_MUVS3_2.png)

视觉模块是一个带有特定视觉算法的识别模块。

模块与主控之间通过串口连接，通过主控编程控制视觉模块数据传输，也可通过wifi连接手机端app实现远程编程功能。

## 参数

尺寸：37 x 37 x 15 mm

主控芯片：ESP32

摄像头：OV7725

视角：85°

板载资源：按键、LED指示灯

连接方式：UART、wifi

接口：PH2.0 4P

**接口图:**

![](./images/pinout_MUVS3_2.png)

## 使用示例

### 串口开发

视觉模块可和主控连接，通过主控编程使用指令控制决定视觉模块的识别功能，并通过串口向主控传输数据。

硬件连接：将视觉模块连至主控P9口，作为UART3的串口设备运行。

程序介绍：在初始化中开启主控和视觉模块间串口Serial3，波特率默认115200，初始化视觉模块至Serial3，启用球检测算法。
循环程序中，将主控的亮灯状态配置为和视觉模块的灯相同，即检测到球亮红灯，未检测到球亮蓝灯。

实验现象：先按视觉模块的RESET键初始化视觉模块，板载两个LED灯会常亮进入等待指令状态，然后初始化主控，主控的初始化程序就向视觉模块发送指令，
此时视觉模块进入检测球状态，两个灯闪红色，此时主控进入循环接收状态。当检测到球时，主控和视觉模块的LED都亮蓝色。

![](./images/Mixly_example_MUVS3_balldetect.png)

注意该视觉模块和MU视觉传感器的区别，由于有wifi连接app的功能，视觉模块默认和主控采用串口连接，使用Mixly或Arduino进行开发，初始化程序参考以上示例。

该程序较为简单，主要为了展示MU的连接和程序初始化。更多编程块和示例程序可参考

[MU 3 Mixly 教程](https://morpx-docs.readthedocs.io/en/latest/MUVS3/MUVS3_Mixly/index.html)



### wifi连接app

视觉模块自带wifi，可以连接MU Bot App，进行遥控或手机端编程等，
详情参考

[MoonBot Kit MU Bot App 教程](https://morpx-docs.readthedocs.io/en/latest/MoonBot/MoonBot_App/index.html)
