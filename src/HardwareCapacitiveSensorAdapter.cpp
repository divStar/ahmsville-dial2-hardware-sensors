#include "HardwareCapacitiveSensorAdapter.h"

HardwareSensors::HardwareCapacitiveSensorAdapter::HardwareCapacitiveSensorAdapter(uint8_t sendingPin, uint8_t receivingPin)
    : sensor(CapacitiveSensor(sendingPin, receivingPin)) {}

void HardwareSensors::HardwareCapacitiveSensorAdapter::set_CS_AutocaL_Millis(unsigned long millis) {
  return sensor.set_CS_AutocaL_Millis(millis);
}

long HardwareSensors::HardwareCapacitiveSensorAdapter::capacitiveSensor(uint8_t samples) { return sensor.capacitiveSensor(samples); }
