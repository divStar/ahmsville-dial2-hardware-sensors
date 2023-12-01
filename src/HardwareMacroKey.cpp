#include "HardwareMacroKey.h"

HardwareSensors::HardwareMacroKey::HardwareMacroKey(int keyId, int pin, const char *type,
                                                    const AbstractSensors::MacroKeyCallbackType &changeHandler)
    : keyId(keyId), pin(pin), riseTime(0), fallTime(0), lastInterrupttime(0), type(type), changeHandler(changeHandler) {
}

int HardwareSensors::HardwareMacroKey::getPin() const {
  return pin;
}

void HardwareSensors::HardwareMacroKey::onChange() {
  unsigned long interruptTime = millis();
  if (interruptTime - lastInterrupttime > DEBOUNCE_DELAY) {
    bool isPressed = false;

    if (riseTime <= fallTime) {
      riseTime = millis();
      isPressed = true;
    } else if (riseTime > fallTime) {
      fallTime = millis();
      isPressed = false;
    }

    if (changeHandler) {
      (changeHandler)(type, keyId, pin, riseTime, fallTime, isPressed);
    }
  }
}
