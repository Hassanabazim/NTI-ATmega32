/*
 * HDCMOTOR_int.h
 *
 *  Created on: Jun 18, 2023
 *      Author: Hassa
 */

#ifndef HMOTOR_HMOTOR_INT_H_
#define HMOTOR_HMOTOR_INT_H_


typedef enum {
	Motor_forward,
	Motor_reverse
}Motor_dir;


ErrorState_t HDCMOTOR_enInit(void);
ErrorState_t HDCMOTOR_enSetON(Motor_dir copy_u8dir, u8 copy_u8duty);
ErrorState_t HDCMOTOR_enSetOFF(MDIO_Pin_t copy_u8pin);


#endif /* HMOTOR_HMOTOR_INT_H_ */
