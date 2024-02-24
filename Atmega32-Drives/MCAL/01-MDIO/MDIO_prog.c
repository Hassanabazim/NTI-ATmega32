/********************************************************************************
 * @file        		:  MADIO_prog.c	  				 						*
 * @Author 	 			:  HASSAN ABDELAZIM ABDELSALAM							*
 * @Version 			:  1.0.0							 					*
 * @Date				:  28/5/2023											*
 ********************************************************************************
 * @attention   Digital Input Output Driver Implementation for Atmega32
 *
 * 	#######################	 HOW TO USE THE DRIVER 	#########################
 *	The Driver has 7-APIs which support Port and Pin post-configuration either
 *	to configure the mood and the value of the operation and by it's paramters
 *  #hint Port and Pin Number configured together as @para to APIs
 *  as shown here
 *  1. SET PIN DIRECTION, 		2. SET PIN VALUE, 		3. GET PIN VALUE
 *	4. SET PORT DIRECTION,  	5. SET PORT VALUE,  	6. GET PORT VALUE
 *	7. TOGGLE PIN
 *
 *
 *********************************************************************************
 * INCLUDES
 ********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"
#include "MDIO_int.h"
#include "MDIO_config.h"
#include "MDIO_priv.h"


/********************************************************************************
 * APIs IMPLEMENTATION
 ********************************************************************************/
/*
 *	@brief		use to set pin direction either input or output
 *
 *	@para		copy_u8pin, copy_u8Dir
 *	@retval		ErrorStates (SUCCESS, OUT_OF_RANG_ERR)
 */

