/********************************************************************************
 * @file        		:  HBUZZ_prog.c					 						*
 * @Author 	 			:  HASSAN ABDELAZIM ABDELSALAM							*
 * @Version 			:  1.0.0							 					*
 * @Description			:  03/06/2023											*
 ********************************************************************************
 * @attention   BUZZER Driver Implementation for Atmega32
 *
 *	#######################	 HOW TO USE THE DRIVER 	#########################
 *	The Driver has 5-APIs Buzz supported by pre-configuration DIO Pins
 *  Assign the mood and the operation, as shown
 *
 *  1. BUZZER INIT				2. BUZZER ON 			3. BUZZER OFF
 *	4. BUZZER SET ONCE  		5. BUZZER SET BY NUMS
 *
 *********************************************************************************
 * INCLUDES
 ********************************************************************************/
#include <util/delay.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MDIO_int.h"
#include "HBUZZ_int.h"
#include "HBUZZ_config.h"
#include "HBUZZ_priv.h"


/********************************************************************************
 * APIs IMPLEMENTATION
 ********************************************************************************/
/*
 *	@brief		Initilize the Buzzer Mood of Operation
 *
 *
 *	@para		copy_u8BuzzID
 *	@retval		SUCCESS, OUT_OF_RANG_ERR
 */
ErrorState_t HBUZZ_enInit(u8 copy_u8BuzzID)
{
	ErrorState_t Local_state = SUCCESS;

	if ((copy_u8BuzzID <= PD7) && (copy_u8BuzzID >= PA0))
	{
		/* configure the mood of operation as an output */
		MDIO_enSetPinDirection(copy_u8BuzzID, OUTPUT);
	}
	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

/*
 *	@brief		Turn on the Buzzer
 *
 *	@para		copy_u8BuzzID
 *	@retval		SUCCESS, OUT_OF_RANG_ERR
 */
ErrorState_t HBUZZ_enSetON(u8 copy_u8BuzzID)
{
	ErrorState_t Local_state = SUCCESS;
	if ((copy_u8BuzzID <= PD7) && (copy_u8BuzzID >= PA0))
	{
		/* set the Buzzer Pin as High*/
		MDIO_enSetPinValue(copy_u8BuzzID, HIGH);
	}
	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}


/*
 *	@brief		Turn OFF the Buzzer
 *
 *	@para		copy_u8BuzzID
 *	@retval		SUCCESS, OUT_OF_RANG_ERR
 */
ErrorState_t HBUZZ_enSetOFF(u8 copy_u8BuzzID)
{
	ErrorState_t Local_state = SUCCESS;

	if ((copy_u8BuzzID <= PD7) && (copy_u8BuzzID >= PA0))
	{
		/* Set the Buzzer Pin as LOW */
		MDIO_enSetPinValue(copy_u8BuzzID, LOW);
	}
	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}


/*
 *	@brief		Turn on the Buzzer One time
 *				by set High, Low with Delay 1 second
 *	@para		copy_u8BuzzID
 *	@retval
 */
ErrorState_t HBUZZ_enSetONCE(u8 copy_u8BuzzID)
{
	ErrorState_t Local_state = SUCCESS;
	if ((copy_u8BuzzID <= PD7) && (copy_u8BuzzID >= PA0))
	{
		/* 1. Set the Buzzer Pin As High */
		MDIO_enSetPinValue(copy_u8BuzzID, HIGH);

		/* 2. predefined Delay using SW delay */
		_delay_ms(1000);

		/* 3. Clear the Buzzer Pin as Low */
		MDIO_enSetPinValue(copy_u8BuzzID, LOW);
	}
	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

/*
 *	@brief		Turn on the Buzzer over number of times
 *
 *	@para		copy_u8BuzzID, copy_u8num
 *	@retval
 */
ErrorState_t HBUZZ_enSetNum(u8 copy_u8BuzzID, u8 copy_u8num)
{
	ErrorState_t Local_state = SUCCESS;
	if ((copy_u8BuzzID <= PD7) && (copy_u8BuzzID >= PA0))
	{
		for (u8 i = 0; i < copy_u8num; i++)
		{
			/* 1. Set the Buzzer Pin As High */
			MDIO_enSetPinValue(copy_u8BuzzID, HIGH);
			/* 2. predefined Delay using SW delay */
			_delay_ms(1000);

			/* 3. Clear the Buzzer Pin as Low */
			MDIO_enSetPinValue(copy_u8BuzzID, LOW);
			/* 4. predefined Delay using SW delay */
			_delay_ms(1000);
		}
	}
	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}

	return Local_state;
}

/********************************************************************************
 * END OF FILE	:	HBUZZ_prog.c
 ********************************************************************************/
