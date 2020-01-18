/*

 * UART.c
 *
 *  Created on: Oct 1, 2019
 *      Author: ahmedAlaa
 */

/*include the required headers*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_REG.h"
#include "UART_CFG.h"
#include "UART.h"

void UART_Initialize(void)
{
	  UBRRL = BAUD_PRESCALE;// Load lower 8-bits into the low byte of the UBRR register
	  UBRRH = (BAUD_PRESCALE >> 8);

	  /* Load upper 8-bits into the high byte of the UBRR register Default frame format is 8 data bits, no parity, 1 stop bit to change use UCSRC, see AVR data sheet*/
	  // Enable receiver and transmitter and receive complete interrupt
	  UCSRB = ((1<<TXEN) | (1<<RXEN) | (1<<RXCIE));
}

void UART_Write(u8 data)
{
	while(!GET_BIT(UCSRA, UDRE));
	UDR = data;
	while(!GET_BIT(UCSRA, TXC));
}

/*receive a character through UART*/
u8 UART_Read()
{
	u8 data;
	while(!GET_BIT(UCSRA, RXC));
	data = UDR;
	return data;
}
