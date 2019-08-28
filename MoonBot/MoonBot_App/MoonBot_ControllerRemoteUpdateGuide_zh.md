MoonBot Kit Remote Controller Firmware Upgrade Wizard
===============================

Programming with MoonBot Kit APP requires burning the specified firmware in the master control.

This article guides users how to upgrade MoonBot Kit master module to burn firmware needed for APP programming.

## Preparation

Hardware：

- MoonBot kit
- PC (Windows、Linux 或 Mac OS)

Software：

- [Arduino Official IDE](https://www.arduino.cc/en/Main/Software?setlang=cn)
- MoonBot Remote control Arduino Source code or firmware

## Upgrade by burning HEX files

- 1.Download [MoonBot Firmware of Master Control Remote Controller](https://github.com/mu-opensource/MoonBot_RemoteController/releases/latest)(.hex File)
- 2.Burn .hex firmware
    - Windows
        ```
        1）Download Arduino Hex Burning tool
        2）Select MoonBot port，Hardware select `Genuino ATmega1280`
        3）Click download and wait for download to complete.
        ```

##  Upgrade Arduino source code by compiling Arduino IDE

- 1.Building[MoonBot Kit Arduino development environment](../MoonBot_Arduino/MoonBot_arduino_development_construction_guide_cn.md)
- 2.Download[MoonBot Kit Master remote control source code](https://github.com/mu-opensource/MoonBot_RemoteController/releases/latest)(Source.zip 文件)
- 3.Open Arduino IDE，Click Project->Loading Library->Add.ZIP library`，Select the.Zip file downloaded in Step 2

    ![](../MoonBot_Arduino/images/arduino_add_zip_library.png)

- 4. Select the. zip file downloaded in step 2 and click OK to load the source code of MoonBot Kit master remote control
- 5.Click Arduino `File->Example>MoonBotRemote->RemoteWithDemo`，Open Source code

    ![](./images/arduino_add_example_remote_with_demo.png)

- 6.Connet MoonBot Kit Master Control to Computer，Click Arduino `Tool->Port`，Selectthe corresponding MoonBot port.
- 7.Click the Download button and wait for the download to complete

## Test

- 1.After restart, press the main control button A, close to the A key LED bright blue light and give a prompt sound.
- 2.After restart, press the main control button B, close to the B key LED bright green light and give a prompt sound.
