#ifndef __CHASSIS_TASK_H
#define __CHASSIS_TASK_H

#include "sbus.h"
#include "board.h"
#include "caterpillar.h"

struct chassis
{
	struct motor_device motor[2];
};

void chassis_init(void);

#endif // __CHASSIS_TASK_H
