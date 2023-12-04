#ifndef DIAL2HARDWARESENSORS_HARDWARELED_H
#define DIAL2HARDWARESENSORS_HARDWARELED_H

#include "AvailableLeds.h"
#include "sensors/ILed.h"

namespace HardwareSensors {

class HardwareLed : public AbstractSensors::ILed {
public:
  explicit HardwareLed(AvailableLeds index);
  void initialize() override {
    // no initialization required for this sensor
  }

  [[nodiscard]] uint8_t getIndex() const override;

  // gcc bug: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=84581;
  // syntax highlighting is done by CLang, which expects proper `override` placement -> error is shown
  [[nodiscard]] const uint8_t (&getColor() const override)[4];

  void setColor(std::initializer_list<uint8_t> values) override;

private:
  AvailableLeds index;

  AbstractSensors::ColorData colorData;
};

} // namespace HardwareSensors

#endif //DIAL2HARDWARESENSORS_HARDWARELED_H
