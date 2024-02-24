/*
 * APP_prog.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Hassa
 */


#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "HKEYPAD_int.h"
#include "HLCD_int.h"
#include "MTIMR0_int.h"
#include "MDIO_int.h"
#include "HMOTOR_int.h"
#include "APP_priv.h"
#include "APP_config.h"
#include "APP_int.h"
#include "avr/delay.h"

void APP_voidStartApp(void)
{
	/* initialization of Drivers */
	MTIMER0_enInit();
	MTIMER0_enStart();
	HLCD_enInit();
	HKEYPAD_enInit();
	HDCMOTOR_enInit();

	while (1)
	{
		/* variables inside the loop to auto reset parameters*/
		uint8_t key  = HKEYPAD_NO_KEY_PRESSED;
		uint8_t temp, freq = 0, duty = 0;

		/* read Duty cycle from keypad and store it */
		HLCD_enCLearDisplay();
		HLCD_enSendString("DUTY CYCYLE%:");
		while (key != ' ')
		{
			HKEYPAD_enGetPressedKey(&key);
			if(key != HKEYPAD_NO_KEY_PRESSED && key != ' ')
			{
				HLCD_enSendData(key);
				temp = key - '0';
				duty = duty * 10 + temp ;
			}
		}
		/* duty out of range return Invalid Duty and reset the prompt*/
		HLCD_enCLearDisplay();
		if (duty > 100)
		{
			HLCD_enSendString("INVALID DUTY CYC");
		}
		/* duty in range prompt for Frequency in MHz */
		else
		{
			key = HKEYPAD_NO_KEY_PRESSED;
			HLCD_enSendString("FREQ MHz :");
		}
		/* read frequency from keypad and store it */
		while (key != ' ')
		{
			HKEYPAD_enGetPressedKey(&key);
			if(key != HKEYPAD_NO_KEY_PRESSED && key != ' ')
			{
				HLCD_enSendData(key);
				temp = key - '0';
				freq = freq * 10 + temp ;
			}
			/* Atmega32-support up to 16MHZ */
			else if (freq > 16)
			{
				freq = 0;
				HLCD_enGoToXY(2, 0);
				HLCD_enSendString("INVALID FREQUENCY");
				_delay_ms(500);
				HLCD_enCLearDisplay();
				HLCD_enSendString("FREQ MHz :");
			}
		}

		/* Duty Cycle & frequency was in range, Display parameters MOTOR ON */

		if (freq > 0 && freq <=16 )
		{
			HDCMOTOR_enSetON(Motor_forward, duty);
			HLCD_enCLearDisplay();
			HLCD_enSendString("MOTOR ON: ");
			HLCD_enGoToXY(1, 11);
			HLCD_enSendIntNum(duty);
			HLCD_enSendData('%');
			HLCD_enGoToXY(2, 0);
			HLCD_enSendString("FREQUENCY: ");
			HLCD_enSendIntNum(freq);
			HLCD_enSendString("MHz");
			_delay_ms(1000);
		}
		else
		{

		}
	}
}
