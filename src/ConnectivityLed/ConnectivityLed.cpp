#include "ConnectivityLed.hpp"

ConnectivityLed::ConnectivityLed(std::unique_ptr<ILedHardware> ledHardware) : Led(std::move(ledHardware)) {}

void ConnectivityLed::setConnectionStatus(bool connected) {
    connectionActive_ = connected;
    if (connected) {
        turnOn();
    } else {
        turnOff();
    }
}

bool ConnectivityLed::isConnected() const {
    return connectionActive_;
}