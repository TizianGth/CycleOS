#include "scheduler.h"

volatile uint8_t schedule_flag = 0;

uint32_t taskA_stack[DEFAULT_STACK_SIZE];
uint32_t taskB_stack[DEFAULT_STACK_SIZE];
uint32_t taskC_stack[DEFAULT_STACK_SIZE];

task_t tasks[] =
{
    {taskA, 1, 0, TASK_READY, taskA_stack},
    {taskB, 1, 0, TASK_READY, taskB_stack},
    {taskC, 1, 0, TASK_READY, taskC_stack},
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