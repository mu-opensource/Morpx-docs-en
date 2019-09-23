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

MoonBot Kit 提供了丰富的眼睛动作库以供调用：

.. code-block:: cpp

    colorWipe(moonbot_eyes, 0x40, 200);         // 眼睛灯珠逐个变成绿色
    theaterChase(moonbot_eyes, 0xFF00, 50);     // 眼睛转圈
    MoonBotEyesCircle(moonbot_eyes, 50);        // 眼睛渐变转圈
    rainbow(moonbot_eyes, 5);                   // 眼睛彩虹色渐变
    rainbowCycle(moonbot_eyes, 5);              // 眼睛灯珠逐个以不同颜色开始彩虹色转圈渐变

.. _api-ref-motor:

API 参考 - Adafruit_NeoPixel
----------------------------------------------

详情见 Adafruit 官网介绍：`https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use <https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use>`_

.. _api-ref-led-action:

API 参考 - LED 眼睛动作
----------------------------------------------

头文件
+++++++++++

    - `src/MoonBot_Eyes.h <https://github.com/mu-opensource/MoonBot/blob/master/src/MoonBot_Eyes.h>`_

枚举类型
+++++++++++

.. glossary::

    enum moonbot_eyes_t

        - 眼睛类型

        *值:*

        :kEyesLeft:
            - 左眼
        :kEyesRight:
            - 右眼
        :kEyesBoth:
            - 双眼

    enum moonbot_look_t

        - 眼睛方向类型

        *值:*

        :kEyesLookUp:
            - 眼睛向上看
        :kEyesLookDown:
            - 眼睛向下看
        :kEyesLookLeft:
            - 眼睛向左看
        :kEyesLookRight:
            - 眼睛向右看

    enum moonbot_eyes_scroll_t

        - 眼睛滚动方向类型

        *值:*

        :kEyesScrollUp:
            - 眼睛向上滚动
        :kEyesScrollDown:
            - 眼睛向下滚动
        :kEyesScrollLeft:
            - 眼睛向左滚动
        :kEyesScrollRight:
            - 眼睛向右滚动

函数
++++++++++

.. glossary::

    void colorFade(Adafruit_NeoPixel& led, uint8_t r, uint8_t g, uint8_t b, uint8_t wait);

        - LED 颜色从当前颜色渐变到指定颜色。

        :参数:

            - ``led`` ：LED 类型
            - ``r`` ：红色通道值
            - ``g`` ：绿色通道值
            - ``b`` ：蓝色通道值
            - ``wait`` ：变化时间

    void colorWipe(Adafruit_NeoPixel& led, uint32_t c, uint8_t wait);

        - LED 灯光颜色逐个变化。

        :参数:

            - ``led`` ：LED 类型
            - ``c`` ：LED 灯光 RGB 颜色
            - ``wait`` ：灯光动作等待时间

    void rainbow(Adafruit_NeoPixel& led, uint8_t wait);

        - LED 灯光从彩虹色依次渐变。

        :参数:

            - ``led`` ：LED 类型
            - ``wait`` ：渐变时间

    void rainbowCycle(Adafruit_NeoPixel& led, uint8_t wait) ;

        - LED 每颗灯珠以不同颜色灯光从彩虹色依次渐变。

        :参数:

            - ``led`` ：LED 类型
            - ``wait`` ：渐变时间

    void theaterChase(Adafruit_NeoPixel& led, uint32_t c, uint8_t wait);

        - LED 以指定颜色转圈。

        :参数:

            - ``led`` ：LED 类型
            - ``c`` ：LED 灯光 RGB 颜色
            - ``wait`` ：灯光动作等待时间

    void MoonBotEyesLook(Adafruit_NeoPixel& led, moonbot_look_t look_tpye, uint32_t color);

        - LED 眼睛向某个方向看。

        :参数:

            - ``led`` ：LED 类型
            - ``look_tpye`` ：眼睛方向类型
            - ``color`` ：眼睛颜色

    void MoonBotEyesScroll(Adafruit_NeoPixel& led, moonbot_eyes_scroll_t scroll_tpye, uint32_t color, uint8_t wait = 50);

        - LED 眼睛向某个方向滚动。

        :参数:

            - ``led`` ：LED 类型
            - ``scroll_tpye`` ：眼睛滚动方向类型
            - ``color`` ：眼睛颜色
            - ``wait`` ：滚动时间，默认为50ms

    void MoonBotEyesCircle(Adafruit_NeoPixel& led, uint32_t color, moonbot_eyes_t eyes_type = kEyesBoth, uint8_t wait = 50);

        - LED 眼睛渐变转圈滚动。

        :参数:

            - ``led`` ：LED 类型
            - ``color`` ：眼睛颜色
            - ``eyes_type`` ：眼睛类型
            - ``wait`` ：滚动时间，默认为50ms
