/*
 * HLED_int.h
 *
 *  Created on: May 31, 2023
 *      Author: Hassan
 */

#ifndef HLED_HLED_INT_H_
#define HLED_HLED_INT_H_


#define	HLED_RED_ID 1
#define HLED_GREN_ID 2
#define HLED_BLUE_ID 3


ErrorState_t HLED_enInit(uint8_t copyu8_LedID);
ErrorState_t HLED_enSetON(uint8_t copyu8_LedID);
ErrorState_t HLED_enSetOFF(uint8_t copyu8_LedID);
ErrorState_t HLED_enToggle(uint8_t copyu8_LedID);



#endif /* HLED_HLED_INT_H_ */
