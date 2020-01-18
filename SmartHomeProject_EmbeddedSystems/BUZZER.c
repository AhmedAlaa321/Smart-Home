/*
 * BUZZER.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */
#include "DIO.h"
#include "BUZZER.h"

void BUZZER_Initialize()
{
	DIO_voidSetDDR(BUZZER, 	HIGH);
}

void BUZZER_ON()
{
	DIO_voidSetPin(BUZZER, HIGH);
}

void BUZZER_OFF()
{
	DIO_voidSetPin(BUZZER, LOW);
}
