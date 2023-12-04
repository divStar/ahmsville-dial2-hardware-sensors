#include "variants/MacroKeysVariantDevice.h"

namespace HardwareSensors {

MacroKeysVariantDevice::MacroKeysVariantDevice(const AbstractSensors::MacroKeyCallbackType &macroKeyChangeHandler)
    : macroKeys(std::make_unique<HardwareMacroKeys>(getLeds(), macroKeyChangeHandler)) {
}

AbstractSensors::DeviceVariants MacroKeysVariantDevice::getVariant() {
  return AbstractSensors::DeviceVariants::MACRO_KEYS_VARIANT;
}

void MacroKeysVariantDevice::initialize() {
  // initialize all sensors
  BaseVariantDevice::initialize();
  macroKeys->initialize();
}

HardwareMacroKeys &MacroKeysVariantDevice::getMacroKeys() {
  return *macroKeys;
}

} // namespace HardwareSensors