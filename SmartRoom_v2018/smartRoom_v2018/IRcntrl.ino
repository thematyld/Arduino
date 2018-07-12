void IRinit() {
  if (irrecv.decode(&IRresult)) {
    decodeIR();
    irrecv.resume();
  }
}

void decodeIR() {
  switch (IRresult.value) {
    case 0xFF40BF:  changeState(RELE2);   //OK
                    changeState(RELE3);
                    break;
    case 0xFFEA15:  changeState(RELE1);   //POWER
                    break;
  }
}
