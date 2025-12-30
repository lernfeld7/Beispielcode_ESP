/*
  Dieser Sketch benötigt die Bibliothek LiquidCrystal I2C von Frank de Brabander.
  Die Installation kann über die Bibliotheksverwaltung erfolgen.
*/
#include <LiquidCrystal_I2C.h>

// LCD initialisieren: Adresse 0x27, 16 Spalten, 2 Zeilen
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Serial.println("\n----------------\nSetup");

  // LCD-Setup
  lcd.init();
  lcd.clear();
  lcd.backlight();

  // Testnachricht
  lcd.setCursor(0, 0);
  lcd.print("Hello world!");
  delay(1000);
  lcd.setCursor(15, 1);
  lcd.print("t");
  delay(500);
  lcd.setCursor(14, 1);
  lcd.print("s");
  delay(500);
  lcd.setCursor(13, 1);
  lcd.print("e");
  delay(500);
  lcd.setCursor(12, 1);
  lcd.print("T");
  delay(3000);

  Serial.println("Setup abgeschlossen");
}

void loop() {
  // Beispiel für 2-zeilig durchlaufendes Symbol
  lcd.clear();
  for (int row = 0; row < 2; row++)
  {
    for (int col = 0; col < 16; col++)
    {
      lcd.setCursor(col, row);
      lcd.print(">");
      delay(800);
      lcd.setCursor(col, row);
      lcd.print(" ");
    }
  }
}