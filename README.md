# rDUINOScope-Adafruit3.5-ILI9341-New-GUI

A modified version of rDUINOScope that works with Adafruit 3.5" 320X480 TFT SPI mode, Updated to the latest firmware version V_2.3.1.
===========================================================
# Update Monday 10/10/2022 (Adafruit 3.5 with ILI9341 NEW GUI + Google Assistant Control):
* Compiled & tested with Arduino IDE V 2.0.0 & IDE 1.8.19.
* Added Dew Point to temperature & Humidity data (Thanks to Julien Gicquiaud) from our support community.
* Fixed a bug prevented the PHD guiding page to load correctly.
* Added Google Assistant ready (DOIT ESP32 DEVKIT V1) firmware. 
* Added Adafruit MQTT Library to the libraries folder.
* Included BT commands to the original code for communicating with Google Assistant control commands.

# Update Friday 10/4/2020 (Fayrouz Update With ILI9341):
* The new version is built on the SdFat Library.
* It uses a modified version of marekburiak-ILI9341_due library that has been modified specially for this project.
* New Graphical User Interface has been developed,Inspired by Dessislav Gouzgounov.
* Corrected Solar System Objects bug from last update. Thanks to (Aitor Plazaola Alcerreca) From the rDUINOScope Support Group.
* Support for Stellarium Mobile Plus has been added.
* Supports the rDUINOScope Companion Android App (will be launched soon on Google Play)!
# Hardware Changes:
* Support for PHD2 Autoguiding has been added. Thanks to the project by https://github.com/kevinferrare/arduino-st4
* A third stepper motor has been added for focus control.
* An Optional DFRobot Mp3 Player has been added for future upgrade.
* Consider the new Wiring Diagram for Hardware Changes!

===========================================================
# Update Saturday 4/5/2019 (Fayrouz Update With Solar System!):
* Removed Nextion Commands to avoid errors in compile.


# Update Tuesday 16/3/2019 (Fayrouz Update With Solar System!):
# Use IDE 1.8.5 to avoid compile errors.
 
#Includes Giacomo Mammarellas's updated features!

* No hardware changes.
* Memory card contents are changed.
* Added Solar System objects tracking to Load Screen.
* Added Battery Power indicator to main screen, currently showing USB only, just for future upgrade.
* Added images for Solar and stellar objects to show on Main Screen. ( Memory Car items changed). 

