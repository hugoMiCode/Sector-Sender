#include "IRSender.h"


IRSender::IRSender(int pin, int8_t puce) {
    this->irPin = pin;
    this->puceSignalBin = puce;
    this->pulseClock = Chrono(Chrono::MICROS);
}

void IRSender::setup()  {
    pinMode(irPin, OUTPUT);
}

void IRSender::sendPulse(long microsec)  {
    pulseClock.restart();

    while (!pulseClock.hasPassed(microsec, false)) {
      digitalWrite(irPin, HIGH);
      delayMicroseconds(9);
      digitalWrite(irPin, LOW);
      delayMicroseconds(9);
    }
}

void IRSender::sendSignal() {
    switch (puceSignalBin)
    {
    case 0b00:
        // SHORT SHORT
        sendPulse(HIGH_SHORT_TIME);
        delayMicroseconds(LOW_SHORT_TIME);
        break;
    case 0b01:
        // SHORT LONG
        sendPulse(HIGH_SHORT_TIME);
        delayMicroseconds(LOW_LONG_TIME);
        break;
    case 0b10:
        // LONG SHORT
        sendPulse(HIGH_LONG_TIME);
        delayMicroseconds(LOW_SHORT_TIME);
        break;
    case 0b11:
        // LONG LONG
        sendPulse(HIGH_LONG_TIME);
        delayMicroseconds(LOW_LONG_TIME);
        break;
    default:
        break;
    }
}