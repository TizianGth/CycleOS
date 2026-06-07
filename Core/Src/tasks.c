#include "tasks.h"
#include "stm32f1xx_hal.h"
#include "os.h"
#include <stdio.h>

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
        task_sleep((100*8)-100);
    }
}

void taskC(void)
{
    
    for(;;) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6); 
        task_sleep(100);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6); 
        task_sleep((100*8*2)-100);
    }
}

void renderTicks(void) {
    for(;;) {
        char buf[16];
        snprintf(buf, sizeof(buf), "%lu", time_now());
        SSD1306_ClearArea(0, 33, SSD1306_WIDTH, SSD1306_HEIGHT);
        SSD1306_Draw_String(0, 33, buf);
        SSD1306_Try_Update();
    }
}

