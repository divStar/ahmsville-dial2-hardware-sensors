#ifndef DIALER_MACROKEYSVARIANTDEVICE_H
#define DIALER_MACROKEYSVARIANTDEVICE_H

#include "sensors/HardwareMacroKeys.h"
#include "variants/BaseVariantDevice.h"
#include "variants/IMacroKeysVariant.h"
#include <memory>

namespace HardwareSensors {

class MacroKeysVariantDevice : virtual public BaseVariantDevice,
                               virtual public AbstractSensors::IMacroKeysVariant<HardwareLed, HardwareLeds, HardwareRotaryEncoder,
                                                                                 HardwareHaptic, HardwareCapacitive, HardwareMacroKeys> {
public:
  /**
   * Constructor. Instantiates all sensor adapters
   * @param macroKeyChangeHandler
   */
  explicit MacroKeysVariantDevice(const AbstractSensors::MacroKeyCallbackType &macroKeyChangeHandler);

  AbstractSensors::DeviceVariants getVariant() override;
  void initialize() override;

  HardwareMacroKeys &getMacroKeys() override;

  ~MacroKeysVariantDevice() override = default;

private:
  /**
   * @brief Macro keys sensor.
   */
  std::unique_ptr<HardwareMacroKeys> macroKeys;
};

} // namespace HardwareSensors

#endif // DIALER_MACROKEYSVARIANTDEVICE_H
