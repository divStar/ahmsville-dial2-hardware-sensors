#ifndef DIALER_HARDWAREHAPTICSENSORADAPTER_H
#define DIALER_HARDWAREHAPTICSENSORADAPTER_H

#include <IHapticSensorAdapter.h>
#include <api/Common.h>

namespace HardwareSensors {

using AbstractSensors::IHapticSensorAdapter;

/**
 * @class   HardwareHapticSensorAdapter
 * @brief   The actual hardware implementation of the haptic sensor adapter used
 * by the application.
 *
 * @author  Igor Voronin
 * @date    06.08.2023
 */
class HardwareHapticSensorAdapter : public IHapticSensorAdapter {
public:
  /**
   * @brief Constructor.
   *
   * @param hapticPin (byte) pin of the haptic sensor
   */
  explicit HardwareHapticSensorAdapter(uint8_t hapticPin);

  void writeStrength(uint8_t strength) override;

private:
  /**
   * @brief pin of the haptic sensor.
   */
  uint8_t hapticPin;
};

} // namespace HardwareSensors

#endif // DIALER_HARDWAREHAPTICSENSORADAPTER_H
