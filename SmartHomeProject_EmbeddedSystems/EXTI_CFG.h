/*
 * EXTI_CFG.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef EXTI_CFG_H
#define EXTI_CFG_H

//For CLEAR last two bits in Interrupt 0, to Interrupt 1 we need shift ISR00, ISR01
#define	EXTI_EDGE_CLR_MSK_INT0						0b11111100

//Control Pulse by change ISR00, ISR01 Bits
//Last two bits represent ISR00, ISR01
#define EXTI_EDGE_LOW_LEVEL_MSK					0b00000000
#define EXTI_EDGE_BOTH_MSK						0b00000001
#define EXTI_EDGE_RISING_MSK					0b00000011
#define EXTI_EDGE_FALLING_MSK					0b00000010


#define EXTI_EDGE_SELECTOR_INT0_MSK				EXTI_EDGE_BOTH_MSK
#define EXTI_EDGE_SELECTOR_INT1_MSK				EXTI_EDGE_FALLING_MSK
#define EXTI_EDGE_SELECTOR_INT2_MSK				EXTI_EDGE_RISING_MSK

#define EXTI_ENABLE_INT0						HIGH
#define EXTI_ENABLE_INT1						LOW
#define EXTI_ENABLE_INT2						LOW


#endif /* EXTI_CFG_H_ */
