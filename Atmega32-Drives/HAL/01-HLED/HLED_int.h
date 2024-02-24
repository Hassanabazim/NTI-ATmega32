/********************************************************************************
 * @file        		:  HLED_int.h						 					*
 * @Author 	 			:  HASSAN ABDELAZIM ABDELSALAM							*
 * @Version 			:  1.0.0							 					*
 * @Date				:  31/05/2023											*
 ********************************************************************************
*  HEADER GAURD
********************************************************************************/
#ifndef _HLED_INT_H_
#define _HLED_INT_H_

/********************************************************************************
* INTERFACE MACROS CONFIGURATION
********************************************************************************/
#define HLED_RED_PIN 		PB7
#define HLED_GREN_PIN 		PA4
#define HLED_BLUE_PIN 		PA5
#define HLED_YELLOW_PIN 	PA6




/********************************************************************************
* APIs Prototypes
********************************************************************************/

ErrorState_t HLED_enInit(u8 copyu8_LedID);
/********************************************************************************
* @fun name			:  	HLED_enInit												*
* @para 	 		:  	copyu8_LedID											*
* @retval 			:  	Initilization LED Mood of operation						*
* @Description      :  	SUCCESS, OUT_OF_RANG_ERR								*															*
********************************************************************************/


ErrorState_t HLED_enSetON(u8 copyu8_LedID);
/********************************************************************************
* @fun name			:  	HLED_enSetON											*
* @para 	 		:  	copyu8_LedID											*
* @retval 			:  	SUCCESS, OUT_OF_RANG_ERR								*
* @Description      :  	TURN ON LED PIN											*															*
********************************************************************************/


ErrorState_t HLED_enSetOFF(u8 copyu8_LedID);
/********************************************************************************
* @fun name			:  	HLED_enSetOFF											*
* @para 	 		:  	copyu8_LedID											*
* @retval 			:  	SUCCESS, OUT_OF_RANG_ERR								*
* @Description      :  	TURN OFF LED PIN										*															*
********************************************************************************/

ErrorState_t HLED_enToggle(u8 copyu8_LedID);
/********************************************************************************
* @fun name			:  	HLED_enToggle											*
* @para 	 		:  	copyu8_LedID											*
* @retval 			:  	SUCCESS, OUT_OF_RANG_ERR								*
* @Description      :  	TOGGLE LED PIN [HIGH-LOW]								*															*
********************************************************************************/




#endif /* _HLED_INT_H_ */
/********************************************************************************
 * END OF FILE	:	HLED_int.h
 ********************************************************************************/
