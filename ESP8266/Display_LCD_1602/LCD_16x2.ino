/*
 * Pin-Belegung
 * LCD : ESP
 * GND | GND
 * VCC | Voltage In
 * SDA | D2
 * SCL | D1
 *
 * Dieses Beispiel benötigt die Library LiquidCrystal I2C von Frank de Brabander (siehe Bibliothesverwaltung).
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
#define I2C_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2
 
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLS, LCD_ROWS);
 
void setup() {
  Wire.begin();
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.backlight();
 
  lcd.setCursor(0, 0);
  lcd.print("Hallo mein Name ist Dumbledore");
  lcd.setCursor(0, 1);
  lcd.print("Ich zaubere gerne");
}
 
void loop() {
 
  lcd.scrollDisplayLeft();
  delay(300);
}