/*
 * MSPI_int.h
 *
 *  Created on: Sep 7, 2023
 *      Author: Hassa
 */

#ifndef _MSPI_INT_H_
#define _MSPI_INT_H_

ErrorState_t MSPI_enMasterInit(void);
ErrorState_t MSPI_enSlaveInit(void);
ErrorState_t MSPI_enMasterWrite(u8 copy_u8data);
ErrorState_t MSPI_enMasterRead(u8 *copy_u8data);
ErrorState_t MSPI_enSlaveWrite(u8 copy_u8data);
ErrorState_t MSPI_enSlaveRead(u8 *copy_u8data);




#endif /* _MSPI_INT_H_ */
