/*
 * Temp_Sensor.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#include "DIO.h"
#include "TIM.h"
#include "ADC.h"
#include <stdlib.h>
#include "TEMP_SENSOR.h"

static void TEMP_ISR(void);
static u8 FIRE_FLAG = LOW;

void TEMP_Initialize(void)
{
	DIO_voidSetDDR(LM35, LOW); //Set LM35 Input
	ADC_Init();
	TIM_voidInitialize();
}

u8 TEMP_READ(void)
{
	return (((ADC_GetResult(0))*4.88f)/10);
}


void TEMP_STR_READ(char *strPtr)
{
	itoa(TEMP_READ(), strPtr, 10);
}

void TEMP_EnableInterrupt(void)
{
	TIM_voidEnableInterrupt();
	//Check TEMP_READ every 1s in case over heat
	TIM_voidSetCallBack(TEMP_ISR);
}

static void TEMP_ISR(void)
{
	if(TEMP_READ() > 40)
	{
		FIRE_FLAG = HIGH;
	}
	else
	{
		FIRE_FLAG = LOW;
	}
}

u8 TEMP_GetFireFlag(void)
{
	return FIRE_FLAG;
}
