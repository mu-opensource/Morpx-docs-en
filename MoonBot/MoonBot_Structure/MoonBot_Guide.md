# MoonBot Instruction

## Introduction

MoonBot is a semi-humanoid robot with abundant sense and interaction. Its body is made by plastic shell and sheet metal frame. 
The track chasis is drived by motor module.Head and hands are drived by servos. 
Eyes and speaker can interact with others with touch, vision and position feedback.

MoonBot can be used to learn service robot applications like reception and patrol.

![](./images/render_MoonBot.png)

## Specification

Size: 150 x 137 x 216 mm

Functions

Motion: head, hands, chassis

Interaction: eyes, speaker

Sense: vision, touch, encoder

## Build Manual

Download pdf guide of MoonBot

[MoonBot build guide](https://github.com/mu-opensource/Morpx-docs-en/raw/master/MoonBot/MoonBot_Structure/docs/MoonBot_manual_en.pdf)

Or watch video guide on youtube

[MoonBot video guide](https://www.youtube.com/watch?v=me56aYx-8Tc)

## Program Examples

Download MoonBot Mixly examples

[MoonBot Examples](https://github.com/mu-opensource/Morpx-docs-en/raw/master/MoonBot/MoonBot_Structure/sources/Mixly_example_MoonBot.zip)

### Shake Body

MoonBot has servos in head and hands, and motors in chassis.Just program to make MoonBot dance.

Code introduction: In initial part, servos are set to head and hands.In loop part, use robot blocks to make MoonBot to move chassis and lands slowly.

![](./images/Mixly_MoonBot_shake.png)

### Follow people

MoonBot can use vision module to recognize people, and always face people with chassis and head.

Code introduction: In initial part, servos are connected to ports and are adjusted direction according to actual position.
Vision module is connected to seiral 3(P9), and the algorithm is set to human body.
In loop part, when detect human body, MoonBot will move chassis according to x offset of human body, and move head according to y position.

Phenomenon: After downloading the program, put MoonBot on desk and stand in front of it.
MoonBot will detect upper body and vision module shines blue when detected.
Walk around and MoonBot will rotate to keep the face in front of you al the time.

![](./images/Mixly_MoonBot_followBody.png)
