#ifndef _BOARD_H_
#define _BOARD_H_

/*******************************************************************************
 * API
 ******************************************************************************/
void BOARD_Init(void);
void BOARD_DelayTicks(uint32_t n);
uint32_t BOARD_GetTick(void);

#endif /* _BOARD_H_ */