# 'Cruiser' Rudder Pedals

![Cruiser_Pedals_2025-Jun-16_10-50-15PM-000_CustomizedView6343715044](https://github.com/user-attachments/assets/7749aea1-4930-418c-9044-283c9d5605e1)

DIY rudder pedals for flight simulation in programs like X-Plane, MSFS, etc. The pedals themselves are almost entirely 3D-printed, minus the fastners, bearings, and electronics. Utilizing a Raspberry Pi Pico 2 as the main microcontroller, the device is plug-and-play with most modern flight simulation softwares after the firmware is flashed. Rudder pedals are used in real planes to control the aircraft's yaw while in flight, and is often times used to control the nose gear on the ground in a flight simulator. Having a controller that can interface with the computer intuitively can provide a much more realistic experience, and can make the task of flying more enjoyable.

I made this project mostly because flight simming is a big hobby of mine, and I've been wanting a set of rudder pedals for quite some time now. I hope that by designing this hardware I can get more people into flight simulation as a whole, and improve the experience of those who are already interested in it.

Check JOURNAL.md for a full log of the design and testing process.

# Credits

This project would not have been as easy (or even possible at all) without the wonderful works of others. I am truly grateful for the cool people out there on the internet that decided to share their creations for others to use and improve on.

**External Code**
- PicoGamepad by RealRobots: https://gitlab.com/realrobots/PicoGamepad

**External CAD Models (used for referencing)**
- 10K Rotary Potentiometer by Pierre Gleizes: https://grabcad.com/library/potentiometer-b10k-1
- Raspberry Pi Pico by Alexander Mandron: https://grabcad.com/library/raspberry-pi-pico-3

# Building Firmware from Source

**Requirements:**
- [Visual Studio Code (latest release)](https://code.visualstudio.com/)
- [PlatformIO Extension for VSCode (latest release)](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

**1. Clone the repository to a location of your choosing**
- If you have Git CLI installed, you can simply run `git clone https://github.com/falsonix/DIY-Rudder-Pedals.git`
- Otherwise just use the 'download .zip' button within GitHub (the green Code button at the top right of the repository's home page)

**2. Open the project inside of the PlatformIO IDE**
- This is on Windows, but the process for MacOS and Linux should be similar.
![image](https://github.com/user-attachments/assets/04b275b5-a8d2-4d13-b2ae-6c81c2cb1075)
![image](https://github.com/user-attachments/assets/4abf8604-79af-426f-8592-1152d4a6ddfa)

Find the `initial-test/` folder inside of `<wherever you downloaded the code>/DIY-Rudder-Pedals/code/`
![image](https://github.com/user-attachments/assets/208b752d-e63e-4856-af6e-79b1ca03abcc)

Upon choosing the `initial-test/` folder, PIO should download and configure everything that you need in the background.

**3. Build the firmware file for the Pico**
*This can also be done from the terminal, but this guide is aimed at less experienced persons.*
- In the bottom left corner of VSCode, locate the check mark in the toolbar.

![image](https://github.com/user-attachments/assets/074759f1-f9b4-45e3-956a-1a615e0e2023)

- After clicking on the check mark, you should get a terminal at the bottom of your window showing the build process.

![image](https://github.com/user-attachments/assets/37facee0-939e-469b-838f-8d9092fa80ea)

- Eventually, if all goes well, you should see a green [SUCCESS] message inside the terminal, along with information about the size and resource usage of the firmware file.

![image](https://github.com/user-attachments/assets/93f4653f-f279-4f89-907e-3274d45b91ca)

**4. Upload the firmware to the Pico**
- Great, now we've got the complete firmware file! Time to flash it to your board and then start using your new rudder pedals.

- Using a file explorer, inside the `initial-test/` folder that we opened earlier, navigate to `.pio/build/pico/`.

![image](https://github.com/user-attachments/assets/1b4318d4-1d47-454d-b64f-93c7c6cb6103)

- Inside of the `pico/` folder there should be a `firmware.uf2` file, which is the one we want. Copy this somewhere, like your desktop or downloads folder, since we'll need it in a minute.

![image](https://github.com/user-attachments/assets/afe6b837-41ec-445b-a84a-16af59c15a6a)

Now we need to move to the Pico.

- Grab yourself a compatible USB cable, and plug one end into your computer.
- Now, holding down the BOOTSEL (or BOOT) button on the Pico, plug the other end of the USB cable into the Pico.
- Release the BOOTSEL button.

The Pico is now in bootloader mode, meaning it will not run any previously uploaded code (if there is any).
- It should show up as a USB drive named `RPI-RP2` or something similar.

Now, copy the `firmware.uf2` file from wherever you put it earlier into the Pico's USB drive folder.
- The device will automatically disconnect from your computer after the transfer is complete, and will reconnect a few seconds later.

Your rudder pedals should now show up properly inside of a flight simulator!
