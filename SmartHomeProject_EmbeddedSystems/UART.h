/*
 * UART.h
 *
 *  Created on: Oct 1, 2019
 *      Author: ahmedAlaa
 */

#ifndef UART_H
#define UART_H

/*** Bits of UCSRC ***/
typedef enum{
	UCPOL = 0,
	UCSZ0,
	UCSZ1,
	USBS,
	UPM0,
	UPM1,
	UMSEL,
	URSEL
}UCSRC_BITS;

/****** Bits of UCSRA ******/
typedef enum{
	UDRE = 5,
	TXC,
	RXC
}UCRSA_BITS;

/****** Bits of UCSRB ******/
typedef enum{
	UCSZ2 = 2,
	TXEN,
	RXEN,
	RXCIE = 7
}UCSRB_BITS;

/*define the required interfaces for different functions*/
/*initialize function that set the baud rate frame format(parity, stop, data bits)*/
void UART_Initialize(void);

u8 UART_Read(void);

void UART_Write(u8 data);

#endif
