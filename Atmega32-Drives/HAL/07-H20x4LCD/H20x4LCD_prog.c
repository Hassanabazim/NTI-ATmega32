/*
 * H20X4LCD_prog.c
 *
 *  Created on: Jun 1, 2023
 *      Author: Hassa
 */


#include <util/delay.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "BIT_MATH.h"
#include "MDIO_int.h"
#include "H20x4LCD_int.h"
#include "H20x4LCD_config.h"
#include "H20x4LCD_priv.h"



ErrorState_t H20X4LCD_enInit(void)
{
	ErrorState_t Local_state = SUCCESS;

	/* 1.configure the LCD pins as OUTPUTS and perform Initialisation Sequence*/
	MDIO_enSetPinDirection( H20X4LCD_RS_PIN, OUTPUT);
	MDIO_enSetPinDirection( H20X4LCD_EN_PIN, OUTPUT);

	MDIO_enSetPinDirection( H20X4LCD_D7_PIN, OUTPUT);
	MDIO_enSetPinDirection( H20X4LCD_D6_PIN, OUTPUT);
	MDIO_enSetPinDirection( H20X4LCD_D5_PIN, OUTPUT);
	MDIO_enSetPinDirection( H20X4LCD_D4_PIN, OUTPUT);
#if(H20X4LCD_MODE == _8BIT_)
	MDIO_enSetPinDirection( H20X4LCD_D3_PIN, OUTPUT);
	MDIO_enSetPinDirection( H20X4LCD_D2_PIN, OUTPUT);
	MDIO_enSetPinDirection( H20X4LCD_D1_PIN, OUTPUT);
	MDIO_enSetPinDirection( H20X4LCD_D0_PIN, OUTPUT);
	_delay_ms(20);
	H20X4LCD_enSendCommand(H20X4LCD_FUNCTION_SET_8BIT_2LINE);
#elif(H20X4LCD_MODE == _4BIT_)
	_delay_ms(20);
	MDIO_enSetPinValue(H20X4LCD_EN_PIN, LOW);

	H20X4LCD_enSendCommand(0x30);
	_delay_ms(5);
	H20X4LCD_enSendCommand(0x30);
	_delay_us(100);
	H20X4LCD_enSendCommand(0x30);
	H20X4LCD_enSendCommand(0x20);

	MDIO_enSetPinValue(H20X4LCD_EN_PIN, HIGH);
	_delay_ms(1);
	MDIO_enSetPinValue(H20X4LCD_EN_PIN, LOW);
	_delay_ms(30);
	H20X4LCD_enSendCommand(H20X4LCD_FUNCTION_SET_4BIT_2LINE);
#endif

	H20X4LCD_enSendCommand(H20X4LCD_DISPLAY_ON_CURSOR_ON_BLINK_OFF);
	H20X4LCD_enSendCommand(H20X4LCD_CLEAR);
	H20X4LCD_enSendCommand(H20X4LCD_ENTRY_MODE_SET_FUNCTION);

	return Local_state;
}
ErrorState_t H20X4LCD_enSendData(u8 copy_u8Data)
{
	// set RS = 1
	MDIO_enSetPinValue(H20X4LCD_RS_PIN, HIGH);
	// send data as a byte to Nlatch
	H20X4LCD_voidNLatch(copy_u8Data);

	return SUCCESS;

}
ErrorState_t H20X4LCD_enSendCommand(u8 copy_u8Command)
{
	// set RS = 0
	MDIO_enSetPinValue(H20X4LCD_RS_PIN, LOW);
	// send Command as a byte to Nlatch
	H20X4LCD_voidNLatch(copy_u8Command);

	return SUCCESS;
}
ErrorState_t H20X4LCD_enSendString(const char * str)
{
	while(*str != '\0')
	{
		H20X4LCD_enSendData(*str);
		str++;
	}
	return SUCCESS;
}
ErrorState_t H20X4LCD_enCLearDisplay(void)
{
	//H20X4LCD_CLEAR
	H20X4LCD_enSendCommand(H20X4LCD_CLEAR);
	return SUCCESS;
}
ErrorState_t H20X4LCD_enSendIntNum(s32 copy_s32Num)
{
	u8 temp_arr[10] = {0} ;
	u8 counter = 0 ;

	if (copy_s32Num == 0 )
	{
		H20X4LCD_enSendData('0');
	}
	else
	{
		if (copy_s32Num < 0)
		{
			H20X4LCD_enSendData('-');
			copy_s32Num *= -1 ;
		}
		while (copy_s32Num > 0)
		{
			temp_arr[counter] = copy_s32Num % 10;
			copy_s32Num = copy_s32Num / 10;
			counter ++;
		}

		while (counter > 0)
		{
			H20X4LCD_enSendData(temp_arr[counter-1] + '0');
			counter --;
		}
	}
	return SUCCESS;
}
ErrorState_t H20X4LCD_enGoToXY(u8 copy_u8X , u8 copy_u8Y)
{
	ErrorState_t local_state = SUCCESS;
	if (copy_u8Y < 20)
	{
		switch(copy_u8X)
		{
		case 0:
			H20X4LCD_enSendCommand(copy_u8Y|0x80);
			break;
		case 1:
			H20X4LCD_enSendCommand(copy_u8Y|0x94);
			break;
		case 2:
			H20X4LCD_enSendCommand(copy_u8Y|0xC0);
			break;
		case 3:
			H20X4LCD_enSendCommand(copy_u8Y|0xD4);
			break;
		default:
			local_state = OUT_OF_RANG_ERR;
		}
	}
	else
	{
		local_state = OUT_OF_RANG_ERR;
	}

	return local_state;
}


