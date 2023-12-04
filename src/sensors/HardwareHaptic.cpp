#include "sensors/HardwareHaptic.h"

namespace HardwareSensors {

HardwareHaptic::HardwareHaptic(uint8_t hapticPin) : hapticPin(hapticPin) {
}

void HardwareHaptic::setStrength(uint8_t strength) {
  analogWrite(hapticPin, strength);
}

void HardwareHaptic::resetStrength() {
  analogWrite(hapticPin, ZERO_STRENGTH);
}

} // namespace HardwareSensors