电机
==========

概览
----------

MoonBot Kit :doc:`../../MoonBot_Hardware/MoonBot_Hardware_motor` 包含了基础的电机及编码器。在对应的 Arduino 库中提供了 :ref:`电机 <api-ref-motor>` 库以用来驱动单电机，以及 :ref:`底盘控制 <api-ref-tankbase>` 库以用来驱动双电机。

我们可以通过在程序中包含 ``MoonBot.h`` 头文件来调用 ``TankBase`` 以驱动双电机底盘，或者通过调用 ``Motor1`` ``Motor2`` 以单独驱动电机。

控制双电机底盘
++++++++++++++

如何让底盘前后左右运动起来？先来看一个简单的例程：

.. literalinclude:: examples/tankbase_move.ino
   :language: cpp

通过调用 ``TankBase.write()`` 函数，分别写入左右电机速度，可以快速地让底盘运动起来。

如果你想精准地控制电机转速，推荐使用 ``TankBase.writeRpm()`` 函数来设置电机转速。

.. code-block:: cpp

      // 底盘左转，左电机速度30转/分，右电机速度-30转/分
      TankBase.writeRpm(30, -30);

.. note::

    使用某些可以精准的控制电机转速的函数（如： ``TankBase.write()`` ``TankBase.writeDistance()`` ``TankBase.writeAngle()`` 等），在硬件上需要连接编码器模块至对应端口，软件上需要在底盘初始化函数 ``TankBase.begin()`` 内，将参数 ``enc_enable`` 设为 ``true`` （该参数默认即为 ``true`` ）

你甚至可以让电机前行特定的距离或转动特定的角度：

.. code-block:: cpp

    void loop() {
        TankBase.writeDistance(30, 20);     // 底盘以30转/分的速度前行20cm
        while(TankBase.read(kLeftMotor) || TankBase.read(kRightMotor));     // 等待底盘停止
        delay(100);
        TankBase.writeAngle(30, 180);       // 底盘以30转/分的速度右转180°
        while(TankBase.read(kLeftMotor) || TankBase.read(kRightMotor));     // 等待底盘停止
        delay(100);
    }

.. note::

    因为存在这安装误差、表面摩擦力等外部扰动，你可能会发现底盘无法走直，直行距离不到位或转动角度不到位，没关系，通过以下几个函数校准底盘就可以将误差控制在±1%以内：

    .. code-block:: cpp

        void setup() {
            TankBase.rpmCorrection(82);           // 调节双轮速度一致%，校准转速误差
            TankBase.distanceCorrection(120);     // 校准直行距离误差%
            TankBase.wheelSpacingSet(100);        // 校准转弯角度误差%
        }

控制单个电机
++++++++++++++++

如果你只希望控制单个电机，可以通过调用 ``Motor1`` ``Motor2`` 来实现。

.. code-block:: cpp

    Motor1.write(100);      // 设置电机1模拟量为100
    Motor2.write(100);      // 设置电机2模拟量为100
    Motor1.writeRpm(30);    // 设置电机1转速速30转/分
    Motor2.writeRpm(30);    // 设置电机2转速速30转/分

.. _api-ref-motor:

API 参考 - 电机
----------------------

头文件
+++++++++++

    - `src/MoonBot_Motor.h <https://github.com/mu-opensource/MoonBot/blob/master/src/MoonBot_Motor.h>`_

枚举类型
+++++++++++

.. glossary::

    enum moonbot_motor_t

        - 电机端口类型

        *值:*

        :kMotor1=0:
        :kMotor2:
        :kMotorNum:

类
+++++

