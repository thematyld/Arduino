/**
 * DISPLAY CONTROLLER
 * @author Martin Bartos
 * 2018
 * Show, how represent data to LCD display
 */
 
void showOnLcd(String text,String state,int row,int col){
  bool allowed=false;
  assert(row>=0 && col>=0); 
  if((text.length()+state.length()+col+1)<20)
    allowed=true; 
    
  if(row<20 && col<4 && allowed){
    lcd.setCursor(col,row);
    lcd.print(text);
    lcd.print(" ");
    lcd.print(state);  
  }
  else{
    lcd.setCursor(col,row);
    lcd.print("NN");
  }
}

void showReleStateLcd(int stateDevice,String text,int row,int col){
  String state="";
  if(stateDevice==HIGH)
    state="ON ";
  else
    state="OFF";

  showOnLcd(text,state,row,col);
}
