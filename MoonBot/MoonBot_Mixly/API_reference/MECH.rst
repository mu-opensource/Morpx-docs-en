Mech
=========

**Mech** include :doc:`mech <../../MoonBot_Structure/MoonMech_Guide_cn>` Integrative Action in Morphology

By calling these modules, you can easily control the manipulator to catch the ball and so on.

.. image:: images/MECH.png

Initialization
--------------

.. image:: images/MECH_init.png

:Introduction:

    Initialize the MoonMech manipulator port.

:Parameters:

    :MU adress:

        - ``MU00`` ：MU address 0x60
        - ``MU01`` ：MU address 0x61
        - ``MU10`` ：MU address 0x62
        - ``MU11`` ：MU address 0x63

    :MU Port:

        - ``2,7,9``

    :Mech claw Steering engine port:

        - ``1~4``

    :Upper arm Steering engine port:

        - ``1~4``

    :Lower arm Steering engine port:

        - ``1~4``

Setting the position of catch ball
---------------

.. image:: images/MECH_set_grab_ball_position.png

:Introduction:

    Setting up the position of the MoonMech manipulator to grasp the ball,The mechanical gripper can catch the ball by adjusting the X-Y value of the recognition ball.

    When the ball is within the given X-Y value range, the mechanical claw closes to grasp the ball.

:Parameters:

    :X:

        - ``0~100`` :Horizontal position of mechanical claw grip ball，The horizontal position of the mechanical claw relative to the ball can be adjusted by modifying this value.

    :Y:

        - ``0~100`` :Vertical position of mechanical claw catching ball,The vertical height of the gripper can be adjusted by modifying this value.

Setting Shooting Conditions
---------------

.. image:: images/MECH_shoot_condition.png

:Introduction:

    Setting up the conditions of MoonMech mechanical claw shooting，The horizontal position X and width of the card can be adjusted to allow the manipulator to shoot accurately into the basket.

    When the card  within the given X-width range, the arm triggers the shooting action to shoot.

:Parameters:

    :X:

        - ``0~100`` ：Horizontal position relative to transverse coordinate X of card when shooting with mechanical claw，The horizontal position of the gripper relative to the card can be adjusted by modifying this value.

    :Width:

        - ``0~100`` ：The size of the card when the mechanical claw shoots,The distance between MoonMECH mechanical arm and basket (card) can be adjusted by modifying this value.

Claw movement
---------------

.. image:: images/MECH_claw_set.png

:Introduction:

    Set up mechanical claw action. This module can be used to control the horizontal or up-down translation of the mechanical claw.

:Parameters:

    :action:

        - ``open`` ：Open the mechanical claw（110°）
        - ``close`` ：Close the mechanical claw（90°）
        - ``forward`` ：The mechanical claw advances horizontally in a unit.
        - ``back`` ：The mechanical claw retreats one unit horizontally
        - ``up`` The mechanical claw is vertically upward in a unit.
        - ``down`` ：A vertical downward unit of a mechanical claw.

Find the ball
-------------

.. image:: images/MECH_search_ball.png

:Introduction:

    Control MoonMech manipulator to perform ball searching.

:Return:

    - ``true`` :Find the ball
    - ``false``:No ball was found.

Catch the ball
-------------

.. image:: images/MECH_grab_ball.png

:Introduction:

    Control MoonMech manipulator to perform catch action.
    
    If the ball manipulator is not found during execution of this block, MoonMech will remain in place and return ``false``。

:Return:

    - ``true`` :Catch the ball
    - ``false``:No ball was found.

Find the card
-------------

.. image:: images/MECH_search_card.png

:Introduction:

    The MoonMech manipulator is controlled to perform the search basket (card) action.

:Parameters:

    :card type:

        - ``shape card``
        - ``traffic card``
        - ``number card``

:Return:

    - ``true`` :Find the given card
    - ``false``:No given card was found

Shoot
-------------

.. image:: images/MECH_shoot_ball.png

:Introduction:

    Control MoonMech manipulator to execute shooting action.
    
    If the ball manipulator is not found during execution of this block, MoonMech will remain in place.
