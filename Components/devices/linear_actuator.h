#ifndef __LINEAR_ACTUATOR_H
#define __LINEAR_ACTUATOR_H

#include "stm32f1xx_hal.h"
#include "device.h"

#define LINEAR_ACT1_PIN		GPIO_PIN_6
#define LINEAR_ACT2_PIN		GPIO_PIN_7
#define LINEAR_ACT3_PIN		GPIO_PIN_8
#define LINEAR_ACT4_PIN		GPIO_PIN_9

#define LINEAR_ACT_PORT		GPIOC

typedef struct linear_device *linear_device_t;

struct linear_device
{
	struct device parent;
	void (*linear_stop)(void);
	void (*linear_forward)(void);
	void (*linear_backward)(void);
};

void linear_stop(void);
void linear_forward(void);
void linear_backward(void);

#endif	// __LINEAR_ACTUATOR_H
