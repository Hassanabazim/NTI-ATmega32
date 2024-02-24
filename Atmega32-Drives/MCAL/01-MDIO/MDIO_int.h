/********************************************************************************
* 	@file        		:  MDIO_int.h				 							*
*	@Author 	 		:  HASSAN ABDELAZIM ABDELSALAM							*
*	@Version 			:  1.0.0							 					*
*	@Date				:  28/05/2023											*
*********************************************************************************
*  HEADER GAURD
********************************************************************************/
#ifndef _MDIO_INT_H_
#define _MDIO_INT_H_

/********************************************************************************
* INTERFACE MACROS CONFIGURATION
********************************************************************************/
#define MDIO_PORT_INPUT		0x00
#define MDIO_PORT_OUTPUT	0xFF
#define MDIO_PORT_LOW		0x00
#define MDIO_PORT_HIGH		0xFF


/********************************************************************************
* typedefs Enum
********************************************************************************/
typedef enum {
	PA0 = 10, PA1, PA2, PA3, PA4, PA5, PA6, PA7,
	PB0 = 20, PB1, PB2, PB3, PB4, PB5, PB6, PB7,
	PC0 = 30, PC1, PC2, PC3, PC4, PC5, PC6, PC7,
	PD0 = 40, PD1, PD2, PD3, PD4, PD5, PD6, PD7,
}MDIO_Pin_t;

typedef enum {
	PORTA = 1,
	PORTB,
	PORTC,
	PORTD,
}MDIO_Port_t;

typedef enum {
	LOW,
	HIGH
}MDIO_Value_t;

typedef enum {
	INPUT,
	OUTPUT
}MDIO_Direction_t;


/********************************************************************************
* APIs Prototypes
********************************************************************************/

ErrorState_t MDIO_enSetPinDirection(MDIO_Pin_t copy_u8pin, MDIO_Direction_t copy_u8Dir);
/********************************************************************************
* @fun name			:  	MDIO_enSetPinDirection									*
* @para 	 		:  	copy_u8pin, copy_u8Dir									*
* @retval 			:  	ErrorStates(SUCCESS, OUT_OF_RANG_ERR)					*
* @Description      :  	Set Pin Direction (INPUT, OUTPUT)						*															*
********************************************************************************/


ErrorState_t MDIO_enSetPinValue(MDIO_Pin_t copy_u8Pin, MDIO_Value_t copy_u8Value);
/********************************************************************************
* @fun name			:	MDIO_enSetPinValue										*
* @para 	 		:  	copy_u8Pin, copy_u8Value								*
* @retval 			:  	ErrorStates(SUCCESS, OUT_OF_RANG_ERR)					*
* @Description      :  	Set Pin Value (LOW, HIGH)								*															*
********************************************************************************/


ErrorState_t MDIO_enSetPortDirection(MDIO_Port_t copy_u8Port, u8 copy_u8Dir);
/********************************************************************************
* @fun name			:  	MDIO_enSetPortDirection									*
* @para 	 		:  	copy_u8Port, copy_u8Dir									*
* @retval 			:  	ErrorStates(SUCCESS, OUT_OF_RANG_ERR)					*
* @Description      :  	Set Port Direction (INPUT, OUTPUT)						*															*
********************************************************************************/


ErrorState_t MDIO_enSetPortValue(MDIO_Port_t copy_u8Port, u8 copy_u8Value);
/********************************************************************************
* @fun name			:  MDIO_enSetPortValue										*
* @para 	 		:  copy_u8Port, copy_u8Value								*
* @retval 			:  ErrorStates(SUCCESS, OUT_OF_RANG_ERR)					*
* @Description      :  Set Port Value (0xHEX)									*															*
********************************************************************************/


ErrorState_t MDIO_enTogglePin(MDIO_Pin_t copy_u8Pin);
/********************************************************************************
* @fun name			:  	MDIO_enTogglePin										*
* @para 	 		:  	copy_u8Pin												*
* @retval 			:  	ErrorStates(SUCCESS, OUT_OF_RANG_ERR)					*
* @Description      :  	Toggle Pin Value [HIGH - LOW]							*															*
********************************************************************************/


ErrorState_t MDIO_enGetPinValue(MDIO_Pin_t copy_u8Pin, u8 *ptr_u8Value);
/********************************************************************************
* @fun name			:  	MDIO_enGetPinValue										*
* @para 	 		:  	copy_u8Pin, ptr_u8Value									*
* @retval 			:  	ErrorStates(SUCCESS, NULL_PTR_ERR)						*
* @Description      :  	GET Pin Value From PINx Register 						*															*
********************************************************************************/


ErrorState_t MDIO_enGetPortValue(MDIO_Port_t copy_u8Port, u8 *ptr_u8Value);
/********************************************************************************
* @fun name			:  	MDIO_enGetPortValue										*
* @para 	 		:  	copy_u8Port, ptr_u8Value								*
* @retval 			:  	ErrorStates(SUCCESS, NULL_PTR_ERR)						*
* @Description      :  	GET PINx Value 											*															*
********************************************************************************/






#endif /* _MDIO_INT_H_ */

/********************************************************************************
 * END OF FILE	:	MDIO_int.h
 ********************************************************************************/
