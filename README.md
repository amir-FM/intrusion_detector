# Intrusion Detector

Arduino based intrusion detection system with multiple modes of operation.

## Description

Made on a breadboard with a ultrasonic sensor for detecting the change in
distance. At startup the system gets a referance distance. In normal operation,
if the absolute value of the diference between the set point and the current
distance exceeeds a set error threshold, the alarm is set off. It features
three modes of operation: Unarmed, Armed and Alarm represented by three colors
solid green, blinking yellow and blinking red. In the unarmed mode the sensor
in inactive and the alarm cannot be triggered. The alarm mode is complemented
by a buzzer.

## Components

1 x Plusivo UNO R3 Development Board
1 x HC-SR04 Ultrasonic Sensor Module
1 x Passive Buzzer
4 x 1k Resistors
1 x Red LED
1 x Green LED
1 x Yellow LED
1 x Button

## Circuit details

**Unarmed**
- green LED is lit
- sensor is disabled
- buzzer is off

**Armed**
- yellow LED is blinking
- ultrasonic sensor is operational

**Alarm**
- red LED is blinking
- alarm is triggered
- buzzer is producing sound

## Code

The functions that trigger the pulsing of LEDs and buzzer are made to be
**non-blocking** as to allow the controller to do other operations.

*Notes:* In this setup the consumption of the system is dependent on the rate
at which the ultrasonic sensor is taking samples. For the sake of detection the
code is running at full speed. If you want lower consumption or for detecting
lower speed targets add a delay.
