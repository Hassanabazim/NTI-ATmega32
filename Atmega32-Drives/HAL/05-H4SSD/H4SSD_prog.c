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
#include "H4SSD_int.h"
#include "H4SSD_config.h"
#include "H4SSD_priv.h"


ErrorState_t H4SSD_enInit(void)
{
	ErrorState_t Local_state = SUCCESS;

	MDIO_enSetPinDirection(H4SSD_BSD_QA_PIN, OUTPUT);
	MDIO_enSetPinDirection(H4SSD_BSD_QB_PIN, OUTPUT);
	MDIO_enSetPinDirection(H4SSD_BSD_QC_PIN, OUTPUT);
	MDIO_enSetPinDirection(H4SSD_BSD_QD_PIN, OUTPUT);
	MDIO_enSetPinDirection(H4SSD_LED_COM1_PIN, OUTPUT);
	MDIO_enSetPinDirection(H4SSD_LED_COM2_PIN, OUTPUT);
	MDIO_enSetPinDirection(H4SSD_LED_COM3_PIN, OUTPUT);
	MDIO_enSetPinDirection(H4SSD_LED_COM4_PIN, OUTPUT);

	return Local_state;
}

ErrorState_t H4SSD_enDisplayIntegerNumber(u16 copyu16_Number)
{
	ErrorState_t Local_state = SUCCESS;
	u8 Local_u8units[4] = {0}, counter = 3;

	if(copyu16_Number > 9999)
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	else
	{
		while (copyu16_Number > 0)
		{
			Local_u8units[counter] = copyu16_Number % 10;
			copyu16_Number  = copyu16_Number / 10;
			counter --;
		}
		for(u16 i=0; i< HSSD_DISPLAY_TIME; i++)
		{
			switch (Local_u8units[3])
			{
			case 0:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 1:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 2:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 3:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 4:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 5:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 6:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 7:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 8:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, HIGH);
				break;
			case 9:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, HIGH);
				break;
			}

#if (H4SSD_TYPE == H4SSD_CC)
			MDIO_enSetPinValue(H4SSD_LED_COM1_PIN , HIGH);
			//delay for the digit to be ON
				_delay_ms(1);
			MDIO_enSetPinValue(H4SSD_LED_COM1_PIN , LOW);
#elif (H4SSD_TYPE == H4SSD_CA)
			MDIO_enSetPinValue(H4SSD_LED_COM1_PIN , LOW);
			//delay for the digit to be ON
				_delay_ms(1);
			MDIO_enSetPinValue(H4SSD_LED_COM1_PIN , HIGH);
#else
#error ("WRONG HSSD_TYPE");
#endif
			switch (Local_u8units[2])
			{
			case 0:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 1:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 2:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 3:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 4:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 5:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 6:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 7:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 8:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, HIGH);
				break;
			case 9:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, HIGH);
				break;
			}

#if (H4SSD_TYPE == H4SSD_CC)
			MDIO_enSetPinValue(H4SSD_LED_COM2_PIN , HIGH);
			//delay for the digit to be ON
				_delay_ms(1);
			MDIO_enSetPinValue(H4SSD_LED_COM2_PIN , LOW);
#elif (H4SSD_TYPE == H4SSD_CA)
			MDIO_enSetPinValue(H4SSD_LED_COM2_PIN , LOW);
			//delay for the digit to be ON
				_delay_ms(1);
			MDIO_enSetPinValue(H4SSD_LED_COM2_PIN , HIGH);
#else
#error ("WRONG HSSD_TYPE");
#endif

			switch (Local_u8units[1])
			{
			case 0:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 1:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 2:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 3:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 4:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 5:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 6:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 7:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 8:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, HIGH);
				break;
			case 9:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, HIGH);
				break;
			}

#if (H4SSD_TYPE == H4SSD_CC)
			MDIO_enSetPinValue(H4SSD_LED_COM3_PIN , HIGH);
			//delay for the digit to be ON
				_delay_ms(1);
			MDIO_enSetPinValue(H4SSD_LED_COM3_PIN , LOW);
#elif (H4SSD_TYPE == H4SSD_CA)
			MDIO_enSetPinValue(H4SSD_LED_COM3_PIN , LOW);
			//delay for the digit to be ON
				_delay_ms(1);
			MDIO_enSetPinValue(H4SSD_LED_COM3_PIN , HIGH);
#else
#error ("WRONG HSSD_TYPE");
#endif
			switch (Local_u8units[0])
			{
			case 0:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 1:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 2:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 3:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 4:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 5:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 6:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 7:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, LOW);
				break;
			case 8:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, HIGH);
				break;
			case 9:
				MDIO_enSetPinValue(H4SSD_BSD_QA_PIN, HIGH);
				MDIO_enSetPinValue(H4SSD_BSD_QB_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QC_PIN, LOW);
				MDIO_enSetPinValue(H4SSD_BSD_QD_PIN, HIGH);
				break;
			}

#if (H4SSD_TYPE == H4SSD_CC)
			MDIO_enSetPinValue(H4SSD_LED_COM4_PIN , HIGH);
			//delay for the digit to be ON
				_delay_ms(1);
			MDIO_enSetPinValue(H4SSD_LED_COM4_PIN , LOW);
#elif (H4SSD_TYPE == H4SSD_CA)
			MDIO_enSetPinValue(H4SSD_LED_COM4_PIN , LOW);
			//delay for the digit to be ON
				_delay_ms(1);
			MDIO_enSetPinValue(H4SSD_LED_COM4_PIN , HIGH);
#else
#error ("WRONG HSSD_TYPE");
#endif
		}
	}
	return Local_state;
}
