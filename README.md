# Janus Controller

The Janus Controller is a Brushless motor driver with an on-board magnetic encoder, a three-phase MOSFET driver, three MOSFET half-bridges, a temperature sensor and current sensing resistors. 

<img src="Images/Front20.01.JPG" width=250 align=left>

Janus Controller was designed to work with ESP32 Dev-Kit1 as a shield so that the programing of the board is easier for hobbyist and students and the overall price of the board is lower. I'm currently working on a version with an on-board microcontroller. 
This board can be used to drive brushless motors as an open-loop system or use the on-board encoder to drive the motors as a closed-loop system and use more complicated algorithms, such as Field Oriented Control for position and velocity control.
I recommend using the [Simple FOC](https://github.com/askuric/Arduino-FOC) Arduino library as it has shown to work perfectly for position and velocity control and is easily implementable, but you can always use your own algorithm. My [example code](JC01F05/JC01F05.ino) uses the Simple FOC library adapted to work with an ESP32.

![Render](Images/JC20.01-Features.PNG)

## Test Station
The test station is a 3D printed base that holds together the Janus Controller board and a brushless motor with a diametrically polarized magnet. This magnet is attached to the rotor of the motor and placed above the magnetic encoder, around 1.5mm above the encoder is optimal making sure the center of the magnet is aligned with the center of the encoder.
In the [CAD](CAD) section you can find the CAD for the Test Station, the Janus Controller board, the motor used, the magnet used and the ESP32 Dev-kit. 

![TestStation](Images/TestStationJC20.01.PNG)

## Practical Example

Big J is a five-bar parallel robot that uses direct drive brushless motors as actuators working with two Janus Controllers in position control mode and a master ESP32. Click the image bellow to watch a demo YouTube video.

<a href="http://www.youtube.com/watch?feature=player_embedded&v=RcFdbI5-R5o
" target="_blank"><img src="Images/BigJ-GIF.gif" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>
