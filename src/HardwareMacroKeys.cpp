#include "HardwareMacroKeys.h"

HardwareSensors::HardwareMacroKeys::HardwareMacroKeys(const Callbacks::MacroKeyCallbackType *changeHandler)
    : changeHandler(changeHandler) {}

void HardwareSensors::HardwareMacroKeys::initializeMacroKeys() {
  keys[0] = HardwareSensors::MacroKey(0, 0, MACRO_KEY_TYPE, changeHandler);
  keys[1] = HardwareSensors::MacroKey(1, 1, MACRO_KEY_TYPE, changeHandler);
  keys[2] = HardwareSensors::MacroKey(2, 5, MACRO_KEY_TYPE, changeHandler);
  keys[3] = HardwareSensors::MacroKey(3, 10, MACRO_KEY_TYPE, changeHandler);
  keys[4] = HardwareSensors::MacroKey(4, 12, MACRO_KEY_TYPE, changeHandler);

  attachInterrupt(
      digitalPinToInterrupt(keys[0].getPin()), []() { keys[0].onChange(); }, CHANGE);
  attachInterrupt(
      digitalPinToInterrupt(keys[1].getPin()), []() { keys[1].onChange(); }, CHANGE);
  attachInterrupt(
      digitalPinToInterrupt(keys[2].getPin()), []() { keys[2].onChange(); }, CHANGE);
  attachInterrupt(
      digitalPinToInterrupt(keys[3].getPin()), []() { keys[3].onChange(); }, CHANGE);
  attachInterrupt(
      digitalPinToInterrupt(keys[4].getPin()), []() { keys[4].onChange(); }, CHANGE);
}
