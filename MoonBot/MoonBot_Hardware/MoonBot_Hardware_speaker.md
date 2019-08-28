# Speaker Module

## Brief Introduction

![](./images/render_speaker.png)

Speaker module is a mp3 player controlled by serial intruction. Put sound files to in and control it with controller module.

## Specification

Size: 48 x 48 x 11.6 mm

Charging Power: 1W

Supported File: mp3

Memory Space: 16MB

**Pinout**

![](./images/pinout_speaker.png)

## Usage

Code Introduction：Let the speaker play music, and use the controller button to pause or play.

Connect the speaker to P2 of controller, set play mode to random play and define speaker volume. Detect the state of button A. If it is pressed, play or pause.

![](./images/Mixly_example_speaker.png)
