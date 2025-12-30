/*
 * Dieses Beispiel zeigt das Einlesen und Ausgeben digitaler Werte am Beispiel von Buttons, LED und Relais.
 * Zur besseren Veranschaulichung erfolgen zusätzlich Ausgaben über die serielle Konsole.
 * Es werden keine zusätzlichen Bibliotheken benötigt.
 */

// Anschlussbelegung gemäß Definition vornehmen
#define LED1 18
#define BTN1 19
#define BTN2 23
#define REL 13

void setup() 
{
  Serial.begin(115200);
  Serial.println("")
  Serial.println("Setup ...");

  // Ein-/Ausgabemodus der Pins setzen
  pinMode(LED1, OUTPUT);
  pinMode(REL, OUTPUT);
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);

  // Teschleife, um sicherzustellen, dass LED und Relais funktionieren
  Serial.println("Funktionstest");
  for (int i = 0; i < 5; i++)
  {
    delay(700);
    digitalWrite(LED1, HIGH);
    digitalWrite(REL, HIGH);
    delay(300);
    digitalWrite(LED1, LOW);
    digitalWrite(REL, LOW);
  }

  Serial.println("Setup abgeschlossen");
}

void loop() 
{
  bool btn1Val = digitalRead(BTN1);
  bool btn2Val = digitalRead(BTN2);
  Serial.print("Button 1: ");
  Serial.print(btn1Val);
  Serial.print(", Button2: ");
  Serial.println(btn2Val);

  // Ein gedrückter Button gibt ein LOW-Signal, weshalb zum Schalten der
  // Bauteile ein NOT (!) vorangestellt werden muss.
  digitalWrite(LED1, !btn1Val);
  digitalWrite(REL, !btn2Val);
  delay(50); // 20 mal pro Sekunde einlesen, schalten und Konsolenausgabe genügt
}