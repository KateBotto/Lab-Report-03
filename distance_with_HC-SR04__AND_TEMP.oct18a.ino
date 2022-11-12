// function, use DHT humidity/temperature sensors and print variable in lcd
// as well as print the distance of the ultrasonic sensor HC-SR04
// use of digital input, digital input and digital output

#include "DHT.h"// initialize the DHT library
#define DHTPIN 7     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11  type of dht you're using
DHT dht(DHTPIN, DHTTYPE);// Initialize DHT sensor.

//hook up HC-SR04 with trig to arduino pin 10 and echo to arduino pin 13.
#define trigPin 10
#define echoPin 13
float duration, distance; // declare varible

#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
dht.begin();// start DHT sensor.
lcd.begin (16,2);// set up the LCD's number of columns and rows: 
pinMode(trigPin, OUTPUT); // declaire trigpin and output
pinMode (echoPin, INPUT); // declaire echopin an input
}

void loop() {
  // put your main code here, to run repeatedly:
// Wait a few seconds between measurements.
  delay(2000);
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
  
  // write a pulse to the HC-SR04 Trigger Pin
digitalWrite (trigPin, LOW);
delayMicroseconds (2);
digitalWrite (trigPin, HIGH);
delayMicroseconds (10);
digitalWrite (trigPin, LOW);
// Measure the responce  from the HC-SR04 Echo Pin
duration = pulseIn (echoPin, HIGH);
// determine distance from duration
// use 343 meters per second as speed of sound
distance = (duration/2)*0.0343;

//send results to lcd
lcd.setCursor (0,0);
lcd.print ("Dist = ");
if (distance >= 400 || distance <= 2){
  lcd.println ("Out of range");
}
else { 
  lcd.print (distance);
  lcd.println (" cm  ");
  delay (500);
}
 // send results of DHT 11 to lcd
  lcd.setCursor (0,1);
  lcd.print(F("Temp: "));
  lcd.print (t);
  lcd.print(F(" C "));

}
