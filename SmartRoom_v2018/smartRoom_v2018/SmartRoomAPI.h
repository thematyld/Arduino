/**
    API
    @author Martin Bartos
    2018
*/

void setup();
void loop();
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
void showOnLcd(char** text, char** state, int rows, int cols);
void showReleStateLcd(int stateDevice, String text, int row, int col);
//-----------------RTC----------------------------------
void showDate(int col, int row);
void showTime(int col, int row);
void readTime(byte *second, byte *minute, byte *hour, byte *dayOfWeek, byte *dayOfMonth, byte *month, byte *year);
void setTime(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year);
byte decToBcd(byte val);
byte bcdToDec(byte val);
//------------------------Time--------------------------//
void turnOffBacklight(byte startHour, byte startMinute, byte endHour, byte endMinute);
void turnOffCountDown(int device, byte minutes);
//--------------------Temperature-----------------------//
void showTemp(int col, int row, unsigned int requiredTime, unsigned long *prevTime);

