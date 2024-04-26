// C++ code
//
#include <LiquidCrystal_I2C.h>
int address=0x27;
int columns=16;
int row=2;
LiquidCrystal_I2C lcd(address,columns,row);
void setup()
{
 lcd.init();
 lcd.backlight();
 lcd.clear();
 lcd.setCursor(5,0); //first=column , second=row
 lcd.print("Hello ");
 lcd.setCursor(5,1);
 lcd.print("World!");
}

void loop()
{
 
}