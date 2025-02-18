#ifndef STATUS_LED_HPP
#define STATUS_LED_HPP

#include "HAL_GPIO.hpp"
#include <memory>

class StatusLed {
public:
    StatusLed(std::unique_ptr<HAL_GPIO> gpioLed) : gpioLed(std::move(gpioLed)) {};
    void init();
    void set(bool state);
    ~StatusLed() = default;
private:
    std::unique_ptr<HAL_GPIO> gpioLed;
};

#endif // STATUS_LED_HPP