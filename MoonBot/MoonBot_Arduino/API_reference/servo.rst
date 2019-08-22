舵机
=============

概览
----------

MoonBot Kit :doc:`../../MoonBot_Hardware/MoonBot_Hardware_controller` 最多可连接四个 :doc:`../../MoonBot_Hardware/MoonBot_Hardware_servo` 。
在 Arduino 库中，我们也提供了 :ref:`舵机 <api-ref-servo>` 库，通过这个库，您可以控制一个或多个舵机同时运动。

:ref:`舵机库 <api-ref-servo>` 继承了 Arduino 基础的舵机驱动 ``class Servo`` 类，除了基础的 ``Servo`` 类成员函数外，我们还提供了舵机校准、多个舵机同时运行等功能的函数。
在 ``MoonBot.h`` 头文件中，我们提供了四个变量 ``m_servo[kServo1]`` ``m_servo[kServo2]`` ``m_servo[kServo3]`` ``m_servo[kServo4]`` ，以分别驱动主控上对应的四个舵机接口。

基础应用
++++++++++++++++

先来看一个舵机的基础应用：

.. literalinclude:: examples/ServoSweep.ino
   :language: cpp

.. note::

    舵机的初始化函数已改为 ``attach(moonbot_servo_t servo_port, bool reverse)`` ，基础的舵机初始化函数 ``uint8_t attach(int pin)`` 已不受支持。

多个舵机同时运动
+++++++++++++++++++++++

我们提供了 ``void MoonBotServo::setTargetAngle()`` 和 ``MoonBotServo::moveAllServoToTarget()`` 函数来让多个舵机同时运动。

.. literalinclude:: examples/MoveAllServoTogether.ino
   :language: cpp

.. note::

    当使用 ``MoonBotServo::moveAllServoToTarget();`` 函数的默认参数时，该函数会等待所有舵机动作运行完成后退出;
    当参数不为0时，会在参数指定时间内退出，并返回动作是否完成。我们可以通过调用 ``bool isMoving(void);`` 来每隔一段时间检查一次当前的运行状态：

    .. code-block:: cpp

        while (!MoonBotServo::moveAllServoToTarget(0)) {
            // 当检测到当前有舵机在进行运动时
            for (int i = 0; i < kServoNum; ++i) {
                if (!m_servo[i].isMoving()) {
                    // 如果检查到当前端口舵机停止运行，打印舵机状态
                    Serial.print("Servo");
                    Serial.print(i);
                    Serial.println(" Stopped.");
                }
            }
        }
        Serial.println("All Servo Stopped.");

    改为以上形式后，使用串口调试软件即会接收到类似以下的信息

    .. code-block::

        Servo1 Stopped.
        ...
        Servo1 Stopped.
        Servo2 Stopped.
        ...
        Servo2 Stopped.
        Servo3 Stopped.
        ...
        Servo3 Stopped.
        All Servo Stopped.

舵机校准
++++++++++++++++

MoonBot Kit :ref:`舵机库 <api-ref-servo>` 中提供了舵机校准函数，可在初始化过程中校准舵机的偏差。

.. code-block:: cpp

    m_servo[kServo1].correction(-2);        //将舵机1向下校准2°

.. _api-ref-servo:

API 参考 - 舵机
----------------------

头文件
+++++++++++

    - `src/MoonBot_Servo.h <https://github.com/mu-opensource/MoonBot/blob/master/src/MoonBot_Servo.h>`_

枚举
++++++++++

.. glossary::

    enum moonbot_servo_t

        - 舵机端口类型

        *值:*

        :kServo1:
        :kServo2:
        :kServo3:
        :kServo4:
        :kServoNum:
            - 舵机端口数量

类
++++++++++

.. glossary::

    class MoonBotServo

        - MoonBot Kit 舵机驱动库

        :成员函数:

            :uint8_t attach(moonbot_servo_t servo_port, bool reverse = MOONBOT_SERVO_REVERSE);:

                - 初始化舵机至对应的舵机端口

                :参数:

                    - ``servo_port`` ：舵机端口
                    - ``reverse`` ：翻转舵机角度

                :返回:

                    - ``NOT_A_PORT`` 舵机端口无效，其他初始化正确

            :uint8_t attach(moonbot_servo_t servo_port, int min, int max, bool reverse = MOONBOT_SERVO_REVERSE);:

                - 初始化舵机至对应的舵机端口，并指定舵机的运行范围

                :参数:

                    - ``servo_port`` ：舵机端口
                    - ``min`` ：舵机最小运行角度
                    - ``max`` ：舵机最大运行角度
                    - ``reverse`` ：翻转舵机角度

                :返回:

                    - ``NOT_A_PORT`` 舵机端口无效，其他初始化正确

            :void detach(void);:

                - 断开舵机与对应端口的连接

            :void write(int value);:

                - 向舵机写入角度

                :参数:

                    - ``value`` ：角度值，取值范围 ``0~180°``

            :int read(void);:

                - 读取舵机当前角度

                :返回:

                    - 当前角度值

            :void reverse(bool state);:

                - 以90°为中心点，翻转舵机角度。

                :参数:

                    - ``state`` :状态， ``true`` 为翻转角度，否则为默认方向

            :void setTargetAngle(int angle, unsigned int speed = 1);:

                - 预设舵机角度，需与函数 ``static bool moveAllServoToTarget()`` 配合使用。

                :参数:

                    - ``angle`` ：预设角度
                    - ``speed`` ：每个脉冲角度的变化量

            :void stop(void);:

                - 停止舵机动作

            :void power(bool state);:

                - 开启或断开舵机供电。

                :参数:

                    - ``state`` ：舵机供电状态， ``true`` 为开启供电

            :void correction(int angle_offset);:

                - 舵机校准

                :参数:

                    - ``angle_offset`` ：舵机校准角度值，取值范围： ``±90°``

            :bool isMoving(void);:

                - 读取舵机当前运动状态。

                :返回:

                    - ``true`` 为当前正在运动，反之为当前没有运动

            :bool isPowerOverload(void);:

                - 检测当前是否电流过载。

                :返回:

                    - ``true`` 为当前电流过载，反之为正常

        :静态成员函数:

            :static bool moveAllServoToTarget(unsigned long timeToWait_ms = 0xFFFFFFFF);:

                - 移动所有舵机值预设角度。

                :参数:

                    - ``timeToWait_ms`` ：等待时间，默认为直至舵机移动到预设角度（无限长）
                
                :返回:

                    - ``true`` 完成移动到预设角度动作，反之未完成动作

            :static void stopAllServo(void);:

                - 停止所有舵机的动作。
