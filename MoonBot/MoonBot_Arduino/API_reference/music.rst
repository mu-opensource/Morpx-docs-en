音乐
==========

概览
----------

MoonBot Kit 提供了两类发声设备，分别是 :doc:`../../MoonBot_Hardware/MoonBot_Hardware_controller` 板载的蜂鸣器模块和外接的 :doc:`../../MoonBot_Hardware/MoonBot_Hardware_speaker` 。相对应的，
我们可以通过调用 Arduino 的基础函数 `tone() <https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/>`_ `noTone() <https://www.arduino.cc/reference/en/language/functions/advanced-io/notone/>`_ 函数来控制蜂鸣器发声，
通过 :ref:`扬声器 <api-ref-speaker>` 库来控制扬声器发声。

我们可以通过在程序中包含 ``MoonBot.h`` 头文件来调用 ``speaker`` 来驱动外部扬声器。

板载蜂鸣器驱动
++++++++++++++++++++

我们可以通过调用宏定义 ``MOONBOT_PIN_BUZZER_SIG`` 来获取对应的 Arduino 引脚，通过控制引脚 ``MOONBOT_PIN_BUZZER_SHDW`` 电平的高低来开启或关闭板载的蜂鸣器功能。

.. code-block:: cpp
    :emphasize-lines: 7

    #include <MoonBot.h>

    void setup()
    {
        pinMode(MOONBOT_PIN_BUZZER_SIG, OUTPUT);        // 初始化蜂鸣器信号引脚为输出模式
        pinMode(MOONBOT_PIN_BUZZER_SHDW, OUTPUT);       // 初始化蜂鸣器供电引脚为输出模式
        digitalWrite(MOONBOT_PIN_BUZZER_SHDW, LOW);     // 将蜂鸣器供电引脚电平拉低以开启蜂鸣器
        tone(MOONBOT_PIN_BUZZER_SIG, 1000, 2000);       // 让蜂鸣器以1000Hz的频率开始播放声音，播放2000ms后停止
    }

.. Attention::

    如上述例程的第七行所述：

    .. code-block:: cpp
        :lineno-start: 7

        digitalWrite(MOONBOT_PIN_BUZZER_SHDW, LOW);     // 将蜂鸣器供电引脚拉低以开启蜂鸣器

    将蜂鸣器供电引脚 ``MOONBOT_PIN_BUZZER_SHDW`` 电平设为 ``LOW`` 即为开启蜂鸣器，设为 ``HIGH`` 即为关闭蜂鸣器功能。该引脚电平默认为 ``LOW`` 。

外接扬声器驱动
++++++++++++++++++++

MoonBot Kit 提供的 :doc:`../../MoonBot_Hardware/MoonBot_Hardware_speaker` 使用了 WT2003S MP3 解码芯片，通过调用 ``speaker`` 你可以轻松自制一台 MP3 播放器！

先来看一个简单的 MP3 播放器的例程：

.. code-block:: cpp

    #include <MoonBot.h>

    void setup()
    {
        speaker.begin(Serial2);     // 初始化speaker至Arduino的串口2（MoonBot对应的端口2）
        speaker.setPlayMode(0);     // 播放模式设置为单曲播放播放模式，播放完一首曲子后停止播放
        speaker.setVolume(20);      // 音量设置为20，最大为32
    }

    void loop()
    {
        if ((!digitalRead(MOONBOT_PIN_BUTTON_A))) {
            // 若按键A被按下
            speaker.playNext();     // 播放下一首歌
        } else if ((!digitalRead(MOONBOT_PIN_BUTTON_B))) {
            // 若按键B被按下
            speaker.playPrevious(); // 播放上一首歌
        }
    }

也可以查看 `官方串口 MP3 播放器 <https://github.com/mu-opensource/MoonBot/blob/master/examples/Terminal_MP3_Player/Terminal_MP3_Player.ino>`_ 的例程以获取更全面的信息。

.. _api-ref-speaker:

API 参考 - 扬声器
----------------------

头文件
+++++++++++

    - `src/MoonBot_WT2003S_MP3_Decoder.h <https://github.com/mu-opensource/MoonBot/blob/master/src/MoonBot_WT2003S_MP3_Decoder.h>`_

类
+++++

.. glossary::

    class WT2003S

        - WT2003S MP3 播放器驱动。


        :成员函数:

            :void begin(SoftwareSerial &serialPort);:

                - 以软串口作为端口初始化扬声器。

                :参数:

                    - ``serialPort`` ：软串口

            :void begin(HardwareSerial &serialPort = Serial);:

                - 以硬件串口作为端口初始化扬声器。

                :参数:

                    - ``serialPort`` ：硬件串口，默认为Serial

            :uint8_t play(char* fileName);:

                - 播放给定文件名的音乐。

                :参数:

                    - ``fileName`` ：音乐文件名前四个字节

                :返回:

                    - ``0`` 命令正常执行，其他命令出错

            :uint8_t setVolume(uint8_t volumeLevel);:

                - 设置扬声器音量

                :参数:

                    - ``volumeLevel`` ：扬声器音量，取值范围 ``0~32``

                :返回:

                    - ``0`` 命令正常执行，其他命令出错

            :uint8_t stop(void);:

                - 停止播放当前正在播放的音乐。

                :返回:

                    - ``0`` 命令正常执行，其他命令出错

            :void pause(void);:

                - 播放时调用此函数，则暂停当前播放。没有播放时调用此函数，则播放当前音乐。

            :uint8_t playPrevious(void);:

                - 播放上一曲音乐，在播放第一曲音乐时，发送该指令可触发播放最后一曲音乐。

                :返回:

                    - ``0`` 命令正常执行，其他命令出错

            :uint8_t playNext(void);:

                - 播放下一曲音乐，在播放最后一曲音乐时，发送该指令可触发播放第一曲音乐。

                :返回:

                    - ``0`` 命令正常执行，其他命令出错

            :uint8_t setPlayMode(uint8_t mode);:

                - 设置扬声器播放模式。

                :参数:

                    - ``mode`` ：

                        +-+--------+
                        |0|单曲播放|
                        +-+--------+
                        |1|单曲循环|
                        +-+--------+
                        |2|列表循环|
                        +-+--------+
                        |3|随机播放|
                        +-+--------+

                :返回:

                    - ``0`` 命令正常执行，其他命令出错

            :uint16_t getSongCount(void);:

                - 获取当前音乐在列表中的序号。

                :返回:

                    - 当前音乐在列表中的序号

            :void getSongName();:

                - 获取当前音乐的乐曲名前9个字节。执行此函数后可以通过读取 ``WT2003S::songName[MP3_NUM_NAME_BYTES]`` 来获取乐曲名。

            :uint8_t playTrackNumber(uint8_t trackNumber);:

                - 播放给定序号的音乐。

                :参数:

                    - ``trackNumber`` ：音乐在列表中的序号

                :返回:

                    - ``0`` 命令正常执行，其他命令出错

            :uint8_t getVolume(void);:

                - 获取当前扬声器的音量值。

                :返回:

                    - ``0~32`` ：扬声器音量值。

            :uint8_t getPlayStatus(void);:

                - 获取当前播放状态。

                :返回:

                    +-+----+
                    |1|播放|
                    +-+----+
                    |2|停止|
                    +-+----+
                    |3|暂停|
                    +-+----+
