# APP编程块_运动

## 运动

![](./images/MoonBot_APP_Moving.jpg)

### 设置舵机角度

![](./images/MoonBot_APP_Moving0.jpg)

舵机口：舵机1~舵机4

角度：0~180°

### 读取舵机角度

![](./images/MoonBot_APP_Moving1.jpg)

读取指定舵机角度

参数：舵机1~4

### 前进

![](./images/MoonBot_APP_Moving2.jpg)

以指定档位速度前进设置好的距离

执行距离：0~999cm

速度参数：很快、快、中、慢、很慢

### 后退

![](./images/MoonBot_APP_Moving3.jpg)

以指定档位速度后退设置好的距离

执行距离：0~999cm

速度参数：很快、快、中、慢、很慢

### 左转

![](./images/MoonBot_APP_Moving4.jpg)

以指定档位速度左转设置好的角度

执行距离：0~999°

速度参数：很快、快、中、慢、很慢

### 右转

![](./images/MoonBot_APP_Moving5.jpg)

以指定档位速度右转设置好的角度

执行距离：0~999°

速度参数：很快、快、中、慢、很慢

### 停止运动

![](./images/MoonBot_APP_Moving6.jpg)

### 电机写入转速

![](./images/MoonBot_APP_Moving7.jpg)

向电机写入一定的转速（-100~+100转/分）

参数：电机1、电机2

### 读取电机速度

![](./images/MoonBot_APP_Moving8.jpg)

参数：电机1、电机2

### 校准直行偏移

![](./images/MoonBot_APP_Moving9.jpg)

通过校准直行偏移使之不会往某一方向偏移

参数：0~200，>100向右校准，<100向左校准

### 校准直行距离

![](./images/MoonBot_APP_Moving10.jpg)

校准外部干扰引起的直行距离不准确的情况

参数：>100增大距离，<100减少距离

### 校准转弯角度

![](./images/MoonBot_APP_Moving11.jpg)

校准外部干扰引起的转弯角度不到位的情况

参数：>100增大转弯角度，<100减少转弯角度

### 校准舵机角度

![](./images/MoonBot_APP_Moving12.jpg)

通过舵机校准模块校准生产安装上的角度误差

参数：舵机1~4

增加/减少（-90~+90°）
