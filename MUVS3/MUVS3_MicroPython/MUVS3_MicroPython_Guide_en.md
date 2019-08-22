# Preparations before Coding
If you want to use Micro:bit to control the MU Vision Sensor, you need to import the MicroPython firmware that contains the ‘MuVisionSensor’ module. Please follow the steps below:

(1) Download the firmware：

GitHub：<https://github.com/mu-opensource/MuVisionSensor3-MicroPython>

Official Website：<http://mai.morpx.com/page.php?a=sensor-support>

(2) Flash the firmware：

Connect the micro:bit to computer via USB cable,and drag the downloaded frimware “microbit-micropython-MuVisionSensor-0.8.0.hex” to MICROBIT disk.
Micro:bit will flash the new firmware and restart.

(3) Download and install Mu Editor :

Mu Editor is a simple Python code editor for beginner programmers with friendly GUI.

It can be downloaded in the main page:<https://codewith.mu/>

(4) Import module

Open Mu Editor, change the mode to BBC micro:bit,and click the”REPL”button to enter serial reply mode.The micro:bit will send firmware version at first.
Type the code below and press enter to run

```python
>>> from MuVisionSensor import *
```

Now you can call all the public APIs in ‘MuVisionSensor’

*Key words auto-completion fuction is only available in REPL mode

![](./images/MicroPython_imported.png)

# Connect to Micro:bit

MU Vision Sensor 3 periphrals and ports:

![](./images/MUVS3_pinout.png)

I2C Mode

(1)Output Mode DIP Switch: set switch 1 downwards and switch 2 upwards

(2)Connect the output Pin1(SDA) to the Pin20 of Micro:bit, and Pin2(SCL) to Pin19  of Micro:bit. Also connecting the ground pin and 3.3v power pin to micro:bit.

(3)Change the I2C address of MU Vision Sensor by resetting Address DIP Switch. In default both switches are downward and the address is 0x60.(Changing this setting is not recommended)

*Only I2C mode is supported now

# Usage of APIs

## Initialize MU Vision Sensor

Two steps to initialize this sensor:

Step1. Call the ‘MuVisionSensor(‘address’)’ to create an object , the value of ’address’  should be consistent with the setting of Address DIP Switch (default is 0x60); 

Step2. Call the ‘begin()’  function to start this sensor;

## Enable Algorithms

**API:**

```python
MuVisionSensor.VisionBegin(vision_type)
```

目前支持的vision_type有：

`VISION_COLOR_DETECT`        颜色检测

`VISION_COLOR_RECOGNITION`   颜色识别

`VISION_BALL_DETECT`         球体检测

`VISION_BODY_DETECT`         人体检测

`VISION_SHAPE_CARD_DETECT`   形状卡片检测

`VISION_TRAFFIC_CARD_DETECT` 交通卡片检测

`VISION_NUM_CARD_DETECT`     数字卡片检测

`VISION_ALL`                开启所有算法

**example:**

```python
from MuVisionSensor import *  #导入库
.... #省略初始化过程
mu.VisionBegin(VISION_COLOR_DETECT)  #开启颜色检测算法
mu.VisionBegin(VISION_SHAPE_CARD_DETECT | VISION_BALL_DETECT) #同时开启形状卡片检测和球体检测算法
```

## Set Performance Level

**API:**

```
MuVisionSensor.VisionSetLevel(vision_type, level)
```

可选的vision_type同上

可选的level有：

`LevelDefault`  默认

`LevelSpeed`  速度优先

`LevelBalance`  平衡

`LevelAccuracy` 准确性优先

**示例：**

```
mu.VisionSetLevel(VISION_BALL_DETECT, LevelSpeed)
```

### Get Performance Level

**API:**

```
mu.VisionSetLevel(vision_type)
```

返回值0~3代表四种算法性能

## Enable High FPS Mode

高帧率模式下识别速度增加，同时功耗增加

**API:**

```
MuVisionSensor.CameraSetFPS(mode)
```

可选的mode有：

`FPSNormal` 正常模式

`FPSHigh` 高帧率模式

### Get FPS Mode

**API:**

```
MuVisionSensor.CameraGetFPS()
```

返回值为 0(FPSNormal)或1(FPSHigh)

## Set White Balance Mode

调节因为外界光源变化而引起的图像偏色

**API:**

```
MuVisionSensor.CameraSetAwb(mode)
```

可选的mode有：

`AutoWhiteBalance`		自动白平衡

`LockWhiteBalance`		锁定白平衡

`WhiteLight`      		白光模式

`YellowLight`     		黄光模式

### Get White Balance mode

**API:**

```
MuVisionSensor.CameraGetAwb()
```

返回值为 0~3，对应4种白平衡模式

## Set Digital Zoom Ratio

**API:**

```
MuVisionSensor.CameraSetZoom(mode)
```

可选的mode有：

`ZoomDefault` 默认

`Zoom1` 变焦模式1

`Zoom2` 变焦模式2

`Zoom3` 变焦模式3

`Zoom4` 变焦模式4

`Zoom5` 变焦模式5

### Get Digital Zoom Ratio Setting

**API:**

```
MuVisionSensor.CameraGetZoom()
```

返回值为 0~5，对应6种白平衡模式

## LED Settings

**API:**

```
MuVisionSensor.LedSetColor(led, detected_color, undetected_color, level)
```

参数说明：

led：要配置的LED灯，可选值为

`Led1` 板载LED1

`Led2` 板载LED2

detected_color：检测到结果时的颜色，可选值为

`LedClose` LED关

`LedRed` 红色

`LedGreen` 绿色

`LedYellow`	黄色

`LedBlue` 蓝色

`LedPurple` 紫色

`LedCyan` 青色

`LedWhite` 白色

undetected_color：未检测到结果时的颜色，可选值同上

level：亮度值，可输入0~15的数字，数值越大越亮

## Restore Default Settings

关闭所有算法，重置所有硬件设置

**API:**
```
MuVisionSensor.SensorSetDefault()
```

## Restart

**API:**
```
MuVisionSensor.SensorSetRestart()
```

## Get Results of Detection

**API:**
```
MuVisionSensor.GetValue(vision_type, object_inf)
```

vision_type的可选值同上

object_inf的可选值为：

`Status` 检测状态，0代表没检测到，1代表检测到

`XValue` 目标的横向坐标

`YValue` 目标的纵向坐标

`WidthValue` 目标的宽度

`HeightValue` 目标的高度

`Label` 目标的标签

`RValue` 红色通道值（颜色识别模式）

`GValue` 绿色通道值（颜色识别模式）

`BValue` 蓝色通道值（颜色识别模式）
