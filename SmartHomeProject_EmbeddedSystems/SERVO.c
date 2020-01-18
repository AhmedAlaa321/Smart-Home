/*
 * SERVO.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#include "BIT_MATH.h"
#include "util/delay.h"
#include "GIE.h"
#include "TIM.h"
#include "SERVO.h"

void SERVO_Initialize()
{
	TIM_voidInitialize();
}

void SERVO_ON()
{
	TIM_voidSetCompareValue(15);  //Open degree
}

void SERVO_OFF()
{
	TIM_voidSetCompareValue(200);  //Close degree
}

