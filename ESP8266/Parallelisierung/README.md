# Quasi-Parallelisierung von Aufgaben

Zeitintervalle im Programmablauf mit `delay(t)` abzubilden führt dazu, dass während der Wartezeit keine anderen Aufgaben erledigt werden können. Das bedeutet z. B., dass du während des Wartens auf einen delay-Befehl keine eingehenden MQTT-Nachrichten verarbeiten und nicht einmal einfache Tastendrücke verarbeiten kannst. Bei allen Programmen, die über einen einfachen Test hinausgehen, solltest du deshalb stets auf die hier gezeigte Technik zurückgreifen.

Das nachfolgende Beispiel lässt 2 LEDs in zwei unabhängigen Zeitintervallen blinken. Während die Wartezeit für das länger dauernde Intervall läuft, blinkt die LED mit dem kürzeren Intervall mehrmals ohne dass die Code-Ausführung durch die längere Wartezeit blockiert würde. 