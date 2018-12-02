#include <TFT.h>  // Arduino TFT library
#include <SPI.h>  // Serial Communication
#include <DHT.h>  // Sensor Library

// Pins für Arduino Nano
#define cs   10
#define dc   9
#define rst  8
#define DHT11_PIN 5

// Objekt für Display
TFT TFTscreen = TFT(cs, dc, rst);

// Objekt für DHT Sensor
DHT dht(DHT11_PIN, DHT11);

// Char Arrays für Werte
char tempChar[11];
char humidityChar[11];

// Variablen für Werte
float temp;
float humidity;

void setup() {
  // TFT Display initialisieren
  TFTscreen.begin();
  TFTscreen.setTextSize(2);
}

void loop() {
  // Display löschen
  TFTscreen.background(0, 0, 0);

  // Werte einlesen
  temp = dht.readTemperature();
  humidity = dht.readHumidity();
  
  // Schrift auf Weiß stellen
  TFTscreen.stroke(255, 255, 255);

  // Werte in Char Arrays umwandeln
  itoa(temp, tempChar, 10);
  itoa(humidity, humidityChar, 10);

  // Texte und Werte ausgeben
  TFTscreen.setTextSize(2);
  TFTscreen.text("Temperatur:\n", 0, 0);
  TFTscreen.setTextSize(3);
  TFTscreen.text(tempChar, 0, 32);
  TFTscreen.text("C", 40, 32);
  
  TFTscreen.setTextSize(2);
  TFTscreen.text("Feuchtigkeit:\n", 0,64);
  TFTscreen.setTextSize(3);
  TFTscreen.text(humidityChar, 0, 96);
  TFTscreen.text("%", 40, 96);

  delay(30000);
}
