/********************************************************************************
* 	@file        		:  MUSART_priv.h							 			*
*	@Author 	 		:  HASSAN ABDELAZIM ABDELSALAM							*
*	@Version 			:  1.0.0							 					*
*	@Date				:  20/06/2023											*
*********************************************************************************
*  HEADER GAURD
********************************************************************************/
#ifndef _MUSART_PRIV_H_
#define _MUSART_PRIV_H_

/********************************************************************************
* USART REGISTER ADDRESS
********************************************************************************/
#define	UDR_REG		 	(*((volatile u8*)0x2C)) //I/O Data Register
#define UCSRA_REG		(*((volatile u8*)0x2B))	//Control and Status Register A
#define UCSRB_REG		(*((volatile u8*)0x2A))	//Control and Status Register B
#define UCSRC_REG		(*((volatile u8*)0x40))	//Control and Status Register C
#define UBRRH_REG		(*((volatile u8*)0x40))	//Baud Rate Registers
#define UBRRL_REG		(*((volatile u8*)0x29))	//Baud Rate Registers



/********************************************************************************
* MOST USED REGISTER PINS
********************************************************************************/

// UCSRA REGISTER PINS
#define RXC		7	// USART Receive Complete
#define TXC		6	// USART Transmit Complete
#define UDRE	5	// USART Data Register Empty
#define FE		4	// Frame Error
#define DOR		3	// Data OverRun
#define PE		2	// Parity Error
#define U2X		1	// Double the USART Transmission Speed

// UCSRB REGISTER PINS
#define RXEN	4	// Receiver Enable
#define TXEN	3	// Transmitter Enable
#define UCSZ2	2	// Character Size
#define RXB8 	1	// Receive Data Bit 8
#define TXB8 	0	// Transmit Data Bit 8

// UCSRC REGISTER PINS
#define URSEL	7	//Register Select
#define UMSEL	6	// USART Mode Select
#define USBS	3	// Stop Bit Select


/********************************************************************************
* PRIVATE MACROS CONFIGURATION
********************************************************************************/

#define MUSART_NULL_CHR					'\0'

// PRE FRAME CONGIFURATION
#define MUSART_PARITY_DISABLE		0
#define MUSART_PARITY_EVEN			2
#define MUSART_PARITY_ODD			3

#define MUSART_5BIT_DATA			0
#define MUSART_6BIT_DATA			1
#define MUSART_7BIT_DATA			2
#define MUSART_8BIT_DATA			3
#define MUSART_9BIT_DATA			7

#define MUSART_STOPBIT1				0
#define MUSART_STOPBIT2				1

#define MUSART_BAUDRATE_1200	(0x340)
#define MUSART_BAUDRATE_2400	(0x19F)
#define MUSART_BAUDRATE_4800	(0xCF)
#define MUSART_BAUDRATE_9600	(0x67)
#define MUSART_BAUDRATE_19200	(0x51)
#define MUSART_BAUDRATE_115200	(0x7)


/********************************************************************************
*  PRIVATE MACROS MASKS
********************************************************************************/

#define MUSART_PARITY_MASK		0XCF
#define MUSART_DATASIZE_MASK	0xF9




#endif /* _MUSART_PRIV_H_ */
