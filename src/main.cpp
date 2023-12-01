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
#include <IAllSensors.h>
#include "AllHardwareSensors.h"
#include "DeviceVersion.h"
#include <memory>

HardwareSensors::DeviceVersion deviceVersion;
std::unique_ptr<HardwareSensors::AllHardwareSensors> allSensors;

void setup() {
  deviceVersion = HardwareSensors::DeviceVersion::ABSOLUTE_VARIANT;
  allSensors = std::make_unique<HardwareSensors::AllHardwareSensors>(nullptr);
}

void loop() {
}