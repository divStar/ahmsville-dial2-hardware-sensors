#include "HardwareHapticSensorAdapter.h"

HardwareSensors::HardwareHapticSensorAdapter::HardwareHapticSensorAdapter(uint8_t hapticPin) : hapticPin(hapticPin) {}

void HardwareSensors::HardwareHapticSensorAdapter::writeStrength(uint8_t strength) { analogWrite(hapticPin, strength); }
