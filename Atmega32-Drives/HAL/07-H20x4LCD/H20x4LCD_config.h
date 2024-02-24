/*
 * HLCD_config.h
 *
 *  Created on: Jun 1, 2023
 *      Author: Hassa
 */

#ifndef H16X2LCD_H20X4LCD_CONFIG_H_
#define H20X4LCD_H20X4LCD_CONFIG_H_

#define H20X4LCD_MODE   	_4BIT_

#define H20X4LCD_RS_PIN   	PA3
#define H20X4LCD_EN_PIN   	PA2
#define H20X4LCD_RW_PIN


#define H20X4LCD_D4_PIN   	PB0
#define H20X4LCD_D5_PIN   	PB1
#define H20X4LCD_D6_PIN   	PB2
#define H20X4LCD_D7_PIN   	PB4

#if(H20X4LCD_MODE == _8BIT_)
#define H20X4LCD_D0_PIN	  	PB0
#define H20X4LCD_D1_PIN	  	PB1
#define H20X4LCD_D2_PIN	  	PB2
#define H20X4LCD_D3_PIN	  	PB3
#endif

#endif /* H20X4LCD_H20X4LCD_CONFIG_H_ */
