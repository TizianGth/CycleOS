#pragma once
#include "time.h"
#include "scheduler.h"
#include "SSD1306.h"

void os_init(I2C_HandleTypeDef* hi2c);
void os_start(void);

uint32_t *stack_init(uint32_t *stack_mem, void (*task)(void));
void task_sleep(uint32_t ms);
