/*
 * HPB_int.h
 *
 *  Created on: Jun 5, 2023
 *      Author: Hassa
 */

#ifndef HPB_HPB_INT_H_
#define HPB_HPB_INT_H_

#include "MDIO_int.h"
typedef enum
{
	PB_PRESSED  ,
	PB_RELEASED
}PBState_t;

typedef enum
{
	HPB1_ID = 1,
	HPB2_ID,
	HPB3_ID,
	HPB4_ID,
}PBID_t;

typedef enum
{
	ACTIVE_LOW,
	ACTIVE_HIGH
}PBMOD_t;
typedef struct
{
	PBID_t PB_ID;
	Pin_t PB_PIN;
	PBMOD_t PB_MODE;
}PB_ST;

ErrorState_t HPB_enInit(PB_ST *ptrPB);
ErrorState_t HPB_enRead(PB_ST *ptrPB, PBState_t * ptrPBState);

#endif /* HPB_HPB_INT_H_ */
