#ifndef STATUS_LED_HPP
#define STATUS_LED_HPP

#include "HAL_GPIO.hpp"

class StatusLed {
public:
    StatusLed();
    void init();
    void set(bool state);
    ~StatusLed() = default;
private:
    HAL_GPIO* gpioLed;
};

#endif // STATUS_LED_HPP