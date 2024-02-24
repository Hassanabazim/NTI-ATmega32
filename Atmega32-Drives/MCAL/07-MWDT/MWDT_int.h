/*
 * MWDT_int.h
 *
 *  Created on: Jun 15, 2023
 *      Author: Hassa
 */

#ifndef _MWDT_INT_H_
#define _MWDT_INT_H_

#define MWDT_TIME_OUT_16_3_MS	0
#define MWDT_TIME_OUT_32_5_MS	1
#define MWDT_TIME_OUT_65_MS		2
#define MWDT_TIME_OUT_0_13_S	3
#define MWDT_TIME_OUT_0_26_S	4
#define MWDT_TIME_OUT_0_52_S	5
#define MWDT_TIME_OUT_1_0_S		6
#define MWDT_TIME_OUT_2_1_S		7


ErrorState_t MWDT_enEnable(void);
ErrorState_t MWDT_enDiable(void);
ErrorState_t MWDT_enSleep(u8 copy_u8TimeOut);
ErrorState_t MWDT_enRefresh(void);

#endif /* _MWDT_INT_H_ */
