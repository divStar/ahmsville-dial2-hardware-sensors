#include "HardwareSpaceNavigator.h"

namespace HardwareSensors {

HardwareSpaceNavigator::HardwareSpaceNavigator(byte starterPin, byte interruptPin)
    : starterPin(starterPin), interruptPin(interruptPin), mpu(MPU6050_IMU::MPU6050_ADDRESS_AD0_HIGH) {
}

void HardwareSpaceNavigator::initialize() {
  pinMode(starterPin, OUTPUT);
  digitalWrite(starterPin, LOW);
  delay(250);

  Wire.begin();
  Wire.setClock(400000);
  mpu.initialize();
  dmpInitDone = mpu.dmpInitialize();
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), dmpDataReady, RISING);
}

void HardwareSpaceNavigator::calibrateSensors() {
  // supply your own gyro offsets here, scaled for min sensitivity
  mpu.setXGyroOffset(220);
  mpu.setYGyroOffset(76);
  mpu.setZGyroOffset(-85);
  mpu.setZAccelOffset(1788); // 1688 factory default for my test chip
}

bool HardwareSpaceNavigator::testConnection() {
  return mpu.testConnection();
}

AbstractSensors::MotionData HardwareSpaceNavigator::getMotionData() {
  AbstractSensors::MotionData md{};
  // clang-format off
  mpu.getMotion6(&md(AbstractSensors::MotionDataType::ACCELEROMETER, AbstractSensors::MotionDataSpatialAxis::X),
                 &md(AbstractSensors::MotionDataType::ACCELEROMETER, AbstractSensors::MotionDataSpatialAxis::Y),
                 &md(AbstractSensors::MotionDataType::ACCELEROMETER, AbstractSensors::MotionDataSpatialAxis::Z),
                 &md(AbstractSensors::MotionDataType::GYROSCOPE, AbstractSensors::MotionDataSpatialAxis::X),
                 &md(AbstractSensors::MotionDataType::GYROSCOPE, AbstractSensors::MotionDataSpatialAxis::Y),
                 &md(AbstractSensors::MotionDataType::GYROSCOPE, AbstractSensors::MotionDataSpatialAxis::Z));
  // clang-format on

  return md;
}

bool HardwareSpaceNavigator::isDmpInitDone() {
  return dmpInitDone == 0;
}

void HardwareSpaceNavigator::dmpDataReady() {
}

} // namespace HardwareSensors