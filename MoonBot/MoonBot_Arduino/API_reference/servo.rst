Servo
=============

Overview
----------

MoonBot Kit :doc:`../../MoonBot_Hardware/MoonBot_Hardware_controller` can be connected up to four :doc:`../../MoonBot_Hardware/MoonBot_Hardware_servo` 。
In Arduino library, we provide :ref:`Servo <api-ref-servo>` library. Through this library, you can control one or more servos to move.

:ref:`Servo library <api-ref-servo>` inherit Arduino basic servo driver ``class Servo``. 
Except for basic ``Servo`` class function, we also provide functions like servo calibration, several servos move together.
In ``MoonBot.h`` header file, we provide four variables ``m_servo[kServo1]`` ``m_servo[kServo2]`` ``m_servo[kServo3]`` ``m_servo[kServo4]`` 
to drive corresponding servo ports in controller module.

Basic Application
++++++++++++++++

There is a basic application of servos.

.. literalinclude:: examples/ServoSweep.ino
   :language: cpp

.. note::

    Initial function of servos is changed to ``attach(moonbot_servo_t servo_port, bool reverse)``, and original function ``uint8_t attach(int pin)`` is not supported anymore.

Servos move together
+++++++++++++++++++++++

We provide ``void MoonBotServo::setTargetAngle()`` and ``MoonBotServo::moveAllServoToTarget()`` functions to make servos move togehther.

.. literalinclude:: examples/MoveAllServoTogether.ino
   :language: cpp

.. note::

    When using ``MoonBotServo::moveAllServoToTarget();`` default parameter, the function will wait for all servos finish moving and stopping.
    When parameter is not 0, it will stop when time is over, and feed back whether moving is finished.
	Function``bool isMoving(void);`` can be used every certain time to check the status.

    .. code-block:: cpp

        while (!MoonBotServo::moveAllServoToTarget(0)) {
            // Check whether servos are moving.
            for (int i = 0; i < kServoNum; ++i) {
                if (!m_servo[i].isMoving()) {
                    // when servos stop, print the status.
                    Serial.print("Servo");
                    Serial.print(i);
                    Serial.println(" Stopped.");
                }
            }
        }
        Serial.println("All Servo Stopped.");

    When using COM monitor, information will be received as below.

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

Servo Calibration
++++++++++++++++

MoonBot Kit :ref:`Servo library <api-ref-servo>` provide servo calibration function that can correct the offset of servos.

.. code-block:: cpp

    m_servo[kServo1].correction(-2);        //Calibrate servo 1 downwards for 2°

.. _api-ref-servo:

API Reference - Servo
----------------------

Header File
+++++++++++

    - `src/MoonBot_Servo.h <https://github.com/mu-opensource/MoonBot/blob/master/src/MoonBot_Servo.h>`_

Enum
++++++++++

.. glossary::

    enum moonbot_servo_t

        - servo port type

        *value:*

        :kServo1:
        :kServo2:
        :kServo3:
        :kServo4:
        :kServoNum:
            - servo port number

Class
++++++++++

.. glossary::

    class MoonBotServo

        - MoonBot Kit servo driver library

        :Member function:

            :uint8_t attach(moonbot_servo_t servo_port, bool reverse = MOONBOT_SERVO_REVERSE);:

                - Initialise servo to servo ports.

                :Parameter:

                    - ``servo_port`` 
                    - ``reverse`` 

                :Return:

                    - ``NOT_A_PORT`` Servo port is invalid, and other initialization is right.

            :uint8_t attach(moonbot_servo_t servo_port, int min, int max, bool reverse = MOONBOT_SERVO_REVERSE);:

                - Initialise servo to servo ports, and set its moving range.

                :Parameter:

                    - ``servo_port`` ：servo port
                    - ``min`` ：minimum degree of servo  
                    - ``max`` ：max degree of servo
                    - ``reverse`` ：reverse servo direction

                :Return:

                    - ``NOT_A_PORT`` Servo port is invalid, and other initialization is right.

            :void detach(void);:

                - Detach servo and port

            :void write(int value);:

                - Write servo angle

                :parameter:

                    - ``value`` ：angle value range ``0~180°``

            :int read(void);:

                - Read current servo degree

                :Return:

                    - current degree

            :void reverse(bool state);:

                - Reverse servo direction

                :parameter:

                    - ``state``: Status ``true`` Direction is reversed

            :void setTargetAngle(int angle, unsigned int speed = 1);:

                - Initialise servos.It should be used together with``static bool moveAllServoToTarget()`` .

                :parameter:

                    - ``angle`` : Initialised angle
                    - ``speed`` : degree of every pulse

            :void stop(void);:

                - stop servos

            :void power(bool state);:

                - open or close servo power.

                :parameter:

                    - ``state`` ：status of servo power, ``true`` means open

            :void correction(int angle_offset);:

                - Servo calibration

                :parameter:

                    - ``angle_offset`` ：Calibrate the angle. Range: ``±90°``

            :bool isMoving(void);:

                - Read moving status.

                :Return:

                    - ``true`` Servo is moving

            :bool isPowerOverload(void);:

                - Detect whether current is overload.

                :Return:

                    - ``true`` Power is overload

        :Static member function:

            :static bool moveAllServoToTarget(unsigned long timeToWait_ms = 0xFFFFFFFF);:

                - Move all servo to set angle

                :Parameter:

                    - ``timeToWait_ms`` : Default time is infinite, until servo move to target angle.
                
                :Return:

                    - ``true`` Finish all movement.

            :static void stopAllServo(void);:

                - Stop all servo movements.
