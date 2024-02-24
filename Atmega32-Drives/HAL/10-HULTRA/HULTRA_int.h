/*
 * HULTRASONIC_int.h
 *
 *  Created on: Jun 21, 2023
 *      Author: Hassa
 */

#ifndef HULTRA_HULTRA_INT_H_
#define HULTRA_HULTRA_INT_H_

typedef enum{
	STATE1=1,
	STATE2,
	STATE3
}StateMachine_t;

ErrorState_t HULTRASONIC_enInit(void);
ErrorState_t HULTRASONIC_enRead(u32 *ptrValue);

#endif /* HULTRA_HULTRA_INT_H_ */
