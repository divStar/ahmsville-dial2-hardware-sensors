#include "variants/SpaceNavVariantDevice.h"

namespace HardwareSensors {

SpaceNavVariantDevice::SpaceNavVariantDevice()
    : upperKnob(std::make_unique<HardwareRotaryEncoder>(KNOB_UPPER_PIN_0, KNOB_UPPER_PIN_1, KNOB_UPPER_PIN_INTERRUPT_0,
                                                        KNOB_UPPER_PIN_INTERRUPT_1)),
      spaceNavigator(std::make_unique<HardwareSpaceNavigator>(SPACE_NAVIGATOR_STARTER_PIN, SPACE_NAVIGATOR_INTERRUPT_PIN)) {
}

AbstractSensors::DeviceVariants SpaceNavVariantDevice::getVariant() {
  return AbstractSensors::DeviceVariants::SPACE_NAV_VARIANT;
}

void SpaceNavVariantDevice::initialize() {
  // initialize all sensors
  BaseVariantDevice::initialize();
  upperKnob->initialize();
  spaceNavigator->initialize();
}

HardwareRotaryEncoder &SpaceNavVariantDevice::getUpperKnob() {
  return *upperKnob;
}

HardwareSpaceNavigator &SpaceNavVariantDevice::getSpaceNavigator() {
  return *spaceNavigator;
}

} // namespace HardwareSensors