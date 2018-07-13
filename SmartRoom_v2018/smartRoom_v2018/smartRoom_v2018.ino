/**
   MAIN
   @author Martin Bartos
   2018
*/

#include "IRremote.h"
#include <assert.h>
#include <Wire.h>
#include "RTClib.h"
#include "SmartRoomAPI.h"
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"

#define RELE_COUNT 4
#define RELE1 8
#define RELE2 9
#define RELE3 10
#define RELE4 11
#define RTC_ADDRESS 0x68

const int IR = 2;
const int tempPin = A0;
const int pinVypR = 6;
const int pinVypL = 7;

LiquidCrystal_I2C lcd(0x3E, 20, 4);
IRrecv irrecv(IR);
decode_results IRresult;
RTC_DS1307 RTC;

int stateVypL = LOW,
    stateVypR = LOW,
    previousL = HIGH,
    previousR = HIGH;

unsigned long prevTempTime = 0;

int stateRele[4];

void setup() {

  analogReference(INTERNAL);
  Wire.begin();
  RTC.begin();
  RTC.adjust(DateTime(__DATE__, __TIME__));
  DateTime now = RTC.now();
  // RTC.adjust(now.unixtime() + 27);

  lcd.init();
  lcd.backlight();
  releInit();
  previousL = digitalRead(pinVypL);
  previousR = digitalRead(pinVypR);
  irrecv.enableIRIn();
}


void loop() {
  showReleStateLcd(stateRele[0], "Hlavni       :", 0, 2);
  showReleStateLcd(stateRele[1], "Podsvetleni  :", 0, 3);
  IRinit();
  showTime(0, 0);
  showDate(12, 0);
  showTemp(8, 1, 2000, &prevTempTime);
  externVyp();

  delay(10);
}



