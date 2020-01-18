/*
 * DIO.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef DIO_H
#define DIO_H
#include "STD_TYPES.h"

typedef enum
{
	H_PORTA = 0,
	H_PORTB,
	H_PORTC,
	H_PORTD
}H_PORTS;

typedef enum
{
	/*PORT D*/
	PIN_0 = 0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,

	/*PORT C*/
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15,

	/*PORT B*/
	PIN_16,
	PIN_17,
	PIN_18,
	PIN_19,
	PIN_20,
	PIN_21,
	PIN_22,
	PIN_23,

	/*PORT A*/
	PIN_24,
	PIN_25,
	PIN_26,
	PIN_27,
	PIN_28,
	PIN_29,
	PIN_30,
	PIN_31
}H_PINS;

typedef enum
{
	/*PORT D*/
	 RX = 0,
	 TX,
	 EMPTY_IO_0,
	 EMPTY_IO_1,
	 LED_0,
	 LED_1,
	 LED_2,
	 DC_MOTOR, //Fan

	 /*PORT C*/
	 LCD_E,
	 LCD_RW,
	 LCD_RS,
	 LCD_D7,
	 LCD_D6,
	 LCD_D5,
	 LCD_D4,
	 EMPTY_IO_2,

	/*PORT B*/
	 EMPTY_IO_3,
	 EMPTY_IO_4,
	 EMPTY_IO_5,
	 SERVO_MOTOR, //Door
	 BUZZER,
	 EMPTY_IO_6,
	 EMPTY_IO_7,
	 EMPTY_IO_8,

	/*PORT A*/
	LM35,
	KEYPAD_COLUMN_0,
	KEYPAD_COLUMN_1,
	KEYPAD_COLUMN_2,
	KEYPAD_ROW_0,
	KEYPAD_ROW_1,
	KEYPAD_ROW_2,
	KEYPAD_ROW_3

}CUSTOM_PINS;

void DIO_voidSetPort(H_PORTS port, u8 portVal);
void DIO_voidSetPin(H_PINS pinIndex, u8 pinVal);
void DIO_voidSetDDR(H_PINS pinIndex, u8 directionStatus);
u8 DIO_getPortVal(H_PORTS port);
u8 DIO_getPinVal(H_PINS pinIndex);
#endif
