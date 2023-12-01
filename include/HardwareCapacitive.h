#ifndef DIALER_HARDWARECAPACITIVESENSORADAPTER_H
#define DIALER_HARDWARECAPACITIVESENSORADAPTER_H

#include <ICapacitive.h>
#include "CapacitiveSensor.h"
#include <memory>

namespace HardwareSensors {

/**
 * @class   HardwareCapacitive
 * @brief   The actual hardware implementation of the capacitive sensor adapter used by the application.
 *
 * @author  Igor Voronin
 * @date    06.08.2023
 */
class HardwareCapacitive : public AbstractSensors::ICapacitive {
public:
  /**
   * @brief Constructor.
   *
   * @param sendingPin    (byte) number of the pin sending information to the sensorAdapter
   * @param receivingPin  (byte) number of the pin receiving information from the sensorAdapter
   */
  explicit HardwareCapacitive(uint8_t sendingPin, uint8_t receivingPin);

  void initialize() override {
    // no initialization required for this sensor
  }

  void set_CS_AutocaL_Millis(unsigned long millis) override;

  long getData(uint8_t samples) override;

private:
  /**
   * @brief Actual hardware capacitive sensor.
   */
  std::unique_ptr<CapacitiveSensor> sensor;
};

} // namespace HardwareSensors

#endif // DIALER_HARDWARECAPACITIVESENSORADAPTER_H
