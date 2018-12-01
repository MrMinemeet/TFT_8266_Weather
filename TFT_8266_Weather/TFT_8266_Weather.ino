#include <TFT.h>  // Arduino TFT library
#include <SPI.h>  // Serial Communication

// Pins für Arduino Nano
#define cs   10
#define dc   9
#define rst  8

// Obejt für Display
TFT TFTscreen = TFT(cs, dc, rst);

// Char Array für Zahl als Char
char tempChar[11];
char humidityChar[11];

float temp = -1.00;
float humidity = -1.00;

void setup() {
  // TFT Display initialisieren
  TFTscreen.begin();

  // Hintergrund auf Schwarz setzen
  TFTscreen.background(0, 0, 0);
  // Textfarbe auf Weiß setzen
  TFTscreen.stroke(255, 255, 255);
  
  TFTscreen.setTextSize(2);
  // Text oben links ausegben
  TFTscreen.text("Temp.:\n", 0, 0);
  TFTscreen.text("Temp.:\n", 0, 50);
  
  TFTscreen.setTextSize(2);
}

void loop() {
  

  TFTscreen.stroke(255, 255, 255);
  
  itoa(temp, tempChar, 10);
  
  itoa(humidity, humidityChar, 10);
  
  // Textfarbe auf Weiß setzen und Temp ausgeben
  TFTscreen.text(tempChar, 0, 25);

  
  // Long in Char Array umwandeln
  itoa(humidity, tempChar, 10);
  
  // Textfarbe auf Weiß setzen und Temp ausgeben
  TFTscreen.text(humidityChar, 0, 70);

  delay(10000);

  // Löschen
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.text(tempChar, 0, 25);
  TFTscreen.text(humidityChar, 0, 70);

}
