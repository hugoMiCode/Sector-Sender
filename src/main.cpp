#include "IRSender.h"

#define IR_SENDER_PIN 2

IRSender irSender(IR_SENDER_PIN, 0b00);


void setup() {
  Serial.begin(115200);

  irSender.setup();
}

void loop() {
  irSender.sendPulseSignal(1500);
}

