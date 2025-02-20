#ifndef LED_HPP
#define LED_HPP

#include "ILedHardware.hpp"
#include <memory>

class Led {
public:
    Led(std::unique_ptr<ILedHardware> ledHardware) : ledHardware_(std::move(ledHardware)) {}

    virtual ~Led() = default;

    virtual void turnOn() {
        ledHardware_->setState(true);
        state_ = true;
    }

    virtual void turnOff() {
        ledHardware_->setState(false);
        state_ = false;
    }

    virtual void toggle() {
        ledHardware_->setState(!state_);
        state_ = !state_;
    }

    virtual bool isOn() const { return state_; }

protected:
    std::unique_ptr<ILedHardware> ledHardware_;
    bool state_;
};

#endif // LED_HPP