/*
 * GIE.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef GIE_H
#define GIE_H


//define status register address
#define SREG				*((volatile u8*)0x5F)

//first we need to enable status register to control all interrupts (parent register)
#define GI_EN()				SET_BIT(SREG,7);
#define GI_DIS()			CLEAR_BIT(SREG,7);
#endif /* GIE_H */
