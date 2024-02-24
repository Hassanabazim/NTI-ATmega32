/*
 * APP_prog.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Hassa
 */

#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MTIMR0_int.h"
#include "MGIO_int.h"
#include "HPB_int.h"
#include "HLED_int.h"
#include "APP_priv.h"
#include "APP_config.h"
#include "APP_int.h"

void Task1(void);
void Task2(void);
void Task3(void);
void schedule_OS(void);

task_t task_queue[] = {{Task1}, {Task2}, {Task3}};


void APP_voidInitApp(void)
{
	PB_ST PB =  {HPB1_ID, PD0, ACTIVE_HIGH};
	/* initialize Drivers & Interrupt callBack */
	HPB_enInit(&PB);
	HLED_enInit(HLED_RED_ID);
	HLED_enInit(HLED_BLUE_ID);
	HLED_enInit(HLED_GREN_ID);
	MTIMER0_enInit();
	MTIMER0_enEnableInt(MTIMER0_OVF_INT_ID);
	MTIMER0_enSetCallBack(MTIMER0_OVF_INT_ID,schedule_OS);
	MTIMER0_enSetTime(500);
	MGIO_enEnable();
	MTIMER0_enStart();

}

void APP_voidStartApp(void)
{
	
	while (1)
	{

	}
}

void Task1(void)
{
	HLED_enToggle(HLED_RED_ID);
}

void Task2(void)
{
	uint8_t Push_state = PB_RELEASED;
	PB_ST PB =  {HPB1_ID, PD0, ACTIVE_HIGH};
	HPB_enRead(&PB,&Push_state);
	if(Push_state == PB_PRESSED)
	{
		HLED_enToggle(HLED_BLUE_ID);
	}
}

void Task3(void)
{
	HLED_enToggle(HLED_GREN_ID);
}

void schedule_OS(void)
{
	static uint8_t flag_t = 0;

	if (flag_t == 0 || flag_t == 2 || flag_t == 4)
	{
		task_queue[1].ptrfn();
		flag_t ++;
	}
	else if (flag_t == 1 || flag_t == 3)
	{
		task_queue[0].ptrfn();
		task_queue[1].ptrfn();
		flag_t ++;
	}

	else if(flag_t == 5)
	{
		task_queue[0].ptrfn();
		task_queue[1].ptrfn();
		task_queue[2].ptrfn();
		flag_t = 0;
	}
}
