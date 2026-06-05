#include "tasks.h"
#include "stm32f1xx_hal.h"
#include "os.h"

// Tasks should NEVER return. 
// TODO: add wraper to ensure never return

void idle() {
    for(;;) {
        //__asm volatile("bkpt #0");
        __WFI();
    }
}

void taskA(void)
{
    for(;;) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4); 
        task_sleep(100);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4); 
        task_sleep(100);
    }
}

void taskB(void)
{
    for(;;) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); 
        task_sleep(100);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); 
        task_sleep(700);
    }
}

void taskC(void)
{
    
    for(;;) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6); 
        task_sleep(100);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6); 
        task_sleep(1500);
    }
}

