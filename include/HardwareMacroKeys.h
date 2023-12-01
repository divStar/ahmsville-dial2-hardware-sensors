#ifndef DIALER_HARDWAREMACROKEYS_H
#define DIALER_HARDWAREMACROKEYS_H

#include <IMacroKeys.h>
#include "HardwareMacroKey.h"
#include <memory>

namespace HardwareSensors {

/**
 * @class   HardwareMacroKeys
 * @brief   The actual hardware implementation of the macro key adapter-interfaces adapter used by the application.
 *
 * @author  Igor Voronin
 * @date    06.08.2023
 */
class HardwareMacroKeys : public AbstractSensors::IMacroKeys {
public:
  /**
   * @brief Constructor.
   *
   * @param type    (const char*) name of the task responsible for the macro keys
   */
  explicit HardwareMacroKeys(const AbstractSensors::MacroKeyCallbackType &changeHandler);

  void initialize() override;

private:
  /**
   * @brief Pin of the <strong>first</strong> MacroKey.
   */
  static const int MACRO_KEY_0_PIN = 0;

  /**
   * @brief Pin of the <strong>second</strong> MacroKey.
   */
  static const int MACRO_KEY_1_PIN = 1;

  /**
   * @brief Pin of the <strong>third</strong> MacroKey.
   */
  static const int MACRO_KEY_2_PIN = 5;

  /**
   * @brief Pin of the <strong>fourth</strong> MacroKey.
   */
  static const int MACRO_KEY_3_PIN = 10;

  /**
   * @brief Pin of the <strong>fifth</strong> MacroKey.
   */
  static const int MACRO_KEY_4_PIN = 12;

  /**
   * @brief MacroKey task type.
   */
  constexpr static const auto MACRO_KEY_TYPE = "macrokey";

  /**
   * @brief Array of macro-keys.
   */
  static std::array<std::unique_ptr<HardwareMacroKey>, 5> keys; // NOLINT(bugprone-dynamic-static-initializers)

  /**
   * @brief Change-handler, that is called after a change occurred and was processed.
   */
  const AbstractSensors::MacroKeyCallbackType &changeHandler;
};

} // namespace HardwareSensors

#endif // DIALER_HARDWAREMACROKEYS_H
