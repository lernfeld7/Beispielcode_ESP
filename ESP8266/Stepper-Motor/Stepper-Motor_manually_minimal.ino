/*
    * PIN-Belegung:
    * Pins D0-D3 des NodeMCU an Pins IN1-IN4 am Motorboard
    * Stromversorgung (5V) an VCC und GND
    * 
    * Motor dreht in der Schleife abwechselnd links und rechts herum.
    */
    
#define IN1 D0  // Input 1 am Motormodul
#define IN2 D1  // Input 2 am Motormodul
#define IN3 D2  // Input 3 am Motormodul
#define IN4 D3  // Input 4 am Motormodul
#define LEFT 0  // Richtungsangabe für Steppermotor
#define RIGHT 1  // Richtungsangabe für Steppermotor
    
// Forward Declarations
void init_stepper();
void step(int s);
int next_step(int currentStep, int currentDirection);
void test_stepper();
void init_echo();
void read_distance();
    
// Konstanten
const int positions[8][4] = { // Abbildung aller 8 Stellungen des
    {LOW, LOW, LOW, HIGH},      // Motors vor dem Getriebe durch
    {LOW, LOW, HIGH, HIGH},     // Beschaltung der 4 Motorwicklungen
    {LOW, LOW, HIGH, LOW},      // Es wird immer abwechselnd eine
    {LOW, HIGH, HIGH, LOW},     // einzelne Wicklung und dann 2 
    {LOW, HIGH, LOW, LOW},      // benachbarte Wicklungen gleichzeitig
    {HIGH, HIGH, LOW, LOW},     // aktiviert. Dadurch kommen bei 4
    {HIGH, LOW, LOW, LOW},      // Wicklungen 8 Einzelschritte bei 
    {HIGH, LOW, LOW, HIGH}      // einer Umdrehung zustande.
};
    
// globale Variablen
int curStep = 0;  // aktueller Schrittzustand
int curDir = RIGHT;  // aktuelle Drehrichtung
    
int curPos = 0;  // aktuelle Motorstellung
int gotoPos = 0; // gewünschte Motorstellung
    
    
/* ---------- Hauptfunktionen ---------- */
    
/**
    * setup
    */
void setup() 
{
    // Serielle Konsole
    Serial.begin(9600);
    Serial.println("Setup");
    
    // Stepper initialisieren
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}
    
/**
    * loop
    */
void loop() 
{
    // rechts drehen, insgesamt 64 Umdrehungen
    for (int i = 0; i < 64; i++)
    {
    // Stellung 1
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(5);
    // Stellung 2
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(5);
    // Stellung 3
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(5);
    // Stellung 4
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(5);
    // Stellung 5
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(5);
    // Stellung 6
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    delay(5);
    // Stellung 7
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(5);
    // Stellung 8
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(5);
    }
    
    // Motor stromlos schalten
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(1000);
    
    // links drehen, insgesamt 64 Umdrehungen
    for (int i = 0; i < 64; i++)
    {
    // Stellung 8
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(5);
    // Stellung 7
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(5);
    // Stellung 6
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    delay(5);
    // Stellung 5
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(5);
    // Stellung 4
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(5);
    // Stellung 3
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(5);
    // Stellung 2
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(5);
    // Stellung 1
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(5);
    }
    // Motor stromlos schalten
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(2000);
}