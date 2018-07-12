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

void switchRele(int rele, int state);
void changeState(int rele);
void decodeIR();
void externVyp();
void IRinit();
void showOnLcd(char** text,char** state,int rows,int cols);

int stateVypL = LOW,
    stateVypR = LOW,
    previousL = HIGH,
    previousR = HIGH;
int stateRele[4];

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Ahoj");
  pinMode(RELE1, OUTPUT);
  pinMode(RELE2, OUTPUT);
  pinMode(RELE3, OUTPUT);
  pinMode(RELE4, OUTPUT);
  pinMode(pinVypL, INPUT);
  pinMode(pinVypR, INPUT);

  switchRele(RELE1, LOW);
  switchRele(RELE2, LOW);
  switchRele(RELE3, LOW);
  switchRele(RELE4, LOW);
  previousL = digitalRead(pinVypL);
  previousR = digitalRead(pinVypR);
  irrecv.enableIRIn();
}

void loop() {
  showReleStateLcd(stateRele[0],"Hlavni:",0,2);
  IRinit();
  externVyp();
  delay(10);
}


