#include <Arduino.h>

#include <LM75A.h>

// Create I2C LM75A instance
LM75A lm75a_sensor;
// Equivalent to "LM75A lm75a_sensor;"

void setup(void)
{
  Serial.begin(115200);
  Serial.println("Temperatures will be displayed every second:");
}

void loop()
{
  float temperature_in_degrees = lm75a_sensor.getTemperatureInDegrees();

  if (temperature_in_degrees == INVALID_LM75A_TEMPERATURE) {
    Serial.println("Error while getting temperature");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature_in_degrees);
    Serial.print(" degrees (");
    Serial.print(lm75a_sensor.degreesToFahrenheit(temperature_in_degrees));
    Serial.println(" fahrenheit)");
  }

  delay(1000);
}
