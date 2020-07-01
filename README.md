# Janus-Controller

The Janus Controller is a Brushless motor driver with an on-board magnetic encoder, a three-phase MOSFET driver, three MOSFET half-bridges, a temperature sensor and current sensing resistors. 

<img src="image/Front20.01.JPG" width=300 align=right>

Janus Controller was designed to work with ESP32 Dev-Kit1 as a shield so that the programing of the board is easier for hobbyist and students and the overall price of the board is lower. I'm currently working on a version with an onboard microcontroller. 
This board can be used to drive brushless motors as an open-loop system or use the on-board encoder to drive the motors as a closed-loop system and use more complicated algorithms, such as Field Oriented Control for position and velocity control.
I recommed using the [Simple FOC](https://github.com/askuric/Arduino-FOC) arduino library as it has shown to work perfectly for position and velocity control and is easily implementable, but you can always use your own algorithm. My [example code](JC01F05/JC01F05.ino) uses the Simple FOC library adapted to work with an ESP32.

## Practical Example

Big J is a five bar parallel robot that uses direct drive brushless motors as actuators working with two Janus Controllers in position control mode and a master ESP32.

<a href="http://www.youtube.com/watch?feature=player_embedded&v=RcFdbI5-R5o
" target="_blank"><img src="http://img.youtube.com/vi/RcFdbI5-R5o/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>
