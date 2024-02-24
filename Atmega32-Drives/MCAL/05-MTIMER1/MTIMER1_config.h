/*
 * MTIMER1_config.h
 *
 *  Created on: Jun 13, 2023
 *      Author: AA
 */

#ifndef _MTIMER1_CONFIG_H_
#define _MTIMER1_CONFIG_H_

/*
 * Please config the Timer clock
 *
 * MTIMER1_NO_CLOCK
 * MTIMER1_PRESCALLER_1
 * MTIMER1_PRESCALLER_8
 * MTIMER1_PRESCALLER_64
 * MTIMER1_PRESCALLER_256
 * MTIMER1_PRESCALLER_1024
 * MTIMER1_ECTTCL_FALL_EDGE
 * MTIMER1_ECTTCL_RAISs_EDGE
 */
#define MTIMER1_CLK	MTIMER1_PRESCALLER_1024

/*
 * Please config the Timer MODE
 *
 * #define MTIMER0_MODE_MASK
#define MTIMER1_MODE_NORMAL
#define MTIMER1_MODE_CTC
#define MTIMER1_MODE_FAST_PWM
#define MTIMER1_MODE_PHASE_CORRESCT_PWM
 */

#define MTIMER1_MODE	MTIMER1_MODE_NORMAL

/*
 * Please config the Timer OC0
 *
#define MTIMER1_OC1_MASK
#define MTIMER1_OC1_DISCONNECTED
#define MTIMER1_OC1_TOGGLE
#define MTIMER1_OC1_CLEARE
#define MTIMER1_OC1_SET
 */

#define MTIMER1_OC1_MODE	MTIMER1_OC1_MASK

#endif /* _MTIMER1_CONFIG_H_ */
