#include "time.h"

typedef void (*task_fn_t)(void);

typedef struct
{
    task_fn_t function;
    uint32_t interval;
    uint32_t last_run;
    uint8_t priority;
} task_t;

extern task_t tasks[];
extern const uint32_t NUM_TASKS;

void taskA(void);
void taskB(void);
void taskC(void);


