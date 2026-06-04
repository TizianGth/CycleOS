#include "scheduler.h"


task_t tasks[] =
{
    {taskA, 1, 0, TASK_READY},
    {taskB, 1, 0, TASK_READY},
    {taskC, 1, 0, TASK_READY},
};
const size_t NUM_TASKS = sizeof(tasks) / sizeof(tasks[0]);
task_t* current_task = NULL;

void scheduler_run(void)
{
    for (int i = 0; i < NUM_TASKS; i++)
    {
        task_t* task = &tasks[i];
        if (task->state == TASK_READY)
        {
            current_task = task;
            task->function();
        }

        // Change states
        if (time_now() >= task->wake_time)
        {
            task->state = TASK_READY;
        }
    }
}