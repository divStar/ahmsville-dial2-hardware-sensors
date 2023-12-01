#ifndef DIAL2HARDWARESENSORS_HARDWARELEDS_H
#define DIAL2HARDWARESENSORS_HARDWARELEDS_H

#include <ILeds.h>
#include "HardwareLed.h"
#include <memory>

namespace HardwareSensors {

class HardwareLeds : public AbstractSensors::ILeds<HardwareLed> {
public:
  ~HardwareLeds() override = default;

  HardwareLed *getLed(uint8_t index) override;
  void addLed(HardwareLed led) override;
  void initialize() override;

private:
  static const int NUM_LEDS = 13;
  std::array<std::unique_ptr<HardwareLed>, NUM_LEDS> leds;
};

} // namespace HardwareSensors

#endif //DIAL2HARDWARESENSORS_HARDWARELEDS_H
