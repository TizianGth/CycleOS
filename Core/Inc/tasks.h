#pragma once
#include "time.h"

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
} task_t;

void taskA(void);
void taskB(void);
void taskC(void);


