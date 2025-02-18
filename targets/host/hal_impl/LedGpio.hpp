#include "HAL_GPIO.hpp"

class LedGpio : public HAL_GPIO
{
public:
    void init() override;
    void set(bool state) override;
    bool read() override;
    void mode(HAL_GPIO_MODE mode) override;
};