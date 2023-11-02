/********************************************************************************
 * @file        		:  MUSART_prog.c								 		*
 * @Author 	 			:  HASSAN ABDELAZIM ABDELSALAM							*
 * @Version 			:  1.0.0							 					*
 * @Date				:  20/06/2023											*
 ********************************************************************************
 * @attention  USART Driver Implementation for Atmega32
 *
 * This Driver support Polling and Interrupt driven data which is you can send
 * and receive data by waiting for corresponding flag or from App Callback
 * The Driver has 7-APIS, Driver Init, Send, Receive 1 Byte or string of Bytes
 * Enable, Disable and Interrupt CallBack fun for TX,RX,handling
 *
 *********************************************************************************
 * INCLUDES
 ********************************************************************************/
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "BIT_MATH.h"
#include "MUSART_int.h"
#include "MUSART_config.h"
#include "MUSART_priv.h"

/********************************************************************************
 * GLOBAL STATIC VARIABLES
 ********************************************************************************/
/* Initialize an array of three callback pointer has APP fun Address */
static MUSART_Callback_t Callback_CH[3] ;

/********************************************************************************
 * APIs IMPLEMENTATION
 ********************************************************************************/

/*
 *@brief 	MUSART Initialize all <pre> configuration of USART Frame
 *			Half Duplex or Full Duplex, Parity even or odd or Disabled
 *		 	8bit or 9bit Data Frame, 1bit or 2bit Stop bit
 *		 	Select the Required BaudRate,Enable TX,RX,USART
 *
 *@param 	void
 *@retval 	ErrorState (SUCCESS)
 *
 */
ErrorState_t MUSART_enInit(void)
{
	/*3. Select DATA FRAME SIZE */
	UCSRC_REG &= MUSART_DATASIZE_MASK;
	UCSRC_REG |= MUSART_DATA_SIZE << 1;

	/* 4.Select ODD OR EVEN OR DISABLED PARITY*/
	UCSRC_REG &= MUSART_PARITY_MASK;
	UCSRC_REG |= MUSART_PARITY_MODE << 4;


	/* 5. Select 1BIT OR 2BIT STOP BITS */
#if (MUSART_STOPBIT_NUM	== MUSART_STOPBIT1)
	CLR_BIT(UCSRC_REG, USBS);

#elif(MUSART_STOPBIT_NUM == MUSART_STOPBIT2)
	SET_BIT(UCSRC_REG, USBS);
#else
#error("INVALID STOP BIT NUMBER");
#endif

	/* Access The UCSRC_REG */
	CLR_BIT(UCSRC_REG, URSEL);

	/* 1. Select the BAUDRATE */
	UBRRL_REG = 103 ;
	//UBRRH_REG = (u8)UBRR_VALUE << 8;

	/* 6. Enable The Transmission Mode */
	SET_BIT(UCSRB_REG, TXEN);
	/* 7. Enable The Receiver Mode */
	SET_BIT(UCSRB_REG, RXEN);

	return SUCCESS;
}

/*
 *@brief 	MUSART SendByte use the Polling Technique to transmit the data
 *			Capture the CPU of waiting Corresponding Flag
 *
 *@param 	copy_u8Data
 *@retval 	ErrorState ( SUCCESS, OUT_OF_RANG_ERR)
 *
 */
ErrorState_t MUSART_enBusySendByte(u8 copy_u8Data)
{
	/* 1. waiting of TX Empty Flag to be set */
	while (!(GET_BIT( UCSRA_REG, UDRE)));
	/* 2. copy the Data into the USART Data Register */
	UDR_REG = copy_u8Data;
	/* 3. waiting of TX Complete Flag to be set */
	while (!(GET_BIT(UCSRA_REG, TXC)));
	/* Clear the TX Complete flag by writing 1 into it */
	SET_BIT(UCSRA_REG, TXC);

	return SUCCESS;
}

/*
 *@brief 	MUSART SendString use the Polling Technique to transmit the data
 *			Byte by Byte, Capture the CPU of waiting Corresponding Flag
 *
 *@param 	*copy_u8Data
 *@retval 	ErrorState (SUCCESS, NULL_PTR_ERR)
 *
 */
ErrorState_t MUSART_enBusySendString(char *copy_u8Data)
{
	ErrorState_t local_state = SUCCESS;

	/* 1. Initialize a local counter to iterate through the string */
	u8 local_u8Counter = 0;
	if (copy_u8Data != NULL)
	{
		/* 2. check the end of the string if has NULL CHR or Not, if Not iterate */
		while (copy_u8Data[local_u8Counter] != '\0')
		{
			/* 3. Send Byte by Byte of string indexed by local Counter */
			MUSART_enBusySendByte(copy_u8Data[local_u8Counter]);
			/* 4. count up the local counter */
			local_u8Counter++;
		}
	}
	else
	{
		local_state = NULL_PTR_ERR;
	}

	return local_state;
}

