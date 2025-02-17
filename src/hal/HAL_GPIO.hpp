#ifndef HAL_GPIO_HPP
#define HAL_GPIO_HPP

#include <stdint.h>

enum class HAL_GPIO_MODE : uint8_t { INPUT, OUTPUT };

class HAL_GPIO {
public:
    virtual void init() = 0;           // Initialize pin
    virtual void set(bool state) = 0;  // Set pin state (HIGH/LOW)
    virtual bool read() = 0;          // Read pin state
    virtual void mode(HAL_GPIO_MODE mode) = 0; // Set pin mode (INPUT/OUTPUT)
    virtual ~HAL_GPIO() = default;        // Virtual destructor for proper cleanup
};

// Factory function to get platform-specific LED connected to GPIO driver
HAL_GPIO* createHalGpio();

#endif // HAL_GPIO