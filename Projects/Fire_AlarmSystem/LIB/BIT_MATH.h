/*
 * BIT_MATH.h
 *
 *  Created on: May 31, 2023
 *      Author: Hassan
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)	REG |= (1<<BIT)
#define CLC_BIT(REG,BIT)   	REG &= ~(1<<BIT)
#define TOG_BIT(REG,BIT)   	REG ^= (1<<BIT)
#define GET_BIT(REG,BIT)   	(REG >> (BIT)) & 1

#endif /* BIT_MATH_H_ */
