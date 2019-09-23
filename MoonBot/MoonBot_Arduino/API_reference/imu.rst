IMU
=============

Introduction
----------

MoonBot Kit :doc:`../../MoonBot_Hardware/MoonBot_Hardware_controller` integrates three functions of triaxial magnetometer, triaxial acceleration and temperature sensor into IMU module.
In the Arduino library, we also provide ref:`IMU < api-ref-imu >` library to facilitate users to access the master control of the current attitude, direction, temperature and other states.

By calling `IMU', we can quickly obtain the current compass angle, pitch angle, roll angle, gravity acceleration, temperature and other state values.

Read master control current direction
+++++++++++++++++++++

By reading the angle of the compass, we can know the direction of the current master control:

.. code-block:: cpp

    #include <MoonBot.h>

    void setup()
    {
      IMU.enable();         // IMU Enable
      IMU.calibrateMag();   // IMU magnetometer calibration,the master control needs to flip in the shape of ”∞“
    }

    void loop()
    {
      Serial.print("compass:");
      // Obtain the compass angle(0~360°).When pointing north, the value is 0 or 360
      Serial.println(IMU.getMagAngle());
    }

.. note::

    When the main control is flat, the return value is Y axis (see the master control front silk mark) and the northward clip.
	When the main control is erected, the return value is the angle between Z axis and North direction.

Obtain Pitch angle or Rolling angle
+++++++++++++++++++++++

.. code-block:: cpp

    // Obtain Pitch angle（±180°），When the main control is up, the angle is positive and the downward angle is negative.
    int pitch = IMU.getAccAngle(kAccPitch);
    // Obtain Rolling angle（±180°），The main control right deviation is positive and the left deviation is negative.
    int roll = IMU.getAccAngle(kAccRoll);

.. note::

    MoonBot Kit The main control direction is Y axis (see the main control front silk mark)，Angles are calculated on this premise.。

Acquisition of current acceleration
+++++++++++++++++++++++

.. code-block:: cpp

    // Acquisition of acceleration，unit：g，The value at rest is 1.0.
    float acceleration = IMU.getAcceleration();

Obtain the current motion state
++++++++++++++++++

.. code-block:: cpp

    void loop() 
    {
        if (IMU.on(kIMUShake)) {
            // If the current master is shaking
            // bright red LED
            LED.setPixelColor(0, 0xff0000);
            LED.setPixelColor(1, 0xff0000);
            LED.show();
        } else if (IMU.on(kIMUFreeFall)) {
            // If the current master is in free fall
            // bright green LED
            LED.setPixelColor(0, 0x00ff00);
            LED.setPixelColor(1, 0x00ff00);
            LED.show();
        } else {
            // If the main control is stationary
            // close LED
            LED.setPixelColor(0, 0x000000);
            LED.setPixelColor(1, 0x000000);
            LED.show();
        }
    }

.. _api-ref-imu:

API Reference - IMU
----------------------

Header file
+++++++++++

    - `src/LSM303AGR_IMU_Sensor.h <https://github.com/mu-opensource/MoonBot/blob/master/src/LSM303AGR_IMU_Sensor.h>`_

enumeration
++++++++++

.. glossary::

    enum lsm303_axes_t

        - IMU Directional axis type

        *value:*

        :kDirX:
        :kDirY:
        :kDirZ:

    enum lsm303_acc_angle_t

        - IMU Attitude Angle Type。

        *value:*

        :kAccRoll:
        :kAccPitch:

    enum imu_state_t

        - IMU Special state type.

        *value:*

        :kIMUShake:

            - IMU Is it in a sloshing state

        :kIMUFreeFall:

            - IMU Is it in a free falling state

Class
++++++++++

.. glossary::

    class LSM303AGR_IMU_Sensor

        - IMU Drive.

        :group function:

            :int enable(void);:

                - enable IMU 

                :Return:

                    - ``0`` enable success, unable failure

            :int advGetMagAngle(lsm303_axes_t main_axes, lsm303_axes_t sub_axes);:

                - Get the plane where the specified spindle and vice-spindle are located, and the angle between the spindle and the North side.

                :parameters:

                    - ``main_axes`` ：Spindle
                    - ``sub_axes`` ：Countershaft

                :Return:

                    - Angle between the spindle and the North

            :int getMagAngle(void);:

                - Obtain the compass angle，When the main control is placed horizontally, the angle between the positive direction of Y axis and the north is returned; 
				when the main control is placed vertically, the angle between the positive direction of Z axis and the north is returned.

                :Return:

                    - Angle between the spindle and the North

            :int getAccAngle(lsm303_acc_angle_t angle_type);:

                - Obtain the main control angle.

                :parameters:

                    - ``angle_type`` ：angle type

                :Return:

                    - angle

            :float getAcceleration(void);:

                - Acquisition of acceleration value。

                :Return:

                    - Acceleration value，unit：g

            :bool on(imu_state_t imu_state);:

                - Get whether the master control is in some state。

                :parameters:

                    - ``imu_state`` ：IMU state

                :Return:

                    - ``true`` IMU In this state,Otherwise, it is not in this state.

            :bool calibrateMag(void);:

                - Calibration of Magnetometer

                :Return:

                    - Whether the calibration is completed or not

            :int16_t temperature(void);:

                - Obtain the original temperature value

                :Return:

                    - Primitive value of temperature

            :float temperatureC(void);:

                - Get the current temperature，unit：Celsius degree

                :Return:

                    - Current temperature，unit：Celsius degree

            :float temperatureF(void);:

                - Current temperature，unit：Fahrenheit degree

                :Return:

                    - Current temperature，unit：Fahrenheit degree

        :group variable:

            :LSM303AGR_ACC_Sensor Acc;:

                - Acceleration drive

            :LSM303AGR_MAG_Sensor Mag;:

                - Magnetometer drive


