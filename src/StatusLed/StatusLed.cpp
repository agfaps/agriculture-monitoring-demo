#include "StatusLed.hpp"
#include "HAL_GPIO.hpp"
#include <iostream>

void StatusLed::init()
{
    if (gpioLed == nullptr) {
        std::cout << "StatusLed::init(): Failed to init LED driver" << std::endl;
        return;
    }
    gpioLed->init();
    gpioLed->mode(HAL_GPIO_MODE::OUTPUT);
}

void StatusLed::set(bool state)
{
    gpioLed->set(state);
}