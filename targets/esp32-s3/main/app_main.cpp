#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

extern "C" void app_main(void) {
    // Your application code goes here
    while(true)
    {
        printf("Hello, World!\n");          // Print "Hello, World!"
        vTaskDelay(pdMS_TO_TICKS(1000));    // Delay for 1 second
    }
}