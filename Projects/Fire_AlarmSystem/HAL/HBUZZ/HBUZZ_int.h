/*
 * HBUZZ_int.h
 *
 *  Created on: Jun 3, 2023
 *      Author: Hassa
 */

#ifndef HBUZZ_HBUZZ_INT_H_
#define HBUZZ_HBUZZ_INT_H_

#define HBUZZ_ID  1

ErrorState_t HBUZZ_enInit(uint8_t copy_u8BuzzID);
ErrorState_t HBUZZ_enSetON(uint8_t copy_u8BuzzID);
ErrorState_t HBUZZ_enSetOFF(uint8_t copy_u8BuzzID);
ErrorState_t HBUZZ_enSetONCE(uint8_t copy_u8BuzzID);
ErrorState_t HBUZZ_enSetNum(uint8_t copy_u8BuzzID, uint8_t copy_u8num);




#endif /* HBUZZ_HBUZZ_INT_H_ */
