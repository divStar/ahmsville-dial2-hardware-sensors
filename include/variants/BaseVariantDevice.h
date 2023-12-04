#ifndef DIALER_BASEVARIANTDEVICE_H
#define DIALER_BASEVARIANTDEVICE_H

#include "sensors/HardwareCapacitive.h"
#include "sensors/HardwareHaptic.h"
#include "sensors/HardwareLeds.h"
#include "sensors/HardwareRotaryEncoder.h"
#include "variants/IBaseVariant.h"
#include <memory>

namespace HardwareSensors {

class BaseVariantDevice
    : virtual public AbstractSensors::IBaseVariant<HardwareLed, HardwareLeds, HardwareRotaryEncoder, HardwareHaptic, HardwareCapacitive> {
public:
  explicit BaseVariantDevice();

  AbstractSensors::DeviceVariants getVariant() override;
  void initialize() override;

  HardwareLeds &getLeds() override;
  HardwareRotaryEncoder &getLowerKnob() override;
  HardwareHaptic &getHaptic() override;
  HardwareCapacitive &getCapacitive() override;

  ~BaseVariantDevice() override = default;

private:
  /**
   * @brief pin 0 of the lower sensorAdapter.
   */
  static const uint8_t KNOB_LOWER_PIN_0 = A2;
  /**
   * @brief pin 1 of the lower sensorAdapter.
   */
  static const uint8_t KNOB_LOWER_PIN_1 = A3;
  /**
   * @brief pin interrupt 0 of the lower sensorAdapter.
   */
  static const uint8_t KNOB_LOWER_PIN_INTERRUPT_0 = 42;
  /**
   * @brief pin interrupt 1 of the lower sensorAdapter.
   */
  static const uint8_t KNOB_LOWER_PIN_INTERRUPT_1 = 13;
  /**
   * @brief pin number for the haptic vibration motor.
   */
  static const uint8_t HAPTIC_PIN = 4;
  /**
   * @brief sending pin for the capacitive touch sensor.
   */
  static const uint8_t CAP_TOUCH_SENDING_PIN = 9;
  /**
   * @brief receiving pin for the capacitive touch sensor.
   */
  static const uint8_t CAP_TOUCH_RECEIVING_PIN = 8;

  /**
   * @brief Leds.
   */
  std::unique_ptr<HardwareLeds> leds;

  /**
   * @brief Lower knob sensor.
   */
  std::unique_ptr<HardwareRotaryEncoder> lowerKnob;

  /**
   * @brief Haptic motor sensor.
   */
  std::unique_ptr<HardwareHaptic> haptic;

  /**
   * @brief Capacitive sensor.
   */
  std::unique_ptr<HardwareCapacitive> capacitive;
};

} // namespace HardwareSensors

#endif // DIALER_BASEVARIANTDEVICE_H
