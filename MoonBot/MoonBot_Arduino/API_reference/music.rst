Music
==========

Overview
----------

MoonBot Kit provide two sound devices, buzzer on :doc:`../../MoonBot_Hardware/MoonBot_Hardware_controller` and :doc:`../../MoonBot_Hardware/MoonBot_Hardware_speaker` .
We can use Arduino basic functions `tone() <https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/>`_ 
and `noTone() <https://www.arduino.cc/reference/en/language/functions/advanced-io/notone/>`_ to control the buzzer. 
Use :ref:`Speaker <api-ref-speaker>` library to control the speaker.

By including ``MoonBot.h`` header file in program, we can call ``speaker`` driver to drive the speaker module.

On-board Buzzer Driver
++++++++++++++++++++

We can use macro definition ``MOONBOT_PIN_BUZZER_SIG`` to get Arduino pin of the buzzer, and control the voltage of ``MOONBOT_PIN_BUZZER_SHDW`` to open or close the buzzer.

.. code-block:: cpp
    :emphasize-lines: 7

    #include <MoonBot.h>

    void setup()
    {
        pinMode(MOONBOT_PIN_BUZZER_SIG, OUTPUT);        // Initialize buzzer signal pin to output mode
        pinMode(MOONBOT_PIN_BUZZER_SHDW, OUTPUT);       // Initialize buzzer power pin to output mode
        digitalWrite(MOONBOT_PIN_BUZZER_SHDW, LOW);     // Pull down buzzer power pin to open buzzer
        tone(MOONBOT_PIN_BUZZER_SIG, 1000, 2000);       // Let buzzer play with 1000Hz for 2000ms
    }

.. Attention::

    In 7th line of the example: 

    .. code-block:: cpp
        :lineno-start: 7

        digitalWrite(MOONBOT_PIN_BUZZER_SHDW, LOW);     // Initialize buzzer power pin to output mode

    Pull ``MOONBOT_PIN_BUZZER_SHDW`` voltage ``LOW`` to open it, and ``HIGH`` to close.The default voltage is ``LOW``.

Speaker Module Driver
++++++++++++++++++++

MoonBot Kit :doc:`../../MoonBot_Hardware/MoonBot_Hardware_speaker` use a WT2003S MP3 decoder chip. Call ``speaker`` library to control it as a MP3 player.

There is a simple MP3 player tutorial: 

.. code-block:: cpp

    #include <MoonBot.h>

    void setup()
    {
        speaker.begin(Serial2);     // Initialize speaker module to Arduino serial port 2（MoonBot GPIO port 2）
        speaker.setPlayMode(0);     // Set play mode to single play, which means stop after playing a music
        speaker.setVolume(20);      // Set volume to 20. Max volume is 32
    }

    void loop()
    {
        if ((!digitalRead(MOONBOT_PIN_BUTTON_A))) {
            // If button A is pressed
            speaker.playNext();     // Play the next music
        } else if ((!digitalRead(MOONBOT_PIN_BUTTON_B))) {
            // If button B is pressed
            speaker.playPrevious(); // Play the last music
        }
    }

Check `Official terminal MP3 player <https://github.com/mu-opensource/MoonBot/blob/master/examples/Terminal_MP3_Player/Terminal_MP3_Player.ino>`_ examples for more detailed information. 

.. _api-ref-speaker:

API Reference - Speaker
----------------------

Header File
+++++++++++

    - `src/MoonBot_WT2003S_MP3_Decoder.h <https://github.com/mu-opensource/MoonBot/blob/master/src/MoonBot_WT2003S_MP3_Decoder.h>`_

Class
+++++

.. glossary::

    class WT2003S

        - WT2003S MP3 player driver


        :Menber function:

            :void begin(SoftwareSerial &serialPort);:

                - Use software serial port to initialize speaker

                :parameter:

                    - ``serialPort`` : software serial port

            :void begin(HardwareSerial &serialPort = Serial);:

                - Use hardware serial port to initialize speaker

                :parameter:

                    - ``serialPort`` : hardware serial port, Serial by default

            :uint8_t play(char* fileName);:

                - play music with the file name
				
                :parameter:

                    - ``fileName`` : 4 bytes of the file name

                :return:

                    - ``0`` means the command is right, other return means wrong

            :uint8_t setVolume(uint8_t volumeLevel);:

                - Set volume of the speaker

                :parameter:

                    - ``volumeLevel`` : volume level, with range of ``0~32``

                :return:

                    - ``0`` means the command is right, other return means wrong

            :uint8_t stop(void);:

                - Stop playing current music

                :return:

                    - ``0`` means the command is right, other return means wrong

            :void pause(void);:

                - Pause when playing, play when pausing

            :uint8_t playPrevious(void);:

                - Play the last music. Play the final music when on the first

                :return:

                    - ``0`` means the command is right, other return means wrong

            :uint8_t playNext(void);:

                - Play the next music. Play the first music when on the final

                :return:

                    - ``0`` means the command is right, other return means wrong

            :uint8_t setPlayMode(uint8_t mode);:

                - Set play mode

                :parameter:

                    - ``mode`` :

                        +-+------------+
                        |0|single play |
                        +-+------------+
                        |1|single cycle|
                        +-+------------+
                        |2|list loop   |
                        +-+------------+
                        |3|randomplay  |
                        +-+------------+

                :return:

                    - ``0`` means the command is right, other return means wrong

            :uint16_t getSongCount(void);:

                - Get the music order number in the list

                :return:

                    - current music order number in the list

            :void getSongName();:

                - Get first 9 bytes of the song name. Read ``WT2003S::songName[MP3_NUM_NAME_BYTES]`` to get the name

            :uint8_t playTrackNumber(uint8_t trackNumber);:

                - Play music with the given order number

                :parameter:

                    - ``trackNumber`` : music order number in the list

                :return:

                    - ``0`` means the command is right, other return means wrong

            :uint8_t getVolume(void);:

                - Get current volume level of the speaker

                :return:

                    - ``0~32`` : volume level of the speaker

            :uint8_t getPlayStatus(void);:

                - Get the current play status

                :return:

                    +-+-----+
                    |1|play |
                    +-+-----+
                    |2|stop |
                    +-+-----+
                    |3|pause|
                    +-+-----+
