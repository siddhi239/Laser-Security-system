#include <Keypad.h>
 const int buz=11;
 const int lgt=7;
 const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 10, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
   
 
 void setup() {
    Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(buz,OUTPUT); //Buzzer Pin
pinMode(lgt,INPUT); // Light Sensor
delay(100);
}

void loop() {
  
int i=0;
if(digitalRead(lgt)==HIGH)
{
  a:
  digitalWrite(buz,HIGH); 
  delay(100);
  digitalWrite(buz ,LOW);
  delay(100);
  
   char key = keypad.getKey();
 
  
  if (key =='4'){
       b:
       Serial.println("Password Correct...Unsecured until restart!!");
       digitalWrite(buz,LOW);
       delay(100);
 
       
       goto b;
              
}

     i++;
     if(i<50){
     goto a;
      }
  }

}
