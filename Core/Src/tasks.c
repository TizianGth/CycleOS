#include "tasks.h"
#include "stm32f1xx_hal.h"

task_t tasks[] =
{
    {taskA, 100, 0, 1},
    {taskB, 500, 0, 1},
    {taskC, 1000, 0, 1},
};
const uint32_t NUM_TASKS =
    sizeof(tasks) / sizeof(tasks[0]);

void taskA(void)
{
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4); 
}

void taskB(void)
{
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); 
}

void taskC(void)
{
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6); 
}

