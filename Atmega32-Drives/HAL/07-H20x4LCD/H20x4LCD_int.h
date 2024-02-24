/*
 * HLCD_int.h
 *
 *  Created on: Jun 1, 2023
 *      Author: Hassa
 */

#ifndef H20X4LCD_H20X4LCD_INT_H_
#define H20X4LCD_H20X4LCD_INT_H_




ErrorState_t  H20X4LCD_enInit(void);
ErrorState_t  H20X4LCD_enSendData(u8 copy_u8Data);
ErrorState_t  H20X4LCD_enSendCommand(u8 copy_u8Command);
ErrorState_t  H20X4LCD_enSendString(const char* str);
ErrorState_t  H20X4LCD_enCLearDisplay(void);
ErrorState_t  H20X4LCD_enSendIntNum(s32 copy_s32Num);
ErrorState_t  H20X4LCD_enGoToXY(u8 copy_u8X , u8 copy_u8Y);
ErrorState_t  H20X4LCD_CustomChar(u8 copy_u8loc, u8 *str);


#endif /* H20X4LCD_H20X4LCD_INT_H_ */
