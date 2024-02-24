/*
 * HLCD_int.h
 *
 *  Created on: Jun 1, 2023
 *      Author: Hassa
 */

#ifndef HLCD_HLCD_INT_H_
#define HLCD_HLCD_INT_H_

ErrorState_t HLCD_enInit(void);
ErrorState_t HLCD_enSendData(uint8_t copy_u8Data);
ErrorState_t HLCD_enSendCommand(uint8_t copy_u8Command);
ErrorState_t HLCD_enSendString(const char * str);
ErrorState_t HLCD_enCLearDisplay(void);
ErrorState_t HLCD_enSendIntNum(int32_t copy_32Num);
ErrorState_t HLCD_enGoToXY(uint8_t copy_u8X , uint8_t copy_u8Y);
ErrorState_t HLCD_CustomChar(uint8_t copy_u8loc, uint8_t *str);


#endif /* HLCD_HLCD_INT_H_ */
