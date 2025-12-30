/*
    * Servo-Beispiel für ESP8266
    * Servo:
    * PWM | D8
    * VCC | 5V
    * GND | GND
    * Belegung siehe auch https://www.electronicsplanet.ch/Roboter/Servo/stecker/graupner.jpg
    * 
    * Durch die Eingabe eines Zahlenwertes von 0 bis 180 in die serielle Konsole 
    * kann die Stellung des Servos vorgegeben werden.
    */
#include <Servo.h>
    
Servo servo;
int oldpos = 0;
int newpos = 0;
    
#define SERVO D8  // Servo an Pin D8
    
    
void setup() {
    servo.attach(SERVO,500,2400);
    Serial.begin(115200);
    servo.write(newpos);
}
    
void loop() {
    // Eingabe lesen
    String s = Serial.readString();
    if (s != "")
    {
    // Eingabe zur neuen Soll-Position erklären, wenn sie nicht leer und im zulässigen Bereich ist
    Serial.println(s);
    int n = s.toInt();
    if ( n >= 0 && n <= 180)
    {
        newpos = n;
    }
    }
    
    // nur ansteuern, wenn sich die Position verändert hat
    if (newpos != oldpos)
    {
    oldpos = newpos;
    servo.write(newpos);
    }
}