#ifndef MOCK_HAL_GPIO_HPP
#define MOCK_HAL_GPIO_HPP

#include "ILedHardware.hpp"
#include "gmock/gmock.h"

class mock_ILedHardware : public ILedHardware {
public:
    MOCK_METHOD(void, setState, (bool state), (override));
    MOCK_METHOD(bool, getState, (), (const, override));
};

#endif // MOCK_HAL_GPIO_HPP