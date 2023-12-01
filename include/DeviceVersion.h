#ifndef DIAL2HARDWARESENSORS_DEVICEVERSION_H
#define DIAL2HARDWARESENSORS_DEVICEVERSION_H

namespace HardwareSensors {

/**
 * @enum    DeviceVersion
 * @brief   This enumeration describes all the possible device versions.
 *
 * Device versions primarly describe the sensors used in said device version and prevent unused sensors from being initialized.
 *
 * @author  Igor Voronin
 * @date    18.11.2023
 */
enum class DeviceVersion {
  /**
   * @brief Base variant.
   *
   * <p><em>Included sensors:</em><ul>
   * <li>one knob</li>
   * <li>capacitive sensor</li>
   * <li>haptic motor</li>
   * </p>
   */
  BASE_VARIANT,
  /**
   * @brief MacroKeys variant.
   *
   * <p><em>Included sensors:</em><ul>
   * <li>one knob</li>
   * <li>capacitive sensor</li>
   * <li>haptic motor</li>
   * <li>macro keys</li>
   * </p>
   */
  MACRO_KEYS_VARIANT,
  /**
   * @brief SpaceNavigator variant.
   *
   * <p><em>Included sensors:</em><ul>
   * <li>two knobs</li>
   * <li>capacitive sensor</li>
   * <li>haptic motor</li>
   * <li>5-axis space navigator joystick</li>
   * </p>
   */
  SPACE_NAV_VARIANT,
  /**
   * @brief Absolute variant.
   *
   * <p><em>Included sensors:</em><ul>
   * <li>two knobs</li>
   * <li>capacitive sensor</li>
   * <li>haptic motor</li>
   * <li>macro keys</li>
   * <li>5-axis space navigator joystick</li>
   * </p>
   */
  ABSOLUTE_VARIANT
};

} // namespace HardwareSensors
#endif // DIAL2HARDWARESENSORS_DEVICEVERSION_H
