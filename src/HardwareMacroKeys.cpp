#include "HardwareMacroKeys.h"

namespace HardwareSensors {

std::array<std::unique_ptr<HardwareMacroKey>, 5> HardwareMacroKeys::keys{};

HardwareMacroKeys::HardwareMacroKeys(const AbstractSensors::MacroKeyCallbackType &changeHandler) : changeHandler(changeHandler) {
}

void HardwareMacroKeys::initialize() {
  keys[0] = std::make_unique<HardwareMacroKey>(0, MACRO_KEY_0_PIN, MACRO_KEY_TYPE, changeHandler);
  keys[1] = std::make_unique<HardwareMacroKey>(1, MACRO_KEY_1_PIN, MACRO_KEY_TYPE, changeHandler);
  keys[2] = std::make_unique<HardwareMacroKey>(2, MACRO_KEY_2_PIN, MACRO_KEY_TYPE, changeHandler);
  keys[3] = std::make_unique<HardwareMacroKey>(3, MACRO_KEY_3_PIN, MACRO_KEY_TYPE, changeHandler);
  keys[4] = std::make_unique<HardwareMacroKey>(4, MACRO_KEY_4_PIN, MACRO_KEY_TYPE, changeHandler);

  attachInterrupt(
      digitalPinToInterrupt(keys[0]->getPin()), []() { keys[0]->onChange(); }, CHANGE);
  attachInterrupt(
      digitalPinToInterrupt(keys[1]->getPin()), []() { keys[1]->onChange(); }, CHANGE);
  attachInterrupt(
      digitalPinToInterrupt(keys[2]->getPin()), []() { keys[2]->onChange(); }, CHANGE);
  attachInterrupt(
      digitalPinToInterrupt(keys[3]->getPin()), []() { keys[3]->onChange(); }, CHANGE);
  attachInterrupt(
      digitalPinToInterrupt(keys[4]->getPin()), []() { keys[4]->onChange(); }, CHANGE);
}

} // namespace HardwareSensors