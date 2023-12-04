#include "variants/AbsoluteVariantDevice.h"

namespace HardwareSensors {

AbsoluteVariantDevice::AbsoluteVariantDevice(const AbstractSensors::MacroKeyCallbackType &macroKeyChangeHandler)
    : SpaceNavVariantDevice(), MacroKeysVariantDevice(macroKeyChangeHandler) {
}

AbstractSensors::DeviceVariants AbsoluteVariantDevice::getVariant() {
  return AbstractSensors::DeviceVariants::ABSOLUTE_VARIANT;
}

void AbsoluteVariantDevice::initialize() {
  // initialize all sensors
  SpaceNavVariantDevice::initialize();
  MacroKeysVariantDevice::initialize();
}

} // namespace HardwareSensors