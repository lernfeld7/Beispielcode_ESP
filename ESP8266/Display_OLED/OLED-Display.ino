/*
    * Beispiel für die Verwendung eines 128x64 Pixel OLED-Displays via I2C-Schnittstelle 
    * 
    * Verdrahtung:
    * ============
    * Display | NodeMCU
    *     GND | GND
    *     VCC | 3.3V
    *     SCL | D1
    *     SDA | D2
    *     
    * Dieses Beispiel zeigt einen statischen Begrüßungsbildschirm mit verschiedenen Textelementen und Linien.
    * Danach verändern sich einige Elemente um periodisch auf und ab zu zählen.
    * 
    * siehe auch: https://github.com/ThingPulse/esp8266-oled-ssd1306
    */
    
#include <Wire.h>
#include <SSD1306.h>
#include <OLEDDisplay.h>
    
#define SDA_PIN D2  // SDA an D2
#define SCL_PIN D1  // SCL an D1
    
#define D1 5  // GPIO 5 des ESP ist D1 auf dem Board
#define D2 4  // GPIO 4 des ESP ist D2 auf dem Board
    
const int DISPLAY_ADDR = 0x3c;  // I2C-Addresse des Displays
    
SSD1306Wire * display;
    
int current = 21;  // aktuelle Zahl
int updown = 1;  // Richtung
    
/**
    * setup
    */
void setup() {
    // Serial
    Serial.begin(115200);
    Serial.println();
    delay(100);
    
    // Display initialisieren
    display = new SSD1306Wire(DISPLAY_ADDR, SDA_PIN, SCL_PIN);
    display->init();
    display->displayOn();
    display->flipScreenVertically();
    display->clear();
    
    // Startbildschirm aufbauen
    display->setFont(ArialMT_Plain_16);
    display->drawString(0, 0, "Hello World!");
    
    display->setFont(ArialMT_Plain_10);
    display->drawString(0, 54, "Berufsschule Lichtenfels");
    
    display->setFont(ArialMT_Plain_24);
    display->drawString(96, 21, String(current));
    
    display->setFont(ArialMT_Plain_10);
    display->drawStringMaxWidth(0, 21, 90, "Ein kleiner Absatz mit Text");
    
    // Linien
    display->drawLine(93, 21, 93, 46);
    display->drawLine(0, 18, 127, 18);
    display->drawLine(0, 52, 127, 52);
    
    // Anzeige aktualisieren
    display->display();
    
    delay(5000);
}
    
    
/**
    * loop
    */
void loop() {
    // gemeinsame Elemente der veränderlichen Anzeige
    display->clear();
    
    display->drawLine(93, 21, 93, 46);
    display->drawLine(0, 18, 127, 18);
    display->drawLine(0, 52, 127, 52);
    display->setFont(ArialMT_Plain_10);
    display->drawString(0, 54, "Berufsschule Lichtenfels");
    
    // Ausgabe für Zählvorgang aufwärts
    if (current < 28 && updown == 1) // aufwärts zählen
    {
    current++;
    display->setFont(ArialMT_Plain_16);
    display->drawString(0, 0, "Aufwärts");
    display->setFont(ArialMT_Plain_10);
    display->drawStringMaxWidth(0, 21, 90, "Es geht aufwärts bis 28");
    display->setFont(ArialMT_Plain_24);
    display->drawString(96, 21, String(current));
    }
    else if (current >= 28) // oben angekommen
    {
    updown = 0;
    }
    
    // Ausgabe für Zählvorgang abwärts
    if (current > 11 && updown == 0) // abwärts zählen
    {
    current--;
    display->setFont(ArialMT_Plain_16);
    display->drawString(0, 0, "Abwärts");
    display->setFont(ArialMT_Plain_10);
    display->drawStringMaxWidth(0, 21, 90, "Es geht abwärts bis 11");
    display->setFont(ArialMT_Plain_24);
    display->drawString(96, 21, String(current));
    }
    
    if (current <= 11) // unten angekommen
    {
    updown = 1;
    }
    
    // Anzeige aktualisieren
    display->display();
    
    delay(500);
}