.. glossary::

    class Motor

        - 基础单电机驱动

        :成员函数:

            :Motor(moonbot_motor_t motor_type);:

                - 构造函数,指定端口类型。

                :参数:

                    - ``motor_type`` ：电机端口类型

            :int begin(const bool reverse_dir = false, const bool enc_enable = true);:

                - 初始化给定端口的电机。

                :参数:

                    - ``reverse_dir`` ：翻转电机转动方向，默认为 ``false``
                    - ``enc_enable`` ：开启电机编码器功能，默认为 ``true``

                :返回:

                    - ``0`` ：初始化成功
                    - ``-1`` ：找不到给定的电机端口

            :void write(int vol);:

                - 写入模拟量。

                :参数:

                    - ``vol`` ：电压的模拟量，取值 **±255** ，>0正转，<0反转

            :int read(void);:

                - 读取模拟量。

                :返回:

                    - ``±255`` ：对应模拟量的值

            :void writeStep(uint32_t step, int rpm = 30);:

                - 驱动电机以给定转速转动给定步数后停止。
                - 该函数会调用编码器功能，必须在 ``begin()`` 函数内开启编码器功能后才可使用。

                :参数:

                    - ``step`` ：转动步数，一圈对应240步
                    - ``rpm`` ：电机转动速度，默认转速30转/分（RPM）

            :void writeRpm(int rpm = 30);:

                - 写入电机转速，单位：转/分（RPM）
                - 该函数会调用编码器功能，必须在 ``begin()`` 函数内开启编码器功能后才可使用。

                :参数:

                    - ``rpm`` ：电机转动速度，默认转速30转/分（RPM）

            :int readRpm(void);:

                - 读取电机转速，单位：转/分（RPM）
                - 该函数会调用编码器功能，必须在 ``begin()`` 函数内开启编码器功能后才可使用。

                :返回:

                    - 电机转动速度

            :void writeDistance(int rpm, uint32_t distance_cm);:

                - 驱动电机以给定转速转动给定距离后停止，因电机在安装和表面摩擦会引起误差，使用该函数前建议先使用函数 ``distanceCorrection()`` 进行校准
                - 该函数会调用编码器功能，必须在 ``begin()`` 函数内开启编码器功能后才可使用。

                :参数:

                    - ``rpm`` ：电机转动速度
                    - ``distance_cm`` ：转动距离，单位：厘米（cm）

            :uint32_t readEncoderPulse(void);:

                - 读取编码器计数值。
                - 该函数会调用编码器功能，必须在 ``begin()`` 函数内开启编码器功能后才可使用。

                :返回:

                    - 当前编码器计数值

            :void rpmCorrection(uint8_t percent);:

                - 电机转速校准

                :参数:

                    - ``percent`` ：校正百分比，>100转速增加，<100转速降低

            :void distanceCorrection(uint8_t percent);:

                - 电机直行距离校准

                :参数:

                    - ``percent`` ：校正百分比，>100距离增加，<100距离降低


.. _api-ref-tankbase:

API 参考 - 底盘控制
----------------------

头文件
+++++++++++

    - `src/MoonBot_TankBase.h <https://github.com/mu-opensource/MoonBot/blob/master/src/MoonBot_TankBase.h>`_

枚举类型
+++++++++++

.. glossary::

    enum motor_type_t

        - 底盘电机类型

        *值:*

        :kLeftMotor=0:
            - 左侧电机
        :kRightMotor:
            - 右侧电机

类
+++++

