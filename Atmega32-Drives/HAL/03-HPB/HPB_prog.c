/********************************************************************************
 * 	@file        		:  HPB_prog.c				 							*
 *	@Author 	 		:  HASSAN ABDELAZIM ABDELSALAM							*
 *	@Version 			:  1.0.0							 					*
 *	@Date				:  05/06/2023											*
 *********************************************************************************
 * @attention   Driver Implementation for ATmega32
 *
 *
 *
 *
 *********************************************************************************
 * INCLUDES
 *********************************************************************************/
#include <util/delay.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MDIO_int.h"
#include "HPB_int.h"
#include "HPB_config.h"
#include "HPB_priv.h"



ErrorState_t HPB_enInit(HPB_INIT_t *ptr_u8PB)
{
	ErrorState_t Local_state = SUCCESS;
	/*	1. check if the PB IDs in the Range */
	if (ptr_u8PB != NULL)
	{
		/* 2. Set the PB Pin as Input */
		MDIO_enSetPinDirection(ptr_u8PB->PB_PIN, INPUT);

		/* 3. Activiate Internal PULL-UPS Resistors if ACTIVE LOW */
		if(ptr_u8PB->PB_MODE == HPB_PULL_UP)
		{
			MDIO_enSetPinValue(ptr_u8PB->PB_PIN, HIGH);
		}
	}
	else
	{
		Local_state = NULL_PTR_ERR;
	}
	return Local_state;
}


ErrorState_t HPB_enRead(const HPB_INIT_t *ptr_u8PB, HPB_State_t *ptr_u8PBState)
{
	ErrorState_t Local_state = SUCCESS;

	/* 1. intialize the Default mood as RELEASED */
	u8 Local_u8pinRead = HPB_RELEASED;

	/* 2. GET the current state of the PB*/
	MDIO_enGetPinValue(ptr_u8PB->PB_PIN, &Local_u8pinRead);

	/*3. check if The current state was PRESSED*/
	if (Local_u8pinRead == HPB_PRESSED)
	{
		/* 4. Wait for debouncing */
		_delay_ms(100);

		/*5. check if The current state was PRESSED*/
		MDIO_enGetPinValue(ptr_u8PB->PB_PIN, &Local_u8pinRead);
		if (Local_u8pinRead == HPB_PRESSED)
		{
			/* 6. Single press busy wait */
			while (Local_u8pinRead == HPB_PRESSED)
			{
				MDIO_enGetPinValue(ptr_u8PB->PB_PIN, &Local_u8pinRead);
			}
			/* 7. Assign PB state to ptr_var and returned by Reference  */
			*ptr_u8PBState = HPB_PRESSED;
		}
		else
		{
			/* 7. Assign PB state to ptr_var and returned by Reference  */
			*ptr_u8PBState = HPB_RELEASED;
		}
	}
	else
	{
		/* 7. Assign PB state to ptr_var and returned by Reference  */
		*ptr_u8PBState = HPB_RELEASED;
	}

	return Local_state;
}
/********************************************************************************
 * END OF FILE	:	HPB_prog.c
 ********************************************************************************/
