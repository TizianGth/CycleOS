#pragma once
#include "time.h"

#define DEFAULT_STACK_SIZE 64

#define PRIORITY_HIGHEST 0
#define PRIORITY_NORMAL  5
#define PRIORITY_LOW     10
#define PRIORITY_IDLE    255

typedef void (*task_fn_t)(void);

typedef enum {
    TASK_READY,
    TASK_RUNNING,
    TASK_SLEEPING
} task_state_t;

typedef struct
{
    uint32_t *sp;
    task_fn_t function;
    uint8_t priority;

    uint32_t wake_time;
    uint32_t last_run_time;
    task_state_t state;
} task_t;

void idle(void);
void taskA(void);
void taskB(void);
void taskC(void);


