Steering engine
=========

**Steering engine** include MoonBot Kit :doc:`../../MoonBot_Hardware/MoonBot_Hardware_servo` drives,It can be used to drive the steering gear connected to the four rudder ports in MoonBot Kit.So the actuator with one or more ports can move simultaneously.

.. image:: images/servo.png

Setting Angles
-----------

.. image:: images/servo_write.png

:Introduction:

    Write the angle to the steering gear connected to the specified steering port.

:Parameters:

    :steering gear port:

        - ``1~4``

    :angel:

        - ``0~180°``

Reading angel
-----------

.. image:: images/servo_read.png

:Introduction:

    Reads the current angle value of the specified steering port.

:Parameters:

    :steering gear port:

        - ``1~4``

Presupposition angle
----------

.. image:: images/servo_set_angle.png

:Introduction:

    Preset the steering angle and speed of the specified steering gear port.

    The module should be used in conjunction with the `synchronous movement of all steering gear to the preset angle `module.

:Parameters:

    :steering gear port:

        - ``1~4``

    :speed:

        - ``fast`` :Set the speed of steering gear to be fast（about150°/s）
        - ``mid`` :Set the steering gear running at medium speed（about 100°/s）
        - ``slow`` :Set the speed of steering gear to slow（about 50°/s）

Synchronize all steering gear to preset angle
---------------------------------

.. image:: images/servo_move_all.png

:Introduction:

    Move all steering gear to the preset angle.

    The module needs to be used in conjunction with the `preset angle' module.

Reversal direction
------------

.. image:: images/servo_reverse.png

:Introduction:

    The steering angle is reversed with 90 degree as the median value.

:Parameters:

    - ``false`` :Default Motion Direction
    - ``true`` :Turn the steering gear in the direction of motion

Correcting
----------

.. image:: images/servo_correction.png

:Introduction:

    Errors in production and installation of gears and steering gear disks may cause steering gear to fail to turn at specified angles.

    The angle error caused by the above reasons can be corrected by the steering gear calibration module.

:Parameters:

    - ``±90°``
