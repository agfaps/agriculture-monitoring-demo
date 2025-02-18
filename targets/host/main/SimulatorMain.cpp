#include <iostream>
#include <memory>

#include "AgricultureMonitoring.hpp"
// #include "hw_module.hpp"
#include "LedGpio.hpp"
#include "StatusLed.hpp"
// #include "display_host.hpp"
// #include "mqtt_host.hpp"
// #include "soil_moisture_host.hpp"
// #include "dht11_host.hpp"

int main(void)
{
    // Create instances of platform-specific implementations
    // auto hwModule     = createHwModule(); // Factory function for HwModule
    auto ledGpio      = std::make_unique<LedGpio>();
    auto statusLed    = std::make_unique<StatusLed>(std::move(ledGpio));
    // auto display      = std::make_unique<Display_Host>();
    // auto mqtt         = std::make_unique<Mqtt_Host>();
    // auto soilMoisture = std::make_unique<SoilMoisture_Host>();
    // auto dht11        = std::make_unique<DHT11_Host>();

    // Create the AgricultureMonitoring application (object)
    AgricultureMonitoring agricultureMonitoring (
        std::move(statusLed)
        // nullptr,
        // nullptr,
        // nullptr,
        // nullptr
    ); // move semantics for hwModule, statusLed, display, mqtt, soilMoisture, dht11);

    // Simulator-specific initialization
    std::cout << "Host Simulator: Starting Agriculture Monitoring System Application..." << std::endl;

    // Call the shared application module
    agricultureMonitoring.run();

    return 0;
}
