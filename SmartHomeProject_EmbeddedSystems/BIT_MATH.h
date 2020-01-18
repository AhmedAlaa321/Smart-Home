/*
 * BIT_MATH.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef BITMATH_H
#define BITMATH_H

#define SET_BIT(num, bitIndex) 		 (num)|=(1<<bitIndex)
#define CLEAR_BIT(num, bitIndex)	 (num)&=~(1<<bitIndex)
#define TOGGLE_BIT(num, bitIndex)	 (num)^=(1<<bitIndex)
#define GET_BIT(num, bitIndex)		 (num&(1<<bitIndex))>>bitIndex

#endif // BITMATH_H
