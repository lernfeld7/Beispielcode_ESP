/*
    * Dieser Sketch verwendet die Bibliothek ESP32Servo von Kevin Harrington und John Bennett.
    * Sie kann über die Bibliotheksverwaltung installiert werden.
    */
    
#include <ESP32Servo.h>
#define BTN1 14
#define BTN2 27
#define SVPIN_A 16
#define SVPIN_B 17
#define OPEN 1
#define CLOSED 0
    
void toggleDoor();
void toggleWindow();
    
Servo svoA;
Servo svoB;
    
int doorstate = CLOSED;
int windowstate = CLOSED;
int doorcmd = CLOSED;
int windowcmd = CLOSED;
int btn1last = HIGH;
int btn2last = HIGH;
    
/** Setup */
void setup() {
    Serial.begin(115200);
    Serial.println("\n----------------\nSetup");
    
    // Servos initialisieren und stellen
    svoA.attach(SVPIN_A);
    svoA.write(0);
    svoB.attach(SVPIN_B);
    svoB.write(0);
    delay(800);
    svoA.detach();
    svoB.detach();
    
    // Taster initialisieren
    pinMode(BTN1, INPUT);
    pinMode(BTN2, INPUT);
    btn1last = digitalRead(BTN1);
    btn2last = digitalRead(BTN2);
    
    Serial.println("Setup abgeschlossen");
}
    
/** loop */
void loop() {
    int btn1val = digitalRead(BTN1);
    int btn2val = digitalRead(BTN2);
    
    // Druck auf Taster 1 erkennen
    if (btn1val != btn1last) // Tasterzustand geändert
    {
    btn1last = btn1val;
    if (btn1val == LOW)  // drücken erkannt, kein loslassen
    {
        if (doorstate == CLOSED)
        {
        doorcmd = OPEN;
        }
        else if (doorstate == OPEN)
        {
        doorcmd = CLOSED;
        }
    }
    }
    
    // Druck auf Taster 2 erkennen
    if (btn2val != btn2last) // Tasterzustand geändert
    {
    btn2last = btn2val;
    if (btn2val == LOW) // drücken erkannt, kein loslassen
    {
        if (windowstate == CLOSED)
        {
        windowcmd = OPEN;
        }
        else if (windowstate == OPEN)
        {
        windowcmd = CLOSED;
        }
    }
    }
    
    // Befehle auslösen
    if (windowstate != windowcmd)
    {
    toggleWindow();
    }
    
    if (doorstate != doorcmd)
    {
    toggleDoor();
    }
    
    delay(500);
}
    
    
/** toggleDoor */
void toggleDoor()
{
    // Sollzustand ermitteln
    int dst = 0;
    if (doorcmd == OPEN)
    {
    dst = 180;
    Serial.println("Tür öffnen");
    }
    else if (doorcmd == CLOSED)
    {
    dst = 0;
    Serial.println("Tür schließen");
    }
    // Bewegung durchführen
    svoA.attach(SVPIN_A);
    svoA.write(dst);
    doorstate = doorcmd;
    delay(1000);
    svoA.detach();
}
    
    
/** toggleWindow */
void toggleWindow()
{
    // Sollzustand ermitteln
    int dst = 0;
    if (windowcmd == OPEN)
    {
    dst = 150; // Das Fenster darf nur bis 150 geöffnet werden!
    Serial.println("Fenster öffnen");
    }
    else if (windowcmd == CLOSED)
    {
    dst = 0;
    Serial.println("Fenster schließen");
    }
    // Bewegung durchführen
    svoB.attach(SVPIN_B);
    svoB.write(dst);
    windowstate = windowcmd;
    delay(1000);
    svoB.detach();
}