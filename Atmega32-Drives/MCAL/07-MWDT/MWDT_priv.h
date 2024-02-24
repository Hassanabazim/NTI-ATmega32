/*
 * MWDT_priv.h
 *
 *  Created on: Jun 15, 2023
 *      Author: Hassa
 */

#ifndef _MWDT_PRIV_H_
#define _MWDT_PRIV_H_


#define WDTCR_REG 	(*((volatile u8*)0x41))

#define WDTOE	4 	 // WATCHDOG ENABLE
#define WDE 	3 	// WATCHDOG TURN OFF ENABLE
#define WDP2	2
#define WDP1	1
#define WDP0	0

#define MWDT_PRESCALER_MASK 	0xF8

#endif /* _MWDT_PRIV_H_ */
