/*
 * EXTI_REG.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef EXTI_REG_H
#define EXTI_REG_H

//volatile to avoid optimization

/*General Interrupt flag  it's contains the status for every interrupt at moment*/
#define GIFR    (*((volatile u8*)0x5A))

/*define general interrupt control register >> it's responsible register to enable
 *  external interrupts like INT0, INT1, INT2 (pin7, 6 ,5) choose which interrupt enable*/
#define GICR    (*((volatile u8*)0x5B))

/*MCU controller register determines the pulse edges like
 * (falling, rising edge by truth table in data sheet) by controlling ISR00, ISR01 (interrupt sense register)*/
#define MCUCR   (*((volatile u8*)0x55))

/*MCU controller status register it's responsible to enable INT2 by controlling pin6(ISR2) if 0 == falling
 * if 1 == rising .. INT2 different cause is detects clock pulses with special oscillator*/
#define MCUCSR  (*((volatile u8*)0x54))

#endif /* EXTI_REG_H_ */
