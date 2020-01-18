/*
 * EXTI.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef EXTI_H
#define EXTI_H
#include "DIO.h"

typedef enum
{
	EXTI_INT0 = PIN_2,
	EXTI_INT1,
	EXTI_INT2 = PIN_18
}EXTI_IntType;

void EXTI_Initialize(void);
void EXTI_SetCallBackFunc(EXTI_IntType IntNum, Ptr2FuncType Func);

#endif /* EXTI_H_ */
