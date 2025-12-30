/*
 * Dieses Skript erzeugt mit Hilfe eines Piezo-Buzzers die Morse-Code-Ausgabe
 * der Zeichenkette "ESP32 CODE".
 * Es deklariert und implementiert die beiden Funktionen dot() und dash(), um
 * die wiederholenden Code-Abschnitte für die Tonausgabe zu konsolidieren.
 */

#define BUZZER 27
#define M_DOT 100
#define M_DASH 300
#define M_WORD 700

void dot();
void dash();

void setup() {
  Serial.begin(115200);
  Serial.println("\n----------------\nSetup");
  ledcAttach(BUZZER, 2000, 10);
  Serial.println("Setup abgeschlossen.");
}

void loop() {
  // Buchstabe E
  dot();
  delay(M_DASH - M_DOT);

  // Buchstabe S
  dot();
  dot();
  dot();
  delay(M_DASH - M_DOT);

  // Buchstabe P
  dot();
  dash();
  dash();
  dot();
  delay(M_DASH - M_DOT);

  // Ziffer 3
  dot();
  dot();
  dot();
  dash();
  dash();
  delay(M_DASH - M_DOT);

  // Ziffer 2
  dot();
  dot();
  dash();
  dash();
  dash();

  delay(M_WORD - M_DOT);

  // Buchstabe C
  dash();
  dot();
  dash();
  dot();
  delay(M_DASH - M_DOT);

  // Buchstabe O
  dash();
  dash();
  dash();
  delay(M_DASH - M_DOT);

  // Buchstabe D
  dash();
  dot();
  dot();
  delay(M_DASH - M_DOT);

  // Buchstabe E
  dot();
  delay(M_DASH - M_DOT);


  delay(60000);
}


void dot()
{
  ledcWrite(BUZZER, 440);
  delay(M_DOT);
  ledcWrite(BUZZER, 0);
  delay(M_DOT);
}

void dash()
{
  ledcWrite(BUZZER, 440);
  delay(M_DASH);
  ledcWrite(BUZZER, 0);
  delay(M_DOT);
}