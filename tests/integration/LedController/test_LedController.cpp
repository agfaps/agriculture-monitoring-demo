#include "ActivityLed.hpp"
#include "ConnectivityLed.hpp"
#include "LedController.hpp"
#include "mock_ILedHardware.hpp"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <memory>

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::StrictMock;

class LedControllerTest : public testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

// Test set connected true
TEST_F(LedControllerTest, SetConnectedTrue_CallsLedHardwareSetState) {
    std::unique_ptr<StrictMock<mock_ILedHardware>> mockConnectivityLedHw = std::make_unique<StrictMock<mock_ILedHardware>>();
    std::unique_ptr<StrictMock<mock_ILedHardware>> mockActivityLedHw     = std::make_unique<StrictMock<mock_ILedHardware>>();

    EXPECT_CALL(*mockConnectivityLedHw, setState(true)).Times(1);

    // example:
    // auto ledGpio      = std::make_unique<LedGpio>();
    // auto statusLed    = std::make_unique<StatusLed>(std::move(ledGpio));

    std::unique_ptr<ConnectivityLed> connLed = std::make_unique<ConnectivityLed>(std::move(mockConnectivityLedHw));
    std::unique_ptr<ActivityLed>     actLed = std::make_unique<ActivityLed>(std::move(mockActivityLedHw));
    LedController ledController(std::move(actLed), std::move(connLed));

    ledController.setConnected(true);
}

// Test set connected false
TEST_F(LedControllerTest, SetConnectedFalse_CallsLedHardwareSetState) {
    std::unique_ptr<StrictMock<mock_ILedHardware>> mockConnectivityLedHw = std::make_unique<StrictMock<mock_ILedHardware>>();
    std::unique_ptr<StrictMock<mock_ILedHardware>> mockActivityLedHw     = std::make_unique<StrictMock<mock_ILedHardware>>();

    EXPECT_CALL(*mockConnectivityLedHw, setState(false)).Times(1);

    std::unique_ptr<ConnectivityLed> connLed = std::make_unique<ConnectivityLed>(std::move(mockConnectivityLedHw));
    std::unique_ptr<ActivityLed>     actLed = std::make_unique<ActivityLed>(std::move(mockActivityLedHw));
    LedController ledController(std::move(actLed), std::move(connLed));

    ledController.setConnected(false);
}

// Test pulse activity
TEST_F(LedControllerTest, PulseActivity_CallsLedHardwareSetState) {
    std::unique_ptr<StrictMock<mock_ILedHardware>> mockConnectivityLedHw = std::make_unique<StrictMock<mock_ILedHardware>>();
    std::unique_ptr<StrictMock<mock_ILedHardware>> mockActivityLedHw     = std::make_unique<StrictMock<mock_ILedHardware>>();

    EXPECT_CALL(*mockActivityLedHw, setState(true)).Times(1);

    std::unique_ptr<ConnectivityLed> connLed = std::make_unique<ConnectivityLed>(std::move(mockConnectivityLedHw));
    std::unique_ptr<ActivityLed>     actLed = std::make_unique<ActivityLed>(std::move(mockActivityLedHw));
    LedController ledController(std::move(actLed), std::move(connLed));

    ledController.pulseActivity();
}

// Test get connection status true
TEST_F(LedControllerTest, GetConnectionStatusTrue) {
    // Option 2: Use NiceMock (better approach if you only care about functionality)
    // ex: std::unique_ptr<NiceMock<mock_ILedHardware>> mockConnectivityLedHw = std::make_unique<NiceMock<mock_ILedHardware>>();
    std::unique_ptr<StrictMock<mock_ILedHardware>> mockConnectivityLedHw = std::make_unique<StrictMock<mock_ILedHardware>>();
    std::unique_ptr<StrictMock<mock_ILedHardware>> mockActivityLedHw     = std::make_unique<StrictMock<mock_ILedHardware>>();

    // OPtion 1: Use EXPECT_CALL
    // due to gmock strict nature, we need to set expectation on mocked method so it wont fail
    // even when we only test another non mocked method return value.
    // This is just because we need to setup and the setup call mocked method.
    EXPECT_CALL(*mockConnectivityLedHw, setState(true)).Times(1);

    std::unique_ptr<ConnectivityLed> connLed = std::make_unique<ConnectivityLed>(std::move(mockConnectivityLedHw));
    std::unique_ptr<ActivityLed>     actLed = std::make_unique<ActivityLed>(std::move(mockActivityLedHw));
    LedController ledController(std::move(actLed), std::move(connLed));

    ledController.setConnected(true);

    // actual test and expectation
    EXPECT_EQ(ledController.getConnectionStatus(), true);
}

// Test get connection status false
TEST_F(LedControllerTest, GetConnectionStatusFalse) {
    // Option 2: Use NiceMock (better approach if you only care about functionality)
    // ex: std::unique_ptr<NiceMock<mock_ILedHardware>> mockConnectivityLedHw = std::make_unique<NiceMock<mock_ILedHardware>>();
    std::unique_ptr<StrictMock<mock_ILedHardware>> mockConnectivityLedHw = std::make_unique<StrictMock<mock_ILedHardware>>();
    std::unique_ptr<StrictMock<mock_ILedHardware>> mockActivityLedHw     = std::make_unique<StrictMock<mock_ILedHardware>>();

    // OPtion 1: Use EXPECT_CALL
    // due to gmock strict nature, we need to set expectation on mocked method so it wont fail
    // even when we only test another non mocked method return value.
    // This is just because we need to setup and the setup call mocked method.
    EXPECT_CALL(*mockConnectivityLedHw, setState(false)).Times(1);

    std::unique_ptr<ConnectivityLed> connLed = std::make_unique<ConnectivityLed>(std::move(mockConnectivityLedHw));
    std::unique_ptr<ActivityLed>     actLed = std::make_unique<ActivityLed>(std::move(mockActivityLedHw));
    LedController ledController(std::move(actLed), std::move(connLed));

    ledController.setConnected(false);

    // actual test and expectation
    EXPECT_EQ(ledController.getConnectionStatus(), false);
}