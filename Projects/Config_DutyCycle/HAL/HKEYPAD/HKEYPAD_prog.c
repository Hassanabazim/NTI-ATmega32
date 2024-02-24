/*
 * HKEYPAD_prog.c
 *
 *  Created on: May 31, 2023
 *      Author: Hassan
 */

#include <util/delay.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MDIO_int.h"
#include "HKEYPAD_priv.h"
#include "HKEYPAD_config.h"
#include "HKEYPAD_int.h"

ErrorState_t HKEYPAD_enInit(void)
{
	ErrorState_t Local_state = SUCCESS;

	//intallize
	MDIO_enSetPinDirection(HKEYPAD_R0_PIN, OUTPUT);
	MDIO_enSetPinDirection(HKEYPAD_R1_PIN, OUTPUT);
	MDIO_enSetPinDirection(HKEYPAD_R2_PIN, OUTPUT);
	MDIO_enSetPinDirection(HKEYPAD_R3_PIN, OUTPUT);

	MDIO_enSetPinDirection(HKEYPAD_C0_PIN, INPUT);
	MDIO_enSetPinDirection(HKEYPAD_C1_PIN, INPUT);
	MDIO_enSetPinDirection(HKEYPAD_C2_PIN, INPUT);
	MDIO_enSetPinDirection(HKEYPAD_C3_PIN, INPUT);

	MDIO_enSetPinValue(HKEYPAD_R0_PIN, HIGH);
	MDIO_enSetPinValue(HKEYPAD_R1_PIN, HIGH);
	MDIO_enSetPinValue(HKEYPAD_R2_PIN, HIGH);
	MDIO_enSetPinValue(HKEYPAD_R3_PIN, HIGH);

#if(KIT_TYPE == SIM_TYPE)
	MDIO_enSetPinValue(HKEYPAD_C0_PIN, HIGH);
	MDIO_enSetPinValue(HKEYPAD_C1_PIN, HIGH);
	MDIO_enSetPinValue(HKEYPAD_C2_PIN, HIGH);
	MDIO_enSetPinValue(HKEYPAD_C3_PIN, HIGH);
#endif

	return Local_state;
}
ErrorState_t HKEYPAD_enGetPressedKey(uint8_t *ptrKey)
{
	uint8_t Local_u8PressedKey = HKEYPAD_NO_KEY_PRESSED;
	uint8_t Local_u8Read;
	uint8_t local_u8ArrKeys[4][4] = HKEYPAD_KEYS;

	uint8_t rowArr[] = {HKEYPAD_R0_PIN, HKEYPAD_R1_PIN, HKEYPAD_R2_PIN, HKEYPAD_R3_PIN};
	uint8_t colArr[] = {HKEYPAD_C0_PIN,HKEYPAD_C1_PIN,HKEYPAD_C2_PIN,HKEYPAD_C3_PIN};

	for (uint8_t row_index = 0; row_index <= 3 ; row_index++)
	{
		//Activate row (set LOW on the Row pins)
		MDIO_enSetPinValue(rowArr[row_index], LOW);

		for(uint8_t col_index = 0; col_index <= 3  ; col_index++)
		{
			// Read the value of the col (HIGH OR LOW)
			MDIO_enGetPinValue(colArr[col_index], &Local_u8Read); // 0
			// for debouncing
			if (Local_u8Read == HKEYPAD_KEY_PRESSED)
			{
				_delay_ms(20);
				// Read the col Pin again to check that's not noise
				MDIO_enGetPinValue(colArr[col_index], &Local_u8Read);
				if (Local_u8Read == HKEYPAD_KEY_PRESSED)
				{
					// for single read to ignore multi-press
					while(Local_u8Read == HKEYPAD_KEY_PRESSED)
					{
						MDIO_enGetPinValue(colArr[col_index], &Local_u8Read);
					}
					Local_u8PressedKey = local_u8ArrKeys[row_index][col_index];
				}
				else
				{

				}

			}//deboncing if
			else
			{

			}

		} // col for loop

		//De-Activate row (set HIGH on the Row pins)
		MDIO_enSetPinValue(rowArr[row_index], HIGH);
	}// row for loop

	*ptrKey = Local_u8PressedKey;
	return SUCCESS;

}
