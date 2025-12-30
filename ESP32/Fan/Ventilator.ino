/* Dieses Beispiel verwendet die GPIO-Pins 18 und 19, um den Ventilator hin- und herdrehen zu lassen. Am Anfang
 * findet im Setup ein Testlauf statt, jeweils volle Geschwindigkeit in beide Richtungen. Anschließend läuft im 
 * Loop der Ventilator immer wieder vorwärt uns rückwärts mit variabler Geschwindigkeit. Wenn der Serielle
 * Monitor geöffnet ist, kann man beobachten, welche Werte für Eingang 1 und 2 des Ventilators zu welchem
 * Verhalten führen.
 */

#define FAN1 18
#define FAN2 19


void setup() {
  Serial.begin(115200);
  Serial.println("Setup");

  Serial.println("Testlauf");
  // vorwärts
  analogWrite(FAN1, 0);
  analogWrite(FAN2, 255);
  delay(2000);
  // rückwärts
  analogWrite(FAN1, 255);
  analogWrite(FAN2, 0);
  delay(2000);
  // stop
  analogWrite(FAN1, 0);
  Serial.println("abgeschlossen");
}


void loop() {

  // vorwärts beschleunigen
  for (int i = 0; i < 256; i++)
  {
    analogWrite(FAN1, i);
    Serial.print("1: ");
    Serial.print(i);
    Serial.println(", 2: 0");
    delay(30);
  }
  
  // vorwärts abbrembsen
  for (int i = 0; i < 256; i++)
  {
    analogWrite(FAN2, i);
    Serial.print("1: 255, 2: ");
    Serial.println(i);
    delay(30);
  }
  
  // rückwärts beschleunigen
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(FAN1, i);Serial.print("1: ");
    Serial.print(i);
    Serial.println(", 2: 255");
    delay(30);
  }
  
  // rückwärts abbremsen
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(FAN2, i);
    Serial.print("1: 0, 2: ");
    Serial.println(i);
    delay(30);
  }
  delay(2000);
}