/*
 * HLCD_priv.h
 *
 *  Created on: Jun 1, 2023
 *      Author: Hassa
 */

#ifndef H20X4LCD_HLCD_PRIV_H_
#define H20X4LCD_HLCD_PRIV_H_


#define _4BIT_   	0
#define _8BIT_   	1


static void  H20X4LCD_voidNLatch(u8 copy_u8Byte);

#define  H20X4LCD_CLEAR  							0x01
#define  H20X4LCD_FUNCTION_SET_8BIT_2LINE  			0x38
#define  H20X4LCD_FUNCTION_SET_4BIT_2LINE  	 		0x28
#define  H20X4LCD_DISPLAY_ON_CURSOR_ON_BLINK_OFF 	0x0E
#define  H20X4LCD_ENTRY_MODE_SET_FUNCTION 			0x06



#endif /* H20X4LCD_HLCD_PRIV_H_ */
