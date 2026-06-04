#include "os.h"
#include "stm32f1xx_hal.h"

void os_init(void)
{
    //scheduler_init();
    //time_init();
}

void os_start(void)
{
    while(1) {
        __WFI();
    }
}

void task_sleep(uint32_t ms)
{
    current_task->wake_time = time_now() + ms;
    current_task->state = TASK_SLEEPING;
}