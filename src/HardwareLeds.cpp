#include "HardwareLeds.h"

namespace HardwareSensors {

HardwareLed *HardwareLeds::getLed(uint8_t index) {
  if (index < leds.size() && leds[index]) {
    return leds[index].get();
  }
  return nullptr; // Index out of range or LED not set
}

void HardwareLeds::addLed(HardwareLed led) {
  leds[led.getIndex()] = std::unique_ptr<HardwareLed>(&led);
}

void HardwareLeds::initialize() {
  addLed(HardwareLed(AvailableLeds::TOP_LED));
  addLed(HardwareLed(AvailableLeds::BASE_LED1));
  addLed(HardwareLed(AvailableLeds::BASE_LED2));
  addLed(HardwareLed(AvailableLeds::BASE_LED3));
  addLed(HardwareLed(AvailableLeds::BASE_LED4));
  addLed(HardwareLed(AvailableLeds::BASE_LED5));
  addLed(HardwareLed(AvailableLeds::BASE_LED6));
  addLed(HardwareLed(AvailableLeds::BASE_LED7));
}

} // namespace HardwareSensors