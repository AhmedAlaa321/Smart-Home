/*
 * TIM.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Interrupts_List.h"
#include "DIO.h"
#include "TIM_REG.h"
#include "TIM_CFG.h"
#include "TIM.h"

static PtrToFuncType TIM_CallBacKFunc;

/*Description: This function shall initialize the Timer peripheral*/
void TIM_voidInitialize()
{
	//Clear Flag
	TIFR |= TIFR_CLEAR_MSK;

	//Disable Interrupt
	TIMSK &= TIMSK_CLEAR_MSK;

	//Initialize Timer Register
	TCNT0 = TIM_INIT_VALUE;

	//Clear CS00, CS01, CS02 Division Mode Bits
	TCCR0 &= TIM_DIV_CLEAR_MSK;

	//Set Prescaler
	switch(TIM_PRESCALER_MODE)
	{
		case TIM_NO_DIV :
			TCCR0 |= TIM_NO_DIV_MSK;
			break;

		case TIM_DIV_BY_8 :
			TCCR0 |= TIM_DIV_BY_8_MSK;
			break;

		case TIM_DIV_BY_64 :
			TCCR0 |= TIM_DIV_BY_64_MSK;
			break;

		case TIM_DIV_BY_256 :
			TCCR0 |= TIM_DIV_BY_256_MSK;
			break;

		case TIM_DIV_BY_1024 :
			TCCR0 |= TIM_DIV_BY_1024_MSK;
			break;

	}

	//Clear WGM01, WGM00 Timer Mode Bits
	TCCR0 &= TIM_MODE_CLEAR_MSK;

	//Choose the current mode
	switch(TIM_MODE)
	{
		case TIM_MODE_NORMAL :
			TCCR0 &= TIM_MODE_NORMAL_MSK;
		    break;

		case TIM_MODE_CTC :
			TCCR0 |= TIM_MODE_CTC_MSK;
			OCR0 = INIT_COMPARE_VALUE;

			//Clear COM01, COM00 OC Mode Bits
			TCCR0 &= OC_CLEAR_MSK;

			switch (OC_MODE)
			{
				case OC_DISCONNECTED :
					TCCR0 &= OC_DISCONNECTED_MSK;
					break;
				case OC_TOGGLE_ON_COMPARE_MATCH :
					TCCR0 |= OC_TOGGLE_ON_COMPARE_MATCH_MSK;
					DIO_voidSetDDR(PIN_19, HIGH);
					break;
				case OC_CLEAR_ON_COMPARE_MATCH :
					TCCR0 |= OC_CLEAR_ON_COMPARE_MATCH_MSK;
					DIO_voidSetDDR(PIN_19, HIGH);
					break;
				case OC_SET_ON_COMPARE_MATCH :
					TCCR0 |= OC_SET_ON_COMPARE_MATCH_MSK;
					DIO_voidSetDDR(PIN_19, HIGH);
					break;
			}
			break;

		case TIM_MODE_FAST_PWM :
			TCCR0 |= TIM_MODE_FAST_PWM_MSK;
			OCR0 = INIT_COMPARE_VALUE;

			//Clear COM01, COM00 OC Mode Bits
			TCCR0 &= OC_CLEAR_MSK;

			switch (OC_MODE)
			{
				case OC_NORMAL :
					TCCR0 &= OC_NORMAL_MSK;
					break;
				case OC_NON_INVERTING :
					TCCR0 |= OC_NON_INVERTING_MSK;
					DIO_voidSetDDR(PIN_19, HIGH);
					break;
				case OC_INVERTING :
					TCCR0 |= OC_INVERTING_MSK;
					DIO_voidSetDDR(PIN_19, HIGH);
					break;
			}
			break;
	}
}

/*Description: enable Timer interrupt*/
void TIM_voidEnableInterrupt()
{
	TIMSK &= TIMSK_CLEAR_MSK;
	switch(TIM_MODE)
	{
		case TIM_MODE_NORMAL :
			TIMSK |= TIMSK_OV_ENABLE_MSK;
			break;
		case TIM_MODE_CTC :
		case TIM_MODE_FAST_PWM :
			TIMSK |= TIMSK_OC_ENABLE_MSK;
			break;
	}
}

/*Description: disable Timer interrupt*/
void TIM_voidDisableInterrupt()
{
	TIMSK &= TIMSK_CLEAR_MSK;
}

/*Description: initialize timer register*/
void TIM_voidInitTimerRegister(u8 startCnt)
{
	TCNT0 = startCnt;
}

/*description function to set the compare register with certain value*/
void TIM_voidSetCompareValue(u8 compareVal)
{
	OCR0 = compareVal;
}

/*Description: set Timer callback function*/
void TIM_voidSetCallBack(PtrToFuncType funcPtr)
{
	TIM_CallBacKFunc = funcPtr;
}

/*defining the interrupt handling function*/
TIMER0_OVF()
{
	TIM_CallBacKFunc();
}

TIMER0_COMP()
{
	TIM_CallBacKFunc();
}


