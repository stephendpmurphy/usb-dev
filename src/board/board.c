#include <stdint.h>

volatile uint32_t g_systickCounter;
volatile uint32_t g_delayCounter;

// SysTick Handler function assumes that a tick is every 1ms
void SysTick_Handler(void)
{
    if (g_delayCounter != 0U)
    {
        g_delayCounter--;
    }

    g_systickCounter++;
}

void BOARD_Init(void) {
    // Clock init
    // Peripheral Init
}

void BOARD_DelayTicks(uint32_t n)
{
    g_delayCounter = n;
    while (g_delayCounter != 0U)
    {
    }
}

uint32_t BOARD_GetTick(void) {
    return g_systickCounter;
}