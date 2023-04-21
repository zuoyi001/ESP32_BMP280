#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
 
Adafruit_BMP280 bmp; // I2C
 
void setup() {
Serial.begin(9600);
Serial.println(F("BMP280 test"));

// Inisialisasi sensor  
if (!bmp.begin(0x76)) {
Serial.println("Could not find a valid BMP280 sensor, check wiring!");
while (1);
}
}
 
void loop() {
  
// Berfungsi untuk membaca dan menulis hasil dari pembacaan temperatur dalam Celsius
Serial.print("Temperature = ");
Serial.print(bmp.readTemperature());
Serial.println(" *C");

// Berfungsi untuk membaca dan menulis hasil dari pembacaan tekanan sekitar
Serial.print("Pressure = ");
Serial.print(bmp.readPressure());
Serial.println(" Pa");

// Berfungsi untuk membaca dan menulis hasil dari estimasi ketinggian berdasarkan tekanan di permukaan laut
Serial.print("Approx altitude = ");
Serial.print(bmp.readAltitude(1013.25)); // this should be adjusted to your local forcase
Serial.println(" m");
 
Serial.println();
delay(2000);
}