#define KEY_COUNT 2
const int rele[4]={8,9,10,11};
const int keys[4]={2,3,4,5};
int key[4];
char keyOn[4];
unsigned long prevTime[4];

void setup() {
  for(int i=0;i<KEY_COUNT;i++){
    keyOn[i]=false;
    prevTime[i]=0;
    pinMode(rele[i],OUTPUT);
    digitalWrite(rele[i],HIGH);
    pinMode(keys[i],INPUT_PULLUP);  
  }
  Serial.begin(9600);
}

void loop() {
  turnKey(0,750,rele[0],&prevTime[0]);
  turnKey(1,750,rele[1],&prevTime[1]);
  delay(10);
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
