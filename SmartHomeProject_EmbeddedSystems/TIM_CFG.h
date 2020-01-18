/*
 * TIM_CFG_H.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef TIM_CFG_H_
#define TIM_CFG_H_

#define TIFR_CLEAR_MSK 0b00000011

#define TIMSK_CLEAR_MSK 		0b11111100
#define TIMSK_OV_ENABLE_MSK 	0b00000001
#define TIMSK_OC_ENABLE_MSK 	0b00000010

//Converting Between Modes by editing on CS00, CS01, CS02 to set Prescaler division mode
#define TIM_DIV_CLEAR_MSK 0b11111000

#define TIM_NO_DIV_MSK 		0b00000001
#define TIM_DIV_BY_8_MSK 	0b00000010
#define TIM_DIV_BY_64_MSK 	0b00000011
#define TIM_DIV_BY_256_MSK 	0b00000100
#define TIM_DIV_BY_1024_MSK 0b00000101

//Counter MODES
//Convert between them by editing in WGM01 BIT_3, WGM00 BIT_6 in TCCR0 register
#define TIM_MODE_CLEAR_MSK 		0b10110111
#define TIM_MODE_NORMAL_MSK 	0b10110111 //Clear when reaches Max Value
#define TIM_MODE_CTC_MSK 		0b00001000//Clear when reaches to compare match then give flag pulse
#define TIM_MODE_FAST_PWM_MSK 	0b01001000

/*what happens when compare match on OC0*/
/*
COM01 COM00 Description
0	  0		Normal port operation, OC0 disconnected.
0	  1     Toggle OC0 on compare match
1     0     Clear OC0 on compare match
1 	  1     Set OC0 on compare match
*/

//Choose one of these
//OC_mode specify if we need output on OC pins
//converting by editing COM00 BIT_4, COM01 BIT_5
#define OC_CLEAR_MSK 0b11001111
//NON_PWM
#define OC_DISCONNECTED_MSK 			0b11001111
#define OC_TOGGLE_ON_COMPARE_MATCH_MSK 	0b00010000
#define OC_CLEAR_ON_COMPARE_MATCH_MSK 	0b00100000
#define OC_SET_ON_COMPARE_MATCH_MSK 	0b00110000
//FAST_PWM
#define OC_NORMAL_MSK 					0b11001111
#define OC_RESERVED_MSK 				0b00010000
#define OC_NON_INVERTING_MSK 			0b00100000
#define OC_INVERTING_MSK 				0b00110000

/*Description: Timer initial value*/
#define TIM_INIT_VALUE 0

//Divides frequency of clock to reduce it to make counter able to count frequency
#define TIM_PRESCALER_MODE  TIM_DIV_BY_64

#define OC_MODE  OC_INVERTING

#define TIM_MODE TIM_MODE_FAST_PWM

/*define the initial compare value in the initialization*/
#define INIT_COMPARE_VALUE 250

#endif /* TIM_CFG_H_ */
