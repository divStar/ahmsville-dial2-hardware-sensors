#ifndef DIALER_ALLREALSENSORS_H
#define DIALER_ALLREALSENSORS_H

#include <IAllSensors.h>
#include "Callbacks.h"
#include "HardwareCapacitive.h"
#include "HardwareHaptic.h"
#include "HardwareLeds.h"
#include "HardwareMacroKeys.h"
#include "HardwareRotaryEncoder.h"
#include "HardwareSpaceNavigator.h"
#include <memory>

namespace HardwareSensors {

class AllHardwareSensors final : public AbstractSensors::IAllSensors<HardwareLed, HardwareLeds, HardwareMacroKeys, HardwareRotaryEncoder,
                                                                     HardwareHaptic, HardwareCapacitive, HardwareSpaceNavigator> {
public:
  /**
   * Constructor. Instantiates all sensor adapters
   * @param macroKeyChangeHandler
   */
  explicit AllHardwareSensors(const AbstractSensors::MacroKeyCallbackType &macroKeyChangeHandler);
  ~AllHardwareSensors() override = default;
  HardwareLeds &getLeds() override;
  HardwareMacroKeys &getMacroKeys() override;
  HardwareRotaryEncoder &getUpperKnob() override;
  HardwareRotaryEncoder &getLowerKnob() override;
  HardwareHaptic &getHaptic() override;
  HardwareCapacitive &getCapacitive() override;
  HardwareSpaceNavigator &getSpaceNavigator() override;

private:
  /**
   * @brief pin 0 of the upper sensorAdapter.
   */
  static const byte KNOB_UPPER_PIN_0 = A1;
  /**
   * @brief pin 1 of the upper sensorAdapter.
   */
  static const byte KNOB_UPPER_PIN_1 = A0;
  /**
   * @brief pin interrupt 0 of the upper sensorAdapter.
   */
  static const byte KNOB_UPPER_PIN_INTERRUPT_0 = 38;
  /**
   * @brief pin interrupt 1 of the upper sensorAdapter.
   */
  static const byte KNOB_UPPER_PIN_INTERRUPT_1 = 27;
  /**
   * @brief pin 0 of the lower sensorAdapter.
   */
  static const byte KNOB_LOWER_PIN_0 = A2;
  /**
   * @brief pin 1 of the lower sensorAdapter.
   */
  static const byte KNOB_LOWER_PIN_1 = A3;
  /**
   * @brief pin interrupt 0 of the lower sensorAdapter.
   */
  static const byte KNOB_LOWER_PIN_INTERRUPT_0 = 42;
  /**
   * @brief pin interrupt 1 of the lower sensorAdapter.
   */
  static const byte KNOB_LOWER_PIN_INTERRUPT_1 = 13;
  /**
   * @brief pin number for the haptic vibration motor.
   */
  static const byte HAPTIC_PIN = 4;
  /**
   * @brief sending pin for the capacitive touch sensor.
   */
  static const uint8_t CAP_TOUCH_SENDING_PIN = 9;
  /**
   * @brief receiving pin for the capacitive touch sensor.
   */
  static const uint8_t CAP_TOUCH_RECEIVING_PIN = 8;
  /**
   * @brief Number of the pin, that is being written to to start the space navigator capabilities.
   */
  static const byte SPACE_NAVIGATOR_STARTER_PIN = 30;
  /**
   * @brief Number of the interrupt pin.
   */
  static const byte SPACE_NAVIGATOR_INTERRUPT_PIN = 2;

  /**
   * @brief Leds.
   */
  std::unique_ptr<HardwareLeds> leds;

  /**
   * @brief Macro keys sensor.
   */
  std::unique_ptr<HardwareMacroKeys> macroKeys;

  /**
   * @brief Upper knob sensor.
   */
  std::unique_ptr<HardwareRotaryEncoder> upperKnobSensor;

  /**
   * @brief Lower knob sensor.
   */
  std::unique_ptr<HardwareRotaryEncoder> lowerKnobSensor;

  /**
   * @brief Haptic motor sensor.
   */
  std::unique_ptr<HardwareHaptic> hapticSensor;

  /**
   * @brief Capacitive sensor.
   */
  std::unique_ptr<HardwareCapacitive> capacitiveSensor;

  /**
   * @brief SpaceNavigator joystick sensor.
   */
  std::unique_ptr<HardwareSpaceNavigator> spaceNavigatorSensors;
};

} // namespace HardwareSensors

#endif // DIALER_ALLREALSENSORS_H
