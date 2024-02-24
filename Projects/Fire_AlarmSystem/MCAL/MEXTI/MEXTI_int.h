/*
 * MEXTI_int.h
 *
 *  Created on: Jun 7, 2023
 *      Author: Hassa
 */


#ifndef MEXTI_MEXTI_INT_H_
#define MEXTI_MEXTI_INT_H_

typedef enum
{
	INT0_ID = 6,
	INT1_ID = 7,
	INT2_ID = 5
}Interrupt_t;

typedef enum
{
	LOW_LEVEL_TRIG = 0,
	ANY_CHANGE_TRIG = 1,
	FAILING_EDGE_TRIG = 2,
	RISING_EDGE_TRI = 3,
}IntTrigger_t;


ErrorState_t MEXTI_enEnable(Interrupt_t copy_enID, IntTrigger_t copy_enTrig);
ErrorState_t MEXTI_enDisable(Interrupt_t copy_enID);
ErrorState_t MEXTI_enSetCalBack(Interrupt_t copy_enID, void(*ptrfn)(void));

#endif /* MEXTI_MEXTI_INT_H_ */
