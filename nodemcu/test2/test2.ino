#include<ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("Neel", "123456780");
  while(WiFi.status()!= WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected");
  Serial.println(WiFi.localIP());
  server.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  client= server.available();
  delay(200);
  if(client==1)
  {
    String req= client.readStringUntil('\n');
    Serial.println(req);
    req.trim();
    if(req== "GET /on HTTP/1.1")
    {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    if(req== "GET /off HTTP/1.1")
    {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }

}
