/********************************************************************************
 * @file        		:  APP_prog.c					 						*
 * @Author 	 			:  HASSAN ABDELAZIM ABDELSALAM							*
 * @Version 			:  1.0.0							 					*
 * @Date				:  06/06/2023											*
 ********************************************************************************
 * @attention   Driver Implementation for Atmega32
 *
 *
 *
 *
 *********************************************************************************
 * INCLUDES
 ********************************************************************************/
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "MDIO_int.h"
#include "MGIE_int.h"
#include "MEXTI_int.h"
#include "MTIMER0_int.h"
#include "MTIMER1_int.h"
#include "MADC_int.h"
#include "MWDT_int.h"
#include "MUSART_int.h"
#include "MSPI_int.h"
#include "MTWI_int.h"
#include "HLED_int.h"
#include "HBUZZ_int.h"
#include "HPB_int.h"
#include "HSSD_int.h"
#include "H4SSD_int.h"
#include "H16x2LCD_int.h"
#include "H20x4LCD_int.h"
#include "HKEYPAD_int.h"
#include "HLM35_int.h"
#include "HMOTOR_int.h"
#include "HULTRA_int.h"
#include "HEEPROM_int.h"
#include "APP_int.h"
#include "APP_priv.h"
#include "APP_config.h"




/********************************************************************************
 * GLOBAL STATIC VARIABLES
 ********************************************************************************/

/********************************************************************************
 * APIs IMPLEMENTATION
 ********************************************************************************/
/*
 *	@brief		APP_voidStartApp use to test all APIs of MCAL & HAL
 *
 *	@para		void
 *	@retval		void
 */

