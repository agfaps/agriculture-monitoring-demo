#include "osal.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void osal_delay_ms(uint32_t ms) {
    vTaskDelay(pdMS_TO_TICKS(ms));
}