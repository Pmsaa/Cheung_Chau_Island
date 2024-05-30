#include "chassis_task.h"

#include "FreeRTOS.h"
#include "task.h"

#define LOG_TAG "chassis"
#define LOG_OUTPUT_LEVEL LOG_INFO
#include "log.h"

osThreadId_t chassisTaskHandle = NULL;
const osThreadAttr_t chassTask_attr = {
	.name = "chassisTask",
	.stack_size = 512,
	.priority = osPriorityNormal,
};

void chassisTask(void *pvParameters);

struct chassis chassis;
struct rc_device chassis_rc;

rc_info_t p_rc_info;
struct caterpillar catp;

float vx, vy, vw;

void chassis_init(void)
{
	char motor_name[2][10] = {0};
	uint8_t name_len = strlen("motor");
	
	for(uint8_t i=0; i<2; i++)
	{
		memcpy(&motor_name[i], "motor", name_len);
		chassis.motor[i].node_id = 0x01 + i;
		chassis.motor[i].can_send_flag = 0;
		chassis.motor[i].speed_rate = 0;
	}
	
	memcpy(&motor_name[0][name_len], "_MR\0", 4);
	memcpy(&motor_name[1][name_len], "_ML\0", 4);
	
	for(uint8_t i=0; i<2; i++)
	{
		motor_register(&chassis.motor[i], motor_name[i]);
	}
	motor_can_send_register(motor_canstd_send);

	caterpillar_set_speed(&catp, 0, 0, 0);
	catp.param.wheel_tread = CATERPILLAR_TREAD;

	rc_device_register(&chassis_rc, "t12");
	
	chassisTaskHandle = osThreadNew(chassisTask, NULL, &chassTask_attr);
}

void chassisTask(void *pvParameters)
{
	log_i("chassisTask");
	
	p_rc_info = rc_device_get_info(&chassis_rc);
	
	for(;;)
	{

		osDelay(100);
	}
}


