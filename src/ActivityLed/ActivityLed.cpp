#include "ActivityLed.hpp"

ActivityLed::ActivityLed(std::unique_ptr<ILedHardware> ledHardware) : Led(std::move(ledHardware)) {}

void ActivityLed::pulseActivity() {
    turnOn();

    // in real implementation, make this pulsing with default pattern
    // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // turnOff();
}

void ActivityLed::update() {
    // in real implementation, this update can change the pulse pattern or another thing
    turnOff();
}