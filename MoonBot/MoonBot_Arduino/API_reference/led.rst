Light
=============

Overview
----------

MoonBot Kit contains two sets of light modules，Respectively located  :doc:`../../MoonBot_Hardware/MoonBot_Hardware_controller` and :doc:`../../MoonBot_Hardware/MoonBot_Hardware_eyes` 。
We can use `Adafruit_NeoPixel <https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use>`_ library to drive these two sets of light modules.

We can drive two on-board LED lights by calling `LED'.Drive 12 LED eyes by calling `moonbot_eyes'.At the same time, through the call: ref: `LED eye movement < api-ref-led-action > ` let the eyes make a rich expression.

LED Foundation driven
+++++++++++++++++

.. code-block:: cpp

    #include <MoonBot.h>

    void setup() {
        // enable main control LED
        LED.begin();
        moonbot_eyes.begin();
        //  clear LED color
        LED.clear();
        LED.show();
        moonbot_eyes.clear();
        moonbot_eyes.show();
    }

    void loop() {
        if (digitalRead(MOONBOT_PIN_BUTTON_A) == LOW
            && digitalRead(MOONBOT_PIN_BUTTON_B) == LOW) {
            // If A&B is pressed at the same time
            // LED and eye lights display cyan
            LED.fill(0x003030);
            LED.show();
            moonbot_eyes.fill(0x003030);
            moonbot_eyes.show();
        } else if (digitalRead(MOONBOT_PIN_BUTTON_A) == LOW) {
            // If key A is pressed
            // LED0，The right eye display green.
            LED.setPixelColor(0, 0x003000);
            LED.setPixelColor(1, 0);
            LED.show();
            moonbot_eyes.clear();
            moonbot_eyes.fill(0x003000, 0, 6);
            moonbot_eyes.show();
        } else if (digitalRead(MOONBOT_PIN_BUTTON_B) == LOW) {
            // If key B is pressed
            // LED1，The left eye display green.
            LED.setPixelColor(0, 0);
            LED.setPixelColor(1, 0x000030);
            LED.show();
            moonbot_eyes.clear();
            moonbot_eyes.fill(0x000030, 6, 6);
            moonbot_eyes.show();
        } else {
            // LED Eye lights off
            LED.clear();
            LED.show();
            moonbot_eyes.clear();
            moonbot_eyes.show();
        }
    }

LED Eye Lighting Action
+++++++++++++++++++++

MoonBot Kit provides abundant Eye action to be used: 

.. code-block:: cpp

    colorWipe(moonbot_eyes, 0x40, 200);         // LEDs turn green one by one
    theaterChase(moonbot_eyes, 0xFF00, 50);     // Eyes turn around
    MoonBotEyesCircle(moonbot_eyes, 50);        // Eyes turn around gradually
    rainbow(moonbot_eyes, 5);                   // Eyes show rainbow color
    rainbowCycle(moonbot_eyes, 5);              // Eyes show rainbow color one by one

.. _api-ref-motor:

API Reference - Adafruit_NeoPixel
----------------------------------------------

Check Adafruit official website for detailed information: `https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use <https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use>`_

.. _api-ref-led-action:

API Reference - LED Eyes Action
----------------------------------------------

Header File
+++++++++++

    - `src/MoonBot_Eyes.h <https://github.com/mu-opensource/MoonBot/blob/master/src/MoonBot_Eyes.h>`_

Enum
+++++++++++

.. glossary::

    enum moonbot_eyes_t

        - eyes type

        *value:*

        :kEyesLeft:
            - left eye
        :kEyesRight:
            - right eye
        :kEyesBoth:
            - both eyes

    enum moonbot_look_t

        - direction that eyes look at

        *value:*

        :kEyesLookUp:
            - Eyes look up
        :kEyesLookDown:
            - Eyes look down
        :kEyesLookLeft:
            - Eyes look left
        :kEyesLookRight:
            - Eyes look right

    enum moonbot_eyes_scroll_t

        - eyes scroll type

        *value:*

        :kEyesScrollUp:
            - eyes scroll up
        :kEyesScrollDown:
            - eyes scroll down
        :kEyesScrollLeft:
            - eyes scroll left
        :kEyesScrollRight:
            - eyes scroll right

Functions
++++++++++

.. glossary::

    void colorFade(Adafruit_NeoPixel& led, uint8_t r, uint8_t g, uint8_t b, uint8_t wait);

        - LED eyes turn to target color gradually

        :parameter:

            - ``led`` : LED type
            - ``r`` : value of red channel
            - ``g`` : value of green channel
            - ``b`` : value of blue channel
            - ``wait`` : time to wait

    void colorWipe(Adafruit_NeoPixel& led, uint32_t c, uint8_t wait);

        - LED change color one by one

        :parameter:

            - ``led``: LED type
            - ``c``: REG color of the LED
            - ``wait``: time to wait for action

    void rainbow(Adafruit_NeoPixel& led, uint8_t wait);

        - LED light shine rainbow color

        :parameter:

            - ``led`` : LED type
            - ``wait`` : time to wait

    void rainbowCycle(Adafruit_NeoPixel& led, uint8_t wait) ;

        - LED change light of rainbow color gradually

        :parameter:

            - ``led`` : LED type
            - ``wait`` : time to wait for changing

    void theaterChase(Adafruit_NeoPixel& led, uint32_t c, uint8_t wait);

        - LED turn around with target color

        :parameter:

            - ``led`` : LED type
            - ``c`` : RGB color of LED light
            - ``wait`` : time to wait for action

    void MoonBotEyesLook(Adafruit_NeoPixel& led, moonbot_look_t look_tpye, uint32_t color);

        - LED eyes look to the direction

        :parameter:

            - ``led`` : LED type
            - ``look_tpye`` : the direction that eyes looks to
            - ``color`` : eyes color

    void MoonBotEyesScroll(Adafruit_NeoPixel& led, moonbot_eyes_scroll_t scroll_tpye, uint32_t color, uint8_t wait = 50);

        - LED eyes scroll to the direction

        :parameter:

            - ``led`` : LED type
            - ``scroll_tpye`` : direction that eyes scroll to
            - ``color`` : LED color type
            - ``wait`` : time to wait, 50ms by default

    void MoonBotEyesCircle(Adafruit_NeoPixel& led, uint32_t color, moonbot_eyes_t eyes_type = kEyesBoth, uint8_t wait = 50);

        - LED eyes turn around gradually

        :parameter:

            - ``led`` : LED type
            - ``color`` : eyes color
            - ``eyes_type`` : eyes type
            - ``wait`` : circle time, 50ms by default
