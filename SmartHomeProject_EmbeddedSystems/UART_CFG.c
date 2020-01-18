/*
 * UART_CFG.c
 *
 *  Created on: Oct 1, 2019
 *      Author: ahmedAlaa
 */

#include "STD_TYPES.h"
#include "UART_CFG.h"

/*define array that represents the array that holds the real configuration of the driver*/
const UART_CFG_TYPE UART_CFG_ARRAY[]=
{
		{(u32)9600, NO_PARITY, EIGHT_BITS, ONE_STOP}
};

