#include "IRremote.h"
#define KEY_COUNT 2

//-----------------------------------------------------------------------------//
const int rele[4]={8,9,10,11};
const int keys[4]={2,3,4,5};
const int IR=12;
IRrecv irrecv(IR);
decode_results IRresult;
int key[4];
char keyOn[4];
unsigned long prevTime[4];
//-----------------------------------------------------------------------------//
void decodeIR();
void turnKey(byte numKey,unsigned int minTime,int device,unsigned long *lastTime);
//-----------------------------------------------------------------------------//
void setup() {
  for(int i=0;i<KEY_COUNT;i++){
    keyOn[i]=false;
    prevTime[i]=0;
    pinMode(rele[i],OUTPUT);
    digitalWrite(rele[i],HIGH);
    pinMode(keys[i],INPUT_PULLUP);  
  }
  irrecv.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  turnKey(0,750,rele[0],&prevTime[0]);
  turnKey(1,750,rele[1],&prevTime[1]);
  if(irrecv.decode(&IRresult)){
    decodeIR();
    irrecv.resume();
    if(keyOn[0]==true)
      Serial.println("AAA");
    else
      Serial.println("NNN");
  }
  delay(10);
}

void decodeIR(){
  switch(IRresult.value){
    case 0xFF6897: IRturning(rele[0],&keyOn[0]);    break;
    case 0xFF9867: Serial.println(" 2");    break;
    } 
  }
  
void IRturning(int device,char *state){
  if(state){
    digitalWrite(device,LOW);
    *state=false;  
  }
  else{
    digitalWrite(device,HIGH);
    *state=true;
    }
  }
    
void turnKey(byte numKey,unsigned int minTime,int device,unsigned long *lastTime){
  if(numKey>=KEY_COUNT)
    return;
  key[numKey]=digitalRead(keys[numKey]);
  unsigned int Time=millis()-(*lastTime);
  
  if(!key[numKey] && Time>minTime){  
    (*lastTime)=millis();
    if(keyOn[numKey]==false){
      digitalWrite(device,HIGH);
      keyOn[numKey]=true;
    }
    else{
      digitalWrite(device,LOW);
      keyOn[numKey]=false;      
    }
  }
}
