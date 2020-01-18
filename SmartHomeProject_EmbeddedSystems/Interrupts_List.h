/*
 * Interrupts_List.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef INTERRUPTS_LIST_H
#define INTERRUPTS_LIST_H

//vectors is memory locations contains jump instructions to interrupt functions like reset
//non-maskable mean can't be disabled like reset
#define EXTI_INT0()				   	void __vector_1(void) __attribute__((signal,used));\
									void __vector_1(void)
#define EXTI_INT1()				   	void __vector_2(void) __attribute__((signal,used));\
									void __vector_2(void)
#define EXTI_INT2()				   	void __vector_3(void) __attribute__((signal,used));\
									void __vector_3(void)
#define TIMER2_COMP()				void __vector_4(void) __attribute__((signal,used));\
									void __vector_4(void)
#define TIMER2_OVF()				void __vector_5(void) __attribute__((signal,used));\
									void __vector_5(void)
#define TIMER1_CAPT()				void __vector_6(void) __attribute__((signal,used));\
									void __vector_6(void)
#define TIMER1_COMPA()				void __vector_7(void) __attribute__((signal,used));\
									void __vector_7(void)
#define TIMER1_COMPB()				void __vector_8(void) __attribute__((signal,used));\
									void __vector_8(void)
#define TIMER1_OVF()				void __vector_9(void) __attribute__((signal,used));\
									void __vector_9(void)
#define TIMER0_COMP()				void __vector_10(void) __attribute__((signal,used));\
									void __vector_10(void)
#define TIMER0_OVF()				void __vector_11(void) __attribute__((signal,used));\
									void __vector_11(void)
#define SPI_STC()					void __vector_12(void) __attribute__((signal,used));\
									void __vector_12(void)
#define USART_RXC()					void __vector_13(void) __attribute__((signal,used));\
									void __vector_13(void)
#define USART_UDRE()				void __vector_14(void) __attribute__((signal,used));\
									void __vector_14(void)
#define USART_TXC()					void __vector_15(void) __attribute__((signal,used));\
									void __vector_15(void)
#define ADC_INT()					void __vector_16(void) __attribute__((signal,used));\
									void __vector_16(void)

#endif /* INTERRUPTS_LIST_H_ */
