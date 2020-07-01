# Janus Controller

The Janus Controller is a Brushless motor driver with an on-board magnetic encoder, a three-phase MOSFET driver, three MOSFET half-bridges, a temperature sensor and current sensing resistors. 

<img src="Images/JC20.01-Features.PNG" width=320 align=left>

Janus Controller was designed to work with ESP32 Dev-Kit1 as a shield so that the programing of the board is easier for hobbyist and students and the overall price of the board is lower. I'm currently working on a version with an on-board microcontroller. 
This board can be used to drive brushless motors as an open-loop system or use the on-board encoder to drive the motors as a closed-loop system and use more complicated algorithms, such as Field Oriented Control for position and velocity control.
I recommend using the [Simple FOC](https://github.com/askuric/Arduino-FOC) Arduino library as it has shown to work perfectly for position and velocity control and is easily implementable, but you can always use your own algorithm. My [example code](JC01F05/JC01F05.ino) uses the [Simple FOC](https://github.com/askuric/Arduino-FOC) library adapted to work with an ESP32.

## Getting started
### The board
In this repository you can find everything you need to get you started with your personal projects. The board was designed around the [JLCPCB SMT Parts Library](https://jlcpcb.com/parts), so you should be able to order an SMD assembled board directly from them for a low price. 
You can order this board from your preferred manufacturer, you just need to download the [gerber files](Gerber) and the [SMD BOM](BOM_JC20.01.csv). If you don't order your board from JLCPCB you should make sure that the manufacturer has in stock the needed SMD parts, if not it shouldn't be too difficult to find a replacement (except for the DRV8305 and the MA730). 

### Brushless motor selection
There are a few general rules that should help you choose the best brushless motor for your particular application. For instance, if you want to build a robot arm, a gimbal, or something that needs relative high torque you should get a low KV motor (usually bellow 300 is good) with a big radius in relation to its length. 
Usually, outrunner brushless motors have more poles than their counterpart, the inrunner, so they spin slower and produce more torque. This makes an outrunner the better choice for this type of application. 
We can use the torque equation of a brushless motor to calculate the ideal torque a motor will produce at a given voltage/ current. The value calculated with this formula will not be the real value because motors are far from ideal. I've found that considering a motor efficiency of around 80% should be good enough for estimating the maximum torque of a brushless motor.
![TorqueFormula](Images/TorqueFormula.PNG) 
If you're not sure how much current the motor will draw you can substitute de current in the formula for voltage over the internal resistance of the motor, as show in the equation (2). 
If the internal resistance of the motor seems too low, there is a parameter in the [example code](JC01F05/JC01F05.ino) that restricts the voltage applied to the motor. Generally, a resistance of around 10 ohms should be perfect.  
![TorqueFormula2](Images/TorqueFormula2.PNG)  

### The magnet
The MA730 Magnetic Encoder works with a diametrically polarized magnet, these can be hard to find but you should be able to find a couple options from eBay. 
The MA730 datasheet recommends a Neodymium alloy (N35) cylinder with dimensions Ø5x3mm inserted into an aluminum shaft, as shown in the picture bellow. You can use a solid cylindrical magnet of different dimensions without the aluminum shaft and still get excellent results. 
![Magnet](Images/MA730Magnet.PNG) 

## Test Station
The test station is a 3D printed base that holds together the Janus Controller board and a brushless motor with a diametrically polarized magnet. This magnet is attached to the rotor of the motor and placed above the magnetic encoder; around 1.5mm above the encoder is optimal, making sure the center of the magnet is aligned with the center of the encoder.
In the [CAD](CAD) section you can find the CAD for the Test Station, the Janus Controller board, the motor used, the magnet used and the ESP32 Dev-kit. 

![TestStation](Images/TestStationJC20.01.PNG)

## Practical Example

Big J is a five-bar parallel robot that uses direct drive brushless motors as actuators working with two Janus Controllers in position control mode and a master ESP32. Click the image bellow to watch a demo YouTube video.

<a href="http://www.youtube.com/watch?feature=player_embedded&v=RcFdbI5-R5o
" target="_blank"><img src="Images/BigJ-GIF.gif" 
alt="IMAGE ALT TEXT HERE" width="300" border="10" /></a>

##Contact

I'm happy to hear from your proyects and to help in any way possible.  
davidglzrys@gmail.com  
[Linkedin](https://www.linkedin.com/in/david-g-reyes/)
