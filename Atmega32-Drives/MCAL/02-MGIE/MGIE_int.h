/*
 * MGIO_int.h
 *
 *  Created on: Jun 7, 2023
 *      Author: Hassa
 */

#ifndef _MGIE_INT_H_
#define _MGIE_INT_H_



#define EXT_INT_0 		__vector_1
#define EXT_INT_1 		__vector_2
#define EXT_INT_2 		__vector_3
#define TIMER1_ICU 		__vector_6
#define TIMER1_OVF 		__vector_9
#define TIMER0_COMP 	__vector_10
#define TIMER0_OVF 		__vector_11
#define SPI_STC			__vector_12
#define USART_RXC		__vector_13
#define USART_UDRE		__vector_14
#define USART_TXC		__vector_15
#define ADC_INT			__vector_16
#define TWI_INT			__vector_19

//ISR definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

ErrorState_t MGIE_enEnable(void);
ErrorState_t MGIE_enDisable(void);


#endif /* _MGIE_INT_H_ */
