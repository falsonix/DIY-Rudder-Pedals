---
title: Cruiser Pedals
author: falsonix (AKA fals)
description: 3D printed fully functional rudder pedals for use in a flight simulation program for added realism.
created_at (MM/DD/YYYY): 06/02/2025
---

**Total time spent on this project as of the latest entry: 22 hours**

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

# June 6th, 2025 [Continuing CAD Design] - 3.75 hours

I didn't end up getting any work done on this project yesterday, due to being occupied with other things. Anyways, I began by sketching out how I wanted the pedals to swivel along the axis, and came up with the following. This pedal design should provide a smoothly rotating surface that won't drag or get stuck on the frame.

![image](https://github.com/user-attachments/assets/eda8bcb7-321f-44f0-af7c-78ee7c62eef0)

I also wanted to add a stopper to make sure that the pedal doesn't rotate fully vertical when not in use, also making the use of the device more comfortable overall. (stopper highlighted in red)

![image](https://github.com/user-attachments/assets/273f4b85-a076-44dc-9f29-b40446a510a2)

After making the pedal solid, I then worked on connecting it to the rotating shafts. The two red pieces below are the points which will connect to the pedal in order to firmly connect it to the rotation axis.

![image](https://github.com/user-attachments/assets/e4d6df13-b208-4d13-8e1a-95b79c81b32c)

I took a break from the pedal design at this point to make a small mockup of the steering mechanism, to test that it actually worked. It is a 1/3 scale replica of the original, and will be printed and tested today.

![image](https://github.com/user-attachments/assets/44db0a42-16f1-425c-bcac-7d33484f8228)

After printing out and assembling the test, here is what it looks like:

![IMG_3127](https://github.com/user-attachments/assets/8be805eb-4eb0-4cf4-bb11-b801df334d10)

And here is how the mechanism in the final version will work:

https://github.com/user-attachments/assets/b4e4ff72-1c32-40a3-b54a-28351c390ba7

I then worked on connecting the rotating axle to the potentiometer, and settled upon a mechanism that uses two identical gears to transfer the force from the pedal into the potentiometer, like so:

![image](https://github.com/user-attachments/assets/8bcaec34-349f-4991-a0be-cc75170c957e)
The original mechanism that was planned in the sketch wouldn't work due to space limits within the pedal assembly.

After connecting the potentiometer to the gear, I then made a mount to hold the potentiometer in place during use.

![image](https://github.com/user-attachments/assets/fbccf24c-b2fb-43f0-acfe-0557a1a46492)

The mount screws to the base of the pedal assembly with an M3x40 screw and accompanying M3 hex nut.

![image](https://github.com/user-attachments/assets/65fb7857-b6c1-4a16-85f9-0b5a572b7374)

# June 9th, 2025 [Continuing CAD Design] - 1 hour

Well. It's been a few days, hasn't it?
I decided it was time to actually connect the pedals to the moving axle, and sketched out a method of attachment that should allow for sturdy movement of the pedal. It uses M4x35 screws and M4 hex nuts to attack the pedal to the axle.

![image](https://github.com/user-attachments/assets/03ef3a62-2cbb-43b0-aed7-68f618dda6ab)

I then went about making the bottom of the pedal look a little better, by adding some chamfers:

![image](https://github.com/user-attachments/assets/c11c26d6-1dfe-4442-8449-12129031117d)

Then, I made a screw-on foot holder, to make steering with the pedals easier and more comfortable:

![image](https://github.com/user-attachments/assets/0751a8c5-bac2-437e-b31f-9ef36ce7b1b1)

Here is what the overall design looks like at the moment:

![image](https://github.com/user-attachments/assets/1821d222-92f0-4607-9697-ab9b4fffe511)

I hollowed out the center of the linkages, to reduce the amount of material required and speed up printing times.

![image](https://github.com/user-attachments/assets/c7518f2b-7ef0-4461-9181-6949cc9e0055)

# June 12th, 2025 [Finishing CAD Design] - 1.75 hours

After attending the Zack Freedman AMA with Hack Club, I regained motivation to work on this project.

I started work today with adding the mechanism on the back that allows the rotation of the steering to be transferred to the potentiometer for measurement purposes, along with rounding off the non-used bases to save materials.

![image](https://github.com/user-attachments/assets/a65f323b-02ef-429e-a992-caa0123e1c41)

After that, I then added M5x16 screws paried with M5 hex nuts to hold the large red semicircle gear in place.

![image](https://github.com/user-attachments/assets/cfac4d26-aeaa-4233-adbe-c7883ee65b51)

I then added shafts for the springs inside the pedals, which are 50mm in length, have a 0.3mm wire diameter, and 6mm outer diameter.

![image](https://github.com/user-attachments/assets/92dac29d-7ac6-42ff-8aff-2ec6236e7c6d)

I then added a small mounting solution for the Pico, which should hold it in place well enough with some hot glue. I did it this way to make adding on to the device much more easy, as all of the GPIO is exposed and not blocked by the base.

![image](https://github.com/user-attachments/assets/d25df915-6c4e-41e3-80e1-9a89e8d4920d)

After that, I made the base slightly taller to help the pedals not drag along the floor. Some adhesive rubber/silicone feet will be placed on the bottom, to keep the device in place.

![image](https://github.com/user-attachments/assets/8a5b488c-5337-47b5-93d2-8525dc30d5a5)

It was at this point that I called the CAD design finished. A full BOM will be in order next, and then the code will follow after I build and can test the device.

# June 15th, 2025 [Wiring and Coding] - 2 hours

Just kidding, that wasn't the final journal entry. There's still so much to be done for this project, starting with the actual electronics portion of the build.
In order to have a good idea of how I wanted the wiring to look from a schematic standpoint, I used Wokwi to lay out and connect all the components digitally. Since the Pico and Pico 2 share the same layout, and the software does not have a Pico 2 model as of yet, I used the original board for the diagram.

Starting with the data pins of each potentiometer, I connected them to all three of the Pico's analog inputs as follows:
- Left Brake - ADC2 (GP28/Pin 34)
- Steering - ADC1 (GP27/Pin 32)
- Right Brake - ADC0 (GP26/Pin 31)

![image](https://github.com/user-attachments/assets/2671750e-8fdf-4fc4-acf0-a0d36b97d477)

(In this example, I used a different looking potentiometer module because the specific ones that I plan to use for this project were not available in the Wokwi simulator.)

After that, I then connected the VCC of all the potentiometers to the 3V3 output on the Pico, and all of the GND pins to GND on the Pico (duh).

![image](https://github.com/user-attachments/assets/46716439-d622-45fe-bdb8-eb35612675cb)

In order to actually test this with real hardware, I assembled a one-potentiometer breadboard circuit using an Orpheus Pico and the B10K potentiometer model that I plan to use for the final build.

![image](https://github.com/user-attachments/assets/967019f9-881b-4b86-9fc2-5cecfad83575)
![IMG_3145](https://github.com/user-attachments/assets/a6300f54-cd41-40db-950a-f46f59a43fb0)

I began by creating a new PlatformIO project for the Pico, as that's what I'm used to using for projects like this. (added in commit [#f6d3838](https://github.com/falsonix/DIY-Rudder-Pedals/commit/f6d38384f946efc683583fb7ab64fab3e2787b84))

After that, I then made a simple C++ program that will readout the value of the potentiometer every 0.5 seconds (500 milliseconds) and print it to the serial console for testing. It works quite well, and seems to be pretty accurate. (commit [#7e03fb2](https://github.com/falsonix/DIY-Rudder-Pedals/commit/7e03fb26ae062cf07cf3a6579dc6d5d069524e63))

I then wanted to work on actually emulating a joystick device through hardware, and researched libraries that would make this possible/easy for me. One that I found was [PicoGamepad](https://gitlab.com/realrobots/PicoGamepad) by RealRobots, which would allow the Pico to emulate a USB HID game controller device, which is what I want to do. It is meant for the Arduino IDE, but seeing as PlatformIO uses the same core, it should work.

I implemented the library by placing the `PicoGamepad.h` file inside of the `include/` directory, and then included it at the top of my code. (commit [#baf10a3](https://github.com/falsonix/DIY-Rudder-Pedals/commit/baf10a37aeb8580ee5eb439774c33f1f0dc29bd6))

Following one of the examples included in the README for the library, I added all the required parameters for the library to function the way that I wanted it to, along with changing the delay inside of the `loop()` to be 50ms instead of 500, for a much better experience. (commit [#243d89d](https://github.com/falsonix/DIY-Rudder-Pedals/commit/243d89dafc05aa474e18be73fe9a4cc093aed5ec)

Upon attempting to compile this code I was met with several errors, which were fixed by dragging the `PicoGamepad.cpp` file into the `src/` directory. (commit [#750bbac](https://github.com/falsonix/DIY-Rudder-Pedals/commit/750bbac4e3dc49d2382af633061927bd49a68678))

When attempting to use the device as a controller in Microsoft Flight Simulator 2020, it actually works! I am honestly surprised at how easy this project has been programming-wise.

# June 15th, 2025 [BOM, CAD Upload, and Coding] - 2 hours

I began today's work by uploading the BOM for the entire project, with estimated prices of everything you need to build the device (commit [#4badbb7](https://github.com/falsonix/DIY-Rudder-Pedals/commit/4badbb7e6190be9a4f1259f4f8bb63aa9c7e5675)). 
I then wanted to export all of the CAD files in both an editable `.step` format and the 3D-printable `.stl` format. This took me a while, as Fusion doesn't currently support bulk exporting, but I got it done after a bit (commit [#e1c4f7a](https://github.com/falsonix/DIY-Rudder-Pedals/commit/e1c4f7ad1d53c4c2786165909cb1275680c19664)). I will release the editable files shortly, after I eat.

Here I am several hours later, without doing anything with the editable CAD files. I will get those uploaded soon, but not immediately. I decided to work on the code again, and add support for all three axes that the final device will have. I don't have the hardware to test it currently, but I still can make some simple changes. Instead of using the X, Y, and Z joystick axes built into the PicoGamepad library, I opted to use the 0, 1, and 2 generic axes, for no reason other than that I felt like it. (commit [#2e807a6](https://github.com/falsonix/DIY-Rudder-Pedals/commit/2e807a6781977d3f4e0a2774960c8f2776c0bb80))

After uploading and testing the firmware in a flight simulator, it works properly as expected.

It was then time to get on with the `.step` CAD files, don't think I forgot about those. I opted to export the entire assembly as one file, and also included the `.f3z` format in case anyone using Fusion wanted better compatibility. (commit [#4a1e17d](https://github.com/falsonix/DIY-Rudder-Pedals/commit/4a1e17d8546717b2db3b3d415eab9f29fbf687fe))
