/*
 * EXTI.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE.h"
#include "DIO.h"
#include "EXTI_REG.h"
#include "EXTI_CFG.h"
#include "EXTI.h"

Ptr2FuncType CallBackFunc_INT0, CallBackFunc_INT1, CallBackFunc_INT2;

static void EXTI_EnInterrupt(EXTI_IntType IntNum)
{
	/*after setting the ISCR edges -by MCUCR & MCUCSR- we enable general interrupt control register
	 * -GICR- to enable interrupt*/
	switch(IntNum)
	{
		case EXTI_INT0: SET_BIT(GICR, 6);
						break;

		case EXTI_INT1: SET_BIT(GICR, 7);
						break;

		case EXTI_INT2: SET_BIT(GICR, 5);
						break;
	}
}

void EXTI_Initialize(void)
{
	//Enable General Interrupt
	GI_EN();
	/*check enabled interrupt by user*/
	//Button2 (D2) connected to INT0
	#if EXTI_ENABLE_INT0 == HIGH
	//if user want to enable interrupt0
		MCUCR &= EXTI_EDGE_CLR_MSK_INT0;  //Here we just CLEAR the two pins ISCR00, ISCR01 needed
		MCUCR |= EXTI_EDGE_SELECTOR_INT0_MSK; //Here we set the ISCR00, ISCR01 as in truth table to enable interrupt
		DIO_voidSetDDR(EXTI_INT0, LOW);
		EXTI_EnInterrupt(EXTI_INT0);

	#endif

	//LED2 (D3) connected to INT1
	#if EXTI_ENABLE_INT1 == HIGH
		MCUCR &= (~((~EXTI_EDGE_CLR_MSK_INT0)<<2));
		MCUCR |= (EXTI_EDGE_SELECTOR_INT1_MSK<<2); //Here we shift cause ISR00, ISR01 in INT2 in bit(5, 4)
		DIO_voidSetDDR(EXTI_INT1, LOW);
		EXTI_EnInterrupt(EXTI_INT1);
	#endif

	#if EXTI_ENABLE_INT2 == HIGH
		//Two ways to enable int2 clear or set pin_6
		#if EXTI_EDGE_SELECTOR_INT2_msk == EXTI_EDGE_RISING_msk
			SET_BIT(MCUCSR,6);
		#elif EXTI_EDGE_SELECTOR_INT2_msk == EXTI_EDGE_FALLING_msk
			CLR_BIT(MCUCSR,6);
		#endif
		DIO_voidSetDDR(EXTI_INT2, LOW);
		EXTI_EnInterrupt(EXTI_INT2);
	#endif
}

void EXTI_SetCallBackFunc(EXTI_IntType intNum, Ptr2FuncType funcPtr)
{
	switch(intNum)
	{
		case EXTI_INT0:
			CallBackFunc_INT0 = funcPtr;
			break;
		case EXTI_INT1:
			CallBackFunc_INT1 = funcPtr;
			break;
		case EXTI_INT2:
			CallBackFunc_INT2 = funcPtr;
			break;
	}
}

/*EXTI_INT0 FUNC*/
void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	if(CallBackFunc_INT0 != 0)
	{
		CallBackFunc_INT0();
	}

}
/*EXTI_INT1 FUNC*/
void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{
	//not null
	if(CallBackFunc_INT1 != 0)
	{
		CallBackFunc_INT1();
	}

}
/*EXTI_INT2 FUNC*/
void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{
	if(CallBackFunc_INT2 != 0)
	{
		CallBackFunc_INT2();
	}

}

