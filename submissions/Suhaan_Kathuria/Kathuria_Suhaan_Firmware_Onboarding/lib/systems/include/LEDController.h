#pragma once
#include <Arduino.h> 
#include "BMEConstants.h"

class LEDController
{
    public: 
        LEDController() = default;
        unsigned long getBlinkInterval(float temperature);
};