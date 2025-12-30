#define PIR 14
    
void setup() {
    Serial.begin(115200);
    Serial.println("\n----------------\nSetup");  
    pinMode(PIR, INPUT);
}
    
void loop() {
    bool pirValue = digitalRead(PIR);
    Serial.print("PIR meldet: ");
    Serial.println(pirValue);
    delay(250);
}