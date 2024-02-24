/*
 * MGIO_prog.c
 *
 *  Created on: Jun 7, 2023
 *      Author: Hassa
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"
#include "MGIO_priv.h"
#include "MGIO_config.h"
#include "MGIO_int.h"


ErrorState_t MGIO_enEnable(void)
{
	//SET_BIT(SREG_REG,I_BIT);
	asm("SEI");
	return SUCCESS;
}
ErrorState_t MGIO_enDisable(void)
{
	//CLC_BIT(SREG_REG,I_BIT);
		asm("CLI");
		return SUCCESS;
}
