灯光
=============

概览
----------

MoonBot Kit 中包含了两组灯光模块，分别位于  :doc:`../../MoonBot_Hardware/MoonBot_Hardware_controller` 和 :doc:`../../MoonBot_Hardware/MoonBot_Hardware_eyes` 。
我们可以使用 `Adafruit_NeoPixel <https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use>`_ 库去驱动这两组灯光模块。

我们可以通过调用 ``LED`` 来驱动板载的两颗 LED 灯，通过调用 ``moonbot_eyes`` 来驱动12颗 LED 眼睛。同时通过调用 :ref:`LED 眼睛动作 <api-ref-led-action>` 让眼睛做出丰富的表情。

LED 基础驱动
+++++++++++++++++

.. code-block:: cpp

    #include <MoonBot.h>

    void setup() {
        // 使能主控LED
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
            // 如果A&B同时被按下
            // LED和眼睛灯光显示青色
            LED.fill(0x003030);
            LED.show();
            moonbot_eyes.fill(0x003030);
            moonbot_eyes.show();
        } else if (digitalRead(MOONBOT_PIN_BUTTON_A) == LOW) {
            // 如果按键A被按下
            // LED0，眼睛右眼显示绿色
            LED.setPixelColor(0, 0x003000);
            LED.setPixelColor(1, 0);
            LED.show();
            moonbot_eyes.clear();
            moonbot_eyes.fill(0x003000, 0, 6);
            moonbot_eyes.show();
        } else if (digitalRead(MOONBOT_PIN_BUTTON_B) == LOW) {
            // 如果按键B被按下
            // LED1，眼睛左眼显示蓝色
            LED.setPixelColor(0, 0);
            LED.setPixelColor(1, 0x000030);
            LED.show();
            moonbot_eyes.clear();
            moonbot_eyes.fill(0x000030, 6, 6);
            moonbot_eyes.show();
        } else {
            // LED 眼睛灯光关闭
            LED.clear();
            LED.show();
            moonbot_eyes.clear();
            moonbot_eyes.show();
        }
    }

LED 眼睛灯光动作
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
