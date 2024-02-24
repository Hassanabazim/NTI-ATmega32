/********************************************************************************
* 	@file        		:  MDIO_priv.h				 							*
*	@Author 	 		:  HASSAN ABDELAZIM ABDELSALAM							*
*	@Version 			:  1.0.0							 					*
*	@Date				:  28/05/2023											*
*********************************************************************************
*  HEADER GAURD
********************************************************************************/
#ifndef _MDIO_PRIV_H_
#define _MDIO_PRIV_H_


/********************************************************************************
* DIO REGISTERS
********************************************************************************/

//PORT A Registers
#define PORTA_REG 	 	(*((volatile u8*)0x3B))
#define DDRA_REG  		(*((volatile u8*)0x3A))
#define PINA_REG  		(*((volatile u8*)0x39))

// PORT B Registers
#define PORTB_REG	 	(*((volatile u8*)0x38))
#define DDRB_REG  		(*((volatile u8*)0x37))
#define PINB_REG 		(*((volatile u8*)0x36))

// PORT C Registers
#define PORTC_REG		(*((volatile u8*)0x35))
#define DDRC_REG  		(*((volatile u8*)0x34))
#define PINC_REG  		(*((volatile u8*)0x33))

// PORT D Registers
#define PORTD_REG		(*((volatile u8*)0x32))
#define DDRD_REG		(*((volatile u8*)0x31))
#define PIND_REG  		(*((volatile u8*)0x30))




#endif /* _MDIO_PRIV_H_ */

/********************************************************************************
 * END OF FILE	:	MDIO_priv.h
 ********************************************************************************/
