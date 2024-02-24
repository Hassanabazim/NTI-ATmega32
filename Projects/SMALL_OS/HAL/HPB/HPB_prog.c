/*
 * HPB_prog.c
 *
 *  Created on: Jun 5, 2023
 *      Author: Hassa
 */

#include <util/delay.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MDIO_int.h"
#include "HPB_priv.h"
#include "HPB_config.h"
#include "HPB_int.h"


ErrorState_t HPB_enInit(PB_ST *ptrPB)
{
	ErrorState_t Local_state = SUCCESS;

	if (ptrPB->PB_ID >= 1 && ptrPB->PB_ID <=4)
	{
		MDIO_enSetPinDirection(ptrPB->PB_PIN, INPUT);

		/* Activiate Internal PULL-UPS Resistors */
		if(ptrPB->PB_MODE == ACTIVE_HIGH)
			MDIO_enSetPinValue(ptrPB->PB_PIN, HIGH);

	}
	else
		Local_state = OUT_OF_RANG_ERR;

	return Local_state;
}


ErrorState_t HPB_enRead(PB_ST *ptrPB, PBState_t * ptrPBState)
{
	ErrorState_t Local_state = SUCCESS;

	uint8_t Local_u8pinRead = PB_RELEASED;

	MDIO_enGetPinValue(ptrPB->PB_PIN, &Local_u8pinRead);
	if (Local_u8pinRead == PB_PRESSED)
	{
		// Wait for debouncing
		_delay_ms(20);
		MDIO_enGetPinValue(ptrPB->PB_PIN, &Local_u8pinRead);
		if (Local_u8pinRead == PB_PRESSED)
		{
			// for single press busy wait
			while (Local_u8pinRead == PB_PRESSED)
			{
				MDIO_enGetPinValue(ptrPB->PB_PIN, &Local_u8pinRead);
			}
			*ptrPBState = PB_PRESSED;
		}
		else
		{
			*ptrPBState = PB_RELEASED;
		}
	}
	else
	{
		*ptrPBState = PB_RELEASED;
	}

	return Local_state;
}
