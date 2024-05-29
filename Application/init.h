#ifndef __INIT_H
#define __INIT_H

#include "stm32f1xx_hal.h"

#include "usart.h"
#include "drv_uart.h"
#include "drv_t12.h"
#include "sbus.h"
#include "can.h"
#include "drv_can.h"

#include "board.h"

void system_service(void);

#endif // __INIT_H
