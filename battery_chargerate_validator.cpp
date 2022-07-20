#include "battery_chargerate_validator.h"

namespace battery
{
  bool battery_chargerate_validators::isParameterOkay()
  {
    allocateChargeRateErrorType();
    ischargeRateValidated = true;
    if (this->chargeRate > chargeRate_min && this->chargeRate < chargeRate_max)
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
  void battery_chargerate_validators::allocateChargeRateErrorType()
  {
    uint8_t errorIndex = 0;
    parameterStatus = static_cast<TypeofErrors>(chargeRateBoundaryValues.size());
    for (errorIndex = 0; errorIndex < chargeRateBoundaryValues.size(); errorIndex++)
    {
      if (chargeRate <= chargeRateBoundaryValues.at(errorIndex))
      {
        parameterStatus = static_cast<TypeofErrors>(errorIndex);
        break;
      }
    }
  }

  void battery_chargerate_validators::setValue(float value)
  {
    isOkay = 0;
    ischargeRateValidated = false;
    this->chargeRate = value;
  }
  void battery_chargerate_validators::display()
  {
    if (ischargeRateValidated == true)
    {
      std::cout << static_cast<int>(parameterStatus) << std::endl;
    }
  }
}