#include "SR04.h"

// Debug flag
#define DEBUG 0

// Led pins
#define GREEN 7
#define YELLOW 4
#define RED 2

// Button pin
#define BUTTON 8

// Ultrasonic sensor pins
#define TRIG_PIN 13
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

int leds[] = {GREEN, YELLOW, RED};
int cycle = 0;

// Reference distance for sensor
long refDistance;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(9600);
  delay(1000);
  refDistance = sr04.Distance();

  if(DEBUG) {
    Serial.print("ref: ");
    Serial.print(refDistance);
    Serial.print("cm\n");
  }
}

// Make buzzer output a pulse of 500ms every 1000ms (non-blocking)
void buzz_loop() {
  static unsigned long start_time = 0;
  unsigned long curr_time = millis();

  if(curr_time - start_time > 1000) {
    start_time = curr_time;
    tone(12, 250, 500);
  }
}

// pulse led every 500ms (non-blocking)
void pulse_led(int pin) {
  static unsigned long start_time = 0;
  static bool led_on = false;
  unsigned long curr_time = millis();

  if(curr_time - start_time > 500) {
    digitalWrite(pin, led_on ? LOW : HIGH);
    led_on = !led_on;
    start_time = curr_time;
    start_time = curr_time;
  }
}

// select on state for every led
void led_controller(int pin) {
  switch(pin) {
  case GREEN:
    digitalWrite(pin, HIGH); // continous
    break;
  case YELLOW: case RED:
    pulse_led(pin); // pulse
    break;
  }
}

void loop() {
  if(digitalRead(BUTTON) == LOW) { // when button is pressed
    digitalWrite(leds[cycle], LOW); // turn current led of then switch

    if(DEBUG) Serial.print("button pressed\n");

    cycle = (cycle + 1) % 2;
    led_controller(leds[cycle]);
    while(digitalRead(BUTTON) == LOW); // block operations until button is released
  }

  int currDistance = sr04.Distance();

  if(DEBUG) {
    Serial.print("curr: ");
    Serial.print(currDistance);
    Serial.print("cm\n");
  }

  if(cycle == 1 && abs(currDistance - refDistance) > 5) { // check if smth. passed through the sensor
    digitalWrite(leds[cycle], LOW);
    buzz_loop();
    cycle = 2;
  }

  led_controller(leds[cycle]);
  if(cycle == 2) buzz_loop(); // righ buzzer if in alarm state

  //delay(300);
}