/*
 * MEXTI_int.h
 *
 *  Created on: Jun 7, 2023
 *      Author: Hassa
 */


#ifndef _MEXTI_INT_H_
#define _MEXTI_INT_H_

typedef enum
{
	MEXTI_INT0_ID = 6,
	MEXTI_INT1_ID = 7,
	MEXTI_INT2_ID = 5
}MEXTI_ID_t;

typedef enum
{
	MEXTI_LOW_LEVEL = 0,
	MEXTI_ANY_CHANGE = 1,
	MEXTI_FAILING_EDGE = 2,
	MEXTI_RISING_EDGE = 3,
}MEXTI_Trigger_t;


ErrorState_t MEXTI_enEnable(MEXTI_ID_t copy_u8IntID, MEXTI_Trigger_t copy_u8IntTrig);
ErrorState_t MEXTI_enDisable(MEXTI_ID_t copy_u8IntID);
ErrorState_t MEXTI_enSetCalBack(MEXTI_ID_t copy_u8IntID, void(*ptrfn)(void));


#endif /* _MEXTI_INT_H_ */