ErrorState_t MDIO_enSetPinDirection(MDIO_Pin_t copy_u8pin, MDIO_Direction_t copy_u8Dir)
{
	ErrorState_t Local_state = SUCCESS;

	/* 1. Get Port, pin value  */
	u8 Local_u8port = copy_u8pin / 10;
	u8 Local_u8pin = copy_u8pin % 10 ;

	/* 2. switch between portA till portD
	 *  check if Direction Input or Output,
	 *  if it input clear the bit, if it output set the bit */
	if (Local_u8port == PORTA)
	{

		switch(copy_u8Dir)
		{
		case INPUT:
			CLR_BIT(DDRA_REG,Local_u8pin);
			break;
		case OUTPUT:
			SET_BIT(DDRA_REG, Local_u8pin);
			break;
		default:
			Local_state = OUT_OF_RANG_ERR;
		}
	}

	else if (Local_u8port == PORTB)
	{
		switch(copy_u8Dir)
		{
		case INPUT:
			CLR_BIT(DDRB_REG,Local_u8pin);
			break;
		case OUTPUT:
			SET_BIT(DDRB_REG, Local_u8pin);
			break;
		default:
			Local_state = OUT_OF_RANG_ERR;
		}
	}

	else if (Local_u8port == PORTC)
	{
		switch(copy_u8Dir)
		{
		case INPUT:
			CLR_BIT(DDRC_REG,Local_u8pin);
			break;
		case OUTPUT:
			SET_BIT(DDRC_REG, Local_u8pin);
			break;
		default:
			Local_state = OUT_OF_RANG_ERR;
		}
	}
	else if (Local_u8port == PORTD)
	{
		switch(copy_u8Dir)
		{
		case INPUT:
			CLR_BIT(DDRD_REG,Local_u8pin);
			break;
		case OUTPUT:
			SET_BIT(DDRD_REG, Local_u8pin);
			break;
		default:
			Local_state = OUT_OF_RANG_ERR;
		}
	}

	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

/*
 *	@brief		use to set pin value either High or Low
 *
 *	@para		copy_u8Pin, copy_u8Value
 *	@retval		ErrorStates (SUCCESS, OUT_OF_RANG_ERR)
 */
ErrorState_t MDIO_enSetPinValue(MDIO_Pin_t copy_u8Pin, MDIO_Value_t copy_u8Value)
{
	ErrorState_t Local_state = SUCCESS;

	/* 1. Get Port, pin value  */
	u8 Local_u8port = copy_u8Pin / 10;
	u8 Local_u8pin = copy_u8Pin %10 ;


	/* 2. switch between portA till portD
	 *  check if Value High or Low, if it high Set the pin
	 *  and if low clear the pin 	*/
	if(Local_u8port == PORTA)
	{
		switch(copy_u8Value)
		{
		case LOW:
			CLR_BIT(PORTA_REG,Local_u8pin);
			break;
		case HIGH:
			SET_BIT(PORTA_REG,Local_u8pin);
			break;
		default:
			Local_state = OUT_OF_RANG_ERR;
		}
	}
	else if(Local_u8port == PORTB)
	{
		switch(copy_u8Value)
		{
		case LOW:
			CLR_BIT(PORTB_REG,Local_u8pin);
			break;
		case HIGH:
			SET_BIT(PORTB_REG,Local_u8pin);
			break;
		default:
			Local_state = OUT_OF_RANG_ERR;
		}
	}

	if(Local_u8port == PORTC)
	{
		switch(copy_u8Value)
		{
		case LOW:
			CLR_BIT(PORTC_REG,Local_u8pin);
			break;
		case HIGH:
			SET_BIT(PORTC_REG, Local_u8pin);
			break;
		default:
			Local_state = OUT_OF_RANG_ERR;
		}
	}

	if(Local_u8port == PORTD)
	{
		switch(copy_u8Value)
		{
		case LOW:
			CLR_BIT(PORTD_REG,Local_u8pin);
			break;
		case HIGH:
			SET_BIT(PORTD_REG, Local_u8pin);
			break;
		default:
			Local_state = OUT_OF_RANG_ERR;
		}
	}

	else
	{
		Local_state = OUT_OF_RANG_ERR;
	}

	return Local_state;
}


/*
 *	@brief		use to set port Direction either Input or Output
 *
 *	@para		copy_u8Port, copy_u8Dir
 *	@retval		ErrorStates (SUCCESS, OUT_OF_RANG_ERR)
 */
ErrorState_t MDIO_enSetPortDirection(MDIO_Port_t copy_u8Port, u8 copy_u8Dir)
{
	ErrorState_t Local_state = SUCCESS;

	/* switch bet portA till PortD and Assign the Mode into the DDRx Register*/
	switch (copy_u8Port)
	{
	case PORTA:
		DDRA_REG = copy_u8Dir;
		break;

	case PORTB:
		DDRB_REG = copy_u8Dir;
		break;

	case PORTC:
		DDRC_REG = copy_u8Dir;
		break;

	case PORTD:
		DDRD_REG = copy_u8Dir;
		break;

	default :
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

/*
 *	@brief		use to set port Value either High, Low
 *
 *	@para		copy_u8Port, copy_u8Value
 *	@retval		ErrorStates (SUCCESS, OUT_OF_RANG_ERR)
 */
ErrorState_t MDIO_enSetPortValue(MDIO_Port_t copy_u8Port, u8 copy_u8Value)
{
	ErrorState_t Local_state = SUCCESS;

	/* switch bet PortA till PortD and Assign the Value into PORTx Register*/
	switch (copy_u8Port)
	{
	case PORTA:
		PORTA_REG = copy_u8Value;
		break;

	case PORTB:
		PORTB_REG = copy_u8Value;
		break;

	case PORTC:
		PORTC_REG = copy_u8Value;
		break;

	case PORTD:
		PORTD_REG = copy_u8Value;
		break;

	default :
		Local_state = OUT_OF_RANG_ERR;
	}
	return Local_state;
}

/*
 *	@brief		use to toggle the Pin from high to low or vica versa
 *
 *	@para		copy_u8Pin
 *	@retval		ErrorStates (SUCCESS, OUT_OF_RANG_ERR)
 */
ErrorState_t MDIO_enTogglePin(MDIO_Pin_t copy_u8Pin)
{
	ErrorState_t Local_state = SUCCESS;

	/*1. get the Port, Pin number */
	u8 Local_u8port = copy_u8Pin / 10;
	u8 Local_u8pin = copy_u8Pin %10 ;

	/* 2. switch bet PortA till PortD and Toggle the Pin into The Portx Register*/
	switch (Local_u8port)
	{
	case PORTA:
		TOG_BIT(PORTA_REG,Local_u8pin);
		break;

	case PORTB:
		TOG_BIT(PORTB_REG,Local_u8pin);
		break;

	case PORTC:
		TOG_BIT(PORTC_REG,Local_u8pin);
		break;

	case PORTD:
		TOG_BIT(PORTD_REG,Local_u8pin);
		break;

	default :
		Local_state = OUT_OF_RANG_ERR;
	}

	return Local_state;
}

/*
 *	@brief		use to Get the Pin Value from PINx Register
 *
 *	@para		copy_u8Pin, *ptr_u8Value
 *	@retval		ErrorStates (SUCCESS, NULL_PTR_ERR)
 */
ErrorState_t MDIO_enGetPinValue(MDIO_Pin_t copy_u8Pin, u8 *ptr_u8Value)
{
	ErrorState_t Local_state = SUCCESS;
	if (ptr_u8Value != NULL)
	{
		/* 1. get the Port and Pin number */
		u8 Local_u8port = copy_u8Pin / 10;
		u8 Local_u8pin = copy_u8Pin %10 ;

		/* 2. switch bet PortA till PortD and get the Pin value
		 * from the PINx Register and store it in ptr_var
		 * and returned it by reference */
		switch (Local_u8port)
		{
		case PORTA:
			*ptr_u8Value = GET_BIT(PINA_REG,Local_u8pin);
			break;

		case PORTB:
			*ptr_u8Value = GET_BIT(PINB_REG,Local_u8pin);
			break;

		case PORTC:
			*ptr_u8Value = GET_BIT(PINC_REG,Local_u8pin);
			break;

		case PORTD:
			*ptr_u8Value = GET_BIT(PIND_REG,Local_u8pin);
			break;

		default :
			Local_state = OUT_OF_RANG_ERR;
		}
	}
	else
	{
		Local_state = NULL_PTR_ERR;
	}
	return Local_state ;
}

/*
 *	@brief		use to Get the PINx Register Value
 *
 *	@para		copy_u8Port, *ptr_u8Value
 *	@retval		ErrorStates (SUCCESS, NULL_PTR_ERR)
 */
ErrorState_t MDIO_enGetPortValue(MDIO_Port_t copy_u8Port, u8 *ptr_u8Value)
{
	ErrorState_t Local_state = SUCCESS;

	/* switch bet PortA till PortD and Store the Register value
	 * into the ptr_var and returned by reference*/
	if (ptr_u8Value != NULL)
	{
		switch (copy_u8Port)
		{
		case PORTA:
			*ptr_u8Value = PINA_REG;
			break;

		case PORTB:
			*ptr_u8Value = PINB_REG;
			break;

		case PORTC:
			*ptr_u8Value = PINC_REG;
			break;

		case PORTD:
			*ptr_u8Value = PIND_REG;
			break;

		default:
			Local_state = OUT_OF_RANG_ERR;
		}
	}

	else
	{
		Local_state = NULL_PTR_ERR;
	}

	return Local_state;
}

/********************************************************************************
 * END OF FILE	:	MDIO_prog.c
 ********************************************************************************/
