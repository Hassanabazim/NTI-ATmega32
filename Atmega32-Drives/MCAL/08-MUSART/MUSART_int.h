/********************************************************************************
* 	@file        		:  MUSART_int.h							 				*
*	@Author 	 		:  HASSAN ABDELAZIM ABDELSALAM							*
*	@Version 			:  1.0.0							 					*
*	@Date				:  03/08/2023											*
*********************************************************************************
*  HEADER GAURD
********************************************************************************/
#ifndef _MUSART_INT_H_
#define _MUSART_INT_H_

#include "STD_TYPES.h"
#include "ERROR_STATE.h"
/********************************************************************************
* Interface MACROS
********************************************************************************/



/********************************************************************************
* typedefs Struct
********************************************************************************/



/********************************************************************************
* typedefs Enums
********************************************************************************/

/* DEfinition of USART INTRRUPTS */
typedef enum
{
	TXEmpty_INT = 5,
	TXComplete_INT,
	RXComplete_INT
}MUSART_INT_t;

/********************************************************************************
* APIs Prototypes
********************************************************************************/

ErrorState_t MUSART_enInit(void);
ErrorState_t MUSART_enBusySendByte(u8 copy_u8Data);
ErrorState_t MUSART_enBusySendString(u8 *copy_u8Data);
ErrorState_t MUSART_enBusyReceiveByte(u8 *ptr_u8Data);
ErrorState_t MUSART_enEnableInt(MUSART_INT_t copy_u8Intnum);
ErrorState_t MUSART_enDisableInt(MUSART_INT_t copy_u8Intnum);
ErrorState_t MUSART_enSendMessage(u8 *copy_u8msg);
ErrorState_t MUSART_enReceieveMessage(u8 *copy_u8msg);
ErrorState_t MUSART_enIntCallBack(MUSART_INT_t copy_u8Intnum, void (*ptr)(void));




#endif /* _MUSART_INT_H_ */
