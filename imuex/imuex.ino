#include<MPU9250.h>
#include<Wire.h>

MPU9250 IMU(Wire, 0x68);

void setup()
{
  Wire.begin();
  Serial.begin(38400);
  IMU.begin();
}

void loop()
{
  IMU.readSensor();
  Serial.print("Accelerometer X axis: ");
  Serial.print(IMU.getAccelX_mss(),3);
  Serial.print("\tAccelerometer Y axis: ");
  Serial.print(IMU.getAccelY_mss(),3);
  Serial.print("\tAccelerometer Z axis: ");
  Serial.println(IMU.getAccelZ_mss(),3);

  Serial.print("Gyroscope X axis: ");
  Serial.print((IMU.getGyroX_rads()*57.295),3);
  Serial.print("\tGyroscope Y axis: ");
  Serial.print((IMU.getGyroY_rads()*57.295),3);
  Serial.print("\tGyroscope Z axis: ");
  Serial.println((IMU.getGyroZ_rads()*57.295),3);

  Serial.println("");
  Serial.println("");

  delay(1000);
}
