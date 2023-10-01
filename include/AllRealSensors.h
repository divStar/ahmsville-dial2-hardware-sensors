#ifndef DIALER_ALLREALSENSORS_H
#define DIALER_ALLREALSENSORS_H

#include <Callbacks.h>
#include <IAllSensors.h>
#include "HardwareCapacitiveSensorAdapter.h"
#include "HardwareHapticSensorAdapter.h"
#include "HardwareMacroKeys.h"
#include "HardwareRotaryEncoderAdapter.h"
#include "HardwareSpaceNavigatorSensorAdapter.h"

namespace HardwareSensors {

using AbstractSensors::IAllSensors;
using AbstractSensors::ICapacitiveSensorAdapter;
using AbstractSensors::IHapticSensorAdapter;
using AbstractSensors::IMacroKeys;
using AbstractSensors::IRotaryEncoderAdapter;
using AbstractSensors::ISpaceNavigatorSensorAdapter;

class AllRealSensors : public IAllSensors {
public:
  explicit AllRealSensors(const Callbacks::MacroKeyCallbackType *macroKeyChangeHandler);
  ~AllRealSensors();
  AbstractSensors::IMacroKeys &getMacroKeys() override;
  AbstractSensors::IRotaryEncoderAdapter &getUpperKnobSensor() override;
  AbstractSensors::IRotaryEncoderAdapter &getLowerKnobSensor() override;
  AbstractSensors::IHapticSensorAdapter &getHapticSensor() override;
  AbstractSensors::ICapacitiveSensorAdapter &getCapacitiveSensor() override;
  AbstractSensors::ISpaceNavigatorSensorAdapter &getSpaceNavigatorSensors() override;

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
   * @brief Number of the pin, that is being written to to start the space
   * navigator capabilities.
   */
  static const byte SPACE_NAVIGATOR_STARTER_PIN = 30;
  /**
   * @brief Number of the interrupt pin.
   */
  static const byte SPACE_NAVIGATOR_INTERRUPT_PIN = 2;

  HardwareSensors::HardwareMacroKeys *macroKeys;
  HardwareSensors::HardwareRotaryEncoderAdapter *upperKnobSensor;
  HardwareSensors::HardwareRotaryEncoderAdapter *lowerKnobSensor;
  HardwareSensors::HardwareHapticSensorAdapter *hapticSensor;
  HardwareSensors::HardwareCapacitiveSensorAdapter *capacitiveSensor;
  HardwareSensors::HardwareSpaceNavigatorSensorAdapter *spaceNavigatorSensors;
};

} // namespace HardwareSensors

#endif // DIALER_ALLREALSENSORS_H
