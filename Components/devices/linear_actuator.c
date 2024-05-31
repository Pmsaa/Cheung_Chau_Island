#include "linear_actuator.h"

#define LOG_TAG	"linear"
#define LOG_OUTPUT_LEVEL LOG_INFO 
#include "log.h"

int32_t linear_register(linear_device_t linear_dev, const char* name)
{
	device_assert(linear_dev != NULL);
	device_assert(name != NULL);
	
	linear_dev->parent.type = DEVICE_LINEAR;
	linear_dev->linear_stop = linear_stop;
	linear_dev->linear_forward = linear_forward;
	linear_dev->linear_backward = linear_backward;
	
	device_init(&(linear_dev->parent), name);
	return E_OK;
}

void linear_stop(void)
{
	var_cpu_sr();
	enter_critical();
	
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);	
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);
	
	exit_critical();
}

void linear_forward(void)
{
	var_cpu_sr();
	enter_critical();
	
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);	
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);
	
	// M1 - M3
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);	
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);

	exit_critical();
}

void linear_backward(void)
{
	var_cpu_sr();
	enter_critical();
	
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);	
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);
	
	// M2 - M4
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_SET);	
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LINEAR_ACT_PORT, LINEAR_ACT1_PIN, GPIO_PIN_SET);

	exit_critical();
}
