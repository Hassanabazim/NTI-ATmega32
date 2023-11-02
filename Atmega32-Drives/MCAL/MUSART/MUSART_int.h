/********************************************************************************
* 	@file        		:  MUSART_int.h							 				*
*	@Author 	 		:  HASSAN ABDELAZIM ABDELSALAM							*
*	@Version 			:  1.0.0							 					*
*	@Date				:  03/08/2023											*
*********************************************************************************
*  HEADER GAURD
********************************************************************************/
#ifndef MUSART_MUSART_INT_H_
#define MUSART_MUSART_INT_H_

#include "STD_TYPES.h"
#include "ERROR_STATE.h"
/********************************************************************************
* Interface MACROS
********************************************************************************/
#define UBRR_VALUE  		((FCPU / (16 * MUSART_BAUDRATE))-1)


/********************************************************************************
* typedefs Struct
********************************************************************************/
/* struct of Callback Interrupts */
typedef struct
{
	u8 *copy_u8Rxdata;
	u8 copy_u8Txdata;
	void (*TxRx_Callback)(void);
}MUSART_Callback_t;


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
/********************************************************************************
* @fun name			:  MUSART_enInit											*
* @para 	 		:  void														*
* @retval 			:  ErrorState (SUCCESS)										*
* @Description      :  Initialize all <pre>configuration of USART Frame 		*
* 		 																		*
********************************************************************************/


ErrorState_t MUSART_enBusySendByte(u8 copy_u8Data);
/********************************************************************************
* @fun name			:  MUSART_enBusySendByte									*
* @para 	 		:  copy_u8Data												*
* @retval 			:  ErrorState ( SUCCESS, OUT_OF_RANG_ERR)					*
* @Description      :  USART Transmit Byte data 								*
********************************************************************************/



ErrorState_t MUSART_enBusySendString(char *copy_u8Data);
/********************************************************************************
* @fun name			:  MUSART_enBusySendString									*
* @para 	 		:  *copy_u8Data												*
* @retval 			:  ErrorState (SUCCESS, OUT_OF_RANG_ERR, NULL_PTR_ERR)		*
* @Description  	:  USART Transmit String of Byte data 						*
********************************************************************************/


ErrorState_t MUSART_enBusyReceiveByte(u8 *ptr_u8Data);
/********************************************************************************
* @fun name			:  MUSART_enBusyReceiveByte									*
* @para 	 		:   *ptr_u8Data												*
* @retval 			:  ErrorState (SUCCESS, OUT_OF_RANG_ERR, NULL_PTR_ERR)		*
* @Description  	:  USART Receive Byte of Data 						  		*
********************************************************************************/



ErrorState_t MUSART_enEnableInt(MUSART_INT_t copy_u8Intnum);
/********************************************************************************
* @fun name			:  MUSART_enEnableInt										*
* @para 	 		:  copy_u8Intnum											*
* @retval 			:  ErrorState (SUCCESS, OUT_OF_RANG_ERR)					*
* @Description  	:  Enable an USART Interrupt 								*
********************************************************************************/



ErrorState_t MUSART_enDisableInt(MUSART_INT_t copy_u8Intnum);
/********************************************************************************
* @fun name			:  MUSART_enDisableInt										*
* @para 	 		:  copy_u8USARTnum, copy_u8Intnum							*
* @retval 			:  ErrorState ( SUCCESS, OUT_OF_RANG_ERR)					*
* @Description      :  Disable an USART Interrupt  								*
********************************************************************************/



ErrorState_t MUSART_enIntCallBack(MUSART_INT_t copy_u8Intnum, MUSART_Callback_t *ptr_contxt);
/********************************************************************************
* @fun name			:  MUSART_enIntCallBack, 									*
* @para 	 		:  copy_u8Intnum, ptr to function							*
* @retval 			:  ErrorState (SUCCESS, NULL_PTR_ERR)						*
* @Description      :  CallBack to Execute APP fun from MCAL 					*
********************************************************************************/




#endif /* MUSART_MUSART_INT_H_ */
