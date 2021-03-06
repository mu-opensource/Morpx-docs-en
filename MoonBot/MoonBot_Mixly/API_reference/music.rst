Music
======

**Music** include MoonBot Kit :doc:`../../MoonBot_Hardware/MoonBot_Hardware_controller` buzzer drive and external Drive :doc:`../../MoonBot_Hardware/MoonBot_Hardware_speaker`.

By calling these modules, you can control MoonBot Kit to play music.

.. image:: images/31.png

Speaker initialization
----------------

.. image:: images/32.png

:Introduction:

    Initializes the speaker connected to the specified port.

:Parameters:

    :port:

        - ``2,7,9``

Speaker Setting Play Mode
-------------------

.. image:: images/33.png

:Introduction:

    Set up the playback mode of the speaker.

:Parameters:

    :Play mode:

        - ``Single Play`` :Stop playing after playing specified music
        - ``Single tune circulation`` :Play specified music in a loop
        - ``Play all`` :Play the next music in the music list automatically after playing the specified music
        - ``Random Play`` :Play one of the music lists randomly after playing the specified music

Speakers Play Music
------------------

.. image:: images/34.png

:Introduction:

    Play music with a given name.

:Parameters:

    :Music Name:

        - :the drop-down menu for the module

Speaker Plays Custom Music
----------------------

.. image:: images/35.png

:Introduction:

    Play music with the specified music name.

    Users need to put corresponding custom music into loudspeakers before this operation.(:doc:`How to save music? <../../MoonBot_Hardware/MoonBot_Hardware_speaker>`),The first four words of a musical name should be letters or numbers.

:Parameters:

    :Music Name:

        - :Customize the first four characters of the music name,Support only ** English ** or ** Numbers **

Speaker Play Setting
----------------

.. image:: images/36.png

:Introduction:

    Set the current speaker playback status.

:Parameters:

    :Play settings:

        - ``Play/pause`` :Play or pause current music
        - ``Next song`` :Play the next music in the music list
        - ``Last song`` :Play the last music in the music list
        - ``Stop`` :Stop playing music


Loudspeaker set volume
-----------------

.. image:: images/37.png

:Introduction:

    Set the loudspeaker volume.

:Parameters:

    :volume:

        - ``0~32``

Buzzer Plays Scales
-----------------

.. image:: images/38.png

:Introduction:

    Buzzer to play scales in a set beat

:Parameters:

    :Scale:

        - ``High, middle and low levels``

    :Rhythm:

        - ``1/16~4 beat`` :Single beat time can be set by buzzer.


Buzzer pauses play
------------------

.. image:: images/39.png

:Introduction:

    The time when the buzzer pauses to play a given beat.

:Parameters:

    :Rhythm:

        - ``1/16~4 beat`` :Single beat time can be set by buzzer.

Buzzer Sets Play Rhythm
--------------------

.. image:: images/310.png

:Introduction:

    Set the number of beats per minute (BPM) of buzzer.

:Parameters:

    :beats per minute:


Buzzer Play Frequency
----------------

.. image:: images/311.png

:Introduction:

    Set up a buzzer to play music at a specified frequency at a given time.

:Parameters:

    :frequency:

        - ``0~65535`` :Frequency Recommendation Setting in the Frequency Range acceptable to the Human Ear（20～20000Hz）

    :time:

        - ``0`` :Continuous broadcasting
        - ``other`` :Stop playing for a specified length of time

Buzzer stop playing
-----------------

.. image:: images/312.png

:Introduction:

    The buzzer stopped playing sound.

