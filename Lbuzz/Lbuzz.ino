int sensor=A0;  
int Buz= 11;      
                                                               
void setup()                                                          
{
  Serial.begin(9600);    
  pinMode(Buz, OUTPUT);                                             
}

void loop()
{
  int senValue=analogRead(sensor); 
  delay(10);                       
  Serial.println(senValue);
  //(read analog value/max value)*max voltage=sensor value
  //(310/1024)*5=1.51)        
  if(senValue>310)             
    tone(Buz, senValue/4); //(2^10)/4=2^8  10 bit to 8 bit conversion.
}
