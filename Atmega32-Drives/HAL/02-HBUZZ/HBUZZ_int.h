/*
 * HBUZZ_int.h
 *
 *  Created on: Jun 3, 2023
 *      Author: Hassa
 */

#ifndef _HBUZZ_INT_H_
#define _HBUZZ_INT_H_

/********************************************************************************
* INTERFACE MACROS CONFIGURATION
********************************************************************************/
#define HBUZZ_PIN  	PC6



/********************************************************************************
* APIs Prototypes
********************************************************************************/

ErrorState_t HBUZZ_enInit(u8 copy_u8BuzzID);
/********************************************************************************
* @fun name			:  HBUZZ_enInit												*
* @para 	 		:  copy_u8BuzzID											*
* @retval 			:  SUCCESS, OUT_OF_RANG_ERR									*
* @Description      :  Initilize the Buzzer Mood of operation					*															*
********************************************************************************/


ErrorState_t HBUZZ_enSetON(u8 copy_u8BuzzID);
/********************************************************************************
* @fun name			:  	HBUZZ_enSetON											*
* @para 	 		:  	copy_u8BuzzID											*
* @retval 			:  	SUCCESS, OUT_OF_RANG_ERR								*
* @Description      :  	Turn ON the Buzzer 										*															*
********************************************************************************/


ErrorState_t HBUZZ_enSetOFF(u8 copy_u8BuzzID);
/********************************************************************************
* @fun name			:  	HBUZZ_enSetOFF											*
* @para 	 		:  	copy_u8BuzzID											*
* @retval 			:  	SUCCESS, OUT_OF_RANG_ERR								*
* @Description      :  	Turn OFF the Buzzer										*															*
********************************************************************************/


ErrorState_t HBUZZ_enSetONCE(u8 copy_u8BuzzID);
/********************************************************************************
* @fun name			:  	HBUZZ_enSetONCE											*
* @para 	 		:  	copy_u8BuzzID											*
* @retval 			:  	SUCCESS, OUT_OF_RANG_ERR								*
* @Description      :   Turn the Buzzer ONCE									*															*
********************************************************************************/


ErrorState_t HBUZZ_enSetNum(u8 copy_u8BuzzID, u8 copy_u8num);
/********************************************************************************
* @fun name			:  	HBUZZ_enSetNum											*
* @para 	 		:  	copy_u8BuzzID, copy_u8num								*
* @retval 			:  	SUCCESS, OUT_OF_RANG_ERR								*
* @Description      :  	Turn the Buzzer no. of times							*															*
********************************************************************************/






#endif /* _HBUZZ_INT_H_ */

/********************************************************************************
 * END OF FILE	:	HBUZZ_int.h
 ********************************************************************************/
