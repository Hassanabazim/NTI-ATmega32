/*
 * MEXTI_prog.c
 *
 *  Created on: Jun 7, 2023
 *      Author: Hassa
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"
#include "MEXTI_priv.h"
#include "MEXTI_config.h"
#include "MEXTI_int.h"
#include <avr/interrupt.h>

void (*callBackArr[3])(void) = {NULL, NULL, NULL};

ErrorState_t MEXTI_enEnable(Interrupt_t copy_enID, IntTrigger_t copy_enTrig)
{
	ErrorState_t Local_state = SUCCESS;

	if (copy_enTrig > RISING_EDGE_TRI || copy_enTrig < LOW_LEVEL_TRIG)
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	else
	{

		switch (copy_enID)
		{
		case INT0_ID:
			// APPLY MASK
			MCUCR_REG &= INT0_SC_MASK;
			// Insert Value
			MCUCR_REG |= copy_enTrig;
			break;
		case INT1_ID:
			MCUCR_REG &= INT1_SC_MASK;
			MCUCR_REG |= copy_enTrig << INT1_SC_SH;
			break;
		case INT2_ID:
			CLC_BIT(MCUCSR_REG,ISC2_BIT);
			MCUCSR_REG |= GET_BIT(copy_enTrig,0) << ISC2_BIT;
			break;
		default:
			Local_state = OUT_OF_RANG_ERR;
		}
		SET_BIT(GICR_REG,copy_enID);
	}
	return Local_state;
}

ErrorState_t MEXTI_enDisable(Interrupt_t copy_enID)
{
	ErrorState_t Local_state = SUCCESS;

	if (copy_enID >= INT2_ID && copy_enID <= INT1_ID)
	{
		CLC_BIT(GICR_REG,copy_enID);
	}
	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}

	return Local_state;
}

ErrorState_t MEXTI_enSetCalBack(Interrupt_t copy_enID, void(*ptrfn)(void))
{
	ErrorState_t Local_state = SUCCESS;
	if (ptrfn == NULL)
	{
		Local_state = NULL_PTR_ERR;
	}
	else
	{
		switch (copy_enID)
		{
		case INT0_ID:
			callBackArr[0] = ptrfn;
					break;
		case INT1_ID:
			callBackArr[1] = ptrfn;
			break;
		case INT2_ID:
			callBackArr[2] = ptrfn;
			break;

		default :
			Local_state = OUT_OF_RANG_ERR;
			break;
		}
	}
	return Local_state;
}

ISR(INT0_vect)
{
	if (callBackArr[0] != NULL)
	{
		callBackArr[0]();
	}
}


ISR(INT1_vect)
{
	if (callBackArr[1] != NULL)
	{
		callBackArr[1]();
	}
}

ISR(INT2_vect)
{
	if (callBackArr[2] != NULL)
	{
		callBackArr[2]();
	}
}
