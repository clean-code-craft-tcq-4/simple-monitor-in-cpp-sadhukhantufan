#include <iostream>
#include "battery_validator.h"

bool battery::isBatteryOkay(battery::battery_functional_validator *validators)
{
  return validators->isParameterOkay();
}

int main()
{
  battery::battery_functional_validator *validators = new battery::battery_functional_validator();

  validators->add(new battery::battery_temperature_validators(25.0f));
  validators->add(new battery::battery_soc_validators(30.0f));
  validators->add(new battery::battery_chargerate_validators(0.5));
  isBatteryOkay(validators);
  validators->display();

  validators->setValue(battery::Parameters::TEMPERTURE, 3);
  validators->setValue(battery::Parameters::CHARGERATE, 0.7f);
  validators->setValue(battery::Parameters::STATEOFCHARGE, 30);
  isBatteryOkay(validators);
  validators->display();

  return 0;
}