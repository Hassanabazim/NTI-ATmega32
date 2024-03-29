/*
 * MTIEMR0_int.h
 *
 *  Created on: Jun 11, 2023
 *      Author: Hassa
 */

#ifndef _MTIMER0_INT_H_
#define _MTIMER0_INT_H_

//prebuild config



#define MTIMER0_OVF_INT_ID	0
#define MTIMER0_COM_INT_ID	1


ErrorState_t MTIMER0_enInit(void);
ErrorState_t MTIMER0_enStart(void);
ErrorState_t MTIMER0_enStop(void);
ErrorState_t MTIMER0_enSetCallBack(u8 copy_u8Int_ID,void (*ptrfn)(void));
ErrorState_t MTIMER0_enSetTime(u32 copy_u32delayMS);
ErrorState_t MTIMER0_enEnableInt(u8 copy_u8Int_ID);
ErrorState_t MTIMER0_enDisableInt(u8 copy_u8Int_ID);
ErrorState_t MTIMER0_enSetCompareValue(u8 copy_u8Value);

#if (MTIMER0_MODE==MTIMER0_FAST_PWM_MODE)
ErrorState_t MTIMER0_enSetFastPWM(u8 copy_u8Duty);
#elif(MTIMER0_MODE == MTIMER0_PHASE_CORRECT_MODE)
ErrorState_t MTIMER0_enSetPhaseCorrectPWM(u8 copy_u8Duty);
#endif













#endif /* 04_MTIMER0_MTIMER0_INT_H_ */
