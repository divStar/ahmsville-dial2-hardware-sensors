#include "variants/BaseVariantDevice.h"

namespace HardwareSensors {

BaseVariantDevice::BaseVariantDevice()
    : leds(std::make_unique<HardwareLeds>()),
      lowerKnob(std::make_unique<HardwareRotaryEncoder>(KNOB_LOWER_PIN_0, KNOB_LOWER_PIN_1, KNOB_LOWER_PIN_INTERRUPT_0,
                                                        KNOB_LOWER_PIN_INTERRUPT_1)),
      haptic(std::make_unique<HardwareHaptic>(HAPTIC_PIN)),
      capacitive(std::make_unique<HardwareCapacitive>(CAP_TOUCH_SENDING_PIN, CAP_TOUCH_RECEIVING_PIN)) {
}

AbstractSensors::DeviceVariants BaseVariantDevice::getVariant() {
  return AbstractSensors::DeviceVariants::BASE_VARIANT;
}

void BaseVariantDevice::initialize() {
  // initialize all sensors
  leds->initialize();
  lowerKnob->initialize();
  haptic->initialize();
  capacitive->initialize();
}

HardwareLeds &BaseVariantDevice::getLeds() {
  return *leds;
}

HardwareRotaryEncoder &BaseVariantDevice::getLowerKnob() {
  return *lowerKnob;
}

HardwareHaptic &BaseVariantDevice::getHaptic() {
  return *haptic;
}

HardwareCapacitive &BaseVariantDevice::getCapacitive() {
  return *capacitive;
}

} // namespace HardwareSensors