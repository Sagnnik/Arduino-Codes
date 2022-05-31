
#include <Wire.h>
#include <MPU6050.h>
#include <KalmanFilter.h>

MPU6050 mpu;

KalmanFilter kalmanX(0.001, 0.003, 0.03);
KalmanFilter kalmanY(0.001, 0.003, 0.03);

float accPitch = 0;
float accRoll = 0;

float kalPitch = 0;
float kalRoll = 0;

void setup() 
{
  Serial.begin(115200);

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    delay(500);
  }
 
  mpu.calibrateGyro();

  Serial.println("accPitch,kalPitch,accRoll,kalRoll");
}

void loop()
{
  Vector acc = mpu.readNormalizeAccel();
  Vector gyr = mpu.readNormalizeGyro();

  accPitch = -(atan2(acc.XAxis, sqrt(acc.YAxis*acc.YAxis + acc.ZAxis*acc.ZAxis))*180.0)/M_PI;
  accRoll  = (atan2(acc.YAxis, acc.ZAxis)*180.0)/M_PI;

  // Kalman filter
  kalPitch = kalmanY.update(accPitch, gyr.YAxis);
  kalRoll = kalmanX.update(accRoll, gyr.XAxis);

  Serial.print(accPitch);
  Serial.print(",");

  // Menampilkan data Pitch setelah di Filter dengan Kalman Filter
  Serial.print(kalPitch);
  Serial.print(",");

  // Menampilkan data Roll sebelum di Filter
  Serial.print(accRoll);
  Serial.print(",");

  // Menampilkan data Roll setelah di Filter dengan Kalman Filter
  Serial.print(kalRoll);
  Serial.println();

}
