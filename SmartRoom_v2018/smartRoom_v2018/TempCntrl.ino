/**
   TIME CONTROLLER
   @author Martin Bartos
   2018
   Controller, which manage time
*/

#include "SmartRoomAPI.h"

void showTemp(int col, int row, unsigned int requiredTime, unsigned long *prevTime) {
  unsigned long time = millis() - (*prevTime);
  if (time > requiredTime) {
    *prevTime = millis();
    int reading = analogRead(tempPin);
    unsigned int tempC = reading / 9.31;
    lcd.setCursor(col, row);
    lcd.print(tempC);
    lcd.print((char)223);
    lcd.print("C");
  }
}
