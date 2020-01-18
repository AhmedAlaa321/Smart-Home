/*
 * ADC.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef ADC_H
#define ADC_H
#include "STD_TYPES.h"

void ADC_Init(void);
void ADC_IntSetCallBackFunc(PtrToFuncType ptrToFunc);
void ADC_EnableInterrupt(void);
u16 ADC_GetResult(u8 ADC_Channel);

#endif /* ADC_H_ */

