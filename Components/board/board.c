#include "board.h"

#include "drv_uart.h"
#include "drv_t12.h"
#include "sbus.h"

#define LOG_TAG	"board"
#define LOG_OUTPUT_LEVEL	LOG_INFO
#include "log.h"

extern struct rc_device chassis_rc;

int32_t t12_rx_data_by_uart(uint8_t *buff, uint16_t len)
{
	rc_device_date_update(&chassis_rc, buff);
	return 0;
}
