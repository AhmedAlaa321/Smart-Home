/*
 * UART_CFG.h
 *
 *  Created on: Oct 1, 2019
 *      Author: ahmedAlaa
 */

#ifndef UART_CFG_H
#define UART_CFG_H

///* define system frequency */
//#define F_CPU 16000000UL

/****** defines for configuration ****/

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

/*define the receive buffer length*/
#define RECIEVE_BUFFER_LENGTH 10

/* data length */
typedef enum{
	FIVE_BITS = 0,
	SIX_BITS,
	SEVEN_BITS,
	EIGHT_BITS,
	NINE_BITS
}DATA_LENGTH;

/* Parity */
typedef enum{
	NO_PARITY = 0,
	EVEN_PARITY = 2,
	ODD_PARITY,
}PARITY_MODE;

/* stop bits length */
typedef enum{
	ONE_STOP = 0,
	TWO_STOPS,
}STOP_LENGTH;

/*define Structure that holds the parameters of the UART*/
typedef struct
{
	u32 baudRate;
	u8 parity;
	u8 dataLen;
	u8 stopLen;
}UART_CFG_TYPE;

const extern UART_CFG_TYPE UART_CFG_ARRAY[];

#endif


