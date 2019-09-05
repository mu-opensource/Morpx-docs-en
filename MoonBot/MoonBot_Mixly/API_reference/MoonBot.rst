MoonBot
==========

**MoonBot** include :doc:`MoonBot robot <../../MoonBot_Structure/MoonBot_Guide_cn>` Integrative Action in Morphology.

By calling these modules, you can control the robot to perform nodding, waving and other actions.

.. image:: images/MoonBot.png

Initialization
----------

.. image:: images/MoonBot_init.png

:Introduction:

    Initialize the ports of the MoonBot robot.

:Parameters:

    :Head steering gear:

        - ``1~4``

    :Left-handed steering gear:

        - ``1~4``

    :Right-handed steering gear:

        - ``1~4``

Wave
----------

.. image:: images/MoonBot_shake_arm.png

:Introduction:

    The arm that drives the robot waves.

:Parameters:

    :Arm:

        - ``Left hand``
        - ``Right hand``
        - ``Both hands``
    
    :deviation:

        - ``0~90`` :Deviation Angle of Up and Down Waves of Robot

    :Speed:

        - ``fast``
        - ``mid``
        - ``slow``

Swing
----------

.. image:: images/MoonBot_swing.png

:Introduction:

    The head and foot of the robot are swing at the same time.

:Parameters:

    :Motor:

        - ``Left motor``
        - ``Right motor``
        - ``Dual motor``

    :Speed:

        - ``fast``
        - ``mid``
        - ``slow``

Shake your body from side to side
-----------------

.. image:: images/MoonBot_sway_body.png

:Introduction:

    Control the robot motor to sway left and right.

:Parameters:

    :Speed:

        - ``fast``
        - ``mid``
        - ``slow``

    :Time:

        - ``0～+∞`` :Single shaking time of motor

Step Forward
-----------

.. image:: images/MoonBot_take_step.png

:Introduction:

    Controlling the robot takes a step forward.

:Parameters:


    :Speed:

        - ``fast``
        - ``mid``
        - ``slow``

    :Time:

        - ``0～+∞`` :The longer the motor takes a step forward, the bigger the step is.

Nod
---------

.. image:: images/MoonBot_nod.png

:Introduction:

    The control robot nodded once.

:Parameters:

    :deviation:

        - ``0~90°`` :Nodding range
    
    :Speed:

        - ``fast``
        - ``mid``
        - ``slow``