void APP_voidStartApp(void)
{
	/*************************************************************************/
#if(APPLICATION == MDIO_TEST)

	u8 pinstate,  portstate;
	/* TEST SET PORT DIR & VALUE APIs */
	MDIO_enSetPortDirection(PORTC, MDIO_PORT_OUTPUT);
	MDIO_enSetPortValue(PORTC, 0xF0);

	/* TEST SET PIN DIR & VALUE APIs */
	MDIO_enSetPinDirection(PC1, OUTPUT);
	MDIO_enSetPinValue(PC1, HIGH);

	/* TEST GET PIN Value APIs */
	MDIO_enGetPinValue(PC2, &pinstate);
	MDIO_enSetPinValue(PC2, pinstate);

	/* TEST GET PORT Value APIs */
	MDIO_enGetPortValue(PORTC, &portstate);
	MDIO_enSetPortValue(PORTD, portstate);

	while (1)
	{
		/* TEST PIN TOGGLE APIs */
		MDIO_enTogglePin(PC0);
		_delay_ms(1000);
	}
	/*************************************************************************/
#elif(APPLICATION == HBUZ_TEST)
	/*************************************************************************/
	HBUZZ_enInit(HBUZZ_PIN);
	HBUZZ_enSetON(HBUZZ_PIN)
	//HBUZZ_enSetONCE(HBUZZ_PIN)
	//HBUZZ_enSetNum(HBUZZ_PIN, 5)
	while(1)
	{
		HBUZZ_enSetOFF(HBUZZ_PIN)
	}
	/*************************************************************************/
#elif(APPLICATION == HLED_TEST)
	/*************************************************************************/
	HLED_enInit(HLED_RED_PIN);
	HLED_enInit(HLED_GREN_PIN);
	HLED_enInit(HLED_YELLOW_PIN);
	HLED_enInit(HLED_BLUE_PIN);

	HLED_enSetON(HLED_RED_PIN);
	HLED_enSetOFF(HLED_YELLOW_PIN);
	HLED_enSetON(HLED_GREN_PIN);
	while (1)
	{
		HLED_enToggle(HLED_YELLOW_PIN);
		_delay_ms(1000);
	}
	/*************************************************************************/
#elif(APPLICATION == HSSD_TEST)
	/*************************************************************************/
	u16 counter = 0 ;
	HSSD_enInit();

	while (1)
	{
		HSSD_enDisplayIntegerNumber(counter++);
	}
	/*************************************************************************/
#elif(APPLICATION == H4SSD_TEST)
	/*************************************************************************/
	u16 counter = 0 ;
	H4SSD_enInit();

	while (1)
	{
		H4SSD_enDisplayIntegerNumber(counter++);
	}
	/*************************************************************************/
#elif(APPLICATION == HPB_TEST)
	/*************************************************************************/
	HPB_State_t local_u8PBstate = HPB_RELEASED;
	HPB_INIT_t button_1 ;
	button_1.PB_PIN = PD7 ;
	HPB_enInit(&button_1);
	HLED_enInit(HLED_RED_PIN);
	HLCD_enInit();

	while (1)
	{
		HPB_enRead(&button_1, &local_u8PBstate);
		if (local_u8PBstate == HPB_PRESSED)
		{
			HLED_enSetON(HLED_RED_PIN);
			HLCD_enSendIntNum(local_u8PBstate);
		}
		else
		{
			HLED_enSetOFF(HLED_RED_PIN);
		}
	}
	/*************************************************************************/
#elif(APPLICATION == H16X2LCD_TEST)
	/*************************************************************************/
	H16X2LCD_enInit();
	//u8 h[]={0x0A,0x1F,0x1F,0x1F,0x1F,0x0E,0x04,0x00};
	//H16X2LCD_enGoToXY(1, 7);
	H16X2LCD_enSendString("HASSAN");
	/*H16X2LCD_enSendIntNum(34);
	H16X2LCD_enSendData('H');
	H16X2LCD_CustomChar(1, h);*/

	while (1)
	{

	}
	/*************************************************************************/
#elif(APPLICATION == H20X4LCD_TEST)
	/*************************************************************************/
	H16X2LCD_enInit();
	u8 h[]={0x0A,0x1F,0x1F,0x1F,0x1F,0x0E,0x04,0x00};
	/*H16X2LCD_enGoToXY(1, 7);
	H16X2LCD_enSendString("HASSAN");
	H16X2LCD_enSendIntNum(34);
	H16X2LCD_enSendData('H');*/
	H16X2LCD_CustomChar(1, h);

	while (1)
	{

	}
	/*************************************************************************/
#elif(APPLICATION == HKEYPAD_TEST)
	/*************************************************************************/
	u8 local_u8Key = HKEYPAD_NO_KEY_PRESSED ;
	HKEYPAD_enInit();
	H20X4LCD_enInit();
	while (1)
	{
		if (HKEYPAD_enGetPressedKey(&local_u8Key)!= HKEYPAD_NO_KEY_PRESSED)
		{
			H20X4LCD_enSendData(local_u8Key);
			_delay_ms(1000);
			H20X4LCD_enCLearDisplay();
		}
		else
		{
			H20X4LCD_enCLearDisplay();
		}
	}
	/*************************************************************************/
#elif(APPLICATION == MEXIT_TEST)
	/*************************************************************************/
	MDIO_enSetPinDirection(PC0, OUTPUT);
	MDIO_enSetPinDirection(PC1, OUTPUT);
	MDIO_enSetPinDirection(PC2, OUTPUT);

	MEXTI_enSetCalBack(MEXTI_INT0_ID, ACTION1);
	MEXTI_enSetCalBack(MEXTI_INT1_ID, ACTION2);
	MEXTI_enSetCalBack(MEXTI_INT2_ID, ACTION3);

	MEXTI_enEnable(MEXTI_INT0_ID, MEXTI_RISING_EDGE);
	MEXTI_enEnable(MEXTI_INT1_ID, MEXTI_RISING_EDGE);
	MEXTI_enEnable(MEXTI_INT2_ID, MEXTI_RISING_EDGE);
	MGIE_enEnable();

	while (1)
	{

	}

	/*************************************************************************/
#elif(APPLICATION == MTIMER0_TEST)
	/*************************************************************************/

	while(1)
	{

	}
	/*************************************************************************/
#elif (APPLICATION == MTIMER1_TEST)
	/*************************************************************************/

	while(1)
	{

	}
	/*************************************************************************/
#elif(APPLICATION == MWDT_TEST)
	/*************************************************************************/

	while(1)
	{

	}
	/*************************************************************************/
#elif(APPLICATION == HULTRA_TEST)
	/*************************************************************************/
	u32 distance ;
	H20X4LCD_enInit();
	HULTRASONIC_enInit();


	while(1)
	{
		HULTRASONIC_enRead(&distance);
		H20X4LCD_enSendIntNum(distance);
		_delay_ms(500);
		H20X4LCD_enCLearDisplay();
	}
	/*************************************************************************/
#elif(APPLICATION == MADC_TEST)
	/*************************************************************************/
	u16 value ;
	MDIO_enSetPinDirection(PA0, INPUT);
	HLCD_enInit();
	MADC_enInit(prescaler_128, vref_AVCC);


	while(1)
	{
		MADC_enReadChannel(channel_0, &value);

		HLCD_enSendString("LDR VALUE=");
		HLCD_enSendIntNum(value);
		_delay_ms(1000);
		HLCD_enCLearDisplay();
	}
	/*************************************************************************/
#elif(APPLICATION == HLM35_TEST)
	/*************************************************************************/

	while(1)
	{

	}
	/*************************************************************************/
#elif(APPLICATION == HMOTOR_TEST)
	/*************************************************************************/

	while(1)
	{

	}
	/*************************************************************************/
#elif(APPLICATION == MUSART_TEST)
	/*************************************************************************/

	MUSART_enInit();
	//MUSART_enBusySendString("Hassan Abdelazeam");
	MUSART_enBusySendByte('H');

	while(1)
	{

	}
	/*************************************************************************/
#elif(APPLICATION == MSPI_TEST)
	/*************************************************************************/

	while(1)
	{

	}
	/*************************************************************************/
#elif(APPLICATION == MTWI_TEST)
	/*************************************************************************/


	while(1)
	{

	}
	/*************************************************************************/
#elif(APPLICATION == HEEPROM_TEST)
	/*************************************************************************/

	while(1)
	{

	}
	/*************************************************************************/
#else
#error("WRONG UNIT TESTING !");
#endif
}

/********************************************************************************
 * CALLBACK FUNCTION IMPLEMENTATION
 ********************************************************************************/
#if (APPLICATION == MEXIT_TEST)
void ACTION1(void)
{
	MGIE_enEnable();
	MDIO_enSetPinValue(PC0, HIGH);
	_delay_ms(5000);
}

void ACTION2(void)
{
	MGIE_enEnable();
	MDIO_enSetPinValue(PC1, HIGH);
	_delay_ms(5000);
}

void ACTION3(void)
{
	MGIE_enEnable();
	MDIO_enSetPinValue(PC2, HIGH);
	_delay_ms(5000);

}
#endif
