#include "sensors/HardwareLed.h"

namespace HardwareSensors {

uint8_t HardwareLed::getIndex() const {
  return static_cast<uint8_t>(index);
}

const uint8_t (&HardwareLed::getColor() const)[4] {
  return this->colorData.getColor();
}

void HardwareLed::setColor(std::initializer_list<uint8_t> values) {
  this->colorData.setColor(values);
}

HardwareLed::HardwareLed(AvailableLeds index) {
  this->index = index;
}

} // namespace HardwareSensors
