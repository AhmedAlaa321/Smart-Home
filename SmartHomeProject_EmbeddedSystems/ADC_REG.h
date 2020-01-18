/*
 * ADC_REG.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX  (*(volatile u8 *)0x27)
#define ADCSRA (*(volatile u8 *)0x26)
#define SFIOR  (*(volatile u8 *)0x50)
#define ADC	   (*(volatile u16 *)0x24)

#endif /* ADC_REG_H_ */
