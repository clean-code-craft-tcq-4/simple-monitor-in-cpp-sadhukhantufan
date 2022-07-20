#ifndef BATTERY_FUNCTIONAL_VALIDATOR
#define BATTERY_FUNCTIONAL_VALIDATOR

#include "battery_parameter_validator.h"

namespace battery
{
  class battery_functional_validator
  {
    std::vector<battery::battery_parameter_validators *> validators;

  public:
    void add(battery_parameter_validators *childClassObj);
    bool isParameterOkay();
    void setValue(Parameters obj, float value);
    void display();
  };
}

#endif // BATTERY_FUNCTIONAL_VALIDATOR