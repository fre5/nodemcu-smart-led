# Nodemcu API reader
NodeMCU 0.9 (ESP-12 Module) and LED lights that can read information from Open Weather API

![](schematics.png)


<h1>How to </h1>
1. Open Arduino IDE. <br>
2. Go to Tools > Manage Libraries , search for esp8266 and install the library.  <br>
3. Under Tools > Board, select the board. Make sure the port is open and connected.  <br>
4. Load ArduinoJson library in Arduino IDE. Download : https://github.com/bblanchon/ArduinoJson <br>
5. Load nodemcu_apiled.ino in Arduino IDE. <br>
6. Change your network credentials accordingly.  <br>
7. Insert a json url inside http.begin("yourAPIurl"). <br>
8. You can now use your API to light up the LED lights. <br>




