/*
 * Verwendung des 2. seriellen Anschlusses auf dem NodeMCU 1.0
 * TX: D4
 * RX: nicht existent, transmit only
 * 
 * TX mit RX am anderen Board verbinden
 * GND mit GND am anderen Board verbinden
 */

int count = 0;
String data = "";

void setup() {
  Serial.begin(38400);
  delay(100);
  Serial.print("Setup ...");
  Serial1.begin(38400);
  Serial.println(" done.");
}


void loop() {
  data = "t:" + String(24.2) + ";h:" + String(47) + ";c:" + String(count);
  count++;
  Serial1.println(data);
  Serial.println(data);
  delay(3000);
  data = "t:" + String(23.9) + ";h:" + String(46) + ";c:" + String(count);
  count++;
  Serial1.println(data);
  Serial.println(data);
  delay(3000);
  data = "t:" + String(23.7) + ";h:" + String(45) + ";c:" + String(count);
  count++;
  Serial1.println(data);
  Serial.println(data);
  delay(3000);
}