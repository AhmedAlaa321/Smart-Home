/*
 * LED.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#include "util/delay.h"
#include "STD_TYPES.h"
#include "DIO.h"
#include "LED.h"

void LED_Initialize()
{
	DIO_voidSetDDR(LED_0, HIGH);
	DIO_voidSetDDR(LED_1, HIGH);
	DIO_voidSetDDR(LED_2, HIGH);
}

void LED_ON(u8 LED_Channel)
{
	switch(LED_Channel)
	{
		case LED_CHANNEL_0 :
			DIO_voidSetPin(LED_0, HIGH);
			break;
		case LED_CHANNEL_1 :
			DIO_voidSetPin(LED_1, HIGH);
			break;
		case LED_CHANNEL_2 :
			DIO_voidSetPin(LED_2, HIGH);
			break;
	}
}

void LED_OFF(u8 LED_Channel)
{
	switch(LED_Channel)
	{
		case LED_CHANNEL_0 :
			DIO_voidSetPin(LED_0, LOW);
			break;
		case LED_CHANNEL_1 :
			DIO_voidSetPin(LED_1, LOW);
			break;
		case LED_CHANNEL_2 :
			DIO_voidSetPin(LED_2, LOW);
			break;
	}
}

void LED_Toggle(u8 LED_Channel)
{
	u8 LEDStatus = 0;
	switch(LED_Channel)
	{
		case LED_CHANNEL_0 :
			LEDStatus = DIO_getPinVal(LED_0);
			DIO_voidSetPin(LED_0, (LEDStatus ^= 1));
			break;
		case LED_CHANNEL_1 :
			LEDStatus = DIO_getPinVal(LED_1);
			DIO_voidSetPin(LED_1, (LEDStatus ^= 1));
			break;
		case LED_CHANNEL_2 :
			LEDStatus = DIO_getPinVal(LED_2);
			DIO_voidSetPin(LED_2, (LEDStatus ^= 1));
			break;
	}
}
