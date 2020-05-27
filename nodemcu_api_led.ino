#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "ssid"; //network ssid
const char* password = "password";  //ssid password

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
    http.begin("url");  //API url
    int httpCode = http.GET();

    if (httpCode > 0) 
    {
      const size_t capacity = JSON_OBJECT_SIZE(1) + 10;
      DynamicJsonDocument doc(capacity);

      const char* json = "{\"ledstate\":1}"; // this example uses object key ledstate with a value of 1

      deserializeJson(doc, json);

      int ledstate = doc["ledstate"]; // 1



    

      if(ledstate == 0)
      {
        digitalWrite(outputD1, HIGH);
        digitalWrite(outputD2, LOW);
        digitalWrite(outputD5, LOW);
      }
      else if(ledstate == 1)
      {
        digitalWrite(outputD1, LOW);
        digitalWrite(outputD2, HIGH);
        digitalWrite(outputD5, LOW);
      }
      else if (ledstate == 2)
      {
        digitalWrite(outputD1, LOW);
        digitalWrite(outputD2, LOW);
        digitalWrite(outputD5, HIGH);
      }

      
              Serial.println(ledstate);


      
    }
    http.end(); //Close connection
  }
  delay(3000);
}
