/*
 * ADC.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#include "BIT_MATH.h"
#include "Interrupts_List.h"
#include "GIE.h"
#include "ADC_REG.h"
#include "ADC_CFG.h"
#include "ADC.h"

static PtrToFuncType CallBackFunc_ADC_INT = 0;

void ADC_Init(void)
{
	ADMUX = ADMUX_ENABLE_MSK;
	ADCSRA = ADCSRA_ENABLE_MSK;
	GI_EN();
}

u16 ADC_GetResult(u8 ADC_Channel) {

	ADC_Channel &= ADC_CHANNEL_CLEAR_MSK;

	ADMUX &= ADMUX_CLEAR_MSK;
	/* choose the correct channel by setting the channel number in MUX4:0 bits */
	ADMUX |= ADC_Channel;

	ADCSRA |= START_CONVERSION_MSK;

	return ADC;/* return the data register */
}

void ADC_EnableInterrupt(void)
{
	ADCSRA |= ADCSRA_ENABLE_INT_MSK;
}

void ADC_IntSetCallBackFunc(PtrToFuncType ptrToFunc)
{
	CallBackFunc_ADC_INT = ptrToFunc;
}

ADC_INT()
{
	if(CallBackFunc_ADC_INT != 0)
	{
		CallBackFunc_ADC_INT();
	}
}
