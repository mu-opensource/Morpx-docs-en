IMU
=============

概览
----------

MoonBot Kit :doc:`../../MoonBot_Hardware/MoonBot_Hardware_controller` 集成了及三轴磁力计、三轴加速度、温度传感器三种功能于一体的 IMU 模组。
对应的，在 Arduino 库中我们也提供了 :ref:`IMU <api-ref-imu>` 库来方便用户获取主控当前姿态、方向、温度等状态。

通过调用 ``IMU`` 我们可以快速的获取当前的指南针角度、俯仰角、横滚角、重力加速度、温度等状态值。

读取主控当前方向
+++++++++++++++++++++

通过读取指南针的角度，我们可以知道当前主控所处方向：

.. code-block:: cpp

    #include <MoonBot.h>

    void setup()
    {
      IMU.enable();         // IMU使能
      IMU.calibrateMag();   // IMU磁力计校准，校准时以"∞"字形晃动主控
    }

    void loop()
    {
      Serial.print("compass:");
      // 获取指南针角度（0~360°）,指向正北时值为0或360
      Serial.println(IMU.getMagAngle());
    }

.. note::

    主控平放时，返回数值为 Y 轴（见主控正面丝印标识）与正北方向夹角；主控竖放时，返回数值为 Z 轴与正北方向夹角。

获取取俯仰角、横滚角
+++++++++++++++++++++++

.. code-block:: cpp

    // 获取俯仰角（±180°），主控向上角度为正，向下角度为负 
    int pitch = IMU.getAccAngle(kAccPitch);
    // 获取横滚角（±180°），主控右倾为正，左倾为正
    int roll = IMU.getAccAngle(kAccRoll);

.. note::

    MoonBot Kit 主控正方向为 Y 轴（见主控正面丝印标识），姿态角度都是以此为前提进行计算的。

获取当前加速度
+++++++++++++++++++++++

.. code-block:: cpp

    // 获取加速度，单位：g，静止时数值为1.0左右
    float acceleration = IMU.getAcceleration();

获取当前运动状态
++++++++++++++++++

.. code-block:: cpp

    void loop() 
    {
        if (IMU.on(kIMUShake)) {
            // 如果当前主控在晃动
            // 亮红灯
            LED.setPixelColor(0, 0xff0000);
            LED.setPixelColor(1, 0xff0000);
            LED.show();
        } else if (IMU.on(kIMUFreeFall)) {
            // 如果当前主控在自由落体
            // 亮绿灯
            LED.setPixelColor(0, 0x00ff00);
            LED.setPixelColor(1, 0x00ff00);
            LED.show();
        } else {
            // 如果主控静置
            // 关闭LED
            LED.setPixelColor(0, 0x000000);
            LED.setPixelColor(1, 0x000000);
            LED.show();
        }
    }

.. _api-ref-imu:

API 参考 - IMU
----------------------

头文件
+++++++++++

    - `src/LSM303AGR_IMU_Sensor.h <https://github.com/mu-opensource/MoonBot/blob/master/src/LSM303AGR_IMU_Sensor.h>`_

枚举
++++++++++

.. glossary::

    enum lsm303_axes_t

        - IMU 方向轴类型。

        *值:*

        :kDirX:
        :kDirY:
        :kDirZ:

    enum lsm303_acc_angle_t

        - IMU 姿态角度类型。

        *值:*

        :kAccRoll:
        :kAccPitch:

    enum imu_state_t

        - IMU 特殊状态类型。

        *值:*

        :kIMUShake:

            - IMU 是否处于晃动状态

        :kIMUFreeFall:

            - IMU 是否处于自由落体状态

类
++++++++++

.. glossary::

    class LSM303AGR_IMU_Sensor

        - IMU 驱动。

        :成员函数:

            :int enable(void);:

                - 使能 IMU 单元。

                :返回:

                    - ``0`` 使能成功，否则失败

            :int advGetMagAngle(lsm303_axes_t main_axes, lsm303_axes_t sub_axes);:

                - 获取给定主轴与副轴所在平面，主轴与正北方夹角

                :参数:

                    - ``main_axes`` ：主轴
                    - ``sub_axes`` ：副轴

                :返回:

                    - 主轴与正北方夹角

            :int getMagAngle(void);:

                - 获取指南针角度，主控平放时，返回 Y 轴正方向与正北方夹角；主控竖放时，返回 Z 轴正方向与正北方夹角。

                :返回:

                    - 主轴与正北方夹角

            :int getAccAngle(lsm303_acc_angle_t angle_type);:

                - 获取主控姿态角度。

                :参数:

                    - ``angle_type`` ：姿态角度类型

                :返回:

                    - 姿态角度

            :float getAcceleration(void);:

                - 获取加速度值。

                :返回:

                    - 加速度值，单位：g

            :bool on(imu_state_t imu_state);:

                - 获取主控知否处于某些状态。

                :参数:

                    - ``imu_state`` ：IMU状态

                :返回:

                    - ``true`` IMU 处于该状态，否则不处于该状态

            :bool calibrateMag(void);:

                - 磁力计校准

                :返回:

                    - 是否校准完成

            :int16_t temperature(void);:

                - 获取温度原始数值

                :返回:

                    - 温度原始数值

            :float temperatureC(void);:

                - 获取当前温度，单位：摄氏度（℃）

                :返回:

                    - 当前温度，单位：摄氏度（℃）

            :float temperatureF(void);:

                - 获取当前温度，单位：华氏度（℉）

                :返回:

                    - 当前温度，单位：华氏度（℉）

        :成员变量:

            :LSM303AGR_ACC_Sensor Acc;:

                - 加速度驱动

            :LSM303AGR_MAG_Sensor Mag;:

                - 磁力计驱动