ErrorState_t H20X4LCD_CustomChar(u8 copy_u8loc, u8 *str)
{
	H20X4LCD_enSendCommand(0x40 + (copy_u8loc * 8));

	for (u8 i = 0; i<8; i++)
	{
		H20X4LCD_enSendData(str[i]);
	}
	return SUCCESS;
}

static void H20X4LCD_voidNLatch(u8 copy_u8Byte)
{

#if(H20X4LCD_MODE == _8BIT_)
	u8 Local_u8LcdPinsArr[] =
	{H20X4LCD_D0_PIN, H20X4LCD_D1_PIN, H20X4LCD_D2_PIN, H20X4LCD_D3_PIN,
			H20X4LCD_D4_PIN,H20X4LCD_D5_PIN, H20X4LCD_D6_PIN, H20X4LCD_D7_PIN};

	// Disable En
	MDIO_enSetPinValue(H20X4LCD_EN_PIN, LOW);
	for (u8 i = 0; i <= 7; i++)
	{
		MDIO_enSetPinValue(Local_u8LcdPinsArr[i], GET_BIT(copy_u8Byte,i));
	}
	MDIO_enSetPinValue(H20X4LCD_EN_PIN, HIGH);
	_delay_ms(1);
	MDIO_enSetPinValue(H20X4LCD_EN_PIN, LOW);
	_delay_ms(30);

#elif(H20X4LCD_MODE == _4BIT_)
	u8 Local_u8LcdPinsArr[4] ={H20X4LCD_D4_PIN,H20X4LCD_D5_PIN, H20X4LCD_D6_PIN, H20X4LCD_D7_PIN};
	/* send higher lcd pins */
	// Disable En
	MDIO_enSetPinValue(H20X4LCD_EN_PIN, LOW);
	for (u8 i = 0; i <= 3; i++)
	{
		MDIO_enSetPinValue(Local_u8LcdPinsArr[i], GET_BIT(copy_u8Byte,(i+4)));
	}
	MDIO_enSetPinValue(H20X4LCD_EN_PIN, HIGH);
	_delay_ms(1);
	MDIO_enSetPinValue(H20X4LCD_EN_PIN, LOW);
	_delay_ms(30);

	/* send lower lcd pins */
	for (u8 i = 0; i <=3 ; i++)
	{
		MDIO_enSetPinValue(Local_u8LcdPinsArr[i], GET_BIT(copy_u8Byte,i));
	}
	MDIO_enSetPinValue(H20X4LCD_EN_PIN, HIGH);
	_delay_ms(1);
	MDIO_enSetPinValue(H20X4LCD_EN_PIN, LOW);
	_delay_ms(30);

#else
#error ("Wrong LCD mode")
#endif
}
