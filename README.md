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

- 1 x Plusivo UNO R3 Development Board
- 1 x HC-SR04 Ultrasonic Sensor Module
- 1 x Passive Buzzer
- 4 x 1k Resistors
- 1 x Red LED
- 1 x Green LED
- 1 x Yellow LED
- 1 x Button

## Circuit details

<table>
<tr>
<th>Unarmed</th>
<th>Armed</th>
<th>Alarm</th>
</tr>
<tr>
<td>
  <img width="400" height="300" alt="unarmed" src="https://github.com/user-attachments/assets/ec517958-9b91-4546-82da-137fbdb6516b" />
</td>
<td>
  <img width="400" height="300" alt="armed" src="https://github.com/user-attachments/assets/94b4ba5b-f6bf-44b3-ae12-bc0283bc6c60" />
</td>
<td>
  <img width="400" height="300" alt="alarm" src="https://github.com/user-attachments/assets/7970cde4-8b1d-4600-9864-1210b08e7344" />
</td>
</tr>
<tr>
<td>
  <ul>
    <li>green LED is lit</li>
    <li>sensor is disabled</li>
    <li>buzzer is off</li>
  </ul>
</td>
<td>
  <ul>
    <li>yellow LED is blinking</li>
    <li>ultrasonic sensor is operationalf</li>
  </ul>
</td>
<td>
  <ul>
    <li>red LED is blinking</li>
    <li>alarm is triggered</li>
    <li>buzzer is producing sound</li>
  </ul>
</td>
</tr>
</table>

## Code

The functions that trigger the pulsing of LEDs and buzzer are made to be
**non-blocking** as to allow the controller to do other operations.

*Notes:* In this setup the consumption of the system is dependent on the rate
at which the ultrasonic sensor is taking samples. For the sake of detection the
code is running at full speed. If you want lower consumption or for detecting
lower speed targets add a delay.
