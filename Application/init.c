#include "init.h"

#define LOG_TAG "init"
#define LOG_OUTPUT_LEVEL	5
#include "log.h"

struct rc_device chassis_rc;

void system_service(void)
{
	usart1_manage_init();
	log_printf("\r\n\r\n---------------------------------------------------------");
	log_i("system start.");
	
	t12_uart_init(t12_rx_data_by_uart, NULL);
	rc_device_register(&chassis_rc, "t12");
	
	
}
