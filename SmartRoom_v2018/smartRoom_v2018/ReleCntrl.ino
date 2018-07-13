/**
 * RELE CONTROLLER
 * @author Martin Bartos
 * 2018
 * Controller, which handle rele behavior
 */
 
#include "SmartRoomAPI.h"

void releInit(){
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
}

void changeState(int rele) {
  int device = 0, state = -1;
  switch (rele) {
    case RELE1  : state = stateRele[0];
      device = RELE1;
      break;
    case RELE2  : state = stateRele[1];
      device = RELE2;
      break;
    case RELE3  : state = stateRele[2];
      device = RELE3;
      break;
    case RELE4  : state = stateRele[3];
      device = RELE4;
      break;
    default: break;
  }

  if (device > 0 && state >= 0) {
    if (state == HIGH)
      switchRele(device, LOW);
    else
      switchRele(device, HIGH);
  }
}

void switchRele(int rele, int state) {
  digitalWrite(rele, state);
  switch (rele) {
    case RELE1  : stateRele[0] = state;
      break;
    case RELE2  : stateRele[1] = state;
      break;
    case RELE3  : stateRele[2] = state;
      break;
    case RELE4  : stateRele[3] = state;
      break;
    default: break;
  }
}
