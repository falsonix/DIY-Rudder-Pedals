---
title: Cruiser Pedals
author: falsonix (AKA fals)
description: 3D printed fully functional rudder pedals for use in a flight simulation program for added realism.
created_at (MM/DD/YYYY): 06/02/2025
---

**Total time spent on this project as of the latest entry: 11.5 hours**

# June 2nd, 2025 [Introduction & Research] - 4.5 hours
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
- A minimum of 3 analog inputs for the potentiometers
- A method of communication over USB

Several boards from popular manufacturers fit the criteria for this project, so I decided to narrow it down to three different models, each with varying features:

**Arduino UNO R4 Minima**
- Price: $20 from [Arduino](https://store-usa.arduino.cc/collections/boards-modules/products/uno-r4-minima)
- Analog Inputs: 6
- RAM: 32 KB
<img src="https://github.com/user-attachments/assets/7401f3ba-7af7-4552-9e3f-deb08d238894" width=250>

**Raspberry Pi Pico**
- Price: $4 from [SparkFun](https://www.sparkfun.com/raspberry-pi-pico.html)
- Analog Inputs: 3
- RAM: 264 KB
<img src="https://github.com/user-attachments/assets/b8e6dbf2-0bae-47db-b3b9-459daf7cb0bc" width=250>

**Raspberry Pi Pico 2**
- Price: $5 from [SparkFun](https://www.sparkfun.com/raspberry-pi-pico-2.html)
- Analog Inputs: 3
- RAM: 520 KB
<img src="https://github.com/user-attachments/assets/8e534676-3ecc-4c62-b446-ba94f8a252f1" width=250>

After considering these three options, I ended up choosing the Raspberry Pi Pico 2, as it is both affordable and has *plenty* of memory for our use case. It also has three analog inputs, which was needed for the potentiometers, and plenty of digital I/O for possible additions later.

Alright, great! Now we've got the hardware and main design features laid out, so it's time to begin the CAD process.

I used the following models from the GrabCAD website as reference to design the 3D printed parts around:
- [10K Rotary Potentiometer by Pierre Gleizes](https://grabcad.com/library/potentiometer-b10k-1)
- [Raspberry Pi Pico by Alexander Mandron](https://grabcad.com/library/raspberry-pi-pico-3)

Starting with the pedals themselves, I measured my own foot and found it to be around 22cm long and 10cm wide. I plan to make the pedals around 20cm by 10cm as I feel this is a suitable size for most people's feet. I then sketched this area out in Autodesk Fusion (formerly Fusion 360), along with a rough sketch of the mechanism that will ensure the pedals stay facing the user while moving forward or backward.

![Screenshot 2025-06-02 192240](https://github.com/user-attachments/assets/bb09fed8-8354-4b6a-b5cc-e923f0ca9336)

After a while of planning, I began creating the main base and two pedal swivel points. The basic concept is that the center acts as a fixed point, and the two pedals rotate around the center. They use 6804 bearings to ensure smooth motion across everything, and will have two linkages connecting them together. The bases of the three were then mirrored onto the top to create a mostly-finished assembly, which is depicted in the screenshot below.

![Screenshot 2025-06-02 214440](https://github.com/user-attachments/assets/07bf5dc6-7a09-4fe5-8310-514a03091a29)

<<End of day 1>>

# June 3rd, 2025 [Continuing CAD Design] - 1.75 hours

Good morning! Today I wanted to continue progress on the actual design of the pedals, starting with modification of the shafts to hold a standard M5 hex nut in order to increase the strength of the screw joint. I accomplished this by cutting a pocket in the shaft to hold the nut, and then a channel into the side so that the nut can be inserted.

![Screenshot 2025-06-03 101306](https://github.com/user-attachments/assets/34350e1d-1816-487b-8f65-fa2f1e98ccd5)

I then realized that the shafts were actually too close to one another for the linkage that I wanted to use, as depicted below. I wanted the linkage to surround the bearing for more strength, but seeing as how the two bearings are really close together, this wouldn't be possible.

![Screenshot 2025-06-03 103547](https://github.com/user-attachments/assets/e3659381-02a7-4f9b-811c-8db6e5d06165)

After fixing the spacing of the shafts, I then began sketching the linkages themselves. I aimed for an internal diameter of 32.2 mm to accomodate the bearings properly, and an outer diameter of 45 mm for more stability.

![Screenshot 2025-06-03 111620](https://github.com/user-attachments/assets/10fb30d4-fdcb-43ea-b4cf-f2f51c9aaa4d)

This is a basic outline of what the linkages will look like in the final product, highlighted in yellow. They may be a little thick, but I'm prioritizing function over form for now.

![Screenshot 2025-06-03 112536](https://github.com/user-attachments/assets/1c631750-63c7-4e41-a5c3-995a30fb2b64)

After that, I thickened the center of the linkages to hold the bearings closer to the exterior, in order to have them be better aligned and stay in place.

![Screenshot 2025-06-03 114135](https://github.com/user-attachments/assets/d53d6450-c653-4ac1-adb3-f398baaf3555)

<Taking a break for a while, will continue later tonight>

# June 4th, 2025 [Continuing CAD Design] - 3.25 hours

Well, guess who didn't end up getting any more work done yesterday OR the start of today. If you guessed me, you're correct. Personally, I blame it on Deltarune releasing this morning.
Anyways, I began the day's progress by planning out how I wanted the pedals to actually interface with the moving bases, and did so in a MS Paint drawing.

![Screenshot 2025-06-04 140419](https://github.com/user-attachments/assets/f4fcfb54-0680-4e8d-9200-eae2a5d39e53)

In order to be able to read a position from the potentiometers, they will be placed inside of the pedal assembly like so:
![Untitled](https://github.com/user-attachments/assets/214b5366-4009-40c1-9c87-2247f4ffe7a0)

After modeling the two side panels of the pedal assembly, I began using references of a 6802 bearing to cut the correctly sized pockets and holes for the axle to protrude through.

![Screenshot 2025-06-04 152044](https://github.com/user-attachments/assets/eb958302-3dc4-4827-805d-9ad9e60e6edd)

![image](https://github.com/user-attachments/assets/f1fdaf95-7414-4d3a-b0f9-590d69daaa16)

I ended up changing the design slightly, in order to have the screw on end caps to the outside and the parts that will attach to the pedal itself on the inside.

![image](https://github.com/user-attachments/assets/3d56848d-c3b4-44ad-adf6-aa603335cafe)

# June 6th, 2025 [Continuing CAD Design] - 2 hours

I didn't end up getting any work done on this project yesterday, due to being occupied with other things. Anyways, I began by sketching out how I wanted the pedals to swivel along the axis, and came up with the following. This pedal design should provide a smoothly rotating surface that won't drag or get stuck on the frame.

![image](https://github.com/user-attachments/assets/eda8bcb7-321f-44f0-af7c-78ee7c62eef0)

I also wanted to add a stopper to make sure that the pedal doesn't rotate fully vertical when not in use, also making the use of the device more comfortable overall. (stopper highlighted in red)

![image](https://github.com/user-attachments/assets/273f4b85-a076-44dc-9f29-b40446a510a2)

After making the pedal solid, I then worked on connecting it to the rotating shafts. The two red pieces below are the points which will connect to the pedal in order to firmly connect it to the rotation axis.

![image](https://github.com/user-attachments/assets/e4d6df13-b208-4d13-8e1a-95b79c81b32c)

I took a break from the pedal design at this point to make a small mockup of the steering mechanism, to test that it actually worked. It is a 1/3 scale replica of the original, and will be printed and tested today.

![image](https://github.com/user-attachments/assets/44db0a42-16f1-425c-bcac-7d33484f8228)
