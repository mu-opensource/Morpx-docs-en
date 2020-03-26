# MoonMech Instruction

## Introduction

MoonMech is a movable mechanical arm. Its body is made by plastic shell and sheet metal frame. 
The track chasis is drived by motor module, and mech arm is drived by servos. The claw on top of the arm can catch various objects with vision feedback.

MoonMech can be used to learn competitive applications like transpotation and playing basketball.

![](./images/render_MoonMech.png)

## Specification

Size: 271 x 137 x 244 mm

Functions

Motion: mech arm, claw, chassis

Sense: vision, encoder

## Build Manual

Download pdf guide of MoonMech

[MoonMech build guide](https://github.com/mu-opensource/Morpx-docs-en/raw/master/MoonBot/MoonBot_Structure/docs/MoonMech_manual_en.pdf)

Or watch video guide on youtube

[MoonMech video guide](https://www.youtube.com/watch?v=Ec-LTPimftk)

## Program Examples

Download MoonMech Mixly examples

[MoonMech Examples](https://github.com/mu-opensource/Morpx-docs-en/raw/master/MoonBot/MoonBot_Structure/sources/Mixly_example_MoonMech.zip)

### Catch Ball

This example shows how to catch ping-pong ball recognized by vision module.

Code introduction: In initial part, vision module and servos are set to their ports.
 Vision algorithm is set to ball detect, and servos are set to initial position.
 In loop part, vision module will detect ball and judge the x offet and move the chassis.Then judge the y offset and move servos.
Use the ball width to estimate the distance. When the width is above 27, the claw will close and catch the ball.

Phenomenon: Turn on MoonMech and it will open claw and look forward, with vision module LEDs shining red.
Put a ping-pong ball in front of the claw, and the LEDs turn blue. Adjust the position of ball until the claw catch it.

![](./images/Mixly_MoonMech_grab_ball.png)