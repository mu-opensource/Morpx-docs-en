Motor
==========

Overview
----------

MoonBot Kit :doc:`../../MoonBot_Hardware/MoonBot_Hardware_motor` includes motor and encoder. In Arduino library we provide :ref:`motor <api-ref-motor>` library
to drive single motor, and :ref:`chassis control <api-ref-tankbase>` library to drive dual motors.

We can include ``MoonBot.h`` header file to call ``TankBase`` to drive motor chassis, or call ``Motor1`` ``Motor2`` to control single motor.

Chassis control
++++++++++++++

How to make the chassis move around? Check this simple example: 

.. literalinclude:: examples/tankbase_move.ino
   :language: cpp

Through ``TankBase.write()`` function, write motor speed of left and right motor can make the chassis move.

If you want to control the motor speed accurately, use ``TankBase.writeRpm()`` function instead.

.. code-block:: cpp

      // Chassis turn left, with left motor speed 30 RPM, and right -30 RPM. 
      TankBase.writeRpm(30, -30);

.. note::

    Use functions that can control accurate speed of the motor like ``TankBase.write()`` ``TankBase.writeDistance()`` ``TankBase.writeAngle()`` , 
	you need to connect the encoder to its port, and initialize function ``TankBase.begin()`` , and change the parameter ``enc_enable`` to ``true`` (default is ``true`` )
    You can also make motor move certain angle or distance.

.. code-block:: cpp

    void loop() {
        TankBase.writeDistance(30, 20);     // Chassis move forward for 20 cm with the speed of 30 RPM
        while(TankBase.read(kLeftMotor) || TankBase.read(kRightMotor));     // Wait for the chassis to stop
        delay(100);
        TankBase.writeAngle(30, 180);       // Chassis turn right for 180 degrees with the speed of 30 RPM
        while(TankBase.read(kLeftMotor) || TankBase.read(kRightMotor));     // Wait for the chassis to stop
        delay(100);
    }

.. note::

    Because of fix devations or friction force, you will find chassis can not go straight. You can use following calibration functions to correct it.

    .. code-block:: cpp

        void setup() {
            TankBase.rpmCorrection(82);           // Calibrate speed offset %
            TankBase.distanceCorrection(120);     // Calibrate distance offset %
            TankBase.wheelSpacingSet(100);        // Calibrate angle offset %
        }

Control Single Motor
++++++++++++++++

If you only want to control single motor, call ``Motor1`` ``Motor2`` to achieve.

.. code-block:: cpp

    Motor1.write(100);      // Set motor1 analog value to 100
    Motor2.write(100);      // Set motor1 analog value to 100
    Motor1.writeRpm(30);    // Set motor1 speed to 30 RPM
    Motor2.writeRpm(30);    // Set motor1 speed to 30 RPM

.. _api-ref-motor:

API Reference - Motor
----------------------

Header File
+++++++++++

    - `src/MoonBot_Motor.h <https://github.com/mu-opensource/MoonBot/blob/master/src/MoonBot_Motor.h>`_

Enum Type
+++++++++++

.. glossary::

    enum moonbot_motor_t

        - motor port type

        *value:*

        :kMotor1=0:
        :kMotor2:
        :kMotorNum:

Class
+++++

.. glossary::

    class Motor

        - Single motor driver

        :member function:

            :Motor(moonbot_motor_t motor_type);:

                - constructed function, define port type

                :parameter:

                    - ``motor_type`` 

            :int begin(const bool reverse_dir = false, const bool enc_enable = true);:

                - Initialize motor in the given port

                :parameter:

                    - ``reverse_dir`` : Reverse motor rotate direction, ``false`` by default
                    - ``enc_enable`` : Enable encoder, ``true`` by default

                :return:

                    - ``0`` :Initailization succeed
                    - ``-1`` : Can not find the motor port

            :void write(int vol);:

                - Write analog value

                :parameter:

                    - ``vol`` : Value of the voltage, with range of **±255** ,>0 means CW，<0 means CCW

            :int read(void);:

                - Read the analog value

                :return:

                    - ``±255`` : Analog value

            :void writeStep(uint32_t step, int rpm = 30);:

                - Drive motor with certain speed and steps and then stop.
                - This function will use encoder, and encoder must be opened in ``begin()`` function.

                :parameter:

                    - ``step`` : Rotation step, 240 steps per cycle
                    - ``rpm`` : Motor rotation speed, 30 RPM per cycle

            :void writeRpm(int rpm = 30);:

                - Write motor speed, unit: RPM
                - This function will use encoder, and encoder must be opened in ``begin()`` function.

                :parameter:

                    - ``rpm`` : Motor rotation speed, 30 RPM by default

            :int readRpm(void);:

                - Read motor speed, unit: RPM
                - This function will use encoder, and encoder must be opened in ``begin()`` function.

                :return:

                    - Motor rotate speed

            :void writeDistance(int rpm, uint32_t distance_cm);:

                - Drive motor with certain speed and distance and then stop. Because of the offsets, please use``distanceCorrection()`` function to calibrate.
                - This function will use encoder, and encoder must be opened in ``begin()`` function.

                :parameter:

                    - ``rpm`` : Motor rotation speed 
                    - ``distance_cm`` : Moving distance, unit: cm

            :uint32_t readEncoderPulse(void);:

                - Read encoder value
                - This function will use encoder, and encoder must be opened in ``begin()`` function.

                :return:

                    - Current encoder value

            :void rpmCorrection(uint8_t percent);:

                - Motors RPM calibration

                :parameter:

                    - ``percent`` : Calibration percentage. >100 means increase , <100 means decrease

            :void distanceCorrection(uint8_t percent);:

                - Motors distance calibration

                :parameter:

                    - ``percent`` : Calibration percentage. >100 means increase distance, <100 means decrease


