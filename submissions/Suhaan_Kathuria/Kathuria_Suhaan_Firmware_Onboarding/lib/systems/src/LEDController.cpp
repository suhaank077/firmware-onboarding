#include "LEDController.h"

unsigned long LEDController::getBlinkInterval(float temperature){
    if (temperature < 20.0f)
    {
        return 1000;
    }
    else if (temperature < 25.0f) {
        return 750;
    }
    else if (temperature < 30.0f) {
        return 500;
    }
    else {
        return 250;
    }
}