#ifndef DIALER_SPACENAVVARIANTDEVICE_H
#define DIALER_SPACENAVVARIANTDEVICE_H

#include "sensors/HardwareSpaceNavigator.h"
#include "variants/BaseVariantDevice.h"
#include "variants/ISpaceNavVariant.h"
#include <memory>

namespace HardwareSensors {

class SpaceNavVariantDevice : virtual public BaseVariantDevice,
                              virtual public AbstractSensors::ISpaceNavVariant<HardwareLed, HardwareLeds, HardwareRotaryEncoder,
                                                                               HardwareHaptic, HardwareCapacitive, HardwareSpaceNavigator> {
public:
  /**
   * Constructor.
   */
  explicit SpaceNavVariantDevice();

  AbstractSensors::DeviceVariants getVariant() override;
  void initialize() override;

  HardwareRotaryEncoder &getUpperKnob() override;
  HardwareSpaceNavigator &getSpaceNavigator() override;

  ~SpaceNavVariantDevice() override = default;

private:
  /**
   * @brief pin 0 of the upper sensorAdapter.
   */
  static const uint8_t KNOB_UPPER_PIN_0 = A1;
  /**
   * @brief pin 1 of the upper sensorAdapter.
   */
  static const uint8_t KNOB_UPPER_PIN_1 = A0;
  /**
   * @brief pin interrupt 0 of the upper sensorAdapter.
   */
  static const uint8_t KNOB_UPPER_PIN_INTERRUPT_0 = 38;
  /**
   * @brief pin interrupt 1 of the upper sensorAdapter.
   */
  static const uint8_t KNOB_UPPER_PIN_INTERRUPT_1 = 27;
  /**
   * @brief Number of the pin, that is being written to to start the space navigator capabilities.
   */
  static const uint8_t SPACE_NAVIGATOR_STARTER_PIN = 30;
  /**
   * @brief Number of the interrupt pin.
   */
  static const uint8_t SPACE_NAVIGATOR_INTERRUPT_PIN = 2;

  /**
   * @brief Upper knob sensor.
   */
  std::unique_ptr<HardwareRotaryEncoder> upperKnob;

  /**
   * @brief SpaceNavigator joystick sensor.
   */
  std::unique_ptr<HardwareSpaceNavigator> spaceNavigator;
};

} // namespace HardwareSensors

#endif // DIALER_SPACENAVVARIANTDEVICE_H
