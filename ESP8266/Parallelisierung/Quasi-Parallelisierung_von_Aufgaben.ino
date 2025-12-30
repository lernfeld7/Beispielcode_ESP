#define LED1 D5
#define LED2 D6
#define INTERVAL1 500
#define INTERVAL2 2100
    
int last_led1 = 0; // letzte Veränderung von LED1
int last_led2 = 0; // letzte Veränderung von LED2
int led1_state = HIGH; // Merker für den Zustand von LED1
int led2_state = HIGH; // Merker für den Zustand von LED2
    
void setup() 
{
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    // LEDs ausschalten
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
}
    
void loop() 
{
    // aktuelle Laufzeit in now speichern
    int now = millis();
    
    // Intervall für LED1
    // prüfen ob seit der letzten Veränderung von LED1 mehr als 500ms vergangen sind
    if (now - last_led1 > INTERVAL1)
    {
    // aktuelle Laufzeit als letzte Veränderung für LED1 speichern
    last_led1 = now; 
    // LED1 umschalten
    if (led1_state == HIGH)
    {
        digitalWrite(LED1, LOW);
        led1_state = LOW;
    }
    else if (led1_state == LOW)
    {
        digitalWrite(LED1, HIGH);
        led1_state = HIGH;
    }
    }
    
    // Intervall für LED2
    // prüfen ob seit der letzten Veränderung von LED2 mehr als 2100ms vergangen sind
    if (now - last_led2 > INTERVAL2)
    {
    // aktuelle Laufzeit als letzte Veränderung für LED2 speichern
    last_led2 = now; 
    // LED2 umschalten
    if (led2_state == HIGH)
    {
        digitalWrite(LED2, LOW);
        led2_state = LOW;
    }
    else if (led2_state == LOW)
    {
        digitalWrite(LED2, HIGH);
        led2_state = HIGH;
    }
    }
}