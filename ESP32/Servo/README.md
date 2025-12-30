# Servo

Dieses Beispiel zeigt wie man Servos verwendet. Es wird die Bibliothek ESP32Servo von Kevin Harrington und John Bennett verwendet. Diese kann über die Bibliotheksverwaltung installiert werden. Es werden 2 Servos und 2 Taster zur Bedienung verwendet. Für das Bewegen von Tür und Fenster sind die Funktionen `toggleDoor()` und `toggleWindow()` vorgesehen. 

**Achtung!**
- Das Servo für das Fenster darf nur bis 150 geöffnet werden.
- Grundsätzlich sollen Servos, um Überlastung bei Verklemmen zu vermeiden, nur direkt vor der Bewegung eingeschaltet und danach wieder ausgeschaltet werden. Dies geschieht über `attach()` und `detach()`.