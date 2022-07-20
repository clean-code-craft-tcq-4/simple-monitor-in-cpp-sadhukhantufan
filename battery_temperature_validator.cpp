#include "battery_temperature_validator.h"

namespace battery
{
  bool battery_temperature_validators::isParameterOkay()
  {
    allocateTempErrorType();
    isTemperatureValidated = true;
    if (this->temperature > temperature_min && this->temperature < temperature_max)
    {
      isOkay = 1;
      return true;
    }
    else
    {
      isOkay = 0;
      return false;
    }
  }
  void battery_temperature_validators::allocateTempErrorType()
  {
    uint8_t errorIndex = 0;
    parameterStatus = static_cast<TypeofErrors>(temperatureBoundaryValues.size());
    for (errorIndex = 0; errorIndex < temperatureBoundaryValues.size(); errorIndex++)
    {
      if (temperature <= temperatureBoundaryValues.at(errorIndex))
      {
        parameterStatus = static_cast<TypeofErrors>(errorIndex);
        break;
      }
    }
  }

  void battery_temperature_validators::setValue(float value)
  {
    isOkay = 0;
    isTemperatureValidated = false;
    this->temperature = value;
  }
  void battery_temperature_validators::display()
  {
    if (isTemperatureValidated == true)
    {
      std::cout << static_cast<int>(parameterStatus) << std::endl;
    }
  }
}