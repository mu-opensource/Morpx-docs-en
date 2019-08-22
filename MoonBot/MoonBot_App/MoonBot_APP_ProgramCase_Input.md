# APP编程块_输入

## 输入

![](./images/MoonBot_APP_Input.jpg)

### 读取按键被按下状态

![](./images/MoonBot_APP_Input0.jpg)

参数：A、B、A+B

返回：按键被按下/未被按下

### 初始化触摸传感器端口

![](./images/MoonBot_APP_Input1.jpg)

参数：端口3、端口5、端口7、端口8

### 初始化红外传感器端口，读取两路红外传感器

![](./images/MoonBot_APP_Input2.jpg)

端口参数：端口3、端口5、端口7、端口8

红外传感器IR1:IR2参数：0:0、0:1、1:0、1:1

0表示未检测到，1表示检测到

### 读取指南针朝向(0~360°)

![](./images/MoonBot_APP_Input3.jpg)

返回：指南针朝向角度

### 读取加速度值（1024/g）

![](./images/MoonBot_APP_Input4.jpg)

参数：x方向、y方向、z方向、强度值

返回：加速度值

### 读取旋转角度（°）

![](./images/MoonBot_APP_Input5.jpg)

参数：俯仰（x）、横滚（y），读取主控倾斜角

返回：角度值（-180°~+180°）

### 读取温度计值

![](./images/MoonBot_APP_Input6.jpg)

返回：温度值

### 读取IMU动作

![](./images/MoonBot_APP_Input7.jpg)

参数：震动、自由落体、X轴向上、X轴向下、Y轴向上、Y轴向下、Z轴向上、Z轴向下、3g、6g、8g

### 校准指南针

![](./images/MoonBot_APP_Input8.jpg)

指南针校准模块，校准时主控需以”∞“字形翻转

