# Auto Cannon

## Introduction

This project is an auto shoot cannon based on direnjie kit and MoonBot structure parts.
MU vision sensor 3 is fixed on top of the cannon that can recognize the coordinates of the target.
So that the controller can control the servos and water gun to aim and shoot the target until clear.

## Contents

- A water gun

- Servo gimbal

- MU vision sensor 3

- Handbit controller

- Lipo battery + 18650 Power Li battery 

- Target with MU number cards

![](./images/MUVS3_Auto_Shoot.png)

这个就是我的自动炮台，采用MoonBot的金属钣金制作舵机云台，实现双舵机控制炮台两个自由度的运动。
额外加了一个固定水弹枪体的3D打印支架和固定用的钣金底座。将MU可识别的数字卡片贴在原本的电动靶上，同时还增大了目标更容易射中 囧。。。

## 程序解析

- 初始设置程序

初始化中对将要用到的外设进行设置，包括舵机和MU。

![](./images/Mixly_Auto_Shoot_1.png)

- 寻找卡片函数

寻找卡片采用舵机左右移动的方式，配合上下微调，找寻180度视角范围内的卡片。

![](./images/Mixly_Auto_Shoot_2.png)

- 对准卡片函数

当寻找到卡片时，进入对准卡片的程序。通过舵机移动修正炮和卡片之间的距离。

![](./images/Mixly_Auto_Shoot_3.png)

- 发射函数

比较简单，通过控制P脚直接输出高电平发射，约0.5秒时间，可以打出约3发水弹，如果击倒比较容易则可以时间更短些。

![](./images/Mixly_Auto_Shoot_4.png)

- 循环程序

将以上函数组合后就是循环程序的内容。

![](./images/Mixly_Auto_Shoot_5.png)

- 远程控制程序

另外可以加入Blynk远程开启炮台的程序，将循环程序作为子程序整体放入Blynk中。按键按下则触发循环程序执行自动发射。

![](./images/Mixly_Auto_Shoot_6.png)

## 实战演习

程序开始，舵机复位至正中。主方向为左右方向，检测并扫描。在遇到数字卡片时跳出寻找卡片，进入对准卡片程序。
在确定视觉模块对准坐标48至52位置时射击，两秒后再次进入扫描。

如果加入远程控制程序，则在blynk端按下按键后开启整段自动射击程序。

视频

# 网帖汇总

[掌控慧眼小MU系列教程](https://makelog.dfrobot.com.cn/article-1746.html)

[小MU|小狗狗，认数字](http://mc.dfrobot.com.cn/thread-296734-1-1.html)

[人工智能（障）——麦昆人体识别与追踪](http://mc.dfrobot.com.cn/thread-296584-1-1.html)

[自动跟随的麦克纳姆轮小车](http://mc.dfrobot.com.cn/thread-296803-1-1.html)

[小MU掌控板之乘法连连看](http://mc.dfrobot.com.cn/thread-296782-1-1.html)
