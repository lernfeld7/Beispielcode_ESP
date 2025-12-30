# Konfigurations-Webseite für WLAN-Einstellungen im EEPROM-Speicher

Dieses Beispiel zeigt, wie der EEPROM-Speicher dazu verwendet werden kann, Zugangsdaten für die WiFi-Verbindung variabel zu speichern und bei Bedarf zu ändern, ohne dass die Firmware neu geflasht werden muss.
Zu diesem Zweck versucht sich der Microcontroller zu einem fest vorgegebenen Konfigurations-Hotspot zu verbinden. Wenn dieser auffindbar ist, startet er die Konfigurations-Webseite und lässt sich konfigurieren. Wenn die Verbindung fehlschlägt, startet der Microcontroller ganz normal. Die Wartezeit für den Hotspot beträgt bei diesem Beispiel 5 Sekunden (10 * 500ms). 

**Achtung**: Dieses Beispiel besteht aus 2 Dateien, welche beide im Sketch-Ordner liegen müssen.