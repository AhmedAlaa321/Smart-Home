/*
 * ADC_CFG.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef ADC_CFG_H
#define ADC_CFG_H

/* Select Reference Voltage (AVCC)(MUX7,MUX6),
 *  Result right justified(MUX5),
 *  select channel zero(MUX4:0) */
#define ADMUX_ENABLE_MSK 	  0b01000000
/* clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
#define ADMUX_CLEAR_MSK 	  0b11100000
/* Enable ADC(ADCSRA 7),Start Conversion(ADCSRA 6),
 * Disable Trigger source(using Single Conversion Mode)(ADCSRA5),
 * Clear Flag(ADCSRA4),Enable Interrupt (ADCSRA3),
 * (ADCSRA2:0)sampling frequency=osc_freq/128 */
#define ADCSRA_ENABLE_MSK	  0b11010111
#define ADCSRA_ENABLE_INT_MSK 0b00001000
/* start conversion write '1' to ADSC */
#define START_CONVERSION_MSK  0b01000000
/* channel number must be from 0 --> 7 So You need Mask the Variable with 0x07 */
#define ADC_CHANNEL_CLEAR_MSK 0b00000111
/* clear ADIF by write '1' to it :) *//*==> I clear by one (one with one = zero) Like  Logical Gate (XOR)*/
#define ADIF_CLEAR_MSK 	      0b00010000

#endif /* ADC_CFG_H_ */
