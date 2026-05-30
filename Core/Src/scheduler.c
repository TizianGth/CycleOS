#include "scheduler.h"

void scheduler_run(void)
{
    for (int i = 0; i < NUM_TASKS; i++)
    {
        task_t* task = &tasks[i];
        if (time_now() - task->last_run >= task->interval)
        {
            task->last_run = time_now();
            task->function();
        }
    }
}