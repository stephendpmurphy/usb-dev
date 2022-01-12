#ifndef _BOARD_H_
#define _BOARD_H_

#define BOARD_NAME "usb-dev"
#define BOARD_DEBUG_UART_TYPE       kSerialPort_Uart
#define BOARD_DEBUG_UART_BASEADDR   (uint32_t) USART0
#define BOARD_DEBUG_UART_INSTANCE   0U
#define BOARD_DEBUG_UART_CLK_FREQ   12000000U
#define BOARD_DEBUG_UART_CLK_ATTACH kFRO12M_to_FLEXCOMM0
#define BOARD_DEBUG_UART_RST        kFC0_RST_SHIFT_RSTn
#define BOARD_DEBUG_UART_CLKSRC     kCLOCK_Flexcomm0
#define BOARD_UART_IRQ_HANDLER      FLEXCOMM0_IRQHandler
#define BOARD_UART_IRQ              FLEXCOMM0_IRQn
#define BOARD_DEBUG_UART_BAUDRATE   115200U

/*******************************************************************************
 * API
 ******************************************************************************/
void BOARD_Init(void);
void BOARD_DelayTicks(uint32_t n);
uint32_t BOARD_GetTick(void);

#endif /* _BOARD_H_ */