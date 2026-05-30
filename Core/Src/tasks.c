#include "tasks.h"
#include "stm32f1xx_hal.h"

void taskA(void)
{
    static uint32_t last = 0;

    if (time_now() - last >= 500)
    {
        last = time_now();
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    }
}