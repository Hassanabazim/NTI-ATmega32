/********************************************************************************
* 	@file        		:  MUSART_config.h							 			*
*	@Author 	 		:  HASSAN ABDELAZIM ABDELSALAM							*
*	@Version 			:  1.0.0							 					*
*	@Date				:  20/06/2023											*
*********************************************************************************
*  HEADER GAURD
********************************************************************************/
#ifndef _MUSART_CONFIG_H_
#define _MUSART_CONFIG_H_

#define FCPU						16000000UL
#define MUSART_TXBUFFER_SIZE		25
#define MUSART_RXBUFFER_SIZE		25
#define MUSART_END_LINE				'#'

/********************************************************************************
* PLEASE CHOOSE USART WIRE MODE FROM THE FOLLOWING:
*
*	MUSART_PARITY_DISABLE
* 	MUSART_PARITY_EVEN
*	MUSART_PARITY_ODD
********************************************************************************/
#define MUSART_PARITY_MODE		MUSART_PARITY_DISABLE



/********************************************************************************
* PLEASE CHOOSE USART DATA SIZE FROM THE FOLLOWING:
*
*	MUSART_5BIT_DATA
*	MUSART_6BIT_DATA
* 	MUSART_7BIT_DATA
* 	MUSART_8BIT_DATA
*	MUSART_9BIT_DATA
********************************************************************************/
#define MUSART_DATA_SIZE		MUSART_8BIT_DATA


/********************************************************************************
* PLEASE CHOOSE USART STOP BIT NUMBER FROM THE FOLLOWING:
*
*	MUSART_STOPBIT1
* 	MUSART_STOPBIT2
*
********************************************************************************/
#define MUSART_STOPBIT_NUM		MUSART_STOPBIT1



/********************************************************************************
* PLEASE CHOOSE USART BAUDRATE FROM THE FOLLOWING:
*
*	MUSART_BAUDRATE_1200
*	MUSART_BAUDRATE_2400
*	MUSART_BAUDRATE_4800
*	MUSART_BAUDRATE_9600
*	MUSART_BAUDRATE_19200
*	MUSART_BAUDRATE_115200
********************************************************************************/
#define MUSART_BAUDRATE			MUSART_BAUDRATE_9600



#endif /* _MUSART_CONFIG_H_ */
