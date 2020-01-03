.. morpx documentation master file, created by
   sphinx-quickstart on Fri Jul 19 17:00:19 2019.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

MoonBot Kit Firmware Upgrade Guide
========================

This doc will guide users to upgrade firmware of MoonBot Kit :doc:`../MoonBot_Hardware/MoonBot_Hardware_controller`
and :doc:`../MoonBot_Hardware/MoonBot_Hardware_MUVS3` .

Preparation
--------

Hardware: 

- MoonBot Kit

- PC（Windows）

Software:

- `Arduino IDE <https://www.arduino.cc/en/Main/Software>`_

- MoonBot Arduino Library

- `MU Vision Sensor 3 upgrade software <http://mai.morpx.com/images/page201904/flash_download_tools_v3.6.5.rar>`_

- `MU(for MoonBot) latest firmware(.bin file) <https://github.com/mu-opensource/MoonBot_RemoteController/releases/latest>`_

Upgrading Steps
------------

Step One: Upgrade firmware of MoonBot Kit Controller
++++++++++++++++++++++++++++++++++++++++++++++++++++

Refer to :doc:`../MoonBot_App/MoonBot_ControllerRemoteUpdateGuide`

Step Two: Upgrade firmware of MU Vision Sensor 3
++++++++++++++++++++++++++++++++++++

1. Connect :doc:`../MoonBot_Hardware/MoonBot_Hardware_MUVS3` to MoonBot Kit
:doc:`../MoonBot_Hardware/MoonBot_Hardware_controller` port P9, and connect the controller to PC.

2. Press and hold function button of :doc:`../MoonBot_Hardware/MoonBot_Hardware_MUVS3`
on the left, and then press Reset button once. Then release function button, and the vision sensor is in upgrading mode now.

3. Open MU Vision Sensor 3 upgrade software ``flash_download_tools_vx.x.x.exe``

4. Choose ``ESP32 DownloadTool``

    .. image:: images/moonbot_upgrade_flash_loader.png

5. Change Settings

    .. image:: images/moonbot_upgrade_setup.png

.. note::

    - SPI SPEED:40MHz
    - SPI MODE:DIO
    - FLASH SIZE:32Mbit
    - BAUD:115200
    - COM：connect to the right COM port, which can be found in  Windows device manager. 

        .. image:: images/moonbot_upgrade_find_com.png

6. Choose ``...`` button and choose firmware file, and choose ``√`` to activate the file.

7. Input address of the firmware behind ``@`` , which is ``0x10000``.

.. Attention::

    **Do not forget to input the address or modify it. Otherwise you will damage the firmware order of the vision sensor. If it happens, please contact to Morpx support to solve it.**

    Phone number: (0571)8195 8588

    E-mail: support@morpx.com

8.Press ``START`` button on the left-bottom corner, and **click continuously**
button B of MoonBot Kit :doc:`../MoonBot_Hardware/MoonBot_Hardware_controller`
until the software start burning firmware. LED on the right side of the controller turns green. 

9.When the software progress bar is full, and shows ``FINISH``, firmware downloading is complete.
