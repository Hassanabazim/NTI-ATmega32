/*
 * HULTRASONIC_prog.c
 *
 *  Created on: Jun 21, 2023
 *      Author: Hassa
 */

#include <util/delay.h>
#include <math.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MDIO_int.h"
#include "MGIE_int.h"
#include "MTIMER1_int.h"
#include "HULTRA_int.h"
#include "HULTRA_config.h"
#include "HULTRA_priv.h"




void ICU_HW(void);
void OVF_HW(void);

static volatile u16 Reading_1 = 0;
static volatile u16 Reading_2 = 0;

static volatile StateMachine_t state = STATE1;
static volatile u8 OVF_count = 0;


ErrorState_t HULTRASONIC_enInit(void)
{
	MDIO_enSetPinDirection(PC5, OUTPUT);
	MDIO_enSetPinDirection(PD6, INPUT);





	/* 4 :Call back for ISR  */
	MTIMER1_enSetCallBack(MTIMER1_ICU_INT_ID, ICU_HW);
	MTIMER1_enSetCallBack(MTIMER1_OVF_INT_ID, OVF_HW);




	return SUCCESS;
}
ErrorState_t HULTRASONIC_enRead(u32 *ptrValue)
{
	ErrorState_t local_state = SUCCESS;

	if (ptrValue != NULL)
	{
		local_state  = NULL_PTR_ERR;
	}

	else
	{
		/* 1: Initialize TIMER1  */
		MTIMER1_enInit();

		/* 2 :Initialize ICU (Rise trigger) */
		MTIMER1_ICU_enInit();
		/* 5 : Start Timer 1 */
		MTIMER1_enStart();


		/* 3 :Enable ICU Interrupt & OVF Interrupt */
		MTIMER1_enEnableINT(MTIMER1_ICU_INT_ID);
		MTIMER1_enEnableINT(MTIMER1_OVF_INT_ID);

		/* Enable Global Interrupt */
		MGIE_enEnable();

		/* trigger the ultrasonic sensor pin */
		MDIO_enSetPinValue(PC5, HIGH);
		_delay_us(10);
		MDIO_enSetPinValue(PC5, LOW);

		/* Busy Waiting until all Readings are taken */
		while(state!= STATE3);
		state = STATE1;

		u32 TimeTicks = (u32)Reading_2 - (u32)Reading_1;


		f32 TickTime = 1024 / 16;
		f32 time  = (TimeTicks *TickTime)/1000000.0;
		*ptrValue = ceil(34300 * (time/2));
	}
	return local_state;

}

void ICU_HW(void)
{
	if(STATE1 == state)
	{
		//Change State

		MTIMER1_ICU_enSetTrigger(MTIMER1_ICU_FALL_EDGE_TRIG);
		MTIMER1_ICU_enRead(&Reading_1);
		state=STATE2;
	}
	else if(STATE2 == state){

		//Change State
		MTIMER1_ICU_enRead(&Reading_2);
		state=STATE3;
		//MTIMER1_ICU_enSetTrigger(MTIMER1_ICU_RAIS_EDGE_TRIG);
		MTIMER1_enDisableINT(MTIMER1_ICU_INT_ID);
		MTIMER1_enStop();
		MGIE_enDisable();
	}
}

void OVF_HW(void)
{
	OVF_count ++;
}

