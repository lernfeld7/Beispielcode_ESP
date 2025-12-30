/*
    * Dieses Beispiel zeigt, wie der EEPROM-Speicher dazu verwendet werden kann, 
    * Zugangsdaten für die WiFi-Verbindung variabel zu speichern und bei Bedarf
    * zu ändern, ohne dass die Firmware neu geflasht werden muss.
    * Zu diesem Zweck versucht sich der Microcontroller zu einem fest vorgegebenen
    * Konfigurations-Hotspot zu verbinden. Wenn dieser auffindbar ist, startet er
    * die Konfigurations-Webseite und lässt sich konfigurieren. Wenn die Verbindung
    * fehlschlägt, startet der Microcontroller ganz normal. Die Wartezeit für den
    * Hotspot beträgt bei diesem Beispiel 5 Sekunden (10 * 500ms).
    *
    * Der HTML-Code für die Webseite befindet sich in der Datei strings.h, diese darf
    * nicht fehlen.
    */
    
#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include <ESP8266WebServer.h>
    
#include "strings.h"
    
    
// PP-Direktiven
#define EEPROM_SIZE 512
#define SSID_SIZE 32
#define SSID_ADDR 0
#define PASS_SIZE 64
#define PASS_ADDR 32
    
    
// forward declarations
void readEEPROMwifi(char *ssid, char *passphrase);
void writeEEPROMwifi(char *ssid, char *passphrase);
void handleRoot();
void handleSetWifi();
void handleReset();
    
// Konstanten
const char* cssid = "configAP"; // Access Point-SSID für den Konfigurationsmodus
const char* cpassword = "configPassphrase"; // Kennwort für den AP im Konfigurationsmodus
const char* hostname = "myMicrocontroller";
char ssid[SSID_SIZE];
char password[PASS_SIZE];
    
    
// Variablen
ESP8266WebServer server(80); // Instanz für den Konfigurations-Webserver
bool configMode = false;
    
    
/**
    * Setup
    */
void setup() {
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    Serial.println();
    
    /* ******** config mode ******** */
    Serial.println("Trying config mode, searching for config AP");
    
    WiFi.begin(cssid, cpassword);
    WiFi.setHostname(hostname);
    
    int configCount = 0;
    while (WiFi.status() != WL_CONNECTED && configCount < 10) {
    delay(500);
    configCount++;
    Serial.print(".");
    }
    Serial.println("");
    if (WiFi.status() != WL_CONNECTED)
    {
    Serial.println("Skipping config Mode");
    }
    else
    {
    Serial.println("WiFi connected to config AP");
    Serial.print("Use 'http://");
    Serial.print(WiFi.localIP());
    Serial.println("' to connect");
    configMode = true;
    }
    
    server.on("/", handleRoot);
    server.on("/setwifi", handleSetWifi);
    server.on("/reset", handleReset);
    server.begin();
    
    if (configMode)
    {
    return;
    }
    
    /* ******** no config mode ******** */
    
    /* WiFi connection */
    readEEPROMwifi(ssid, password);
    
    Serial.print("Connecting to ");
    Serial.print(ssid);
    Serial.print(" using ");
    Serial.println(password);
    
    WiFi.begin(ssid, password);
    WiFi.setHostname(hostname);
    
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print(WiFi.localIP());
}
    
    
/**
    Loop
    */
void loop() {
    if (configMode)
    {
    server.handleClient();
    }
    else
    {
    Serial.println("Faul sein ist wunderschön, denn die Arbeit hat noch Zeit. (Pipi Langstrumpf)");
    delay(5000);
    }
}
    
    
/**
    * read ssid and passphrase from eeprom and write into given char arrays
    */
void readEEPROMwifi(char *ssid, char *passphrase)
{
    EEPROM.begin(EEPROM_SIZE);
    // read ssid from eeprom
    for (int i = 0; i < SSID_SIZE; i++)
    {
    ssid[i] = char(EEPROM.read(SSID_ADDR + i));
    }
    // read passphrase from eeprom
    for (int i = 0; i < PASS_SIZE; i++)
    {
    passphrase[i] = char(EEPROM.read(PASS_ADDR + i));
    }
    // end eeprom access
    EEPROM.end();
}
    
/**
    * write given ssid and passphrase into corresponding eeprom space
    */
void writeEEPROMwifi(char *ssid, char *passphrase)
{
    EEPROM.begin(EEPROM_SIZE);
    // write ssid to eeprom
    for (int i = 0; i < SSID_SIZE; i++)
    {
    EEPROM.write(SSID_ADDR + i, ssid[i]);
    }
    // write passphrase to eeprom
    for (int i = 0; i < PASS_SIZE; i++)
    {
    EEPROM.write(PASS_ADDR + i, passphrase[i]);
    }
    // commit write and end access
    EEPROM.commit();
    EEPROM.end();
}
    
/**
    * handle GET request for root page access
    */
void handleRoot()
{
    server.send(200, "text/html", sRootPage);
}
    
/**
    * handle request for set wifi action
    */
void handleSetWifi()
{
    String ssid_str = server.arg("ssid");
    String passphrase_str = server.arg("passphrase");
    char ssid[SSID_SIZE];
    char passphrase[PASS_SIZE];
    ssid_str.toCharArray(ssid, SSID_SIZE);
    passphrase_str.toCharArray(passphrase, PASS_SIZE);
    writeEEPROMwifi(ssid, passphrase);
    server.send(200, "text/html", sSetWifiHandler);
    readEEPROMwifi(ssid, passphrase);
}
    
/**
    * handle request for reset
    * */
void handleReset()
{
    server.send(200, "text/plain", "rebooting");
    delay(500);
    ESP.restart();
}