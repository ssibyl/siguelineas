#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

constexpr gpio_num_t PULSADOR = GPIO_NUM_4;
constexpr gpio_num_t LED_PIN = GPIO_NUM_15;

extern "C" void app_main();

void app_main() {

    // setup
    gpio_config_t config = {};

    config.pin_bit_mask = (1<<LED_PIN);
    config.mode = GPIO_MODE_OUTPUT;
    config.pull_up_en = GPIO_PULLUP_DISABLE;
    config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    config.intr_type = GPIO_INTR_DISABLE;

    gpio_config(&config);

    config.pin_bit_mask = (1<<PULSADOR);
    config.mode = GPIO_MODE_INPUT;
    config.pull_up_en = GPIO_PULLUP_ENABLE;
    config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    config.intr_type = GPIO_INTR_DISABLE;

    gpio_config(&config);

    // loop
    while(1) {
        if (gpio_get_level(PULSADOR)) 
            gpio_set_level(LED_PIN, 0);
        else
            gpio_set_level(LED_PIN, 1);
    }
}