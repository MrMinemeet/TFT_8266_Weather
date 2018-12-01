#include <TFT.h>  // Arduino TFT library
#include <SPI.h>  // Serial Communication
#include <DHT.h>  // Sensor Library

// Pins für Arduino Nano
#define cs   10
#define dc   9
#define rst  8
#define DHT11_PIN 5

// Object für Display
TFT TFTscreen = TFT(cs, dc, rst);
DHT dht(DHT11_PIN, DHT11);

// Char Array für Zahl als Char
char tempChar[11];
char humidityChar[11];

float temp;
float humidity;

void setup() {
  // TFT Display initialisieren
  TFTscreen.begin();
  TFTscreen.setTextSize(2);
}

void loop() {

  TFTscreen.background(0, 0, 0);

  
  temp = dht.readTemperature();
  humidity = dht.readHumidity();
  

  TFTscreen.stroke(255, 255, 255);
  
  itoa(temp, tempChar, 10);
  
  itoa(humidity, humidityChar, 10);

  
  TFTscreen.text("Temp.:\n", 0, 0);
  
  // Textfarbe auf Weiß setzen und Temp ausgeben
  TFTscreen.text(tempChar, 0, 32);

  
  TFTscreen.text("Temp.:\n", 0,64);

  
  // Long in Char Array umwandeln
  itoa(humidity, tempChar, 10);
  
  // Textfarbe auf Weiß setzen und Temp ausgeben
  TFTscreen.text(humidityChar, 0, 96);

  delay(5000);

}
