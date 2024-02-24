/*
 * HSSD_config.h
 *
 *  Created on: May 31, 2023
 *      Author: Hassan
 */

#ifndef H4SSD_H4SSD_CONFIG_H_
#define H4SSD_H4SSD_CONFIG_H_

/* Please Configure Pins for 7-Segment LEDS
 * A,B,.....,DP
 *
 * Please Configure Enable pins for both-7Segment
 * EN1, EN2
 *
 * Please Cnfigure 7-Segment MODE
 * HSSD_CC, HSSD_CA
 */

#define H4SSD_TYPE 			 	H4SSD_CA

#define H4SSD_BSD_QA_PIN		PB0
#define H4SSD_BSD_QB_PIN		PB1
#define H4SSD_BSD_QC_PIN		PB2
#define H4SSD_BSD_QD_PIN		PB4
#define H4SSD_LED_COM1_PIN		PA3
#define H4SSD_LED_COM2_PIN		PA2
#define H4SSD_LED_COM3_PIN		PB5
#define H4SSD_LED_COM4_PIN		PB6


#define HSSD_DISPLAY_TIME  		75



#endif /* HSSD_HSSD_CONFIG_H_ */
