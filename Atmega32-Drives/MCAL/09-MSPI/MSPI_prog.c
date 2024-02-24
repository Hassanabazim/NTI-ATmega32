/*
 * MSPI_prog.c
 *
 *  Created on: Sep 7, 2023
 *      Author: Hassa
 */


#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "BIT_MATH.h"
#include "MDIO_int.h"
#include "MGIE_int.h"
#include "MSPI_int.h"
#include "MSPI_config.h"
#include "MSPI_priv.h"


ErrorState_t MSPI_enMasterInit(void)
{
	/*	configure SPI MOSI Pin as output	*/
	MDIO_enSetPinDirection(MSPI_MOSI_Pin, OUTPUT);
	/*	configure SPI SS Pin as output	*/
	MDIO_enSetPinDirection(MSPI_SS_Pin, OUTPUT);
	/*	configure SPI SCK Pin as output	*/
	MDIO_enSetPinDirection(MSPI_SCK_Pin, OUTPUT);
	/*	configure SPI MISO Pin as input	*/
	MDIO_enSetPinDirection(MSPI_MISO_Pin, INPUT);

	/*	initialize SPI SS pin with HIGH (No slave selected) */
	MDIO_enSetPinValue(MSPI_SS_Pin, HIGH);
	/*	enable SPI Module	*/
	SET_BIT(SPI_SPCR_REG,MSPI_SPE_BIT);

	/*	enable SPI Module in Master mode	*/
	SET_BIT(SPI_SPCR_REG,MSPI_MSTR_BIT);

	/*	set SCK frequency by F_CPU/16	*/
	/*	Set SPI Speed	1MHZ*/
	SPI_SPCR_REG |= MSPI_SCK_PRESCALER;

	return SUCCESS;
}

ErrorState_t MSPI_enSlaveInit(void)
{
	/*	configure SPI MOSI Pin as input	*/
	MDIO_enSetPinDirection(MSPI_MOSI_Pin, INPUT);
	/*	configure SPI SS Pin as input	*/
	MDIO_enSetPinDirection(MSPI_SS_Pin, INPUT);
	/*	configure SPI SCK Pin as input	*/
	MDIO_enSetPinDirection(MSPI_SCK_Pin, INPUT);
	/*	configure SPI MISO Pin as output	*/
	MDIO_enSetPinDirection(MSPI_MISO_Pin, OUTPUT);

	/*	enable SPI Module	*/
	SET_BIT(SPI_SPCR_REG,MSPI_SPE_BIT);
	/*	enable SPI Module in Slave mode	*/
	CLR_BIT(SPI_SPCR_REG,MSPI_MSTR_BIT);

	return SUCCESS;
}
ErrorState_t MSPI_enMasterWrite(u8 copy_u8data)
{
	u8 loc_flush_byte;
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = copy_u8data;
	/*	wait until byte sent	*/
	while(!(GET_BIT(SPI_SPSR_REG,MSPI_SPIF_BIT)));

	/*	flush the data register	*/
	loc_flush_byte = SPI_SPDR_REG;

	return SUCCESS;
}

ErrorState_t MSPI_enMasterRead(u8 *copy_u8data)
{
	ErrorState_t local_state = SUCCESS;
	if (copy_u8data != NULL)
	{
		u8 loc_dummy_byte=0xFF;
		/*	load SPI data register with a byte to send	*/
		SPI_SPDR_REG = loc_dummy_byte;
		/*	wait until byte received	*/
		while(!(GET_BIT(SPI_SPSR_REG,MSPI_SPIF_BIT)));
		/*	read the data register	*/
		*copy_u8data =  SPI_SPDR_REG;
	}
	else
	{
		local_state = NULL_PTR_ERR;
	}
	return local_state;
}

ErrorState_t MSPI_enSlaveWrite(u8 copy_u8data)
{
	SPI_SPDR_REG = copy_u8data;

	return SUCCESS;

}
ErrorState_t MSPI_enSlaveRead(u8 *copy_u8data)
{
	ErrorState_t local_state = SUCCESS;
	if (copy_u8data != NULL)
	{
		/*	wait until byte received	*/
		while(!(GET_BIT(SPI_SPSR_REG,MSPI_SPIF_BIT)));

		/*	read the data register	*/
		*copy_u8data =  SPI_SPDR_REG;
	}
	else
	{
		local_state = NULL_PTR_ERR;
	}
	return local_state;
}
