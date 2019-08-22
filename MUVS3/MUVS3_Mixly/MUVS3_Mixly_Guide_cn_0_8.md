# Mixly库导入

打开Mixly软件，选择主控设备，常用Arduino Uno。如果使用MoonBot主控，则选择Arduino Mega（atmega 1280），选择设备的COM口。

![](./images/MUVS3_Mixly_hardware.png)

点击导入库。

![](./images/MUVS3_Mixly_import.png)

选中库中名为MUVisionSensor3.xml文件，点击打开。

![](./images/MUVS3_Mixly_file.png)

若在Mixly导航栏出现MUVisionSensor3一栏，且下方出现导入自定义库成功，则导入成功。

![](./images/MUVS3_Mixly_imported.png)

# Arduino硬件连接

MU Vision Sensor 3的外设和接口如图所示：

![](./images/MUVS3_pinout.png)

## I2C模式

(1)将模块左侧输出模式拨码开关1拨至下方，2拨至上方，切换至I2C模式；

(2)(不推荐修改此设置)将模块右侧的地址选择拨码开关拨至对应位(默认地址0x60，1、2都在下方)；

(3)将模块输出接口SDA口接至Arduino对应的SDA口，SCL口接至Arduino对应的SCL口。

## 串口模式

(1)将模块左侧输出模式拨码开关1、2都拨至下方，切换至串口模式；

(2)(不推荐修改此设置)将模块的地址选择拨码开关拨至对应位(默认地址1、2都在下方)；

(3)将模块输出接口RX口接至Arduino对应的TX口，TX口接至Arduino对应的RX口。

# 模块使用介绍

## 模块说明

**初始化模块**

(1)硬件串口：视觉传感器使用串口模式，连接主控的硬件串口时主控初始化，该串口为主控和电脑端的串口通信，用于视觉会占用，电脑端打印字符会错乱或通信异常；

![](./images/Mixly_block_serial_init.png)

(2)软件串口：视觉传感器使用串口模式，连接主控的软件串口时主控初始化，主控可自定义RX和TX引脚，实际环境软串口速度太快可能不稳定，波特率不建议超过9600；

![](./images/Mixly_block_softserial_init.png)

(3)硬件I2C：视觉传感器使用I2C模式，连接主控I2C引脚时主控初始化。

![](./images/Mixly_block_i2c_init.png)

**开启算法**

![](./images/Mixly_block_enable_algorithm.png)

**设置算法性能**

![](./images/Mixly_block_algorithm_performance.png)

**开启摄像头高帧率模式**

识别速度增加，同时功耗、发热量增加。

![](./images/Mixly_block_highFPS.png)

**设置摄像头白平衡**

调节因为外界光源变化而引起的图像偏色。

![](./images/Mixly_block_setWB.png)

**板载LED灯光设置**

![](./images/Mixly_block_setLED.png)

**恢复模块默认设置**
关闭所有算法，重置所有硬件设置。

![](./images/Mixly_block_setdefault.png)

**获取算法识别结果**

(1) 球、人体

![](./images/Mixly_block_ball_detect.png)

(2) 卡片

![](./images/Mixly_block_card_detect.png)

(3) 颜色识别

![](./images/Mixly_block_color_recognition.png)

(4) 色块检测

![](./images/Mixly_block_color_block.png)

## 完整示例

**颜色识别**

![](./images/Mixly_example_color_recognition.png)

**球体检测**

![](./images/Mixly_example_ball_detect.png)

**形状卡片检测**

![](./images/Mixly_example_card_detect.png)

# 常见问题

1.导入库后无法打开模块或模块都是黑框怎么办？
 
请下载最新版Mixly程序，重新导入后即可。  

2.我正确导入了库，下载了例程，但是模块没有反应，串口也没有任何输出怎么办？ 
  
(1) 检查接线是否正确，是否有接触不良的现象。

(2) 检查模块背后的白灯是否常量，白灯不亮则表示电源口没有电压或电源线接线错误。

(3) 检查输出模式拨码开关和地址选择拨码开关是否是拨至正确位置。

(4) 模块从上电到初始化完成需要一段时间，建议在“设置”模块前加入一段不小于500ms的延时。  
 
(5) 点击模块Reset按钮，模块正面两个LED会短暂闪烁一次光。红光则表示当前模式为串口模式，绿光则表示当前模式为I2C模式。若光的颜色与输出模式拨码开关不符，则可能为拨码开关松动，重新拨动拨码开关至正确位置即可。  

3.我下载了程序，串口有正确的内容输出，但是LED灯光不亮怎么办？  

(1) 当算法为颜色识别算法时，程序默认会关闭LED，防止LED灯光照射使物体偏色。  

(2) 设置中打开LED灯光，调节灯光亮度大于0。  

4.按我对比了文档和Mixly库，发现有些功能Mixly库没有怎么办？  

为了使库易于理解和操作，在Mixly库中去除了一些不常用的功能，简化了一些参数的设置方式。若这些省去的功能影响到了您的项目，请发邮件至摩图科技售后：support@morpx.com寻求技术支持和解决方案。  

5.我发现烧录前一次程序的算法会对后一次程序的算法有影响，如：前一次烧录了颜色识别算法，后一次烧录球算法，就算没有识别到球LED也会显示识别到，而只烧录球算法则没有这种现象，怎么办？  

这是因为前一种算法在程序结束后并没有被关闭导致的，可以在设置模块时加入“恢复默认设置”模块，或重新断电拨插模块即可。  
