#include "battery_functional_validation.h"
#include "battery_standards.h"

namespace battery
{

  bool battery::BatteryHealth::checkRange(float actualValue, float minValue, float maxValue)
  {
    return (actualValue < minValue || actualValue > maxValue);
  }

  bool battery::BatteryHealth::batteryTemperatureIsOk(float temperature)
  {
    bool result = true;
    if (checkRange(temperature, temperature_min, temperature_max))
    {
      std::cout << "Temperature out of range!\n";
      result = false;
    }
    return result;
  }

  bool battery::BatteryHealth::batterySocIsOk(float soc)
  {
    bool result = true;
    if (checkRange(soc, soc_min, soc_max))
    {
      std::cout << "State of Charge out of range!\n";
      result = false;
    }
    return result;
  }

  bool battery::BatteryHealth::batteryChargeRateIsOk(float chargeRate)
  {
    bool result = true;
    if (checkRange(chargeRate, chargeRate_min, chargeRate_max))
    {
      std::cout << "Charge Rate out of range!\n";
      result = false;
    }
    return result;
  }

  bool battery::BatteryHealth::batteryHealthIsOk(float temperature, float soc, float chargeRate)
  {
    return (batteryTemperatureIsOk(temperature) && batterySocIsOk(soc) && batteryChargeRateIsOk(chargeRate));
  }
}