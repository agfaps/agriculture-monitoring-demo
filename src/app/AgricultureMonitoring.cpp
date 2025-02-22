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
    // osal_(std::move(osal)), 
    statusLed_(std::move(statusLed))
    // display_(std::move(display))
    // mqtt_(std::move(mqtt)), 
    // soilMoisture_(std::move(soilMoisture)), 
    // dht11_(std::move(dht11))
{}

void AgricultureMonitoring::run() {
    // Initialize modules
    statusLed_->init();
    // display_->init();
    // mqtt_->connect();

    while (true)
    {
        /* code */
        // Toggle the LED, update the LCD, and send MQTT message
        statusLed_->set(true);
        // display_->print("LED ON");
        // mqtt_->publish("status/led", "ON");
        osal_delay_ms(1000);

        statusLed_->set(false);
        // display_->print("LED OFF");
        // mqtt_->publish("status/led", "OFF");
        osal_delay_ms(1000);

        // Read soil moisture and display it on the LCD/send it to MQTT
        // float moisture = soilMoisture_->read();
        // char moisture_str[16];
        // snprintf(moisture_str, sizeof(moisture_str), "%.2f", moisture);
        // display_->print("Moisture: " + std::string(moisture_str) + "%");
        // mqtt_->publish("sensor/soil_ moisture", moisture_str);
        // osal_delay_ms(1000);

        // // Read temperature and humidity and display them on the LCD/send them to MQTT
        // DHT11Data dht11_data = dht11_->read();
        // char temp_str[16];
        // char humidity_str[16];
        // snprintf(temp_str, sizeof(temp_str), "%.2f", dht11_data.temperature);
        // snprintf(humidity_str, sizeof(humidity_str), "%.2f", dht11_data.humidity);
        // display_->print("Temp: " + std::string(temp_str) + "C");
        // display_->print("Humidity: " + std::string(humidity_str) + "%");
        // mqtt_->publish("sensor/temperature", temp_str);
        // mqtt_->publish("sensor/humidity", humidity_str);
        // osal_delay_ms(1000);
    }
}
