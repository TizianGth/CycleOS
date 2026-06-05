#pragma once
#include "time.h"
#include "scheduler.h"

void os_init(void);
void os_start(void);

uint32_t *stack_init(uint32_t *stack_mem, void (*task)(void));
void task_sleep(uint32_t ms);
