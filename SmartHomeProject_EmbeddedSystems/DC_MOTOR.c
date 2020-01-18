/*
 * DC_MOTOR.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */
#include "DIO.h"
#include "DC_MOTOR.h"

void DC_MOTOR_Initialize()
{
	DIO_voidSetDDR(DC_MOTOR, HIGH); //Set DDR Output
}

void DC_MOTOR_ON()
{

	DIO_voidSetPin(DC_MOTOR, HIGH);
}

void DC_MOTOR_OFF()
{
	DIO_voidSetPin(DC_MOTOR, LOW);
}
