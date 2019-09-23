Pin Map
=============

Overview
----------

MoonBot Kit :doc:`../../MoonBot_Hardware/MoonBot_Hardware_controller` contains 9 GPIO ports, 4 servo ports, two motor ports and other on board resources.
And in Arduino library we provide :ref:`pin map<api-ref-pins>` livrary and relevant defined pin to guide users requiring corresponding pin number.

Through these functions and macros, we can easily get pin numbers of MoonBot Kit controller.

Get Keys Status
+++++++++++++++++++++

For example, turn on the on-board LEDs by getting button status.

.. code-block:: cpp

    #include <MoonBot.h>

    int button_a = MOONBOT_PIN_BUTTON_A;        // Get button A pin number
    int button_b = MOONBOT_PIN_BUTTON_B;        // Get button B pin number

    void setup()
    {
        LED.begin();        // On board LEDs begin
    }

    void loop()
    {
        if ((!digitalRead(button_a) && !digitalRead(button_b))) {
            // If button A and B is pressed at mean time, LED 0 and 1 show cyan.
            LED.setPixelColor(0, 0x00ffff);
            LED.setPixelColor(1, 0x00ffff);
            LED.show();
        } else if ((!digitalRead(button_a))) {
            // If only button B is pressed, LED 0 show green
            LED.setPixelColor(0, 0x00ff00);
            LED.setPixelColor(1, 0x000000);
            LED.show();
        } else if ((!digitalRead(button_b))) {
            // If only button A is pressed, LED 1 show blue.
            LED.setPixelColor(0, 0x000000);
            LED.setPixelColor(1, 0x0000ff);
            LED.show();
        } else {
            // If buttons are not pressed, LEDs turn off.
            LED.setPixelColor(0, 0x000000);
            LED.setPixelColor(1, 0x000000);
            LED.show();
        }
    }

Get LED Eyes Pin Number
+++++++++++++++++++++

Initialize LED by getting the status of :doc:`../../MoonBot_Hardware/MoonBot_Hardware_eyes` on port 3.

.. code-block:: cpp

  moonbot_eyes.setPin(moonbotPortToPin(kPort3, kPortPin1));     // Set port 3 as the first pin of LED eyes.
  moonbot_eyes.begin();         // Initialize LED eyes

Get Touch Module status
+++++++++++++++++++++

Read status of :doc:`../../MoonBot_Hardware/MoonBot_Hardware_touch` on the GPIO ports.

.. literalinclude:: examples/read_touch_state.ino
   :language: cpp

Get Infrared Module Status
+++++++++++++++++++++

We can use the same way to read the status of :doc:`../../MoonBot_Hardware/MoonBot_Hardware_infrared`.

.. literalinclude:: examples/read_ir_state.ino
   :language: cpp


.. Attention::

    Infrared module is in low level when touched, and pin mode is ``LOW``; And it is not touched when level is ``HIGH``.

.. _api-ref-pins:

API Reference - Pin Map
----------------------

Header File
+++++++++++

    - `src/pins_moonbot.h <https://github.com/mu-opensource/MoonBot/blob/master/src/pins_moonbot.h>`_

Enum
+++++++++

.. glossary::

    enum moonbot_servo_t

        - MoonBot Kit servo port

        *value:*

        :kServo1=0:
        :kServo2:
        :kServo3:
        :kServo4:
        :kServoNum:

            - servo port number

    enum servo_pin_t

        - servo port type

        *value:*

        :kSignal:

            - servo signal pin

        :kShutDown:

            - servo power pin

        :kState:

            - servo status pin

    enum moonbot_motor_t 

        - MoonBot Kit motor port

        *value:*

        :kMotor1=0:
        :kMotor2:
        :kMotorNum:

            - motor port number


    enum motor_pin_t

        - motor port type

        *value:*

        :kDirection:

            - motor direction pin

        :kSpeed:

            - motor speed pin

    enum moonbot_port_t

        - MoonBot Kit GPIO port

        *value:*

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

            - GPIO port number

    enum port_pin_t

        - GPIO port type

        *value:*

        :kPortPin1=0:
        :kPortPin2:
        :kPortPinNum:

            - port pin number

Macro Definition
+++++++++

.. glossary::

    MOONBOT_PIN_LED

        - MoonBot Kit contrller on-board LED pin

    MOONBOT_PIN_BUZZER_SIG 

        - MoonBot Kit controller buzzer signal pin

    MOONBOT_PIN_BUZZER_SHDW

        - MoonBot Kit controller buzzer power pin

    MOONBOT_PIN_BUTTON_A

        - MoonBot Kit controller button A pin

    MOONBOT_PIN_BUTTON_B

        - MoonBot Kit controller button B pin

Functions
+++++++++

.. glossary::

    uint8_t moonbotPortToPin(moonbot_port_t port_num, port_pin_t pin_num);

        - Get MoonBot Kit controller Arduino pin number of the GPIO port.

        :value:

            - ``port_num``: GPIO port
            - ``pin_num``: port pin number

        :return:

            - Arduino pin number of the port pin

    uint8_t moonbotMotorToPin(moonbot_motor_t motor_num, motor_pin_t pin_type);

        - Get MoonBot Kit controller Arduino pin number of the motor port.

        :value:

            - ``motor_num`` : motor port number
            - ``pin_type`` : motor pin type

        :return:

            - motor port Arduino pin

    uint8_t moonbotServoToPin(moonbot_servo_t servo_num, servo_pin_t pin_type);

        - Get MoonBot Kit controller Arduino pin number of the servo port.

        :value:

            - ``servo_num`` : servo port number
            - ``pin_type`` : servo pin type

        :return:

            - servo port Arduino pin



