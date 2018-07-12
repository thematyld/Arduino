void externVyp() {
  stateVypL = digitalRead(pinVypL);
  stateVypR = digitalRead(pinVypR);

  //-------------Externi-vypinac-Levy---------------//
  if (previousL == LOW && stateVypL == HIGH) {
    changeState(RELE1);
    previousL = HIGH;
  }
  if (previousL == HIGH && stateVypL == LOW) {
    changeState(RELE1);
    previousL = LOW;
  }

  //-------------Externi-vypinac-PRAVY---------------//
  if (previousR == LOW && stateVypR == HIGH) {
    changeState(RELE2);
    changeState(RELE3);
    previousR = HIGH;
  }
  if (previousR == HIGH && stateVypR == LOW) {
    changeState(RELE2);
    changeState(RELE3);
    previousR = LOW;
  }
}
