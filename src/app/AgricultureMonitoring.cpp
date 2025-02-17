#include "AgricultureMonitoring.hpp"
#include "osal.h"
#include "HAL_GPIO.hpp"

AgricultureMonitoring::AgricultureMonitoring(
//    std::unique_ptr<OSAL> osal,
    std::unique_ptr<StatusLed> statusLed
    // std::unique_ptr<Display> display
    // std::unique_ptr<Mqtt> mqtt,
    // std::unique_ptr<SoilMoisture> soilMoisture,
    // std::unique_ptr<DHT11> dht11
) : 
    // osal(std::move(osal)), 
    statusLed(std::move(statusLed))
    // display(std::move(display))
    // mqtt(std::move(mqtt)), 
    // soilMoisture(std::move(soilMoisture)), 
    // dht11(std::move(dht11))
{}

void AgricultureMonitoring::run() {
    // Initialize modules
    statusLed->init();
    // display->init();
    // mqtt->connect();

    while (true)
    {
        /* code */
        // Toggle the LED, update the LCD, and send MQTT message
        statusLed->set(true);
        // display->print("LED ON");
        // mqtt->publish("status/led", "ON");
        osal_delay_ms(1000);

        statusLed->set(false);
        // display->print("LED OFF");
        // mqtt->publish("status/led", "OFF");
        osal_delay_ms(1000);

        // Read soil moisture and display it on the LCD/send it to MQTT
        // float moisture = soilMoisture->read();
        // char moisture_str[16];
        // snprintf(moisture_str, sizeof(moisture_str), "%.2f", moisture);
        // display->print("Moisture: " + std::string(moisture_str) + "%");
        // mqtt->publish("sensor/soil_ moisture", moisture_str);
        // osal_delay_ms(1000);

        // // Read temperature and humidity and display them on the LCD/send them to MQTT
        // DHT11Data dht11_data = dht11->read();
        // char temp_str[16];
        // char humidity_str[16];
        // snprintf(temp_str, sizeof(temp_str), "%.2f", dht11_data.temperature);
        // snprintf(humidity_str, sizeof(humidity_str), "%.2f", dht11_data.humidity);
        // display->print("Temp: " + std::string(temp_str) + "C");
        // display->print("Humidity: " + std::string(humidity_str) + "%");
        // mqtt->publish("sensor/temperature", temp_str);
        // mqtt->publish("sensor/humidity", humidity_str);
        // osal_delay_ms(1000);
    }
}
