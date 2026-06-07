#include "scheduler.h"
#include <assert.h>

uint32_t idle_stack[DEFAULT_STACK_SIZE];
uint32_t taskA_stack[DEFAULT_STACK_SIZE];
uint32_t taskB_stack[DEFAULT_STACK_SIZE];
uint32_t taskC_stack[DEFAULT_STACK_SIZE];

uint32_t taskRenderTicks_stack[DEFAULT_STACK_SIZE];

task_t tasks[] =
{
    {idle_stack, idle,   PRIORITY_IDLE,   0, 0, TASK_READY},
    {taskA_stack, taskA, PRIORITY_NORMAL, 0, 0, TASK_READY},
    {taskB_stack, taskB, PRIORITY_NORMAL, 0, 0, TASK_READY},
    {taskC_stack, taskC, PRIORITY_NORMAL, 0, 0, TASK_READY},

    {taskRenderTicks_stack, renderTicks, PRIORITY_LOW, 0, 0, TASK_READY},
};

const size_t NUM_TASKS = sizeof(tasks) / sizeof(tasks[0]);

task_t* current_task = NULL;
task_t* idle_task = &tasks[0];

void update_sleeping_tasks(void)
{
    for (size_t i = 0; i < NUM_TASKS; i++)
    {
        task_t* t = &tasks[i];

        if (t->state == TASK_SLEEPING &&
            time_now() >= t->wake_time)
        {
            t->state = TASK_READY;
        }
    }
}

void update_current_task_time(void)
{
    if (current_task != NULL && current_task->state == TASK_RUNNING)
    {
        current_task->last_run_time = time_now();
    }
}

void pick_next_task(void)
{
    task_t* best = NULL;

    for (size_t i = 0; i < NUM_TASKS; i++)
    {
        task_t* t = &tasks[i];

        if (t->state != TASK_READY)
            continue;

        if (best == NULL ||
            (t->priority < best->priority) ||
            (t->priority == best->priority && t->last_run_time < best->last_run_time))
        {
            best = t;
        }
    }
    
    if (best == NULL)
        best = idle_task;
    current_task = best;
}
