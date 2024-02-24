/*
 * HTEMP_int.h
 *
 *  Created on: Jun 13, 2023
 *      Author: Hassa
 */

#ifndef HLM35_HLM35_INT_H_
#define HLM35_HLM35_INT_H_


ErrorState_t HLM35_enInit(void);
ErrorState_t HLM35_enTempRead(u8 *pTempValue);



#endif /* HLM35_HLM35_INT_H_ */
