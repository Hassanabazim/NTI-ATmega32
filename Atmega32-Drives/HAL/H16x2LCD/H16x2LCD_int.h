/*
 * HLCD_int.h
 *
 *  Created on: Jun 1, 2023
 *      Author: Hassa
 */

#ifndef H16X2LCD_H16X2LCD_INT_H_
#define H16X2LCD_H16X2LCD_INT_H_


ErrorState_t H16X2LCD_enInit(void);
ErrorState_t H16X2LCD_enSendData(u8 copy_u8Data);
/**
 * @fn ErrorState_t H16X2LCD_enSendCommand(u8)
 * @brief
 *
 * @param copy_u8Command
 * @return
 */
ErrorState_t H16X2LCD_enSendCommand(u8 copy_u8Command);
ErrorState_t H16X2LCD_enSendString(const char *str);
ErrorState_t H16X2LCD_enCLearDisplay(void);
ErrorState_t H16X2LCD_enSendIntNum(s32 copy_s32Num);
ErrorState_t H16X2LCD_enGoToXY(u8 copy_u8X, u8 copy_u8Y);
ErrorState_t H16X2LCD_CustomChar(u8 copy_u8loc, u8 *str);

#endif /* H16X2LCD_H16X2LCD_INT_H_ */
