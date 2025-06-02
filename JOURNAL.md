---
title: Cruiser Pedals
author: falsonix (AKA fals)
description: 3D printed fully functional rudder pedals for use in a flight simulation program for added realism.
created_at (MM/DD/YYYY): 06/02/2025
---

**Total time spent on this project as of the latest entry: 1.5 hours**

# June 2nd, 2025 [Introduction & Research]
Today marks the beginning of this project. I wanted to create something that I'd actually use more than once, and wanted to tie it into my current obsession with virtual planes.
Before continuing with any research, I began thinking of specific aspects that I'd like to incorporate into this project. Those are:
- Easily constructed by anyone with a 3D printer, screwdriver, and soldering iron
- Fully compatible with modern flight simulation programs such as X-Plane 12 and Microsoft Flight Simulator (2020 release since I can't afford the 2024 release).
- Sturdy and durable for a long lifetime
  
I began with researching what types of pedals are available for purchase, and what common design features they share. A few things that I noticed were similar on several models are:
- Flat or slightly curved pedals to easily grip the feet
- Raised walls on the sides/back of the pedals to prevent the feet from slipping off of the pedals
- Mechanism (that kind of reminds me of the steering thing on the front wheels of a car) that allows the pedals to shift forward and backward according to user input, while keeping the input inverted between pedals
- A relatively small base footprint, which does help keep the underneath of your desk uncrowded

I then wanted to research already available 3D-printable solutions. After looking through many different models, I found several that were similar to what I wanted to create. The list is:
**3D Printed DIY Flight Simulator Pedals (Rudder & Brake) Using Arduino - Easy Project**
- Author: Danilo Vilardi
- Link: https://www.youtube.com/watch?v=B3WRmVOTyvY
**Highlighted due to:**
- Simple construction
- Mechanism used to attach potentiometers for downward brake pressure measurement

**Valkyrie Rudder Pedals**
- Author: hotpretzel
- Link: https://www.printables.com/model/32579-valkyrie-rudder-pedals
**Highlighted due to:**
- Usage of some metal/wooden parts for extra structural integrity
- Base design

**SIM Rudder Pedals V1**
- Author: DIY Beyond 3D
- Link: (https://makerworld.com/en/models/44430-sim-rudder-pedals-v1)
- **Highlighted due to:**
- Sturdy metal frame
- Usage of gears throughout the whole assembly

Then began parts research. Almost all of the designs that I went over utilized potentiometers to measure the current position of the pedals/brakes. One of the most popular choices is this generic looking potentiometer that I'm sure you've seen if you have dabbled in hardware before, and is sold practically anywhere that sells hobbyist parts.

**10K Linear Panel-Mount**
- Price: $0.95 from [Adafruit](https://www.adafruit.com/product/562)
- Claimed lifespan: 100,000 cycles
<img src="https://github.com/user-attachments/assets/7b253470-4fb5-439f-a1d0-75fb38fc6d77" width="250">

I remembered seeing something about rotary encoders having longer lifespans than potentiometers, and that would be ideal for the project goal of having a long-lasting device. Most rotary encoders have what are called detents (the little clicks that are made as the knob turns) however, which would cause issues for this project as we want smooth rotation. Luckily, detentless encoders exist and are not that much more expensive than normal rotary encoders. A common option for a part of this desription would be the EC12:

**EC12 Detentless Rotary Encoder**
- Price: $1.51 from [Mouser](https://www.mouser.com/ProductDetail/652-PEC12R-4020F-S24)
- Claimed lifespan: 30,000 cycles

![PEC12R](https://github.com/user-attachments/assets/ff93eb05-d7cd-4e70-a4d1-25abeea70df8)

So apparently in this case I was incorrect about the lifespan of encoders compared to potentiometers, and as such something like the unit from Adafruit above will be used (both for longevity and attainability). But what are potentiometers without a board to recieve their input and send it on to the target computer?

There are thousands of microcontroller boards that would fulfill the purpose that I need, but I want one that can easily be acquired by someone else trying to build this project. Ideally, the board should have:
- Enough flash RAM to handle inputs smoothly (32-64 KB for extra breathing room)
- A fast clock speed (to allow for more detections per millisecond)
- A minimum of 3 analog inputs for the potentiometers
- A method of communication over USB

(Going out for a few hours now, going to research when I return) - (4:18 PM CST)
