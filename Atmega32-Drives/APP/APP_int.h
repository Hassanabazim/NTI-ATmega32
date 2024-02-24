/********************************************************************************
* 	@file        		:  APP_int.h				 							*
*	@Author 	 		:  HASSAN ABDELAZIM ABDELSALAM							*
*	@Version 			:  1.0.0							 					*
*	@Date				:  06/06/2023											*
*********************************************************************************
*  HEADER GAURD
********************************************************************************/
#ifndef APP_INT_H_
#define APP_INT_H_

/********************************************************************************
 * CALLBACK FUNCTION Prototype
 ********************************************************************************/
#if (APPLICATION == MEXIT_TEST)
void ACTION1(void);
void ACTION2(void);
void ACTION3(void);
#endif


/********************************************************************************
* APIs Prototypes
********************************************************************************/

void APP_voidStartApp(void);
/********************************************************************************
* @fun name			: APP_voidStartApp 											*
* @para 	 		: void														*
* @retval 			: void														*
* @Description      : Application start all needed APIS							*															*
********************************************************************************/



#endif  /* APP_INT_H_ */

/********************************************************************************
 * END OF FILE	:	APP_int.h
 ********************************************************************************/
