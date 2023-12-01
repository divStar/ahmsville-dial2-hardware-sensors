#include "HardwareRotaryEncoder.h"

namespace HardwareSensors {

HardwareRotaryEncoder::HardwareRotaryEncoder(int pin0, int pin1, int pinInterrupt0, int pinInterrupt1)
    : pin0(pin0), pin1(pin1), pinInterrupt0(pinInterrupt0), pinInterrupt1(pinInterrupt1),
      filteredSensor1Value(std::make_unique<SimpleKalmanFilter>(DEFAULT_MEASUREMENT_ERROR, DEFAULT_ESTIMATE_ERROR, DEFAULT_PROCESS_NOISE)),
      filteredSensor2Value(std::make_unique<SimpleKalmanFilter>(DEFAULT_MEASUREMENT_ERROR, DEFAULT_ESTIMATE_ERROR, DEFAULT_PROCESS_NOISE)) {
}

void HardwareRotaryEncoder::initialize() {
  pinMode(pin0, INPUT);
  pinMode(pin1, INPUT);
  pinMode(pinInterrupt0, INPUT);
  pinMode(pinInterrupt1, INPUT);
}

void HardwareRotaryEncoder::updateSensorData() {
  // Read new values
  values[0] = static_cast<float>(analogRead(pin0));
  values[1] = static_cast<float>(analogRead(pin1));

  // Smoothen the analog values
  values[0] = filteredSensor1Value->updateEstimate(values[0]);
  values[1] = filteredSensor2Value->updateEstimate(values[1]);

  currentRotationAngleDelta = this->calculateRotationAngleDelta();
}

float HardwareRotaryEncoder::getRotationAngleDelta() const {
  return currentRotationAngleDelta;
}

float HardwareRotaryEncoder::calculateRotationAngleDelta() {
  // Get sensorAdapter values
  auto normalizedSensor1Value = values[0] - SENSOR_MIDPOINT;
  auto normalizedSensor2Value = values[1] - SENSOR_MIDPOINT;

  // Calculate the rotation angle delta
  auto currentRotationAngle = atan2(normalizedSensor1Value, normalizedSensor2Value);
  auto rotationAngleDelta = currentRotationAngle - previousRotationAngle;

  if (rotationAngleDelta > M_PI) {
    rotationAngleDelta -= 2 * M_PI;
  } else if (rotationAngleDelta < -M_PI) {
    rotationAngleDelta += 2 * M_PI;
  }

  // Save the current rotation angle as the previous one for next iteration
  previousRotationAngle = static_cast<float>(currentRotationAngle);

  return static_cast<float>(rotationAngleDelta);
}

} // namespace HardwareSensors
