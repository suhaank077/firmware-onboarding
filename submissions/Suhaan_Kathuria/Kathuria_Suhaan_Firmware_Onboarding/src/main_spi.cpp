#include <Arduino.h>

#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

BMESPIInterface bme;
LEDController ledController;

void setup()
{
    Serial.begin(115200);

    pinMode(BMEConstants::LED_PIN, OUTPUT);

    bool sensorStarted = bme.begin();

    if (!sensorStarted)
    {
        Serial.println("Could not find BME280 over SPI!");

        while (true)
        {
        }
    }

    Serial.println("BME280 connected over SPI!");
}

void loop()
{
    float temperature = bme.readTemperature();

    unsigned long blinkInterval =
        ledController.getBlinkInterval(temperature);

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" C | Blink interval: ");
    Serial.print(blinkInterval);
    Serial.println(" ms");

    digitalWrite(BMEConstants::LED_PIN, HIGH);
    delay(blinkInterval / 2);

    digitalWrite(BMEConstants::LED_PIN, LOW);
    delay(blinkInterval / 2);
}