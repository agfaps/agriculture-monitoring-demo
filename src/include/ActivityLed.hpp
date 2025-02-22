#ifndef ACTIVITY_LED_HPP
#define ACTIVITY_LED_HPP

#include "Led.hpp"

class ActivityLed : public Led {
public:
    explicit ActivityLed(std::unique_ptr<ILedHardware> ledHardware);

    void pulseActivity();   // we can implement enum ActivityState::Enabled, ActivityState::Disabled for more expressive API
    void update();
};

#endif // ACTIVITY_LED_HPP