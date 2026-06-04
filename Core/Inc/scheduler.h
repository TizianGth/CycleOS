#pragma once
#include "tasks.h"
void scheduler_run(void);

extern task_t tasks[];
extern const size_t NUM_TASKS;
extern task_t* current_task;