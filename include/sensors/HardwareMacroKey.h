#ifndef MACROKEY_H
#define MACROKEY_H

#include <USB/USBAPI.h>
#include "MacroKeyCallbackType.h"
#include "sensors/IMacroKey.h"

namespace HardwareSensors {

/**
 * @class   MacroKey
 * @brief   Class to handle a single macro-key.
 *
 * This class handles a single macro-key and sends the state upon interrupt.
 *
 * @author  Igor Voronin
 * @date    16.07.2023
 */
class HardwareMacroKey : public AbstractSensors::IMacroKey {
public:
  /**
   * @brief Constructor.
   *
   * @param keyId           (int) the ID of the key
   * @param pin             (int) number of the pin of this macro-key
   * @param type            (char*) name of the task responsible for the macro keys
   * @param changeHandler   (MacroKeyCallbackType) Change-handler, that is called after a change occurred and was processed
   */
  explicit HardwareMacroKey(int keyId, int pin, const char *type, const AbstractSensors::MacroKeyCallbackType &changeHandler);

  void initialize() override {
    // no initialization required for this sensor
  }

  /**
   * @brief Returns the set pin.
   *
   * @return (int) number of the pin
   */
  [[nodiscard]] int getPin() const override;

  /**
   * @brief Function, which is called upon state change via interrupt.
   */
  void onChange() override;

private:
  /**
   * @brief Default debounce delay for the macro-key.
   */
  static const unsigned long DEBOUNCE_DELAY = 100;

  /**
   * @brief ID of the macro-key.
   */
  int keyId;

  /**
   * @brief Number of the pin of the macro-key.
   */
  int pin;

  /**
   * @brief Rise time (when the very first press has been registered).
   */
  volatile unsigned long riseTime;

  /**
   * @brief Fall time (when the very last press has been registered).
   */
  volatile unsigned long fallTime;

  /**
   * @brief Last time an interrupt occured.
   */
  volatile unsigned long lastInterrupttime;

  /**
   * @brief Name of the task responsible for the macro keys.
   */
  const char *type;

  /**
   * @brief Change-handler, that is called after a change occurred and was processed.
   *
   * @details This function is called with all the parameters described in
   * Callbacks::MacroKeyCallbackType and is usually used for logging purposes.
   */
  const AbstractSensors::MacroKeyCallbackType &changeHandler;
};

} // namespace HardwareSensors

#endif
