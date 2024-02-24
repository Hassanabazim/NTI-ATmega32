/*
 * HSSD_config.h
 *
 *  Created on: May 31, 2023
 *      Author: Hassan
 */

#ifndef HSSD_HSSD_CONFIG_H_
#define HSSD_HSSD_CONFIG_H_

/* Please Configure Pins for 7-Segment LEDS
 * A,B,.....,DP
 *
 * Please Configure Enable pins for both-7Segment
 * EN1, EN2
 *
 * Please Cnfigure 7-Segment MODE
 * HSSD_CC, HSSD_CA
 */

#define HSSD_LED_DP_PIN		PB0
#define HSSD_LED_A_PIN 		PA1
#define HSSD_LED_B_PIN		PA2
#define HSSD_LED_C_PIN		PA3
#define HSSD_LED_D_PIN		PA4
#define HSSD_LED_E_PIN		PA5
#define HSSD_LED_F_PIN		PA6
#define HSSD_LED_G_PIN		PA7

#define HSSD_LED_EN1_PIN	PC6
#define HSSD_LED_EN2_PIN	PC7

#define HSSD_DISPLAY_TIME  	500

#define HSSD_TYPE   HSSD_CC

#endif /* HSSD_HSSD_CONFIG_H_ */
