# Stepper-Motor ansteuern

Bei einem Stepper-Motor können verschiedene Wicklungen im Motor einzeln angesteuert werden. Dadurch kann der Motor in Bruchteilen einzelner Umdrehungen bewegt werden. In Verbindung mit einem Getriebe entsteht dadurch die Möglichkeit, sehr feine Bewegungen vorzunehmen.
Der Stepper-Motor aus dem Beispiel verfügt über 4 getrennt voneinander ansteuerbare Wicklungen, weswegen auch das Board mit dem Steuerungsmodul für den Motor über 4 Anschlüsse verfügt.

Der hier dargestellte Quellcode kommt ohne die Verwendung einer Bibliothek aus.

**Wichtig**: Am Ende einer Drehbewegung müssen alle Motorspulen stromlos geschaltet werden, damit der Motor im Stillstand nicht von Strom durchflossen wird und Schaden nimmt. 