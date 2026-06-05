#include "scheduler.h"
#include <assert.h>

#define idle_task (&tasks[0])

volatile uint8_t schedule_flag = 0;

uint32_t idle_stack[DEFAULT_STACK_SIZE];
uint32_t taskA_stack[DEFAULT_STACK_SIZE];
uint32_t taskB_stack[DEFAULT_STACK_SIZE];
uint32_t taskC_stack[DEFAULT_STACK_SIZE];

task_t tasks[] =
{
    {idle_stack, idle,   PRIORITY_IDLE,   0, TASK_READY},
    {taskA_stack, taskA, PRIORITY_NORMAL, 0, TASK_READY},
    {taskB_stack, taskB, PRIORITY_NORMAL, 0, TASK_READY},
    {taskC_stack, taskC, PRIORITY_NORMAL, 0, TASK_READY},
};
const size_t NUM_TASKS = sizeof(tasks) / sizeof(tasks[0]);
task_t* current_task = NULL;

void pick_next_task(void)
{
    task_t* best = NULL;

    for (int i = 0; i < NUM_TASKS; i++)
    {
        task_t* t = &tasks[i];

        if (t->state == TASK_SLEEPING &&
            time_now() >= t->wake_time)
        {
            t->state = TASK_READY;
        }

        if (t->state != TASK_READY)
            continue;

        if (best == NULL || t->priority < best->priority)
        {
            best = t;
        }
    }
    
    if (best == NULL) {
        current_task = idle_task;
    } else {
        current_task = best;
    }
    current_task = current_task;
}
