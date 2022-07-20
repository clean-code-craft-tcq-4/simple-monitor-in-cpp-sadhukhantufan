#ifndef BATTERY_CHARGERATE_VALIDATOR
#define BATTERY_CHARGERATE_VALIDATOR

#include "battery_parameter_validator.h"

namespace battery
{

  class battery_chargerate_validators : public battery_parameter_validators
  {
    float chargeRate;

    bool ischargeRateValidated = false;
    const float chargeRate_max = 0.0f;
    const float chargeRate_min = 0.8f;

    const std::vector<float> chargeRateBoundaryValues = {chargeRate_max, chargeRate_min};

  public:
    // int soc;
    battery_chargerate_validators(float chargeRate)
    {
      this->chargeRate = chargeRate;
    }
    bool isParameterOkay();
    void allocateChargeRateErrorType();

    void setValue(float value);
    void display();
  };
}
#endif // BATTERY_CHARGERATE_VALIDATOR