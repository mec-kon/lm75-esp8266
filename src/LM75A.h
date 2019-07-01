/*
 * \brief I2C LM75A temperature sensor library
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 8 July 2016 & 14 January 2018
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.1
 */

#ifndef LM75A_h
#define LM75A_h

#include "Arduino.h"

static const uint8_t I2C_SDA = D1;
static const uint8_t I2C_SCL = D2;

#define INVALID_LM75A_TEMPERATURE 1000

namespace LM75AConstValues
{

/*
 * Accordingto I2C bus specifications,the LM75Ahas a 7-bitslaveaddress.
 * The four mostsignificantbits of the slaveaddressare hardwiredinsidethe LM75Aand are“1001”.
 * The threeleastsignificantbits of the addressare assigned to pins A2–A0,
 * and are set by connectingthesepins to groundfor a low, (0); or to +VS for a high.
 *
 * 0x48 = 1001000 (A2=0, A1=0, A0=0)
*/
const int LM75A_BASE_ADDRESS = 0x48;

/*
 * The temperature register always stores an 11-bit 2's complement data giving atemperature resolution of 0.125°C.
*/
const float LM75A_DEGREES_RESOLUTION = 0.125;

const int LM75A_REG_ADDR_TEMP = 0;
}

class LM75A
{
  public:
    /*!
     * @brief LM75A Initialize I2C LM75A Temperature sensor instance
     */
    LM75A();

    /*!
     * @brief getTemperatureInDegrees Get temperature from LM75A sensor in degrees
     * @return (float) Sensor temperature in degrees (return INVALID_LM75A_TEMPERATURE if error happened)
     */
    float getTemperatureInDegrees() const;

    /*!
     * @brief getTemperatureInFahrenheit Get temperature from LM75A sensor in fahrenheit
     * @return (float) Sensor temperature in fahrenheit (return INVALID_LM75A_TEMPERATURE if error happened)
     */
    float getTemperatureInFahrenheit() const;

    /*!
     * @brief fahrenheitToDegrees Convert temperature from fahrenheit to degrees
     */
    static float fahrenheitToDegrees(float temperature_in_fahrenheit);

    /*!
     * @brief degreesToFahrenheit Convert temperature from degrees to fahrenheit
     */
    static float degreesToFahrenheit(float temperature_in_degrees);

  private:
    int i2c_device_address;
};

#endif //LM75A_h

