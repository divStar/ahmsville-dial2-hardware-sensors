#include "HardwareCapacitive.h"

namespace HardwareSensors {

HardwareCapacitive::HardwareCapacitive(uint8_t sendingPin, uint8_t receivingPin)
    : sensor(std::make_unique<CapacitiveSensor>(sendingPin, receivingPin)) {
}

void HardwareCapacitive::set_CS_AutocaL_Millis(unsigned long millis) {
  return sensor->set_CS_AutocaL_Millis(millis);
}

long HardwareCapacitive::getData(uint8_t samples) {
  return sensor->capacitiveSensor(samples);
}

} // namespace HardwareSensors
