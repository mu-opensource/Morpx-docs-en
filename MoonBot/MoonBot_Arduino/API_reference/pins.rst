引脚映射
=============

概览
----------

MoonBot Kit :doc:`../../MoonBot_Hardware/MoonBot_Hardware_controller` 包含了9个通用端口、4个舵机端口、2个电机端口、2个按键、1个蜂鸣器，
对应的，在 Arduino 库中我们也提供了 :ref:`引脚映射 <api-ref-pins>` 库和相关引脚的宏定义来方便用户获取对应引脚号。

通过这些函数和宏，我们可以方便的获取 MoonBot Kit 主控上的端口、舵机等对应引脚号。

按键状态获取
+++++++++++++++++++++

比如，通过获取板载按键的状态来点亮板载的 LED：

.. code-block:: cpp

    #include <MoonBot.h>

    int button_a = MOONBOT_PIN_BUTTON_A;        // 获取板载按键A的引脚号
    int button_b = MOONBOT_PIN_BUTTON_B;        // 获取板载按键B的引脚号

    void setup()
    {
        LED.begin();        // 板载LED初始化
    }

    void loop()
    {
        if ((!digitalRead(button_a) && !digitalRead(button_b))) {
            // 如果按键A和B同时被按下，板载LED 0 1同时亮青色灯光
            LED.setPixelColor(0, 0x00ffff);
            LED.setPixelColor(1, 0x00ffff);
            LED.show();
        } else if ((!digitalRead(button_a))) {
            // 如果按键A和B同时被按下，板载LED 0亮绿色灯光
            LED.setPixelColor(0, 0x00ff00);
            LED.setPixelColor(1, 0x000000);
            LED.show();
        } else if ((!digitalRead(button_b))) {
            // 如果按键A和B同时被按下，板载LED 1亮蓝色灯光
            LED.setPixelColor(0, 0x000000);
            LED.setPixelColor(1, 0x0000ff);
            LED.show();
        } else {
            // 如果按键A和B同都没被按下，板载LED关闭
            LED.setPixelColor(0, 0x000000);
            LED.setPixelColor(1, 0x000000);
            LED.show();
        }
    }

获取LED眼睛引脚
+++++++++++++++++++++

再或者，我们希望获取连接在端口3上的 :doc:`../../MoonBot_Hardware/MoonBot_Hardware_eyes` 引脚来初始化 LED：

.. code-block:: cpp

  moonbot_eyes.setPin(moonbotPortToPin(kPort3, kPortPin1));     // 设置LED眼睛模块的引脚为端口3的第一个引脚
  moonbot_eyes.begin();         // LED眼睛初始化

触摸模块状态获取
+++++++++++++++++++++

以及，读取连接在各个通用端口上 :doc:`../../MoonBot_Hardware/MoonBot_Hardware_touch` 的状态：

.. literalinclude:: examples/read_touch_state.ino
   :language: cpp

红外模块状态获取
+++++++++++++++++++++

同样的，我们可以用相同的方法读取 :doc:`../../MoonBot_Hardware/MoonBot_Hardware_infrared` 的状态：

.. literalinclude:: examples/read_ir_state.ino
   :language: cpp


.. Attention::

    红外传感器为低电平触发，当对应引脚电平为 ``LOW`` 时，红外传感器被触发；反之，读取引脚电平为 ``HIGH`` 时，红外传感器不被触发。

.. _api-ref-pins:

API 参考 - 引脚映射
----------------------

头文件
+++++++++++

    - `src/pins_moonbot.h <https://github.com/mu-opensource/MoonBot/blob/master/src/pins_moonbot.h>`_

枚举
+++++++++

.. glossary::

    enum moonbot_servo_t

        - MoonBot Kit 舵机端口

        *值:*

        :kServo1=0:
        :kServo2:
        :kServo3:
        :kServo4:
        :kServoNum:

            - 舵机端口数量

    enum servo_pin_t

        - 舵机端口引脚类型

        *值:*

        :kSignal:

            - 舵机信号引脚

        :kShutDown:

            - 舵机供电引脚

        :kState:

            - 舵机状态引脚

    enum moonbot_motor_t 

        - MoonBot Kit 电机端口

        *值:*

        :kMotor1=0:
        :kMotor2:
        :kMotorNum:

            - 电机端口数量


    enum motor_pin_t

        - 电机端口引脚类型

        *值:*

        :kDirection:

            - 电机方向引脚

        :kSpeed:

            - 电机速度引脚

    enum moonbot_port_t

        - MoonBot Kit 通用端口

        *值:*

        :kPort1=0:
        :kPort2:
        :kPort3:
        :kPort4:
        :kPort5:
        :kPort6:
        :kPort7:
        :kPort8:
        :kPort9:
        :kPortNum:

            - 通用端口数量

    enum port_pin_t

        - 通用端口引脚类型

        *值:*

        :kPortPin1=0:
        :kPortPin2:
        :kPortPinNum:

            - 端口引脚数量

宏
+++++++++

.. glossary::

    MOONBOT_PIN_LED

        - MoonBot Kit 主控板载 LED 引脚

    MOONBOT_PIN_BUZZER_SIG 

        - MoonBot Kit 主控板载蜂鸣器信号引脚

    MOONBOT_PIN_BUZZER_SHDW

        - MoonBot Kit 主控板载蜂鸣器供电引脚

    MOONBOT_PIN_BUTTON_A

        - MoonBot Kit 主控板载按钮 A 引脚

    MOONBOT_PIN_BUTTON_B

        - MoonBot Kit 主控板载按钮 B 引脚

函数
+++++++++

.. glossary::

    uint8_t moonbotPortToPin(moonbot_port_t port_num, port_pin_t pin_num);

        - 获取 MoonBot Kit 给定端口的引脚对应的 Arduino 引脚

        :参数:

            - ``port_num`` ：通用端口号
            - ``pin_num`` ：端口引脚号

        :返回:

            - 对应的 Arduino 引脚

    uint8_t moonbotMotorToPin(moonbot_motor_t motor_num, motor_pin_t pin_type);

        - 获取 MoonBot Kit 给定电机端口的引脚类型对应的 Arduino 引脚

        :参数:

            - ``motor_num`` ：电机端口号
            - ``pin_type`` ：电机端口引脚类型

        :返回:

            - 对应的 Arduino 引脚

    uint8_t moonbotServoToPin(moonbot_servo_t servo_num, servo_pin_t pin_type);

        - 获取 MoonBot Kit 给定舵机端口的引脚类型对应的 Arduino 引脚

        :参数:

            - ``servo_num`` ：舵机端口号
            - ``pin_type`` ：舵机端口引脚类型

        :返回:

            - 对应的 Arduino 引脚



