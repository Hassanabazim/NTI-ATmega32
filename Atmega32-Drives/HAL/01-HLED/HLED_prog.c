/********************************************************************************
 * @file        		:  HLED_prog.c					 						*
 * @Author 	 			:  HASSAN ABDELAZIM ABDELSALAM							*
 * @Version 			:  1.0.0							 					*
 * @Date				:  31/05/2023											*
 ********************************************************************************
 * @attention	LED Driver Implementation for Atmega32
 *
 * #######################	 HOW TO USE THE DRIVER 	#########################
 *	The Driver has 4-APIs Buzz supported by pre-configuration DIO Pins
 *  Assign the mood and the operation, as shown
 *
 * 		 1. LED INIT					2. LED ON
 *		 3. LED OFF						4.LED TOGGLE
 *********************************************************************************
 * INCLUDES
 ********************************************************************************/
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MDIO_int.h"
#include "HLED_int.h"
#include "HLED_config.h"
#include "HLED_priv.h"


/********************************************************************************
 * APIs IMPLEMENTATION
 ********************************************************************************/
/*
 *	@brief		Initilization LED Mood of operation
 *
 *	@para		copyu8_LedID
 *	@retval		SUCCESS, OUT_OF_RANG_ERR
 */
ErrorState_t HLED_enInit(u8 copyu8_LedID)
{
	ErrorState_t Local_state = SUCCESS;

	/* SET the Led pin as output */
	if ((copyu8_LedID <= PD7) && (copyu8_LedID >= PA0))
	{
		MDIO_enSetPinDirection(copyu8_LedID, OUTPUT);
	}
	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

/*
 *	@brief		TURN ON LED PIN Based on the Direction of the LED
 *
 *	@para		copyu8_LedID
 *	@retval		SUCCESS, OUT_OF_RANG_ERR
 */
ErrorState_t HLED_enSetON(u8 copyu8_LedID)
{
	ErrorState_t Local_state = SUCCESS;

	if ((copyu8_LedID <= PD7) && (copyu8_LedID >= PA0))
	{
		/* LED Direction Forward, Set LED pin as HIGH */
#if(HLED_DIR_MODE == HLED_DIR_FORWARD)
		MDIO_enSetPinValue(copyu8_LedID, HIGH);

		/* LED Direction Reverse, SET LED pin as HIGH */
#elif (HLED_DIR_MODE == HLED_DIR_REVERSE)
		MDIO_enSetPinValue(copyu8_LedID, LOW);
#else
#error ("WRONG LED DIRECTION")
#endif
	}
	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}

	return Local_state;
}

/*
 *	@brief		TURN OFF LED PIN Based on the Direction of the LED
 *
 *	@para		copyu8_LedID
 *	@retval		SUCCESS, OUT_OF_RANG_ERR
 */
ErrorState_t HLED_enSetOFF(u8 copyu8_LedID)
{
	ErrorState_t Local_state = SUCCESS;

	if ((copyu8_LedID <= PD7) && (copyu8_LedID >= PA0))
	{
		/* LED Direction Forward, Set LED pin as LOW */
#if(HLED_DIR_MODE == HLED_DIR_FORWARD)
		MDIO_enSetPinValue(copyu8_LedID, LOW);

		/* LED Direction Reverse, Set LED pin as HIGH */
#elif (HLED_DIR_MODE == HLED_DIR_REVERSE)
		MDIO_enSetPinValue(copyu8_LedID, HIGH);
#else
#error ("WRONG LED DIRECTION")
#endif
	}

	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

/*
 *	@brief		TOGGLE LED PIN [HIGH-LOW] and Visca Versa
 *
 *	@para		copyu8_LedID
 *	@retval		SUCCESS, OUT_OF_RANG_ERR
 */
ErrorState_t HLED_enToggle(u8 copyu8_LedID)
{
	ErrorState_t Local_state = SUCCESS;

	/* Toggle the LED PIN */
	if ((copyu8_LedID <= PD7) && (copyu8_LedID >= PA0))
	{
		MDIO_enTogglePin(copyu8_LedID);
	}

	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}

	return Local_state;
}

/********************************************************************************
 * END OF FILE	:	HLED_prog.c
 ********************************************************************************/
