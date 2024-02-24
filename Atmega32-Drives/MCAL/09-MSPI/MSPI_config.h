/*
 * MSPI_config.h
 *
 *  Created on: Sep 7, 2023
 *      Author: Hassa
 */

#ifndef _MSPI_CONFIG_H_
#define _MSPI_CONFIG_H_

#define MSPI_MOSI_Pin		PB5
#define MSPI_SS_Pin			PB4
#define MSPI_SCK_Pin		PB7
#define MSPI_MISO_Pin		PB6

 /*
  *	 PLEASE CHOOSE SPI PRESCALER
  *
  *
  *	 MSPI_SCK_FREQ_FCPU_DIV_4		(0<<0)
  *	 MSPI_SCK_FREQ_FCPU_DIV_16		(1<<0)
  *	 MSPI_SCK_FREQ_FCPU_DIV_64		(2<<0)
  *	 MSPI_SCK_FREQ_FCPU_DIV_128		(3<<0)
  */

#define MSPI_SCK_PRESCALER		MSPI_SCK_FREQ_FCPU_DIV_4


#endif /* _MSPI_CONFIG_H_ */
