/*
 * MEXTI_prog.c
 *
 *  Created on: Jun 7, 2023
 *      Author: Hassa
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"
#include "MGIE_int.h"
#include "MEXTI_int.h"
#include "MEXTI_config.h"
#include "MEXTI_priv.h"

void (*callBackArr[3])(void) = {NULL, NULL, NULL};

ErrorState_t MEXTI_enEnable(MEXTI_ID_t copy_u8IntID, MEXTI_Trigger_t copy_u8IntTrig)
{
	ErrorState_t Local_state = SUCCESS;

	if (copy_u8IntTrig > MEXTI_RISING_EDGE || copy_u8IntTrig < MEXTI_FAILING_EDGE)
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	else
	{

		switch (copy_u8IntID)
		{
		case MEXTI_INT0_ID:
			// APPLY MASK
			MCUCR_REG &= MEXTI_INT0_SC_MASK;
			// Insert Value
			MCUCR_REG |= copy_u8IntTrig;
			break;
		case MEXTI_INT1_ID:
			MCUCR_REG &= MEXTI_INT1_SC_MASK;
			MCUCR_REG |= copy_u8IntTrig << MEXTI_INT1_SC_SH;
			break;
		case MEXTI_INT2_ID:
			CLR_BIT(MCUCSR_REG,ISC2_BIT);
			MCUCSR_REG |= GET_BIT(copy_u8IntTrig,0) << ISC2_BIT;
			break;
		default:
			Local_state = OUT_OF_RANG_ERR;
		}
		SET_BIT(GICR_REG,copy_u8IntID);
	}
	return Local_state;
}

ErrorState_t MEXTI_enDisable(MEXTI_ID_t copy_u8IntID)
{
	ErrorState_t Local_state = SUCCESS;

	if (copy_u8IntID >= MEXTI_INT2_ID && copy_u8IntID <= MEXTI_INT1_ID)
	{
		CLR_BIT(GICR_REG,copy_u8IntID);
	}
	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}

	return Local_state;
}

ErrorState_t MEXTI_enSetCalBack(MEXTI_ID_t copy_u8IntID, void(*ptrfn)(void))
{
	ErrorState_t Local_state = SUCCESS;
	if (ptrfn == NULL)
	{
		Local_state = NULL_PTR_ERR;
	}
	else
	{
		switch (copy_u8IntID)
		{
		case MEXTI_INT0_ID:
			callBackArr[0] = ptrfn;
					break;
		case MEXTI_INT1_ID:
			callBackArr[1] = ptrfn;
			break;
		case MEXTI_INT2_ID:
			callBackArr[2] = ptrfn;
			break;

		default :
			Local_state = OUT_OF_RANG_ERR;
			break;
		}
	}
	return Local_state;
}

ISR(EXT_INT_0)
{
	if (callBackArr[0] != NULL)
	{
		callBackArr[0]();
	}
}


ISR(EXT_INT_1)
{
	if (callBackArr[1] != NULL)
	{
		callBackArr[1]();
	}
}

ISR(EXT_INT_2)
{
	if (callBackArr[2] != NULL)
	{
		callBackArr[2]();
	}
}
