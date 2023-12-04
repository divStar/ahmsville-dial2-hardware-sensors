#ifndef DIALER_ABSOLUTEVARIANTDEVICE_H
#define DIALER_ABSOLUTEVARIANTDEVICE_H

#include "MacroKeyCallbackType.h"
#include "variants/IAbsoluteVariant.h"
#include "variants/MacroKeysVariantDevice.h"
#include "variants/SpaceNavVariantDevice.h"
#include <memory>

namespace HardwareSensors {

class AbsoluteVariantDevice : public SpaceNavVariantDevice,
                              public MacroKeysVariantDevice,
                              public AbstractSensors::IAbsoluteVariant<HardwareLed, HardwareLeds, HardwareRotaryEncoder, HardwareHaptic,
                                                                       HardwareCapacitive, HardwareMacroKeys, HardwareSpaceNavigator> {
  // Note: inheriting the `IAbsoluteVariant` interface is not currently necessary, because `SpaceNavVariantDevice` and
  // `MacroKeysVariantDevice` provide all the functionality; however: it's still here for the sake of consistency and future extensibility.
public:
  /**
   * Constructor. Instantiates all sensor adapters
   * @param macroKeyChangeHandler
   */
  explicit AbsoluteVariantDevice(const AbstractSensors::MacroKeyCallbackType &macroKeyChangeHandler);

  AbstractSensors::DeviceVariants getVariant() override;
  void initialize() override;

  ~AbsoluteVariantDevice() override = default;
};

} // namespace HardwareSensors

#endif // DIALER_ABSOLUTEVARIANTDEVICE_H
