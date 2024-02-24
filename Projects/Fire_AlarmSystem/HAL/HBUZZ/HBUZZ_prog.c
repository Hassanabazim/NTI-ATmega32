/*
 * HBUZZ_prog.c
 *
 *  Created on: Jun 3, 2023
 *      Author: Hassa
 */
#include "util/delay.h"
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MDIO_int.h"
#include "HBUZZ_priv.h"
#include "HBUZZ_config.h"
#include "HBUZZ_int.h"


ErrorState_t HBUZZ_enInit(uint8_t copy_u8BuzzID)
{
	ErrorState_t Local_state = SUCCESS;
	switch (copy_u8BuzzID)
	{
	case HBUZZ_ID:
		MDIO_enSetPinDirection(HBUZZ_PIN, OUTPUT);
		break;

		default :
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

ErrorState_t HBUZZ_enSetON(uint8_t copy_u8BuzzID)
{
	ErrorState_t Local_state = SUCCESS;
	switch (copy_u8BuzzID)
	{
	case HBUZZ_ID:
		MDIO_enSetPinValue(HBUZZ_PIN, HIGH);
		break;

		default :
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

ErrorState_t HBUZZ_enSetOFF(uint8_t copy_u8BuzzID)
{
	ErrorState_t Local_state = SUCCESS;
	switch (copy_u8BuzzID)
	{
	case HBUZZ_ID:
		MDIO_enSetPinValue(HBUZZ_PIN, LOW);
		break;

		default :
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

ErrorState_t HBUZZ_enSetONCE(uint8_t copy_u8BuzzID)
{
	ErrorState_t Local_state = SUCCESS;
	switch (copy_u8BuzzID)
	{
	case HBUZZ_ID:
		MDIO_enSetPinValue(HBUZZ_PIN, HIGH);
		_delay_ms(1000);
		MDIO_enSetPinValue(HBUZZ_PIN, LOW);
		break;

	default :
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

ErrorState_t HBUZZ_enSetNum(uint8_t copy_u8BuzzID, uint8_t copy_u8num)
{
	ErrorState_t Local_state = SUCCESS;
	switch (copy_u8BuzzID)
	{
	case HBUZZ_ID:
		for (uint8_t i = 0; i < copy_u8num; i++)
			{
				MDIO_enSetPinValue(HBUZZ_PIN, HIGH);
				_delay_ms(1000);
				MDIO_enSetPinValue(HBUZZ_PIN, LOW);
				_delay_ms(1000);
			}
			break;

			default :
			Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}
