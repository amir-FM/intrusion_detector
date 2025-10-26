# Intrusion Detector

Arduino based intrusion detection system with multiple modes of operation.

## Description

Made on a breadboard with a ultrasonic sensor for detecting the change in distance. At startup the system gets a referance distance. In normal operation, if the absolute value of the diference between the set point and the current distance exceeeds a set error threshold, the alarm is set off.
It features three modes of operation: Unarmed, Armed and Alarm represented by three colors solid green, blinking yellow and blinking red. In the unarmed mode the sensor in inactive and the alarm cannot be triggered. The alarm mode is complemented by a buzzer.

## Components
