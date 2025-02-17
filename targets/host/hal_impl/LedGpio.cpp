#include "HAL_GPIO.hpp"
#include <iostream>

class LedGpio : public HAL_GPIO
{
public:
    void init() override
    {
        std::cout << "LedGpio::init" << std::endl;
    }
    void set(bool state) override
    {

        std::cout << "LedGpio::set: " << (state ? "ON" : "OFF") << std::endl;
    }
    bool read() override
    {
        std::cout << "LedGpio::read" << std::endl;
        return false;
    }
    void mode(HAL_GPIO_MODE mode) override
    {
        std::cout << "LedGpio::mode" << std::endl;
    }
};

// Factory function
HAL_GPIO* createHalGpio() {
    return new LedGpio();
}