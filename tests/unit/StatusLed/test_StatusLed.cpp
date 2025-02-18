#include "StatusLed.hpp"
#include "mock_HAL_GPIO.hpp"
#include "gtest.h"
#include "gmock.h"
#include <memory>

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::StrictMock;

class StatusLedTest : public testing::Test {
protected:
    void SetUp() override {
        mockGpio  = std::make_unique<StrictMock<mock_HAL_GPIO>>();
        statusLed = std::make_unique<StatusLed>(std::move(mockGpio));
    }

    std::unique_ptr<StrictMock<mock_HAL_GPIO>> mockGpio;
    std::unique_ptr<StatusLed> statusLed;
};

// Test initialization
TEST_F(StatusLedTest, Init_CallsGpioInitAndMode) {
    EXPECT_CALL(*mockGpio, init()).Times(1);
    EXPECT_CALL(*mockGpio, mode(HAL_GPIO_MODE::OUTPUT)).Times(1);
    
    statusLed->init();
}

// Test setting LED ON
TEST_F(StatusLedTest, SetLed_On_CallsGpioSetTrue) {
    EXPECT_CALL(*mockGpio, set(true)).Times(1);

    statusLed->set(true);
}

// Test setting LED OFF
TEST_F(StatusLedTest, SetLed_Off_CallsGpioSetTrue) {
    EXPECT_CALL(*mockGpio, set(false)).Times(1);

    statusLed->set(false);
}