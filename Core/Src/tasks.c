#include "tasks.h"
#include "stm32f1xx_hal.h"
#include "os.h"

void taskA(void)
{
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4); 
    task_sleep(100);
}

void taskB(void)
{
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); 
    task_sleep(1000);
}

void taskC(void)
{
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6); 
    task_sleep(10000);
}

