#include <LiquidCrystal.h>
// Pin mapping following the connections table:
// LiquidCrystal(RS , Enable , D4 , D5 , D6 , D7)
const int pin_RS = 12;
const int pin_EN = 11;
const int pin_D4 = 5;
const int pin_D5 = 4;
const int pin_D6 = 3;
const int pin_D7 = 2;

LiquidCrystal lcd(pin_RS , pin_EN , pin_D4 , pin_D5 , pin_D6 , pin_D7);

void setup () {
   lcd.begin (16, 2); // Sets the LCD with 16 columns e 2 lines
   lcd.clear (); // Clears the screen and set mouse to (0,0)
   lcd.print("Hello , World!");

}
void loop() {
   lcd.setCursor (0,1); // moves the cursor to the second line
   lcd.print(millis () /1000); // shows number of seconds
}
