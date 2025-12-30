/*
    * benötigt: DHT sensor library for ESPx von beegee_tokyo (Installation über Library Manager)
    * Board: NodeMCU 1.0 (ESP-12E Module)
    * DHT22-Sensor an D4 anschließen
*/
    
#include <DHTesp.h>
#define DHT_PIN D4
    
float temperatur = 0.0;
float temperatur_old = 0.0;
float humidity = 0.0;
float humidity_old = 0.0;
    
DHTesp dht;
    
    
void setup() 
{
    Serial.begin(9600); 
    delay(2000);
    
    Serial.println("Setting up Sensor:");
    dht.setup(DHT_PIN, DHTesp::DHT22);
    Serial.println("Done");
}
    
    
void loop() 
{
    Serial.println("Auslesen:");
    temperatur = dht.getTemperature();
    humidity = dht.getHumidity();  
    
    /* Temperatur ausgeben, wenn verändert */
    if (temperatur != temperatur_old) 
    {
    temperatur_old = temperatur;
    Serial.println(temperatur_old);
    }
    
    /* Luftfeuchtigkeit ausgeben, wenn verändert */
    if (humidity != humidity_old) 
    {
    humidity_old = humidity;
    Serial.println(humidity);
    }
    
    delay(5000);
}