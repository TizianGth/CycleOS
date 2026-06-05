#pragma once
#include "tasks.h"
#include <stdbool.h>

void pick_next_task(void);

extern task_t tasks[];
extern const size_t NUM_TASKS;
extern task_t* current_task;