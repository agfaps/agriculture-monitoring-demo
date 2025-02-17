#ifndef AGRICULTURE_MONITORING_HPP
#define AGRICULTURE_MONITORING_HPP

#include "StatusLed.hpp"
// #include "display.hpp"
// #include "mqtt.hpp"
// #include "soil_moisture.hpp"
// #include "dht11.hpp"
//#include "osal.hpp"
#include <memory>

class AgricultureMonitoring {
public:
    AgricultureMonitoring(
//        std::unique_ptr<OSAL> osal,
        std::unique_ptr<StatusLed> statusLed
        // std::unique_ptr<Display> display
        // std::unique_ptr<Mqtt> mqtt,
        // std::unique_ptr<SoilMoisture> soilMoisture,
        // std::unique_ptr<DHT11> dht11
    );
    void run();

private:
//    std::unique_ptr<OSAL> osal;
    std::unique_ptr<StatusLed> statusLed;
    // std::unique_ptr<Display> display;
    // std::unique_ptr<Mqtt> mqtt;
    // std::unique_ptr<SoilMoisture> soilMoisture;
    // std::unique_ptr<DHT11> dht11;
};

#endif // AGRICULTURE_MONITORING_HPP