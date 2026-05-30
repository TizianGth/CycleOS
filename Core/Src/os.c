#include "os.h"

void os_init(void)
{
    //scheduler_init();
    //time_init();
}

void os_start(void)
{
    while (1)
    {
        scheduler_run();
    }
}