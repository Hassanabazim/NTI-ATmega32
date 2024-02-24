/*
 * MWDT_prog.c
 *
 *  Created on: Jun 15, 2023
 *      Author: Hassa
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"
#include "MWDT_int.h"
#include "MWDT_config.h"
#include "MWDT_priv.h"

ErrorState_t MWDT_enEnable(void)
{
	SET_BIT(WDTCR_REG, WDTOE);
	return SUCCESS;

}
ErrorState_t MWDT_enDiable(void)
{
	/* 1. Set on WDT */
	WDTCR_REG |= (1 << WDTOE) | (1<<WDE);
	/* 2. Turn off WDT */
	WDTCR_REG = 0x00;
	return SUCCESS;
}

ErrorState_t MWDT_enSleep(u8 copy_u8TimeOut)
{
	ErrorState_t Local_state = SUCCESS;
	if (copy_u8TimeOut >= MWDT_TIME_OUT_16_3_MS && copy_u8TimeOut <=MWDT_TIME_OUT_2_1_S)
	{
		WDTCR_REG &= MWDT_PRESCALER_MASK;

		WDTCR_REG |= copy_u8TimeOut;
	}
	else
	{
		Local_state =  OUT_OF_RANG_ERR;
	}
	return Local_state;
}

ErrorState_t MWDT_enRefresh(void)
{
	asm ("WDR");
	return SUCCESS;
}

