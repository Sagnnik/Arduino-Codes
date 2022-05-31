

#include "MPU9250.h"
#include<Wire.h>

MPU9250 IMU(Wire,0x68);
int status;

void setup() {
  
  Serial.begin(115200);
  while(!Serial) {}

  
  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }
}

void loop() {
  
  IMU.readSensor();
  
  Serial.print(IMU.getAccelX_mss(),3);
  Serial.print("\t");
  Serial.print(IMU.getAccelY_mss(),3);
  Serial.print("\t");
  Serial.print(IMU.getAccelZ_mss(),3);
  Serial.print("\t");
  Serial.print(IMU.getGyroX_rads(),3);
  Serial.print("\t");
  Serial.print(IMU.getGyroY_rads(),3);
  Serial.print("\t");
  Serial.print(IMU.getGyroZ_rads(),3);
  Serial.print("\t");
  delay(600);
}
