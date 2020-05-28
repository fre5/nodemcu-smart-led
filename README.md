# Nodemcu API reader
NodeMCU 0.9 (ESP-12 Module) and LED lights that can read information from the web 

![](schematics.png)


<h1>How to </h1>
1. Open Arduino IDE. <br>
2. Go to Tools > Manage Libraries, search for esp8266 and install the library.  <br>
3. Under Tools > Board, select your board, in this case it's NodeMCU. Make sure the port is open and connected.  <br>
4. load ArduinoJson library in Arduino IDE, get it [https://github.com/bblanchon/ArduinoJson]
5. Open nodemcu_smart_led.ino in Arduino IDE. <br>
6. Change your network credentials accordingly.  <br>
7. Insert a json url inside http.begin("yourAPIurl"). <br>



