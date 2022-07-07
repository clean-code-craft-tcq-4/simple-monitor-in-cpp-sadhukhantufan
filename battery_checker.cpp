#include <assert.h>

#include "battery_functional_validation.h"

int main()
{
  battery::BatteryHealth batteryStatus;
  assert(batteryStatus.batteryHealthIsOk(25, 70, 0.7) == true);
  assert(batteryStatus.batteryHealthIsOk(50, 85, 0) == false);
  return 0;
}