/**
 * @file   main.cpp
 * @brief  This file contains dummy setup() and loop() functions.
 *
 * This file is <strong>never</strong> included when the library is published.
 *
 * @author Igor Voronin
 * @date   12.11.2023
 */

#include <Arduino.h>
#include "variants/AbsoluteVariantDevice.h"
#include "variants/BaseVariantDevice.h"
#include "variants/MacroKeysVariantDevice.h"
#include "variants/SpaceNavVariantDevice.h"
#include <memory>

std::unique_ptr<HardwareSensors::BaseVariantDevice> baseVariantDevice;
std::unique_ptr<HardwareSensors::MacroKeysVariantDevice> macroKeysVariantDevice;
std::unique_ptr<HardwareSensors::SpaceNavVariantDevice> spaceNavVariantDevice;
std::unique_ptr<HardwareSensors::AbsoluteVariantDevice> absoluteVariantDevice;

void setup() {
  baseVariantDevice = std::make_unique<HardwareSensors::BaseVariantDevice>();
  macroKeysVariantDevice = std::make_unique<HardwareSensors::MacroKeysVariantDevice>(nullptr);
  spaceNavVariantDevice = std::make_unique<HardwareSensors::SpaceNavVariantDevice>();
  absoluteVariantDevice = std::make_unique<HardwareSensors::AbsoluteVariantDevice>(nullptr);
}

void loop() {
}