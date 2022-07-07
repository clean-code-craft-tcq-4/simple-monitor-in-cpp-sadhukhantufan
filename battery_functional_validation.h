#include <iostream>

namespace battery
{
  class BatteryHealth
  {
  private:
    bool batteryTemperatureIsOk(float temperature);
    bool batterySocIsOk(float soc);
    bool batteryChargeRateIsOk(float chargeRate);
    bool checkRange(float actualValue, float minValue, float maxValue);

  public:
    bool batteryHealthIsOk(float temperature, float soc, float chargeRate);
  };
}