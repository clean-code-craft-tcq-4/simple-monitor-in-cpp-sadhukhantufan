#ifndef BATTERY_VALIDATOR
#define BATTERY_VALIDATOR

#include <iostream>
#include "battery_temperature_validator.h"
#include "battery_soc_validator.h"
#include "battery_chargerate_validator.h"
#include "battery_functional_validator.h"

namespace battery
{
  bool isBatteryOkay(battery::battery_functional_validator *validators);
}

#endif // BATTERY_VALIDATOR