# SnailBoard
Created in Visual Studio with Visual Micro plugin. Currently not really functional, being worked on to become a Planck-style keyboard (4x12 ortholinear).

I designed the keyboard, printed it, hand-wired it, and am now making its firmware from scratch. All files will be available when it is fully functional.

### Final goal
The project will contain the following components once finished:
- Fully modular keyboard based around a single core component: the keyplate (all parts meant to be printed)
- Different chassis to accomodate the different microcontrollers (Teensy LC/3.2 and Teensy 3.5/3.6 planned for now)
- Rotatable function to use the perfectly symetrical design of the keyboard to change the side of the usb port from left to right
- Object-Oriented based firmware for easy future devloppement (such as adding new and different key types)
- Separate tool to create and manage layouts (will have an interface and probably be made in C# for the sake of simplicity)
- The end-user will only need to interact with the layout tool and the Arduino IDE for compiling and uploading in the end, no need of coding knowledge (even if it would help). If possible, might integrate a way to compile and upload directly from the layout tool.
