/*
 * TIM.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef TIM_H_
#define TIM_H_
#include "STD_TYPES.h"

typedef enum{
	TIM_NO_DIV = 0,
	TIM_DIV_BY_8,
	TIM_DIV_BY_64,
	TIM_DIV_BY_256,
	TIM_DIV_BY_1024
}PRESCALER_MODES;

typedef enum{
	TIM_MODE_NORMAL = 0,
	TIM_MODE_CTC,
	TIM_MODE_FAST_PWM
}TIMER_MODES;

typedef enum{
	OC_DISCONNECTED = 0,
	OC_TOGGLE_ON_COMPARE_MATCH,
	OC_CLEAR_ON_COMPARE_MATCH,
	OC_SET_ON_COMPARE_MATCH
}OC_MODES_NON_PWM;

typedef enum{
	OC_NORMAL = 0,
	OC_RESERVED,
	OC_NON_INVERTING,
	OC_INVERTING
}OC_MODES_FAST_PWM;

/*Description: This function shall initialize the Timer peripheral*/
void TIM_voidInitialize(void);

/*Description: enable Timer interrupt*/
void TIM_voidEnableInterrupt(void);

/*Description: disable Timer interrupt*/
void TIM_voidDisableInterrupt(void);

/*Description: set Timer callback function*/
void TIM_voidSetCallBack(PtrToFuncType funcPtr);

/*Description: initialize timer register*/
void TIM_voidInitTimerRegister(u8 startCnt);

/*description function to set the compare register with certain value*/
void TIM_voidSetCompareValue(u8 compareVal);

#endif /* TIM_H_ */
