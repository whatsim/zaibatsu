/*
  Shared.cpp
*/

#include <Arduboy2.h>
#include "Shared.h"

Shared::Shared()
{
  
}

float Shared::lerp(float a, float b, float f)
{
    return a + f * (b - a);
}
