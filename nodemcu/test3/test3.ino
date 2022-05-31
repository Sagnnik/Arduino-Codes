#include<ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.softAP("NodeMCU", "12345678");
  Serial.println();
  Serial.println("NodeMCU started");
  Serial.println(WiFi.softAPIP());
  server.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  client= server.available();
  if (client==1)
  {
    String req= client.readStringUntil('\n');
    Serial.println(req);
    req.trim();
    if(req== "GET /off HTTP/1.1")
    {
      digitalWrite(LED_BUILTIN,HIGH);
    }
    if(req== "GET /on HTTP/1.1")
    {
      digitalWrite(LED_BUILTIN, LOW);
    }

 
  }

}
