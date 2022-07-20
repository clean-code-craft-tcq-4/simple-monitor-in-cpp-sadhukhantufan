#ifndef BATTERY_TEMPERATURE_VALIDATOR
#define BATTERY_TEMPERATURE_VALIDATOR

#include "battery_parameter_validator.h"

namespace battery
{

  class battery_temperature_validators : public battery_parameter_validators
  {
    float temperature;

    bool isTemperatureValidated = false;
    const float temperature_max = 45.0f;
    const float temperature_min = 0.0f;

    const std::vector<float> temperatureBoundaryValues = {temperature_min, temperature_max};

  public:
    // int temp;
    battery_temperature_validators(float temp)
    {
      this->temperature = temp;
    }
    bool isParameterOkay();
    void allocateTempErrorType();

    void setValue(float value);
    void display();
  };
}

#endif // BATTERY_TEMPERATURE_VALIDATOR