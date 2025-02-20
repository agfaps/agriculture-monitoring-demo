#ifndef BASE_LED_HPP
#define BASE_LED_HPP

#include "HAL_GPIO.hpp"
#include <memory>
#include <string>

class BaseLed {
public:
    BaseLed(std::unique_ptr<HAL_GPIO> gpioLed, const std::string& name) : 
        gpioLed_(std::move(gpioLed)), 
        name_(name) {}
    
    virtual ~BaseLed() = default;

    virtual void turnOn() {
        gpioLed_->set(true);
        state_ = true;
    }

    virtual void turnOff() {
        gpioLed_->set(false);
        state_ = false;
    }

    virtual void toggle() {
        gpioLed_->set(!state_);
        state_ = !state_;
    }

    // derived class has option to implement gpioLed_->read() and have real state from GPIO.
    virtual bool getState() const { return state_; }

    std::string getName() const { return name_; }

protected:
    std::unique_ptr<HAL_GPIO> gpioLed_;
    std::string name_;
    bool state_;
};

#endif // BASE_LED_HPP