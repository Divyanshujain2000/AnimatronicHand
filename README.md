### AnimatronicHand

# What is animatronics?

Animatronics is the relationship between the animation and the electronics. It is the technology where machines/robots imitate human and animal activities like walking, moving arms, facial expressions etc. You can build machines and control them by moving your hands, fingers and facial muscles.
The actions are imitated by the robotic structures with the help of motors and wires/threads/ropes.
Animatronic hand is a robotic hand that works with the help of animatronics. It is a robotic hand that is controlled by the user with the help of a glove. 

# So what is the use of an animatronic hand? 

In today’s world, to avoid any sort of skin diseases arising for workers in the chemical industry use of Animatronic hand in the chemical industry has a vast applications. As there is improvement, there is also be less forms of skin diseases. Moreover, it can be used as an alternative arm for the physically challenged persons. Thus the applications of Animatronic hand are numerous. The technology doesn’t bring any unemployment issues as it only safeguards the employees either be the chemical industry or the physically challenged persons. One of the pros of an animatronic hand is the ease of handling it in a simple manner as compared to a mechanical hand.

Here, in this project we have a made a simple animatronic hand with the help of arduino and servo motors. The user wears the glove and the robotic hand imitates the hand gestures. When the user bends a finger the sensor on the glove detects the angle and send a signal to the the robotic hand. The signal can be sent through wireless communication using simple radio frequency transmission. Here, in this project we have used RF transmitter - receiver for the wireless communication. The robotic hand upon receiving the signal maps the bending angle of the finger to the motor angle and then the motor pulls the corresponding finger (of the robotic hand) with the help of a thread. 

All this project requires are microcontrollers, flex sensors, servo motors, a hand frame, a glove, power source and Rf transmitter-receiver for wireless communication. Xbee can be used to provide long range communication, however, to keep the project simple we have used a 433Mhz RF transmitter-receiver. For the ease of controlling servo motors we have used a PWM driver(PCA9865). It is a 16 channel pwm driver with I2C interface. So via various coding of the Arduino, the animatronic hand can be made and utilized for various applications. 
https://github.com/Divyanshujain2000/AnimatronicHand/issues/1#issue-504197136
## config:

use 2 microcontrollers like arduino uno's

1 is set as the rf trasmitter end ,which is connected to the glove 
	glove contain 5 flex sensors(each for 1 finger) and the reading of the flex is taken on analog pins of arduino
		ADC
		A0	thumb
		A1	index
		A2	middle
		A3	ring
		A4	pinky
	the transmitter module is connected to the mcu and the code is loaded through arduino ide
2 is set as rf reciver  end , which is connected to the robot arm 
	the arm contain pwm driver to which 5 motors are connected to pull the string connected to the finger,
	the pwm driver(PCA9865) is communicting through i2c to the arduino, to which recievr is connected
the rf module is used as the commucation means is  433MHz RF Transmitter Receiver Wireless Module

## components:
 rf																 https://www.electronicscomp.com/433mhz-rf-transmitter-receiver-module-india?gclid=CjwKCAjw5_DsBRBPEiwAIEDRW19dJXQeM6LmA6BWHD-u8VNiiXAJngK2LbEg7soNXiEMxB0ih39olxoC9RQQAvD_BwE

 pwm driver 
https://robu.in/product/diy-kit-16-channel-12-bit-pwmservo-driver-i2c-interface-pca9685-arduino-raspberry-pi-shield-module-servo-shield/?gclid=CjwKCAjw5_DsBRBPEiwAIEDRW6ghipWKUIy-Tk2tmETOTaLoplHm3qM4qoK-F7Wi1qdDSpyVsQ64gxoCuLEQAvD_BwE

 mcu
https://robu.in/product/arduino-uno-r3-ch340g-atmega328p-devlopment-board/?gclid=CjwKCAjw5_DsBRBPEiwAIEDRW1GVc3Mb3zeVRW6Jp6AGMvNlHIvgR-Y0p08nwS0UG3Dd8yhdi_q9DhoCkiEQAvD_BwE

 flex 
 https://robu.in/product/flex-sensor-2-2-bend-sensor-hand-gesture-recognition/?gclid=CjwKCAjw5_DsBRBPEiwAIEDRWyqpaIGddGFoY7Aoy2E55tt3CxYr6aAtUQhCBdsJe5Dx7mgV67oYwxoC-20QAvD_BwE

 servo https://robu.in/product/towerpro-sg90-9g-mini-servo-9-gram/?gclid=CjwKCAjw5_DsBRBPEiwAIEDRW_j57tTEzhvRCmtbW7DVromyIXnX4H1uUrrPMlKaQHmabJT8DYTEYRoCwqQQAvD_BwE
