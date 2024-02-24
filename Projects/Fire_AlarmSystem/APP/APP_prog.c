/*
 * APP.c
 *
 *  Created on: Jun 2, 2023
 *      Author: Hassa
 */

#include <util/delay.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MDIO_int.h"
#include "MEXTI_int.h"
#include "MGIO_int.h"
#include "HPB_int.h"
#include "HLED_int.h"
#include "HBUZZ_int.h"
#include "HLCD_int.h"
#include "APP_priv.h"
#include "APP_config.h"
#include "APP_int.h"

uint8_t flag = 0;
// Interrupt Action to set a flag
void ACTION1(void)
{
	flag = 1;
}

void APP_voidStartApp(void)
{
#if(APPLICATION == KIT1)

	// intallization of LEDS, LCD, BUZZ
	uint8_t pinValue = PB_RELEASED;
	HLED_enInit(HLED_RED_ID);
	HLED_enInit(HLED_GREN_ID);
	HLED_enInit(HLED_BLUE_ID);
	HLCD_enInit();
	HBUZZ_enInit(HBUZZ_ID);

	/* Enable INT0 if SW in KIT2 is ON */
	MEXTI_enEnable(INT0_ID, FAILING_EDGE_TRIG);
	MEXTI_enSetCalBack(INT0_ID, ACTION1);
	MGIO_enEnable();

	while (1)
	{
		if(flag == 1)
		{
			HLCD_enGoToXY(1, 2);
			HLCD_enSendString("NORMAL MODE!");
			HBUZZ_enSetON(HBUZZ_ID);
			HLED_enToggle(HLED_RED_ID);
			HLED_enToggle(HLED_GREN_ID);
			HLED_enToggle(HLED_BLUE_ID);
			_delay_ms(500);
			/* if SW of KIT2 PRESSED, ACTIONS stop
			 * Flag = 0 and the ACTION OFF
			 */
			MDIO_enGetPinValue(PD2, &pinValue);
			if (pinValue == PB_PRESSED)
			{
				HLED_enSetOFF(HLED_RED_ID);
				HLED_enSetOFF(HLED_GREN_ID);
				HLED_enSetOFF(HLED_BLUE_ID);
				HBUZZ_enSetOFF(HBUZZ_ID);
				HLCD_enCLearDisplay();
				flag = 0;

				/* if SW of KIT2 is Pressed Again, Interrupt will be Disable forever
				 * only here it's infinite loop */
				while(flag == 0)
				{
					MDIO_enGetPinValue(PD2, &pinValue);
					if (pinValue == PB_PRESSED)
					{
						flag = 0;
						HLCD_enGoToXY(1, 2);
						HLCD_enSendString("STOP MODE!");
					}
				}

			}
		}
	}
#elif (APPLICATION == KIT2)
	//Intiallize SW OF KIT2
	PB_ST button1 = {HPB1_ID, PD0};
	HPB_enInit(&button1);
	while (1)
	{

	}

#endif
}
