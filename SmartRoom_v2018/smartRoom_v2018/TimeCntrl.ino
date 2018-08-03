/**
   TIME CONTROLLER
   @author Martin Bartos
   2018
   Controller, which manage time
*/

#include "SmartRoomAPI.h"
void turnOffCountDown(int device, byte minutes) {
  DateTime now = RTC.now();
  
  if (countDownAble == true) {
    if ((now.minute() + minutes) >= 60) {
      reqHour = now.hour() + 1;
      reqMinute = now.minute() - 60;
    }
    else{
      reqHour=now.hour();
      reqMinute=now.minute()+minutes;  
    }
    countDownAble = false;
  }
  else {
    if ((now.hour() == reqHour) && (now.minute() == reqMinute)){
      switchRele(device, LOW);
      countDownAble=true;
    }
  }


}

void turnOffBacklight(byte startHour, byte startMinute, byte endHour, byte endMinute) {
  DateTime now = RTC.now();

  if ((now.hour() >= startHour) && (now.hour() <= endHour)) {
    if ((now.minute() >= startMinute) && (now.minute() <= endMinute)) {
      backlight = false;
      lcd.noBacklight();
    }
    else {
      backlight = true;
      lcd.backlight();
    }
  }
}

void showTime(int col, int row) {
  //Hours
  lcd.setCursor(col, row);
  DateTime now = RTC.now();
  if (now.hour() < 10)
    lcd.print("0");
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  if (now.minute() < 10)
    lcd.print("0");
  lcd.print(now.minute(), DEC);
  lcd.print(":");
  if (now.second() < 10)
    lcd.print("0");
  lcd.print(now.second(), DEC);

}
void showDate(int col, int row) {
  DateTime now = RTC.now();
  lcd.setCursor(col, row);
  if (now.day() < 10)
    lcd.print(" ");
  lcd.print(now.day(), DEC);
  lcd.print(".");
  lcd.print(now.month(), DEC);
  lcd.print(".");

  //lcd.print((now.year()%2000), DEC);
  lcd.print(" ");

  switch (now.dayOfTheWeek()) {
    case 1:
      lcd.print("Po");
      break;
    case 2:
      lcd.print("Ut");
      break;
    case 3:
      lcd.print("St");
      break;
    case 4:
      lcd.print("Ct");
      break;
    case 5:
      lcd.print("Pa");
      break;
    case 6:
      lcd.print("So");
      break;
    case 0:
      lcd.print("Ne");
      break;
    default:;
  }
}

byte decToBcd(byte val) {
  return ( (val / 10 * 16) + (val % 10) );
}

// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val) {
  return ( (val / 16 * 10) + (val % 16) );
}
