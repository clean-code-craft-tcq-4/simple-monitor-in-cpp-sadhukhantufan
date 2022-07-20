#include <iostream>
#include <vector>
#include "battery_functional_validator.h"

namespace battery
{
  void battery_functional_validator::add(battery_parameter_validators *childClassObj)
  {
    validators.push_back(childClassObj);
  }
  bool battery_functional_validator::isParameterOkay()
  {
    bool result = true;
    for (auto iter = validators.begin(); iter != validators.end(); iter++)
    {
      result &= (*iter)->isParameterOkay();
    }
    return result; // returns true if all checks passed.
  }
  void battery_functional_validator::setValue(Parameters obj, float value)
  {
    validators.at(static_cast<int>(obj))->setValue(value);
  }
  void battery_functional_validator::display()
  {
    for (uint8_t i = 0; i < validators.size(); i++)
    {
      validators.at(i)->display();
    }
  }
}