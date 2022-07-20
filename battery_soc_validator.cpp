#include "battery_soc_validator.h"

namespace battery
{
  bool battery_soc_validators::isParameterOkay()
  {
    allocateSocErrorType();
    isSocValidated = true;
    if (this->stateOfCharge > soc_min && this->stateOfCharge < soc_max)
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
  void battery_soc_validators::allocateSocErrorType()
  {
    uint8_t errorIndex = 0;
    parameterStatus = static_cast<TypeofErrors>(socBoundaryValues.size());
    for (errorIndex = 0; errorIndex < socBoundaryValues.size(); errorIndex++)
    {
      if (stateOfCharge <= socBoundaryValues.at(errorIndex))
      {
        parameterStatus = static_cast<TypeofErrors>(errorIndex);
        break;
      }
    }
  }

  void battery_soc_validators::setValue(float value)
  {
    isOkay = 0;
    isSocValidated = false;
    this->stateOfCharge = value;
  }
  void battery_soc_validators::display()
  {
    if (isSocValidated == true)
    {
      std::cout << static_cast<int>(parameterStatus) << std::endl;
    }
  }
}