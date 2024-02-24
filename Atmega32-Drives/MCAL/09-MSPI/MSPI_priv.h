/*
 * MSPI_priv.h
 *
 *  Created on: Sep 7, 2023
 *      Author: Hassa
 */

#ifndef _MSPI_PRIV_H_
#define _MSPI_PRIV_H_

#define SPI_SPCR_REG 				(*(u8*)0x2D)
#define SPI_SPSR_REG				(*(u8*)0x2E)
#define SPI_SPDR_REG				(*(u8*)0x2F)

#define MSPI_SCK_FREQ_FCPU_DIV_4		(0<<0)
#define MSPI_SCK_FREQ_FCPU_DIV_16		(1<<0)
#define MSPI_SCK_FREQ_FCPU_DIV_64		(2<<0)
#define MSPI_SCK_FREQ_FCPU_DIV_128		(3<<0)

#define MSPI_SPE_BIT           		(6)
#define MSPI_MSTR_BIT				(4)
#define MSPI_SPIF_BIT				(7)


#endif /* _MSPI_PRIV_H_ */
