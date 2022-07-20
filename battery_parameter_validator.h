#ifndef BATTERY_PARAMETER_VALIDATOR
#define BATTERY_PARAMETER_VALIDATOR

#include <iostream>
#include <vector>

namespace battery
{
  enum class TypeofErrors
  {
    LowerLimitViolation,
    InRange,
    UpperLimitViolation
  };

  enum class Parameters
  {
    TEMPERTURE,
    STATEOFCHARGE,
    CHARGERATE
  };

  class battery_parameter_validators
  {
  public:
    bool isOkay = 0;
    TypeofErrors parameterStatus = TypeofErrors::InRange;
    virtual bool isParameterOkay() = 0;
    // virtual bool checkForEarlyWarning() = 0;
    virtual void display() = 0;
    virtual void setValue(float) = 0;
  };
}

#endif // BATTERY_PARAMETER_VALIDATOR