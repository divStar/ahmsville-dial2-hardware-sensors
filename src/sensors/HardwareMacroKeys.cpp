#include "sensors/HardwareMacroKeys.h"

namespace HardwareSensors {

std::array<std::unique_ptr<HardwareMacroKey>, HardwareMacroKeys::COUNT_MACRO_KEYS> HardwareMacroKeys::macroKeys{};

HardwareMacroKeys::HardwareMacroKeys(HardwareSensors::HardwareLeds &leds, const AbstractSensors::MacroKeyCallbackType &changeHandler)
    : leds(leds), changeHandler(changeHandler) {
}

void HardwareMacroKeys::initialize() {
  macroKeys[0] = std::make_unique<HardwareMacroKey>(0, MACRO_KEY_0_PIN, MACRO_KEY_TYPE, changeHandler);
  macroKeys[1] = std::make_unique<HardwareMacroKey>(1, MACRO_KEY_1_PIN, MACRO_KEY_TYPE, changeHandler);
  macroKeys[2] = std::make_unique<HardwareMacroKey>(2, MACRO_KEY_2_PIN, MACRO_KEY_TYPE, changeHandler);
  macroKeys[3] = std::make_unique<HardwareMacroKey>(3, MACRO_KEY_3_PIN, MACRO_KEY_TYPE, changeHandler);
  macroKeys[4] = std::make_unique<HardwareMacroKey>(4, MACRO_KEY_4_PIN, MACRO_KEY_TYPE, changeHandler);

  attachInterrupt(
      digitalPinToInterrupt(macroKeys[0]->getPin()), []() { macroKeys[0]->onChange(); }, CHANGE);
  attachInterrupt(
      digitalPinToInterrupt(macroKeys[1]->getPin()), []() { macroKeys[1]->onChange(); }, CHANGE);
  attachInterrupt(
      digitalPinToInterrupt(macroKeys[2]->getPin()), []() { macroKeys[2]->onChange(); }, CHANGE);
  attachInterrupt(
      digitalPinToInterrupt(macroKeys[3]->getPin()), []() { macroKeys[3]->onChange(); }, CHANGE);
  attachInterrupt(
      digitalPinToInterrupt(macroKeys[4]->getPin()), []() { macroKeys[4]->onChange(); }, CHANGE);

  leds.addLed(HardwareLed(AvailableLeds::MK_LED1));
  leds.addLed(HardwareLed(AvailableLeds::MK_LED2));
  leds.addLed(HardwareLed(AvailableLeds::MK_LED3));
  leds.addLed(HardwareLed(AvailableLeds::MK_LED4));
  leds.addLed(HardwareLed(AvailableLeds::MK_LED5));
}

} // namespace HardwareSensors