===========================================================
 # Update Tuesday 3/7/2018 (Fayrouz Update!):
 
 #Includes Giacomo Mammarellas's updated features!

 * No hardware changes.
 * Memory card contents are changed.
 * Changed supporters logos at startup page.
 * Full Hardware check and confirmation at initilize.
 * More Accurate Joystick calibration at startup.
 * Options' data are saved to a text file on the memory card, and will be restored and initilized during next boot.
 * A new screen brightness control triangle has been added.
 * New on screen messages has been added.
 * Prevent (Load), (Home), (Bluetooth), and (Track) buttons to function while steppers are off. Avoiding Wrong Telescope Position coordinates while      steppers are off.
 * Corrected Steppers' speed during " Slew to" process . very slow>slow>fast>faster>>>>>>>>>>>fast>slow>very slow>stop>track.
 * faster browsing for Messier and treasures catalogs.
 * Automatic date and time set on clockScreen() derived from GPS data: the software is able to calculate the location's time zone and      to auto update from summer or winter time.
 * Added an new button in Options screen to update date and time from GPS data.
 * New debug mode. can be used to debug touchscreen actions.
 
 ===========================================================

 # Update Saturday 23/9/2017:
 
 # Added Giacomo Mammarellas's new features Like:

 - Joypad calibration at startup. No more panic to find right values for the joypad.
 - Empirial March sound function moved to confirm good initialization of the device. If no sound then you're having problems! :'(
 - Automatic data and time set on clockScreen() derived from GPS data: the software is able to calculate the location's time zone and      to auto update to summer or winter time.
 - Custom line of text can be appended to any .csv file to display custom "Description" strings. Example: I added "rich cluster with        more than 100 stars" to M11 in messier.csv
 - Orange color for Name and Description when tracking objects.
 - Added custom.csv wich can be used to add more custom sky objects (still to be implemented)
===========================================================

#Repairs: 
- Re-position Summer button at Clock Screen.
- added Green and Red colors to Screen-Timeout at the status bar.

===========================================================

#rDUINOScope

THE WORLD'S FIRST STAND ALONE ARDUINO BASED TELESCOPE CONTROL GOTO (handheld controller). 

rDUINOScope is an Open Source, Arduino Due based Telescope Control System (GOTO). Drafted as stand alone system, rDUINOScope does not need PC, Tablet or Cell Phone, nor Internet connection in order to operate and deliver stunning views! It does however supports Bluetooth and LX200 protocol to connect and be controlled by smart devices!


rDUINOScope uses database with THE BEST ~250 stellar objects ( Messier and Hidden Treasures Catalogues) and 200 stars, calculates their position on the sky and points the telescope. Implemented Alignment procedures allow for "Always in the eyepiece" experience when slewing to selected objects and once the object is in the eyepiece, the system keeps tracking it.

The best part of rDUINOScope is that it is an OPEN SOURCE SOFTWARE and HARDWARE! Few custom telescope makers have announced that they are adding or about to add it to their product line. In addition, few months ago a new HW shield board was born as a spin-off project to spare you the hassle of building your own rDUINOScope!

Published under GNU General Public License

Instructions on how to build hardware can be found on the project's website: http://rduinoscope.byethost24.com/
HACKADAY.IO Project: https://hackaday.io/project/21024-rduinoscope

Facebook: https://www.facebook.com/rDUINOScope/


#rDUINOScope v2.3.1 Boiana EQ 
===========================================================
Release date: 03 August 2017
Status: Stable Version
Author: Dessislav Gouzgounov / Десислав Гузгнов /(deskog@gmail.com) 


v2.3.1 aims to bring all existing hardware platforms into one code base. Additionally this version introduces new features to the rDUINOScope like Screensaver, TFT brightness, MosFET to control power to DRV8825 and etc.

Current release will also be used as a base to add the Alt/Az changes.

New features added in v2.3.1:
===========================================================
- Brings all existing flavours of the hardware to use same code!
- Hardware Changes!!! - Plese reffer to the HACKADAY instructions!
- Screen Brightness control;
- Screen Auto OFF function with timeout;
- Implemented FET transistor to control power to the stepper motors;
- More BlueTooth commands added to prepare for a screenless version (or operation);
- It is now possible to control rDUINOScope without the TFT screen - so called "BLIND" version.
- BUG fixes:
	- GPS fixes;
	- SlewTo speed issues for low amperage;



New features added in v2.3:
===========================================================
- Code Optimization for Performance (SlewTo now capable of speeds > 3 deg/sec);
- Added Celestial, Lunar and Solar tracking speeds;
- Added new Main Menu system for more functionality;
- Added control on 2 external devices (DEV 1 & 2 - you can hook your Heater, Fan and etc);
- Added support for SkySafari 5 (smartphone software);
- Added build in Star Atlas showing current telescope position;
- Shows current Firmware version on Loading screen and on Bluetooth request using LX200 protocol;
- Bug fixes:
	o Wrong DEC movement for negative DEC values passed over Bluetooth;
	o LST revised in the format XX:XX;




New features added in v2.1:
===========================================================
- Added “1 Star Alignment” Method;
- Added “Iterative Alignment” Method;
- Added 200 brightest stars to be used in alignment procedures;
- Added Bluetooth control from Stellarium (cloned LX200 communication protocols);
- Added Bluetooth connection with PC;
- Code has been refactored for easy reading/editing;
- Bug fixes:
	o Wrong DEC movement for negative DEC values;
	o Revised RA movement formula;
	o OnScreen messages have been fixed;
	o 1px. Buttons move after press event was fixed;
