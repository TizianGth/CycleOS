#pragma once
#include "time.h"

#define DEFAULT_STACK_SIZE 64

typedef void (*task_fn_t)(void);

typedef enum {
    TASK_READY,
    TASK_RUNNING,
    TASK_SLEEPING
} task_state_t;

typedef struct
{
    task_fn_t function;
    uint8_t priority;

    uint32_t wake_time;
    task_state_t state;
    uint32_t *stack_ptr;
} task_t;

void taskA(void);
void taskB(void);
void taskC(void);