.. glossary::

    class MoonBotTankBase

        - 底盘双电机驱动程序

        :成员函数:

            :MoonBotTankBase(Motor& left_motor, Motor& right_motor);:

                - 构造函数，指定左右电机至指定端口。

                :参数:

                    - ``left_motor`` ：左电机
                    - ``right_motor`` ：右电机

            :int begin(const bool reverse_dir = false, const bool enc_enable = true);:

                - 初始化坦克底盘的电机。

                :参数:

                    - ``reverse_dir`` ：翻转电机转动方向，默认为 ``false``
                    - ``enc_enable`` ：开启电机编码器功能，默认为 ``true``

                :返回:

                    - ``0`` ：初始化成功
                    - ``-1`` ：找不到给定的电机端口

            :int begin(const bool left_reverse_dir, const bool right_reverse_dir, const bool enc_enable);:

                - 初始化坦克底盘的电机。

                :参数:

                    - ``left_reverse_dir`` ：翻转左电机转动方向
                    - ``right_reverse_dir`` ：翻转右电机转动方向
                    - ``enc_enable`` ：开启电机编码器功能

                :返回:

                    - ``0`` ：初始化成功
                    - ``-1`` ：找不到给定的电机端口

            :void write(int left_vol, int right_vol);:

                - 向左右电机写入模拟量。

                :参数:

                    - ``left_vol`` ：左电压的模拟量，取值 **±255** ，>0正转，<0反转
                    - ``right_vol`` ：右电压的模拟量，取值 **±255** ，>0正转，<0反转

            :int read(motor_type_t motor_type);:

                - 读取指定电机的模拟量。

                :参数:

                    - ``motor_type`` ：电机类型

                :返回:

                    - ``±255`` ：对应模拟量的值

            :uint32_t readEncoderPulse(motor_type_t motor_type);:

                - 读取对应电机编码器计数值。
                - 该函数会调用编码器功能，必须在 ``begin()`` 函数内开启编码器功能后才可使用。

                :参数:

                    - ``motor_type`` ：电机类型

                :返回:

                    - 当前编码器计数值

            :void writeRpm(int left_rpm, int right_rpm);:

                - 向左右电机写入转速，单位：转/分（RPM）
                - 该函数会调用编码器功能，必须在 ``begin()`` 函数内开启编码器功能后才可使用。

                :参数:

                    - ``left_rpm`` ：左电机转动速度
                    - ``right_rpm`` ：右电机转动速度

            :int readRpm(motor_type_t motor_type);:

                - 读取对应电机转速，单位：转/分（RPM）
                - 该函数会调用编码器功能，必须在 ``begin()`` 函数内开启编码器功能后才可使用。

                :参数:

                    - ``motor_type`` ：电机类型

                :返回:

                    - 电机转动速度

            :void writeDistance(int rpm, uint32_t distance_cm);:

                - 驱动左右电机以给定转速直行给定距离后停止，因电机在安装和表面摩擦会引起误差，使用该函数前建议先使用函数 ``rpmCorrection（）`` 和 ``distanceCorrection()`` 进行校准
                - 该函数会调用编码器功能，必须在 ``begin()`` 函数内开启编码器功能后才可使用。

                :参数:

                    - ``rpm`` ：电机转动速度
                    - ``distance_cm`` ：转动距离，单位：厘米（cm）

            :void writeAngle(int rpm, uint32_t angle);:

                - 驱动左右电机以给定转速转弯给定角度后停止，因电机在安装和表面摩擦会引起误差，使用该函数前建议先使用函数 ``rpmCorrection（）`` 和 ``wheelSpacingSet()`` 进行校准
                - 该函数会调用编码器功能，必须在 ``begin()`` 函数内开启编码器功能后才可使用。

                :参数:

                    - ``rpm`` ：电机转动速度
                    - ``angle`` ：转动角度，单位：度（°）

            :void wheelSpacingSet(int correct, float space_cm = 0);:

                - 设定轮子间距，校正转弯角度，该函数可以校准轮子转弯不到位的情况

                :参数:

                    - ``correct`` ：校正值，>100转弯角度变大，小于100转弯角度减小
                    - ``space_cm`` ：电机间距

            :void rpmCorrection(int percent);:

                - 校准左右电机转速

                :参数:

                    - ``percent`` ：校正值，>100向右校正，<100向左校正

            :void distanceCorrection(int percent);:

                - 底盘直行距离校准

                :参数:

                    - ``percent`` ：校正百分比，>100距离增加，<100距离降低

            :void forward(unsigned int step, unsigned int rpm = 30);:

                - 底盘向前直行一定距离后停止。

                :参数:

                    - ``step`` ：前行距离，单位：厘米（cm）
                    - ``rpm`` ：电机转动速度，默认转速30转/分（RPM）

            :void backward(unsigned int step, unsigned int rpm = 30);:

                - 底盘向后直行一定距离后停止。

                :参数:

                    - ``step`` ：后退距离，单位：厘米（cm）
                    - ``rpm`` ：电机转动速度，默认转速30转/分（RPM）

            :void turnLeft(unsigned int step, unsigned int rpm = 30);:

                - 底盘左转一定角度后停止。

                :参数:

                    - ``step`` ：左转角度，单位：度（°）
                    - ``rpm`` ：电机转动速度，默认转速30转/分（RPM）

            :void turnRight(unsigned int step, unsigned int rpm = 30);:

                - 底盘右转一定角度后停止。

                :参数:

                    - ``step`` ：右转角度，单位：度（°）
                    - ``rpm`` ：电机转动速度，默认转速30转/分（RPM）

            :void stop(void);:

                - 底盘停止运行。

