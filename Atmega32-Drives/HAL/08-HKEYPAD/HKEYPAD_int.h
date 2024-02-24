/*
 * HKEYPAD_int.h
 *
 *  Created on: May 31, 2023
 *      Author: Hassan
 */

#ifndef HKEYPAD_HKEYPAD_INT_H_
#define HKEYPAD_HKEYPAD_INT_H_

/*  NO_KEY_Pressed
  	  out of range to Avoid problems with KEYPAD nums */
#define HKEYPAD_NO_KEY_PRESSED 	0xFF



ErrorState_t HKEYPAD_enInit(void);
ErrorState_t HKEYPAD_enGetPressedKey(u8 *ptrKey);


#endif /* HKEYPAD_HKEYPAD_INT_H_ */
