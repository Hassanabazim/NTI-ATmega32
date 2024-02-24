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
#include "MGIE_int.h"
#include "MUSART_int.h"
#include "MUSART_config.h"
#include "MUSART_priv.h"

/********************************************************************************
 * GLOBAL STATIC VARIABLES
 ********************************************************************************/
/* Initialize an array of three callback pointer has APP fun Address */
u8  Receive_Flag = 0;

u8  uart_TxBufferIndex = 0;
u8  uart_RxBufferIndex = 0;

u8  uart_TxBUFFER[MUSART_TXBUFFER_SIZE] ;
u8  uart_RxBUFFER[MUSART_RXBUFFER_SIZE] ;

static void(*uart_Callback[3])(void) = {NULL} ;



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
	UBRRL_REG = (u8)MUSART_BAUDRATE ;
	UBRRH_REG = (u8)(MUSART_BAUDRATE>> 8);

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
ErrorState_t MUSART_enBusySendString(u8 *copy_u8Data)
{
	ErrorState_t local_state = SUCCESS;

	/* 1. Initialize a local counter to iterate through the string */
	u8 local_u8Counter = 0;
	if (copy_u8Data != NULL)
	{
		/* 2. check the end of the string if has NULL CHR or Not, if Not iterate */
		while (copy_u8Data[local_u8Counter] !=  MUSART_NULL_CHR
		)
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

ErrorState_t MUSART_enSendMessage(u8 *copy_u8msg)
{
	/*@ brief This API use to store the TX_buffer to send by interrupt ASynchronous
	 * 1. copy string of bytes or byte from user to Tx buffer
	 * 2. if the buffer element was NULL break it
	 * 3.  send the first byte
	 * */
	ErrorState_t local_state = SUCCESS;
	uart_TxBufferIndex = 0;
	if (copy_u8msg != NULL)
	{
		for (u8 i = 0; i < MUSART_TXBUFFER_SIZE; i++)
		{
			uart_TxBUFFER[i] = copy_u8msg[i];

			if (uart_TxBUFFER[i] == MUSART_NULL_CHR)
				break;
		}
		UDR_REG =  uart_TxBUFFER[uart_TxBufferIndex];
	}
	else
	{
		local_state = NULL_PTR_ERR;
	}
	return local_state;
}

ErrorState_t MUSART_enReceieveMessage(u8 *copy_u8msg)
{
	/*@ brief This API use to store the msg from RX buffer with interrupt ASynchronous
	 * 1. copy string of bytes or byte from Rx buffer to App buffer to return it
	 * 2. if the buffer element was ENDline char break it
	 * 3.  exchange the EndLine char with the NUll char
	 * 4. clear the receieve flag to receieve data again
	 * */
	ErrorState_t local_state = SUCCESS;

	if (copy_u8msg != NULL)
	{
		uart_RxBufferIndex = 0;
		for (u8 i = 0; i <MUSART_RXBUFFER_SIZE; i++ )
		{
			copy_u8msg[i] = uart_RxBUFFER[i];

			if (copy_u8msg[i] == MUSART_END_LINE)
			{
				copy_u8msg[i] = MUSART_NULL_CHR;
				Receive_Flag = 0;
				break;
			}
		}
	}
	else
	{
		local_state = NULL_PTR_ERR;
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
ErrorState_t MUSART_enIntCallBack(MUSART_INT_t copy_u8Intnum, void (*ptr)(void))
{
	ErrorState_t local_state = SUCCESS;
	if (ptr != NULL)
	{
		copy_u8Intnum = copy_u8Intnum - TXEmpty_INT;
		/* callback fun of Channel Index has a address of Application fun */
		uart_Callback[copy_u8Intnum] = ptr;
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

ISR(USART_UDRE)
{
	if (uart_Callback[0] != NULL)
	{
		uart_Callback[0]();
	}
}

ISR(USART_TXC)
{
	uart_TxBufferIndex++;

	if (uart_TxBUFFER[uart_TxBufferIndex] == MUSART_NULL_CHR)
	{
		uart_TxBufferIndex = 0;
		uart_Callback[1]();
	}
	else
	{
		UDR_REG =  uart_TxBUFFER[uart_TxBufferIndex];
	}
}

ISR(USART_RXC)
{
	uart_RxBUFFER[uart_RxBufferIndex] = UDR_REG ;

	if (uart_RxBUFFER[uart_RxBufferIndex] == MUSART_END_LINE)
	{
		uart_RxBufferIndex = 0;
		uart_Callback[2]();
		Receive_Flag = 1;
	}
	else
	{
		uart_RxBufferIndex++;
	}
}
