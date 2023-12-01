#include "AllHardwareSensors.h"

namespace HardwareSensors {

AllHardwareSensors::AllHardwareSensors(const AbstractSensors::MacroKeyCallbackType &macroKeyChangeHandler)
    : macroKeys(std::make_unique<HardwareMacroKeys>(macroKeyChangeHandler)),
      upperKnobSensor(std::make_unique<HardwareRotaryEncoder>(KNOB_UPPER_PIN_0, KNOB_UPPER_PIN_1, KNOB_UPPER_PIN_INTERRUPT_0,
                                                              KNOB_UPPER_PIN_INTERRUPT_1)),
      lowerKnobSensor(std::make_unique<HardwareRotaryEncoder>(KNOB_LOWER_PIN_0, KNOB_LOWER_PIN_1, KNOB_LOWER_PIN_INTERRUPT_0,
                                                              KNOB_LOWER_PIN_INTERRUPT_1)),
      hapticSensor(std::make_unique<HardwareHaptic>(HAPTIC_PIN)),
      capacitiveSensor(std::make_unique<HardwareCapacitive>(CAP_TOUCH_SENDING_PIN, CAP_TOUCH_RECEIVING_PIN)),
      spaceNavigatorSensors(std::make_unique<HardwareSpaceNavigator>(SPACE_NAVIGATOR_STARTER_PIN, SPACE_NAVIGATOR_INTERRUPT_PIN)) {
}

HardwareLeds &AllHardwareSensors::getLeds() {
  return *leds;
}

HardwareMacroKeys &AllHardwareSensors::getMacroKeys() {
  return *macroKeys;
}

HardwareRotaryEncoder &AllHardwareSensors::getUpperKnob() {
  return *upperKnobSensor;
}

HardwareRotaryEncoder &AllHardwareSensors::getLowerKnob() {
  return *lowerKnobSensor;
}

HardwareHaptic &AllHardwareSensors::getHaptic() {
  return *hapticSensor;
}

HardwareCapacitive &AllHardwareSensors::getCapacitive() {
  return *capacitiveSensor;
}

HardwareSpaceNavigator &AllHardwareSensors::getSpaceNavigator() {
  return *spaceNavigatorSensors;
}

} // namespace HardwareSensors