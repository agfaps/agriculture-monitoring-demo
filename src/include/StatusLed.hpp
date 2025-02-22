#ifndef STATUS_LED_HPP
#define STATUS_LED_HPP

#include "HAL_GPIO.hpp"
#include <memory>
#include <iostream>

class StatusLed {
public:
   explicit StatusLed(std::unique_ptr<HAL_GPIO> gpioLed) : gpioLed_(std::move(gpioLed)) {};
    void init();
    void set(bool state);
    ~StatusLed() = default;
private:
    std::unique_ptr<HAL_GPIO> gpioLed_;
};

#endif // STATUS_LED_HPP