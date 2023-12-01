#ifndef DIALER_HARDWAREHAPTICSENSORADAPTER_H
#define DIALER_HARDWAREHAPTICSENSORADAPTER_H

#include <IHaptic.h>
#include <api/Common.h>

namespace HardwareSensors {

/**
 * @class   HardwareHaptic
 * @brief   The actual hardware implementation of the haptic sensor adapter used
 * by the application.
 *
 * @author  Igor Voronin
 * @date    06.08.2023
 */
class HardwareHaptic : public AbstractSensors::IHaptic {
public:
  /**
   * @brief Constructor.
   *
   * @param hapticPin (byte) pin of the haptic sensor
   */
  explicit HardwareHaptic(uint8_t hapticPin);

  void initialize() override {
    // no initialization required for this sensor
  }

  void setStrength(uint8_t strength) override;

  void resetStrength() override;

private:
  /**
   * @brief Constant describing the zero-strength value, which is when the sensor is considered to be "off".
   */
  const static uint8_t ZERO_STRENGTH = 0;

  /**
   * @brief pin of the haptic sensor.
   */
  uint8_t hapticPin;
};

} // namespace HardwareSensors

#endif // DIALER_HARDWAREHAPTICSENSORADAPTER_H
