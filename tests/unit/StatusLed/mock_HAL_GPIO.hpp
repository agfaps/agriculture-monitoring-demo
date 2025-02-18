#ifndef MOCK_HAL_GPIO_HPP
#define MOCK_HAL_GPIO_HPP

#include "HAL_GPIO.hpp"
#include "gmock/gmock.h"

class mock_HAL_GPIO : public HAL_GPIO {
public:
    MOCK_METHOD(void, init, (), (override));
    MOCK_METHOD(void, set, (bool state), (override));
    MOCK_METHOD(bool, read, (), (override));
    MOCK_METHOD(void, mode, (HAL_GPIO_MODE mode), (override));
};

#endif // MOCK_HAL_GPIO_HPP