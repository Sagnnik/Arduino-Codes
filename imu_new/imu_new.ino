#include <MPU9250.h>
#include <math.h>


// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 IMU(Wire,0x68);
int status;

float ax;
float ay;
float az;
float thetaA;
float phiA;

float gx;
float gy;
float gz;
float thetaG=0;
float phiG=0;

float dt;
unsigned long millisOld;


void setup() {
  // serial to display data
  Serial.begin(115200);
  while(!Serial) {}

  // start communication with IMU 
  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }
  millisOld =millis();
}
void loop() {
  // read the sensor
  IMU.readSensor();
  // display the data

  ax =IMU.getAccelX_mss();
  ay =IMU.getAccelY_mss();
  az =-IMU.getAccelZ_mss();
  thetaA =atan2(ax/9.8,az/9.8)/2/3.14159*360;
  phiA =atan2(ay/9.8,az/9.8)/2/3.14159*360;
  
  /*Serial.print(ax,6);
  Serial.print(","); 
  Serial.print(ay,6);
  Serial.print(","); 
  Serial.print(az,6);
  Serial.print(","); */
  Serial.print(thetaA);
  Serial.print(","); 
  Serial.println(phiA);

  gx =IMU.getGyroX_rads();
  gy =IMU.getGyroY_rads();
  gz =IMU.getGyroZ_rads();
  dt= (millis()-millisOld)/1000.0;
  millisOld =millis();
  thetaG =thetaG+gy*dt;
  phiG =phiG+gx*dt;
  
  /*Serial.print("\t");
  Serial.print(gx,6);
  Serial.print(",");  
  Serial.print(gy,6);
  Serial.print(",");  
  Serial.println(gz,6);
  Serial.print(",");*/
  Serial.print(thetaG);
  Serial.print(",");
  Serial.print(phiG);
  Serial.println();
  delay(200);
} 
