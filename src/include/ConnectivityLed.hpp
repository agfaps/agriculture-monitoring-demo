#ifndef CONNECTIVITY_LED_HPP
#define CONNECTIVITY_LED_HPP

#include "Led.hpp"

class ConnectivityLed : public Led {
public:
    explicit ConnectivityLed(std::unique_ptr<ILedHardware> ledHardware);

    void setConnectionStatus(bool connected);
    bool isConnected() const;
private:
    bool connectionActive_;
};

#endif // CONNECTIVITY_LED_HPP