/*
 *@brief 	MUSART ReceiveByte use the Polling Technique to Receive the data
 *			Capture the CPU of waiting Corresponding Flag
 *
 *@param 	*copy_u8Data
 *@retval 	ErrorState (SUCCESS, NULL_PTR_ERR)
 *
 */
ErrorState_t MUSART_enBusyReceiveByte(u8 *ptr_u8Data)
{
	ErrorState_t local_state = SUCCESS;

	if (ptr_u8Data != NULL)
	{
		/* 1. waiting of RX Not Empty Flag to be set */
		while (!(GET_BIT(UCSRA_REG, RXC)));
		/* 2. get the Data from Data Register, Assign the value
		 * into the ptr_u8Data to be returned as ptr, the flag is cleared
		 * by reading the Data from the register
		 */
		*ptr_u8Data = UDR_REG ;
	}
	else
	{
		local_state = NULL_PTR_ERR;
	}

	return local_state;
}

/*
 *@brief 	MUSART Enable Interrupt of the Corresponding Event
 *			RXNEmpty, TXCompelete, TXEmpty Interrupt
 *
 *@param 	copy_u8Intnum
 *@retval 	ErrorState (SUCCESS, OUT_OF_RANG_ERR)
 *
 */
ErrorState_t MUSART_enEnableInt(MUSART_INT_t copy_u8Intnum)
{
	ErrorState_t local_state = SUCCESS;

	if ((copy_u8Intnum >= TXEmpty_INT) && (copy_u8Intnum <= RXComplete_INT))
	{
		SET_BIT(UCSRA_REG, copy_u8Intnum);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}
	return local_state;
}

/*
 *@brief 	MUSART Disable Interrupt of the Corresponding Event
 *			RXNEmpty, TXCompelete, TXEmpty Interrupt
 *
 *@param 	copy_u8Intnum
 *@retval 	ErrorState (SUCCESS, OUT_OF_RANG_ERR)
 *
 */
ErrorState_t MUSART_enDisableInt(MUSART_INT_t copy_u8Intnum)
{
	ErrorState_t local_state = SUCCESS;

	if ((copy_u8Intnum >= TXEmpty_INT) && (copy_u8Intnum <= RXComplete_INT))
	{
		CLR_BIT(UCSRA_REG, copy_u8Intnum);
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}
	return local_state;
}

/*
 *@brief 	MUSART Interrupt callBack of the Corresponding Event
 *			RXNEmpty, TXCompelete, TXEmpty Interrupt
 *
 *@param 	copy_u8Intnum, ptr to function
 *@retval 	ErrorState ( SUCCESS, OUT_OF_RANG_ERR)
 *
 */
ErrorState_t MUSART_enIntCallBack(MUSART_INT_t copy_u8Intnum, MUSART_Callback_t *ptr_contxt)
{
	ErrorState_t local_state = SUCCESS;
	if (ptr_contxt != NULL)
	{
		copy_u8Intnum = copy_u8Intnum - TXEmpty_INT;
		/* callback fun of Channel Index has a address of Application fun */
		Callback_CH[copy_u8Intnum].TxRx_Callback = ptr_contxt->TxRx_Callback;
		Callback_CH[copy_u8Intnum].copy_u8Txdata = ptr_contxt->copy_u8Txdata;
	}
	else
	{
		local_state = NULL_PTR_ERR;
	}

	return local_state;
}

/********************************************************************************
 * HANDLEAR IMPLEMENTATION
 ********************************************************************************/
/*
 *@brief 	USART ISR when any Interrupt happens,
 *		 	going to ISR Mood and Execute Application function
 *
 *@param 	void
 *@retval 	void
 *
 */

void USART_UDRE(void)
{

	if (Callback_CH[0].TxRx_Callback != NULL)
	{
		UDR_REG = Callback_CH[0].copy_u8Txdata;
	}
	Callback_CH[0].TxRx_Callback();
}

void USART_TXC(void)
{

	if (Callback_CH[1].TxRx_Callback != NULL)
	{
		/* Clear the TX Complete flag by writing 1 into it */
		SET_BIT(UCSRA_REG, TXC);
	}
	Callback_CH[1].TxRx_Callback();
}

void USART_RXC(void)
{

	if (Callback_CH[2].TxRx_Callback != NULL)
	{
		Callback_CH[2].copy_u8Rxdata = UDR_REG;
	}
	Callback_CH[2].TxRx_Callback();
}
