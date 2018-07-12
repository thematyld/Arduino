/**
 * MAIN
 * @author Martin Bartos
 * 2018
 */
 
#include "IRremote.h"
#include <assert.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RELE_COUNT 4
#define RELE1 8
#define RELE2 9
#define RELE3 10
#define RELE4 11

const int IR = 5;
const int pinVypR = 6;
const int pinVypL = 7;

LiquidCrystal_I2C lcd(0x3E,20,4); 
IRrecv irrecv(IR);
decode_results IRresult;
//----------------Prototype-of-functions----------------

//----------------ReleCntrl-----------------------------
void releInit();
void switchRele(int rele, int state);
void changeState(int rele);
//----------------IRcntrl-------------------------------
void decodeIR();
void IRinit();
//----------------ExternVypinacCntrl--------------------
void externVyp();
//----------------DisplayCntrl--------------------------
void showOnLcd(char** text,char** state,int rows,int cols);
void showReleStateLcd(int stateDevice,String text,int row,int col);
//------------------------------------------------------
int stateVypL = LOW,
    stateVypR = LOW,
    previousL = HIGH,
    previousR = HIGH;
int stateRele[4];

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(5,0);
  lcd.print("SmartHome");
  releInit();
  previousL = digitalRead(pinVypL);
  previousR = digitalRead(pinVypR);
  irrecv.enableIRIn();
}

void loop() {
  showReleStateLcd(stateRele[0],"Hlavni      :",2,0);
  showReleStateLcd(stateRele[1],"Podsvetleni :",3,0);
  
  IRinit();
  externVyp();
  delay(10);
}


