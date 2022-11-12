// function is to print on the lcd the voltage and bit value
// use of analog input
#include <LiquidCrystal.h> // include lcd library
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
lcd.begin (16,2);  // set up the LCD's number of columns and rows:
lcd.print ("Voltage ");// Print a message to the LCD.

}

void loop() {
  // put your main code here, to run repeatedly:
int sensorValue = analogRead (A0); // read the potentiometer on A0:
float voltage= sensorValue*0.0049; // find voltage value by multiplication 
//of sensor value and 0.0049
lcd.setCursor(0,1);// set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
lcd.print (voltage);// Print a message to the LCD.
lcd.print ("     ");// Print a message to the LCD.
lcd.print (sensorValue);// Print a message to the LCD.
}
