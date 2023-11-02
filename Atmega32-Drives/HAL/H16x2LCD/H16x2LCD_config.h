/*
 * HLCD_config.h
 *
 *  Created on: Jun 1, 2023
 *      Author: Hassa
 */

#ifndef H16X2LCD_H16X2LCD_CONFIG_H_
#define H16X2LCD_H16X2LCD_CONFIG_H_

#define H16X2LCD_MODE   	_4BIT_

#define H16X2LCD_RS_PIN   	PA3
#define H16X2LCD_EN_PIN   	PA2
#define H16X2LCD_RW_PIN


#define H16X2LCD_D4_PIN   	PB0
#define H16X2LCD_D5_PIN   	PB1
#define H16X2LCD_D6_PIN   	PB2
#define H16X2LCD_D7_PIN   	PB4

#if(H16X2LCD_MODE == _8BIT_)
#define H16X2LCD_D0_PIN	  	PB0
#define H16X2LCD_D1_PIN	  	PB1
#define H16X2LCD_D2_PIN	  	PB2
#define H16X2LCD_D3_PIN	  	PB3
#endif

#endif /* H16X2LCD_H16X2LCD_CONFIG_H_ */
