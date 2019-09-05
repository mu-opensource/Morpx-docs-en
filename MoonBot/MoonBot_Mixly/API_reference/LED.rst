Light
========

**Light** include MoonBot Kit :doc:`../../MoonBot_Hardware/MoonBot_Hardware_controller` Two on-board LEDs and 12 external LEDs :doc:`../../MoonBot_Hardware/MoonBot_Hardware_eyes` drivers.

With these modules, you can easily set the color and brightness of the LED.

.. image:: images/LED.png

Eye Initialization
------------

.. image:: images/eyes_init.png

:Introduction:

    Initialize the eye module to the specified port.

:Parameters:

    :port:

        - ``1~9``

Eye display
------------

.. image:: images/eyes_show.png

:Introduction:

    Write the color value of the eye LED into the buffer and display it.

:Introduction:

    :colour:

        - .. image:: images/LED_color.png

Eyes show expression
------------

.. image:: images/eyes_show_emotion.png

:Introduction:

    Eye LED displays facial movements.

:Parameters:

    :Expression:

        - `` Module Dropdown Menu``

Master control LED display
--------------

.. image:: images/controller_LED_show.png

:Introduction:

    Write the color value of the master LED into the buffer and display it.

:Parameters:

    :colour:

        - .. image:: images/LED_color.png

LED Setting RGB Value
---------------

.. image:: images/LED_set_RGB.png

:Introduction:

    Write the RGB color value of a given LED lamp into the buffer.

:Parameters:

    :LED Type:

        - ``Eye`` :eye LED
        - ``master control LED`` :master control LED

    :Lamp number:

        - Eye: ``0~11``, master control LED : ``0~1``

    :R value:

        - ``0~255`` :Red Channel Analog

    :G value:

        - ``0~255`` :Green Channel Analog

    :B value:

        - ``0~255`` :Blue Channel Analog

LED Setting HSV Value
----------------

.. image:: images/LED_set_HSV.png

:Introduction:

    Write the HSV color value of a given LED lamp into the cache.

:Parameters:

    :LED Type:

        - ``Eye`` :Eye LED
        - ``master control LED`` :master control LED

    :Lamp number:

        - Eye: ``0~11``, master control LED : ``0~1``

    :H value:

        - ``0~360°``: Tone Value

        .. image:: images/hue_color.jpeg

    :S value:

        - ``0~255`` :Saturation value analogue

    :V value:

        - ``0~255`` :Luminance value analogue

LED show
-----------------

.. image:: images/LED_show.png

:Introduction:

    Show the color values in a given LED buffer

:Parameters:

    :LED Type:

        - ``Eye`` :Eye LED
        - ``master control LED`` :master control LED

LED clear
----------------

.. image:: images/LED_clear.png

:Introduction:

    Clear the cache of the specified LED.

:Parameters:

    :LED Type:

        - ``Eye`` :Eye LED
        - ``master control LED`` :master control LED

LED brightness
-------------

.. image:: images/LED_brightness.png

:Introduction:

    Set the brightness of the given LED.

:Parameters:

    :LED Type:

        - ``Eye`` :Eye LED
        - ``master control LED`` :master control LED

    :brightness:

        - ``0~255`` : ``0`` darkest,``255`` brightest
