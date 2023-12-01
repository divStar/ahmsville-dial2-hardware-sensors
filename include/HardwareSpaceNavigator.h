#ifndef DIALER_HARDWARESPACENAVIGATORSENSORADAPTER_H
#define DIALER_HARDWARESPACENAVIGATORSENSORADAPTER_H

#include <ISpaceNavigator.h>
#include <MPU6050.h>
#include <Wire.h>
#include <helper_3dmath.h>

namespace HardwareSensors {

/**
 * @class   HardwareSpaceNavigator
 * @brief   The actual hardware implementation of the MPU6050 sensor(s) adapter used by the application.
 *
 * @author  Igor Voronin
 * @date    06.08.2023
 */
class HardwareSpaceNavigator : public AbstractSensors::ISpaceNavigator {
public:
  explicit HardwareSpaceNavigator(byte starterPin, byte interruptPin);

  void initialize() override;

  void calibrateSensors() override;

  bool testConnection() override;

  bool isDmpInitDone() override;

  AbstractSensors::MotionData getMotionData() override;

private:
  /**
   * @brief the starter pin (e.g. pin 30 by default).
   */
  byte starterPin;

  /**
   * @brief the interrupt pin (e.g. pin 2 by default).
   */
  byte interruptPin;

  /**
   * @brief MPU6050, that is used to set up and receive the accelerometer as well as the gyroscope.
   */
  MPU6050 mpu;

  /**
   * @brief This variable describes if DMP completed. The dummy value should be overwritten during setup().
   */
  unsigned int dmpInitDone = 100;

  /**
   * @brief This function currently has no use, but is passed to <code>attachInterrupt</code> on set up.
   */
  static void dmpDataReady();
};

} // namespace HardwareSensors

#endif // DIALER_HARDWARESPACENAVIGATORSENSORADAPTER_H
