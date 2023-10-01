#include "AllRealSensors.h"

HardwareSensors::AllRealSensors::~AllRealSensors() { delete (macroKeys); }

HardwareSensors::AllRealSensors::AllRealSensors(const Callbacks::MacroKeyCallbackType *macroKeyChangeHandler)
    : macroKeys(new HardwareSensors::HardwareMacroKeys(macroKeyChangeHandler)),
      upperKnobSensor(new HardwareSensors::HardwareRotaryEncoderAdapter(KNOB_UPPER_PIN_0, KNOB_UPPER_PIN_1, KNOB_UPPER_PIN_INTERRUPT_0,
                                                                        KNOB_UPPER_PIN_INTERRUPT_1)),
      lowerKnobSensor(new HardwareSensors::HardwareRotaryEncoderAdapter(KNOB_LOWER_PIN_0, KNOB_LOWER_PIN_1, KNOB_LOWER_PIN_INTERRUPT_0,
                                                                        KNOB_LOWER_PIN_INTERRUPT_1)),
      hapticSensor(new HardwareSensors::HardwareHapticSensorAdapter(HAPTIC_PIN)),
      capacitiveSensor(new HardwareSensors::HardwareCapacitiveSensorAdapter(CAP_TOUCH_SENDING_PIN, CAP_TOUCH_RECEIVING_PIN)),
      spaceNavigatorSensors(
          new HardwareSensors::HardwareSpaceNavigatorSensorAdapter(SPACE_NAVIGATOR_STARTER_PIN, SPACE_NAVIGATOR_INTERRUPT_PIN)) {}
HardwareSensors::IMacroKeys &HardwareSensors::AllRealSensors::getMacroKeys() { return *macroKeys; }

HardwareSensors::IRotaryEncoderAdapter &HardwareSensors::AllRealSensors::getUpperKnobSensor() { return *upperKnobSensor; }

HardwareSensors::IRotaryEncoderAdapter &HardwareSensors::AllRealSensors::getLowerKnobSensor() { return *lowerKnobSensor; }

HardwareSensors::IHapticSensorAdapter &HardwareSensors::AllRealSensors::getHapticSensor() { return *hapticSensor; }

HardwareSensors::ICapacitiveSensorAdapter &HardwareSensors::AllRealSensors::getCapacitiveSensor() { return *capacitiveSensor; }
HardwareSensors::ISpaceNavigatorSensorAdapter &HardwareSensors::AllRealSensors::getSpaceNavigatorSensors() {
  return *spaceNavigatorSensors;
}
