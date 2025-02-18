#include "StatusLed.hpp"
#include "mock_HAL_GPIO.hpp"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <memory>

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::StrictMock;

class StatusLedTest : public testing::Test {
protected:
    void SetUp() override {
        // mockGpio  = std::make_unique<StrictMock<mock_HAL_GPIO>>();
        // statusLed = std::make_unique<StatusLed>(std::move(mockGpio));
    }

    void TearDown() override {
        // mockGpio.reset();
    }

    // std::unique_ptr<StrictMock<mock_HAL_GPIO>> mockGpio;
    // std::unique_ptr<StatusLed> statusLed;
};

// Test initialization
TEST_F(StatusLedTest, Init_CallsGpioInitAndMode) {
    // be really careful with move
    // Make sure you set expectations first and then move the mock.
    /**
     *  Test Code Might Be Moving mockGpio Too Early
        You likely have:
        mockGpio  = std::make_unique<StrictMock<mock_HAL_GPIO>>();
        statusLed = std::make_unique<StatusLed>(std::move(mockGpio));  // Moves ownership
        ⚠️ After std::move(mockGpio), mockGpio is null!
        If later you do EXPECT_CALL(*mockGpio, init()), you are dereferencing null, causing segmentation fault.
     * 
     */
    std::unique_ptr<StrictMock<mock_HAL_GPIO>> mockGpio = std::make_unique<StrictMock<mock_HAL_GPIO>>();

    EXPECT_CALL(*mockGpio, init()).Times(1);
    EXPECT_CALL(*mockGpio, mode(HAL_GPIO_MODE::OUTPUT)).Times(1);

    StatusLed statusLed(std::move(mockGpio));
    statusLed.init();
}

// Test setting LED ON
TEST_F(StatusLedTest, SetLed_On_CallsGpioSetTrue) {
    std::unique_ptr<StrictMock<mock_HAL_GPIO>> mockGpio = std::make_unique<StrictMock<mock_HAL_GPIO>>();

    EXPECT_CALL(*mockGpio, set(true)).Times(1);

    StatusLed statusLed(std::move(mockGpio));
    statusLed.set(true);
}

// Test setting LED OFF
TEST_F(StatusLedTest, SetLed_Off_CallsGpioSetTrue) {
    std::unique_ptr<StrictMock<mock_HAL_GPIO>> mockGpio = std::make_unique<StrictMock<mock_HAL_GPIO>>();

    EXPECT_CALL(*mockGpio, set(false)).Times(1);

    StatusLed statusLed(std::move(mockGpio));
    statusLed.set(false);
}