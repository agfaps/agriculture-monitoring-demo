#ifndef LED_CONTROLLER_HPP
#define LED_CONTROLLER_HPP

#include <memory>

#include "ActivityLed.hpp"
#include "ConnectivityLed.hpp"

class LedController {
public:
    LedController(
        std::unique_ptr<ActivityLed> activityLed,
        std::unique_ptr<ConnectivityLed> connectivityLed
    );

    void setConnected(bool connected);
    void pulseActivity();
    bool getConnectionStatus() const;

private:
    std::unique_ptr<ActivityLed> activityLed_;
    std::unique_ptr<ConnectivityLed> connectivityLed_;
};

#endif // LED_CONTROLLER_HPP