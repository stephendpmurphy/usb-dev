#include <stdint.h>
#include "fsl_common.h"
#include "fsl_debug_console.h"
#include "fsl_inputmux.h"
#include "fsl_power.h"
#include "board.h"
#include "pin_mux.h"
#include "gpio.h"

volatile uint32_t g_systickCounter;
volatile uint32_t g_delayCounter;

static void BOARD_InitDebugConsole(void)
{
    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);
    RESET_ClearPeripheralReset(BOARD_DEBUG_UART_RST);
    uint32_t uartClkSrcFreq = BOARD_DEBUG_UART_CLK_FREQ;
    DbgConsole_Init(BOARD_DEBUG_UART_INSTANCE, BOARD_DEBUG_UART_BAUDRATE, BOARD_DEBUG_UART_TYPE, uartClkSrcFreq);
}

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
    // Power Init
    POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);

    // Board pin init
    BOARD_InitPins();
    // Init the Debug console on UART0
    BOARD_InitDebugConsole();

    // Clock configuration
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);
    CLOCK_AttachClk(kMAIN_CLK_to_ADC_CLK);
    CLOCK_SetClkDiv(kCLOCK_DivAdcAsyncClk, 8U, true);
    // Set our oscillator to 150Mhz
    BOARD_BootClockPLL150M();
    // Set our SysTick frequency
    SysTick_Config(SystemCoreClock / 1000000U);
    // Power Init
    POWER_DisablePD(kPDRUNCFG_PD_LDOGPADC);

    // Set the initial LED states
    gpio_setStatusLED(false);
    gpio_setPowerLED(false);
    gpio_setCommLED(false);

    // Set the initial Range select states
    gpio_setMicroAmpEn(false);
    gpio_setNanoAmpEn(false);
    gpio_setMilliAmpEn(true);
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