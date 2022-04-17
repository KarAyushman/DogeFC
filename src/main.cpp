#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_MPU6050.h>

Adafruit_BMP280 bmp;

void setup() {

  Wire.begin();
  Serial.begin(115200);

  Serial.println("BMP Test");

  //BMP Initialization
  if (!bmp.begin()) {  
    Serial.println("Could not find a valid BMP280 sensor, check connections!");
    while (1) delay(20);
  }

  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     
                  Adafruit_BMP280::SAMPLING_X2,     
                  Adafruit_BMP280::SAMPLING_X16,    
                  Adafruit_BMP280::FILTER_X16,      
                  Adafruit_BMP280::STANDBY_MS_500);

  //BMP Post-Initialization Test Values
  Serial.print(F("Temperature = "));
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");


  Serial.print(F("Pressure = "));
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  Serial.print(F("Approx altitude = "));
  Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
  Serial.println(" m");
  delay(2000);


}

void loop() {
}