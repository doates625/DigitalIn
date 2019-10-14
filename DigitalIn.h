/**
 * @file DigitalIn.h
 * @brief Class for Arduino and Mbed digital inputs
 * @author Dan Oates (WPI Class of 2020)
 * 
 * This class implements the Mbed DigitalIn class for Arduino to allow for
 * cross-platform libraries. Additionally, the type PinMode from Mbed is defined
 * in this file. For the Mbed platform, PinMode can be one of (PullUp, PullDown,
 * PullNone, or OpenDrain). For Arduino, only PullUp and PullNone are supported.
 * 
 * Dependencies:
 * - Platform: https://github.com/doates625/Platform.git
 * 
 * References:
 * - Mbed DigitalIn: https://os.mbed.com/docs/mbed-os/v5.14/apis/digitalin.html
 */
#pragma once
#include <Platform.h>

#if defined(PLATFORM_ARDUINO)

/**
 * PinMode Enumeration
 */
typedef enum
{
	PullUp,
	PullNone,
}
PinMode;

/**
 * Class Declaration
 */
class DigitalIn
{
public:
	DigitalIn(Platform::pintype_t pin, PinMode mode = PullNone);
	int read();
	void mode(PinMode mode);
	int is_connected();
	operator int();
protected:
	Platform::pintype_t pin;
};

#endif