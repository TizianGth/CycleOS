#include "time.h"
#include "scheduler.h"

volatile uint32_t os_ticks = 0;

void HAL_SYSTICK_Callback(void)
{
    os_ticks++;
}

uint32_t time_now(void)
{
    return os_ticks;
}