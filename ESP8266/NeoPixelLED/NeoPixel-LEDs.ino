/* NeoPixel-Beispiel für ESP8266 */

/* Wichtige Hinweise für die praktische Umsetzung
 * Für den Betrieb der NeoPixel ist eine eigenständige 5V-Stromversorgung notwendig. Die
 * Minus-Pole der Stromversorgung und des ESP-Boards müssen miteinander verbunden sein. Der
 * Plus-Pol der Stromversorgung kann mit Vin (5V) am ESP-Board verbunden werden.
 * ---------------------------------------------------------------------------------------------
 * Beim Anschließen der NeoPixel muss unbedingt auf korrekte Polarität geachtet werden, da diese
 * ansonsten umgehend kaputtgehen.
 * ---------------------------------------------------------------------------------------------
 */
#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN D6
#define NUMPIXELS 2

// Bei den meisten NeoPixel-LEDs ist die Farbreihenfolge Green Red Blue (GRB).
Adafruit_NeoPixel pixels(NUMPIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);


void setup()
{
	// NeoPixel-Reihe initialisieren
	pixels.begin();
	// Anzeigewert für alle Pixel auf 0 0 0 stellen
	pixels.clear();
	// aktuelle Anzeigewerte an die Pixel senden
	pixels.show();
}

void loop()
{
	// erstes Pixel grün
	pixels.setPixelColor(0, pixels.Color(255, 0, 0));
	// zweites Pixel rot
	pixels.setPixelColor(1, pixels.Color(0, 255, 0));
	pixels.show();
	delay(2000);
	
	// erstes Pixel blau
	pixels.setPixelColor(0, pixels.Color(0, 0, 255));
	// zweites Pixel gelb
	pixels.setPixelColor(1, pixels.Color(255, 255, 0));
	pixels.show();
	delay(2000);
	
	// Helligkeit reduzieren
	pixels.setBrightness(127);
	pixels.show();
	delay(2000);
	
	// Helligkeit erhöhen
	pixels.setBrightness(255);
	pixels.show();
	delay(2000);
}