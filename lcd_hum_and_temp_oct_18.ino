// function, use DHT humidity/temperature sensors and print variable in lcd
// use of digital input 
#include "DHT.h" // initialize the DHT library
#define DHTPIN 7     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   //  type of dht you're using
DHT dht(DHTPIN, DHTTYPE);// Initialize DHT sensor.
#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  dht.begin();// start DHT sensor.
lcd.begin (16,2);// set up the LCD's number of columns and rows:  
}

void loop() {
  
  delay(2000);// Wait a few seconds between measurements.
  
  // Reading temperature or humidity takes about 250 milliseconds
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    lcd.println(F("Failed to read from DHT sensor!"));
    return;
    }

  
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h);

  
  lcd.setCursor(0,0);// print the values on lcd
  lcd.print(F("Hum: "));// print the values on lcd
  lcd.print(h);// print the values on lcd
  lcd.print (F("% "));// print the values on lcd
 
  lcd.setCursor (0,1);// print the values on lcd
  lcd.print(F("Temp: "));// print the values on lcd
  lcd.print (t);// print the values on lcd
  lcd.print(F(" C "));// print the values on lcd

  
   }
