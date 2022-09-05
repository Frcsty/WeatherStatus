#include <Wire.h>
#include <LiquidCrystal.h>
#include <Adafruit_BMP085.h>
#include <dht11.h>

#define debug true
#define seaLevelPressure_hPa 1013.25
#define DHT11PIN 22

LiquidCrystal lcd(8,9,4,5,6,7); 
Adafruit_BMP085 bmp;
dht11 DHT11;

void setup() {
  lcd.begin(16, 2);
  if (debug) 
    Serial.begin(115200);
 
  if (!bmp.begin())
  	if (debug) Serial.println("Could not find a valid BMP sensor, check wiring!");
    else lcd.print("Sensor Missing");

  lcd.print("Reading sensor");
}

void loop() {
  lcd.clear();
  DHT11.read(DHT11PIN);

  lcd.print("Temp: "); lcd.print(bmp.readTemperature()); lcd.print(" °C, Hum: "); lcd.print(DHT11.humidity); lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Pres: ") lcd.print(bmp.readPressure(), 3); lcd.print(" Pa");

  if (debug) {
    Serial.print("Humidity (%): "); Serial.println(DHT11.humidity);
    Serial.print("Temperature 1 (C): "); Serial.println(DHT11.temperature);

    Serial.print("Temperature 2 (C): "); Serial.println(bmp.readTemperature());
    Serial.print("Pressure (Pa): "); Serial.println(bmp.readPressure());
  }

  delay(2000);
}