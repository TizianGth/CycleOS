#pragma once
#include "time.h"
#include "scheduler.h"

void os_init(void);
void os_start(void);

void task_sleep(uint32_t ms);