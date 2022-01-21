# Desk-Control

This is a re-upload of an older project, as I didn't use github at the time. This project spanned July 2020 - August 2020. I am happy to report that it is still working perfectly to this day! (January 2022)

I personally don't enjoy having any form of light when I try to sleep. This would normally mean that I need to unplug my digital clock, monitors, etc on my desk. This causes wear on connectors, is time consuming, and certainly not elegant. To solve this problem, I created a simple relay-based PCB to toggle power on/off for various devices on my desk, and I use a simple button interface to control this. 

I also utilized an arduino to allow for smart control logic of the buttons, backlights, and relay timing. "Smart" features include a fade on/off animation in the buttons' backlights, minimum time between toggles (to allow devices to fully boot before power is cut to them). The PCB uses transistor-switched 12v power to allow for a PWM signal to control the buttons' backlights, optocouplers for relay isolation protection, as well as a basic power supply. 


See below for images of the project:
![alt text](https://github.com/woodepic/Desk-Control/blob/main/src/IMG_6762.jpg "Button 3 toggles clock") ![alt text](https://github.com/woodepic/Desk-Control/blob/main/src/IMG_6767.jpg "Underside view of buttons & PCB") ![alt text](https://github.com/woodepic/Desk-Control/blob/main/src/IMG_6766.jpg "Button 2 toggles in-desk touch monitor")
