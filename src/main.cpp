#include <Arduino.h>
#include <Chrono.h>

#define IR_SEND_PIN 2

int puceId = 2;

void pulseIr(long microsecs);

void setup() {
  pinMode(IR_SEND_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  pulseIr(400);

  if (puceId == 1)
    delayMicroseconds(400);
  else if (puceId == 2)
    delayMicroseconds(800);
  else if (puceId == 3) {
    delayMicroseconds(800);
    pulseIr(400);
    delayMicroseconds(400);
  }
}

void pulseIr(long microsecs)
{
  Chrono pulseClock(Chrono::MICROS);

  while (!pulseClock.hasPassed(microsecs, false)) {
    digitalWrite(IR_SEND_PIN, HIGH);
    delayMicroseconds(9);
    digitalWrite(IR_SEND_PIN, LOW);
    delayMicroseconds(9);
  }
}
