#include <Arduino.h>
#include <AccelStepper.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

#define PIN_SENSOR 16

// U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(16, 10);
AccelStepper motor_r(AccelStepper::FULL4WIRE, 2, 4, 3, 5);
AccelStepper motor_l(AccelStepper::FULL4WIRE, 6, 8, 7, 9);

void setup() {
  pinMode(LED_BUILTIN_RX, OUTPUT);
  pinMode(LED_BUILTIN_TX, OUTPUT);
  pinMode(PIN_SENSOR, INPUT);
  // u8x8.begin();
  motor_r.setMaxSpeed(400.0); // 600
  motor_r.setAcceleration(500.0); // 1500
  motor_l.setMaxSpeed(400.0); // 600
  motor_l.setAcceleration(500.0); // 1500
}

bool ledState = LOW;
long curTime = 0;

short fwdStep = 100;
const short pollInterval = 100;

void loop() {
  curTime = millis();

  if (motor_r.distanceToGo() <= fwdStep) {
    motor_r.move(fwdStep);
  } 

  if (!digitalRead(PIN_SENSOR)) {
    digitalWrite(LED_BUILTIN_RX, HIGH);
    fwdStep = 0;
    motor_r.stop();
  } else {
    fwdStep = 100;
    digitalWrite(LED_BUILTIN_RX, LOW);
  }
   //if (motor_l.distanceToGo() == 0 && curTime % 300 < 10) {
  //  digitalWrite(LED_BUILTIN_TX, motor_l.currentPosition() > 0);
  //  motor_l.moveTo(-motor_l.currentPosition());
  //} 

  motor_l.run();
  motor_r.run();

  // u8x8.setFont(u8x8_font_chroma48medium8_r);
  // u8x8.drawString(0,1,"Hello World!");
}