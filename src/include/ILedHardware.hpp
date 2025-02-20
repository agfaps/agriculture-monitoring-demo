#ifndef I_LED_HARDWARE_HPP
#define I_LED_HARDWARE_HPP

class ILedHardware {
public:
    virtual void setState(bool state) = 0;
    virtual bool getState() const = 0;
    virtual ~ILedHardware() = default;
};

#endif // I_LED_HARDWARE_HPP