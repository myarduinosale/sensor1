
#include <Keypad.h>
const byte ROWS = 5; //four rows

const byte COLS = 4; //three columns

char keys[ROWS][COLS] = {

  {'Q','W','#','*'},

  {'1','2','3','U'},

  {'4','5','6','D'},

  {'7','8','9','S'},
  
  {'L','0','R','N'}

};

byte rowPins[ROWS] = {10,9, 8, 7, 6};

byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup(){

  Serial.begin(9600);

}

void loop(){

  char key = keypad.getKey();

 

  if (key != NO_KEY){

    Serial.println(key);

  }

}
