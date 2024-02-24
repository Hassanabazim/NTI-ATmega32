/*
 * HSSD_prog.c
 *
 *  Created on: May 31, 2023
 *      Author: Hassan
 */

#include <util/delay.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MDIO_int.h"
#include "HSSD_int.h"
#include "HSSD_config.h"
#include "HSSD_priv.h"


ErrorState_t HSSD_enInit(void)
{
	ErrorState_t Local_state = SUCCESS;

	MDIO_enSetPinDirection(HSSD_LED_DP_PIN, OUTPUT);
	MDIO_enSetPinDirection(HSSD_LED_A_PIN, OUTPUT);
	MDIO_enSetPinDirection(HSSD_LED_B_PIN, OUTPUT);
	MDIO_enSetPinDirection(HSSD_LED_C_PIN, OUTPUT);
	MDIO_enSetPinDirection(HSSD_LED_D_PIN, OUTPUT);
	MDIO_enSetPinDirection(HSSD_LED_E_PIN, OUTPUT);
	MDIO_enSetPinDirection(HSSD_LED_F_PIN, OUTPUT);
	MDIO_enSetPinDirection(HSSD_LED_G_PIN, OUTPUT);

	MDIO_enSetPinDirection(HSSD_LED_EN1_PIN, OUTPUT);
	MDIO_enSetPinDirection(HSSD_LED_EN2_PIN, OUTPUT);

	return Local_state;
}

ErrorState_t HSSD_enDisplayIntegerNumber(u8 copyu8_Number)
{
	ErrorState_t Local_state = SUCCESS;

	if(copyu8_Number > 99)
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	else
	{
		u8 Local_u8Units = copyu8_Number % 10;
		u8 Local_u8Tens  = copyu8_Number / 10;
#if (HSSD_TYPE == HSSD_CC)
		MDIO_enSetPinValue(HSSD_LED_DP_PIN ,LOW);
#elif(HSSD_TYPE == HSSD_CA)
		MDIO_enSetPinValue(HSSD_LED_DP_PIN ,HIGH);
#else
#error ("WRONG HSSD TYPE");
#endif

		for(u16 i=0; i< HSSD_DISPLAY_TIME; i++)
		{
			switch(Local_u8Units)
			{
#if (HSSD_TYPE == HSSD_CC)
			case 0:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 1:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 2:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 3:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 4:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 5:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 6:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 7:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 8:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 9:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;
#elif (HSSD_TYPE == HSSD_CA)
			case 0:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 1:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 2:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 3:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 4:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 5:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 6:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 7:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 8:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 9:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;
#else
#error ("WRONG HSSD TYPE");
#endif
			default : break;
			}
#if(HSSD_TYPE == HSSD_CC)
			MDIO_enSetPinValue(HSSD_LED_EN1_PIN , HIGH);
			MDIO_enSetPinValue(HSSD_LED_EN2_PIN , LOW);
			// delay for the digit to be ON
			_delay_ms(1);
			MDIO_enSetPinValue(HSSD_LED_EN2_PIN , HIGH);
#elif(HSSD_TYPE == HSSD_CA)
			MDIO_enSetPinValue(HSSD_LED_EN1_PIN , LOW);
			MDIO_enSetPinValue(HSSD_LED_EN2_PIN , HIGH);
			// delay for the digit to be ON
			_delay_ms(1);
			MDIO_enSetPinValue(HSSD_LED_EN2_PIN , LOW);
#else
#error ("Wrong HSSD TYPE");
#endif


			switch(Local_u8Tens)
			{
#if(HSSD_TYPE == HSSD_CC)
			case 0:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 1:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 2:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 3:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 4:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 5:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 6:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 7:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 8:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 9:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;
#elif(HSSD_TYPE == HSSD_CA)
			case 0:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 1:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 2:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 3:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 4:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 5:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 6:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 7:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,HIGH);
				break;

			case 8:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;

			case 9:
				MDIO_enSetPinValue(HSSD_LED_A_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_B_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_C_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_D_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_E_PIN ,HIGH);
				MDIO_enSetPinValue(HSSD_LED_F_PIN ,LOW);
				MDIO_enSetPinValue(HSSD_LED_G_PIN ,LOW);
				break;
#else
#error ("WRONG HSSD TYPE");
#endif
			default : break;
			}
#if(HSSD_TYPE == HSSD_CC)
			MDIO_enSetPinValue(HSSD_LED_EN1_PIN , LOW);
			MDIO_enSetPinValue(HSSD_LED_EN2_PIN , HIGH);
			// delay for the digit to be ON
			_delay_ms(1);
			//Disable DIG 1
			MDIO_enSetPinValue(HSSD_LED_EN1_PIN , HIGH);
#elif(HSSD_TYPE == HSSD_CA)
			MDIO_enSetPinValue(HSSD_LED_EN1_PIN , HIGH);
			MDIO_enSetPinValue(HSSD_LED_EN2_PIN , LOW);
			// delay for the digit to be ON
			_delay_ms(1);
			//Disable DIG 1
			MDIO_enSetPinValue(HSSD_LED_EN1_PIN , LOW);
#else
#error ("WRONG HSSD_TYPE");
#endif
		}

	}
	return Local_state;
}
