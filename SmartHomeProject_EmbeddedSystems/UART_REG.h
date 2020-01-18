/*
 * UART_REG.h
 *
 *  Created on: Oct 1, 2019
 *      Author: MahmoudGamal
 */

#ifndef UART_REG_H
#define UART_REG_H

/*define the needed registers needed by the UART*/
#define UBRRH *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)
#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRC *((volatile u8*)0x40)
#define UDR   *((volatile u8*)0x2C)

#endif /* UART_REG_H_ */
