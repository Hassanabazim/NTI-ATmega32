/*
 * MTIEMR0_int.h
 *
 *  Created on: Jun 11, 2023
 *      Author: Hassa
 */

#ifndef MTIMER0_MTIMR0_INT_H_
#define MTIMER0_MTIMR0_INT_H_

//prebuild config

#define MTIMER0_OVF_INT_ID	0
#define MTIMER0_COM_INT_ID	1


ErrorState_t MTIMER0_enInit(void);
ErrorState_t MTIMER0_enStart(void);
ErrorState_t MTIMER0_enStop(void);
ErrorState_t MTIMER0_enSetCallBack(uint8_t copy_u8Int_ID,void (*ptrfn)(void));
ErrorState_t MTIMER0_enSetTime(uint32_t copy_u32delayMS);
ErrorState_t MTIMER0_enEnableInt(uint8_t copy_u8Int_ID);
ErrorState_t MTIMER0_enDisableInt(uint8_t copy_u8Int_ID);
ErrorState_t MTIMER0_enSetCompareValue(uint8_t copy_u8Value);

#if (MTIMER0_MODE==MTIMER0_FAST_PWM_MODE)
ErrorState_t MTIMER0_enSetFastPWM(uint8_t copy_u8Duty);
#elif(MTIMER0_MODE == MTIMER0_PHASE_CORRECT_MODE)
ErrorState_t MTIMER0_enSetPhaseCorrectPWM(uint8_t copy_u8Duty);
#endif













#endif /* MTIMER0_MTIMR0_INT_H_ */
