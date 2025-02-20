#include "LedController.hpp"

LedController::LedController(
    std::unique_ptr<ActivityLed> activityLed, 
    std::unique_ptr<ConnectivityLed> connectivityLed) {
        activityLed_ = std::move(activityLed);
        connectivityLed_ = std::move(connectivityLed);
}

void LedController::setConnected(bool connected) {
    connectivityLed_->setConnectionStatus(connected);
}

void LedController::pulseActivity() {
    activityLed_->pulseActivity();
}

bool LedController::getConnectionStatus() const {
    return connectivityLed_->isConnected();
}