.. _api-ref-tankbase:

API Reference - Chassis Control
----------------------

Header File
+++++++++++

    - `src/MoonBot_TankBase.h <https://github.com/mu-opensource/MoonBot/blob/master/src/MoonBot_TankBase.h>`_

Enum Type
+++++++++++

.. glossary::

    enum motor_type_t

        - motor type

        *value:*

        :kLeftMotor=0:
            - left motor
        :kRightMotor:
            - right motor

Class
+++++

.. glossary::

    class MoonBotTankBase

        - Chassis dual motor driver

        :member function:

            :MoonBotTankBase(Motor& left_motor, Motor& right_motor);:

                - constructed function, define two motors to the port

                :parameter:

                    - ``left_motor`` 
                    - ``right_motor`` 

            :int begin(const bool reverse_dir = false, const bool enc_enable = true);:

                - Initialize chassis motors

                :parameter:

                    - ``reverse_dir`` : Reverse rotation direction, ``false`` by default
                    - ``enc_enable`` : Enable encoder, ``true`` by default

                :return:

                    - ``0`` : Initialization succeed
                    - ``-1`` : Can not find the motor port

            :int begin(const bool left_reverse_dir, const bool right_reverse_dir, const bool enc_enable);:

                - Initialize chassis motors

                :parameter:

                    - ``left_reverse_dir`` : Reverse left motor rotation direction
                    - ``right_reverse_dir`` : Reverse right motor rotation direction
                    - ``enc_enable`` : Enable encoder

                :return:

                    - ``0`` : Initialization succeed
                    - ``-1`` : Can not find the motor port

            :void write(int left_vol, int right_vol);:

                - Write analog value to motors

                :parameter:

                    - ``left_vol`` : Left motor voltage, range of **±255** , >0 means CW, <0 means CCW
                    - ``right_vol`` : Right motor voltage, range of **±255** , >0 means CW, <0 means CCW

            :int read(motor_type_t motor_type);:

                - Read analog value from motors

                :parameter:

                    - ``motor_type`` 

                :return:

                    - ``±255`` : Analog value

            :uint32_t readEncoderPulse(motor_type_t motor_type);:

                - Read motor encoder value
                - This function call encoder, and should be opened after ``begin()`` function

                :parameter:

                    - ``motor_type`` 

                :return:

                    - Current encoder value

            :void writeRpm(int left_rpm, int right_rpm);:

                - Write motors speed, unit: RPM
                - This function will use encoder, and encoder must be opened in ``begin()`` function.

                :parameter:

                    - ``left_rpm`` : Left motor rotation speed 
                    - ``right_rpm`` : Right motor rotation speed 

            :int readRpm(motor_type_t motor_type);:

                - Read motors speed, unit: RPM
                - This function will use encoder, and encoder must be opened in ``begin()`` function.

                :parameter:

                    - ``motor_type`` 

                :return:

                    - Motor rotation speed 

            :void writeDistance(int rpm, uint32_t distance_cm);:

                - Drive motors with certain distance and stop. Because of the offsets, please use ``rpmCorrection（）`` and ``distanceCorrection()`` function to calibrate.
                - This function will use encoder, and encoder must be opened in ``begin()`` function.

                :parameter:

                    - ``rpm`` ：Motor rotation speed 
                    - ``distance_cm`` : Moving distance, unit: cm

            :void writeAngle(int rpm, uint32_t angle);:

                - Drive motors with certain distance and stop. Because of the offsets, please use ``rpmCorrection（）`` and ``wheelSpacingSet()`` function to calibrate.
                - This function will use encoder, and encoder must be opened in ``begin()`` function.

                :parameter:

                    - ``rpm`` : Motor rotation speed 
                    - ``angle`` : Rotation angle, unit: degree(°)

            :void wheelSpacingSet(int correct, float space_cm = 0);:

                - Set wheel spacing and calibrate turn angle. This function can calibrate that wheel can not turn the accurate angle

                :parameter:

                    - ``correct`` Correction value, >100 means angle increase, <100 means decrease
                    - ``space_cm`` : Motor spacing

            :void rpmCorrection(int percent);:

                - Calibrate the speed of left and right motor

                :parameter:

                    - ``percent`` : Calibration value, >100 means calibrate to right, <100 means calibrate to left

            :void distanceCorrection(int percent);:

                - Calibrate moving distance

                :parameter:

                    - ``percent`` : Calibration value, >100 means increase distance, <100 means decrease

            :void forward(unsigned int step, unsigned int rpm = 30);:

                - Chassis move forward for certain distance and stop

                :parameter:

                    - ``step`` : Forward distance, unit: cm
                    - ``rpm`` : Motor rotate speed, 30RPM by default

            :void backward(unsigned int step, unsigned int rpm = 30);:

                - Chassis move backward for certain distance and stop

                :parameter:

                    - ``step`` : Back distance, unit: cm
                    - ``rpm`` : Motor rotate speed, 30RPM by default

            :void turnLeft(unsigned int step, unsigned int rpm = 30);:

                - Chassis turns left for certain degrees and stop

                :parameter:

                    - ``step`` : Left turn angle, unit: degree(°)
                    - ``rpm`` : Motor rotate speed, 30 RPM by default

            :void turnRight(unsigned int step, unsigned int rpm = 30);:

                - Chassis turns right for certain degrees and stop

                :parameter:

                    - ``step`` : Right turn angle, unit: degree(°)
                    - ``rpm`` : Motor rotate speed, 30 RPM by default

            :void stop(void);:

                - Chassis stop moving

