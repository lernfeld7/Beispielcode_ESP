#pragma once
    
String sRootPage = "<!DOCTYPE html>\r\n\
<html>\r\n\
<head>\r\n\
<meta charset=utf-8>\r\n\
<meta name=viewport content=width='device-width, initial-scale=1'>\r\n\
<title>Login Form</title>\r\n\
<style>\r\n\
body {\r\n\
font-family: sans-serif;\r\n\
}\r\n\
div.section {\r\n\
margin: 32px 0;\r\n\
}\r\n\
hr {\r\n\
width: 50%;\r\n\
color: #002260;\r\n\
}\r\n\
h1, h2 {\r\n\
color: #002260;\r\n\
}\r\n\
h2 {\r\n\
font-weight: normal;\r\n\
font-size: large;\r\n\
}\r\n\
label, input[type=submit] {\r\n\
display: block;\r\n\
margin: 10px 0;\r\n\
}\r\n\
input[type=text], input[type=password] {\r\n\
width: 100%;\r\n\
padding: 8px 8px;\r\n\
margin: 8px 0;\r\n\
box-sizing: border-box;\r\n\
border: 1px solid #ccc;\r\n\
border-radius: 4px;\r\n\
}\r\n\
input[type=submit] {\r\n\
width: 100%;\r\n\
background-color: #0047ab;\r\n\
color: white;\r\n\
padding: 8px 8px;\r\n\
margin: 4px 0;\r\n\
border: none;\r\n\
border-radius: 4px;\r\n\
cursor: pointer;\r\n\
}\r\n\
form {\r\n\
width: 30%;\r\n\
margin: 0 auto;\r\n\
text-align: left;\r\n\
}\r\n\
</style>\r\n\
</head>\r\n\
<body>\r\n\
<h1>Konfiguration</h1>\r\n\
<div id=wifi class=section>\r\n\
<h2>WiFi-Zugangsdaten festlegen</h2>\r\n\
<p><form method=GET action=setwifi>\r\n\
<label for=ssid>SSID:</label>\r\n\
<input name=ssid id=ssid length=32 type=text /><br />\r\n\
<label for=passphrase>Passphrase:</label>\r\n\
<input name=passphrase id=passphrase length=64 type=password /><br />\r\n\
<input type=submit value=festlegen>\r\n\
</form></p>\r\n\
</div><hr />\r\n\
<div id=reset class=section>\r\n\
<h2>Controller neu starten</h2>\r\n\
<p><form method=GET action=/reset>\r\n\
<input type=submit value=Neustart />\r\n\
</form></p>\r\n\
</div>\r\n\
</body>\r\n\
</html>\r\n";
    
String sSetWifiHandler = "<h1>WiFi-Konfiguration</h1>\r\n\
<p>WiFi-Einstellungen wurden gespeichert. F&uuml;r weitere Einstellungen <a href=\"/\">zur&uuml;ck</a>.<br />\r\n\
Zum Aktivieren der Einstellungen bitte <a href=\"/reset\">neu starten</a> und Access Point deaktivieren.</p>\r\n";