#ifndef IR_SENDER_H
#define IR_SENDER_H

#include <Arduino.h>
#include <Chrono.h>

#define LOW_SHORT_TIME 400
#define LOW_LONG_TIME 800
#define HIGH_SHORT_TIME 400
#define HIGH_LONG_TIME 800

// on pourrait faire 8 secteurs en ajoutant un bit en plus
enum class Puce{
  Finish = 0b00,
  Sector1 = 0b01,
  Sector2 = 0b10,
  Sector3 = 0b11
};


class IRSender {
private:
  int irPin;
  int8_t puceSignalBin;
  Chrono pulseClock;


  void sendPulse(long microsec);

public:
  IRSender(int pin, int8_t puce);

  void setup();

  void sendSignal();


  // pour faire les tests
  unsigned long previousMillis = 0;
  void sendPulseSignal(unsigned long intervalMS) {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= intervalMS) {
      for (int i = 0; i < 8; i++)
        sendSignal();

      previousMillis = currentMillis;
    }
  }
};

#endif // IR_SENDER_H