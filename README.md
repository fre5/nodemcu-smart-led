# Nodemcu API reader
A microcontroller board that connects to an access point and reads API from the web. I used LED lights as the output, but it can be used with all sorts of things (servo, relay, etc). I'd like to keep it simple and not rely on third party apps, instead I use a browser for an ideal solution.

![](schematics.png)


<h1>How to </h1>
1. Open Arduino IDE. <br>
2. Go to Tools > Manage Libraries, search for esp8266 and install the library.  <br>
3. Under Tools > Board, select your board, in this case it's NodeMCU. Make sure the port is open and connected.  <br>
3. Open nodemcu_smart_led.ino in Arduino IDE. <br>
4. Change your network credentials accordingly.  <br>
5. Insert a json url inside http.begin("yourAPIurl"). <br>



