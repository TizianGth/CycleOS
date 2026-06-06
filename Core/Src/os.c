#include "os.h"
#include "stm32f1xx_hal.h"

void os_init(void)
{   
    for(size_t i = 0; i < NUM_TASKS; i++) 
        tasks[i].sp = stack_init(tasks[i].sp, tasks[i].function);
    current_task = idle_task;
}

void os_start(void)
{
    __set_PSP((uint32_t)current_task->sp);
    __set_CONTROL(0x02); // PSP
    __ISB();

    SCB->ICSR = SCB_ICSR_PENDSVSET_Msk;

    __enable_irq();

    while (1)
    {
        __WFI();
    }
}

uint32_t *stack_init(uint32_t *stack_mem, void (*task)(void))
{
    uint32_t *sp = stack_mem + DEFAULT_STACK_SIZE;
    sp = (uint32_t *)((uint32_t)sp & ~((uint32_t)0x7));

    // Hardware-stacked frame for exception return
    *(--sp) = 0x01000000;           // xPSR
    *(--sp) = ((uint32_t)task) | 1U; // PC
    *(--sp) = 0xFFFFFFFD;           // LR (task LR, not exception return)
    *(--sp) = 0;                    // R12
    *(--sp) = 0;                    // R3
    *(--sp) = 0;                    // R2
    *(--sp) = 0;                    // R1
    *(--sp) = 0;                    // R0

    for (int i = 4; i <= 11; i++) {
        *(--sp) = 0;
    }

    return sp;
}

void task_sleep(uint32_t ms)
{
    current_task->wake_time = time_now() + ms;
    current_task->state = TASK_SLEEPING;

    SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk; // trigger context switch
}