/*
 * Arduino als Empfänger für Daten an der seriellen Schnittstelle
 * Dateneingang über Pin RX
 *
 * RX mit TX am anderen Board verbinden
 * GND mit GND am anderen Board verbinden
 */
String data;
int index = 0;

void setup() 
{
  Serial.begin(38400);
  /*while (!Serial)
  {
    // wait for serial to connect
  }*/
  Serial.println("Setup done.");
}

void loop() 
{
  if (Serial.available())
  {
    double temp;
    double hum;
    int count;

    // von der seriellen Schnittstelle einlesen
    data = Serial.readString();
    data.trim();
    
    // Nachricht am Semikolon aufteilen
    String first = data.substring(0, data.indexOf(";"));
    String remaining = data.substring(data.indexOf(";") + 1, data.length());
    String second = remaining.substring(0, remaining.indexOf(";"));
    String third = remaining.substring(remaining.indexOf(";") + 1, remaining.length());
    
    // Nachricht nach Temperatur und Luftfeuchte auswerten
    if (first.substring(0, 2) == "t:")
    {
      temp = first.substring(first.indexOf(":") + 1, first.length()).toDouble();
    }
    if (second.substring(0, 2) == "h:")
    {
      hum = second.substring(second.indexOf(":") + 1, second.length()).toDouble();
    }
    if (third.substring(0, 2) == "c:")
    {
      count = third.substring(third.indexOf(":") + 1, third.length()).toDouble();
    }

    // Ausgabe
    Serial.print("Temperatur: ");
    Serial.print(temp);
    Serial.print(", Luftfeuchte: ");
    Serial.print(hum);
    Serial.print(", Zähler: ");
    Serial.println(count);
  }
}