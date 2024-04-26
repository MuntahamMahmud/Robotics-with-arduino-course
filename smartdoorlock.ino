#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

//----------------LCD----------------
int address=0x27;
int columns=16;
int row=2;
LiquidCrystal_I2C lcd(address,columns,row);

//---------------KEYPAD--------------------
const byte ROWS = 4; // Number of rows in the keypad
const byte COLS = 4; // Number of columns in the keypad

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; // Row pins connected to Arduino
byte colPins[COLS] = {5, 4, 3, 2}; // Column pins connected to Arduino

// Create instance of the Keypad class
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//------------password----------------

String inputpassword="";
String systempassword="1234";
int password_length=4;

void setup()
{ lcd.init();
  lcd.clear();
 lcd.backlight();
  Serial.begin(9600);

}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("enter your pass");
  int x=0;
  pinMode(10,OUTPUT);
  while(1){
  char key=keypad.getKey();
  if(key){
    if(inputpassword.length()<password_length)
    {
    
    inputpassword=inputpassword+key;
    lcd.setCursor(x,1);
    lcd.print("*");
    x++;
    }
    if(inputpassword.length()==password_length)
    {
      if(inputpassword==systempassword){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("door unlocked");
    digitalWrite(10,HIGH);
    inputpassword="";
    delay(2000);
    break;  
      } 
      else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(inputpassword);
      delay(2000);
      break;
      }
    }
    
    
  }
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("door locked");
  delay(1000);
}