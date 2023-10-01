#ifndef DIALER_HARDWAREMACROKEYS_H
#define DIALER_HARDWAREMACROKEYS_H

#include <Callbacks.h>
#include <IMacroKeys.h>
#include "MacroKey.h"

namespace HardwareSensors {

using AbstractSensors::IMacroKeys;

/**
 * @class   HardwareMacroKeys
 * @brief   The actual hardware implementation of the macro key adapter-interfaces adapter
 * used by the application.
 *
 * @author  Igor Voronin
 * @date    06.08.2023
 */
class HardwareMacroKeys : public IMacroKeys {
public:
  /**
   * @brief Constructor.
   *
   * @param type    (const char*) name of the task responsible for the macro keys
   */
  explicit HardwareMacroKeys(const Callbacks::MacroKeyCallbackType *changeHandler);

  void initializeMacroKeys() override;

private:
  /**
   * @brief MacroKey task type.
   */
  constexpr static const auto MACRO_KEY_TYPE = "macrokey";

  /**
   * @brief Array of macro-keys.
   */
  static HardwareSensors::MacroKey keys[5];

  /**
   * @brief Change-handler, that is called after a change occurred and was processed.
   */
  const Callbacks::MacroKeyCallbackType *changeHandler;
};

} // namespace HardwareSensors

#endif // DIALER_HARDWAREMACROKEYS_H
