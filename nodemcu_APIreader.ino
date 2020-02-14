// Reads a json file to switch the LEDs 

// Make sure ArduinoJson library is installed
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "yourwifi";
const char* password = "yourpassword";

const int outputD1 = 5;
const int outputD2 = 4;
const int outputD5 = 14;
const int outputD6 = 12;

void setup()
{
  Serial.begin(57600);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting...");
  }

  pinMode(outputD1, OUTPUT);
  pinMode(outputD2, OUTPUT);
  pinMode(outputD5, OUTPUT);
}

void loop()
{


  
  if(WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http; //Object of class HTTPClient
    http.begin("yourAPIurl");
    int httpCode = http.GET();

    if (httpCode > 0) 
    {
      const size_t bufferSize = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(8) + 370;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());
 
      int id = root["id"]; 
      const int number = root["yourAPIvalue"]; 


      if(number == 0)
      {
        Serial.println(number);
        digitalWrite(outputD1, HIGH);
        digitalWrite(outputD2, LOW);
        digitalWrite(outputD5, LOW);
      }
      else if(number == 1)
      {
        Serial.println(number);
        digitalWrite(outputD1, LOW);
        digitalWrite(outputD2, HIGH);
        digitalWrite(outputD5, LOW);
      }
      else if (number == 2)
      {
        Serial.println(number);
        digitalWrite(outputD1, LOW);
        digitalWrite(outputD2, LOW);
        digitalWrite(outputD5, HIGH);
      }
      

      
    }
    http.end(); //Close connection
  }
  delay(3000);
}
