#include "StatusLed.hpp"
#include "HAL_GPIO.hpp"
#include <iostream>

StatusLed::StatusLed() {
    gpioLed = createHalGpio();  // Get platform-specific LED driver
    if (gpioLed == nullptr) {
        std::cout << "Failed to create LED driver" << std::endl;
        return;
    }
    else
    {
        std::cout << "StatusLed::StatusLED(): Success create LED driver" << std::endl;
    }
}
void StatusLed::init()
{
    if (gpioLed == nullptr) {
        std::cout << "StatusLed::init(): Failed to create LED driver" << std::endl;
        return;
    }
    gpioLed->init();
    gpioLed->mode(HAL_GPIO_MODE::OUTPUT);
}

void StatusLed::set(bool state)
{
    gpioLed->set(state);
}