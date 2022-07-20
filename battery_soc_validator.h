#ifndef BATTERY_SOC_VALIDATOR
#define BATTERY_SOC_VALIDATOR

#include "battery_parameter_validator.h"

namespace battery
{

  class battery_soc_validators : public battery_parameter_validators
  {
    float stateOfCharge;

    bool isSocValidated = false;
    const float soc_max = 80;
    const float soc_min = 20;

    const std::vector<float> socBoundaryValues = {soc_max, soc_min};

  public:
    // int soc;
    battery_soc_validators(float soc)
    {
      this->stateOfCharge = soc;
    }
    bool isParameterOkay();
    void allocateSocErrorType();

    void setValue(float value);
    void display();
  };
}

#endif // BATTERY_SOC_VALIDATOR