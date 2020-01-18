/*
 * Keypad.c
 *
 *  Created on: Oct 1, 2019
 *      Author: MahmoudGamal
 */

#include "Keypad.h"

#include "DIO.h"
#include "string.h"
#include <stdlib.h>
#include <util/delay.h>

void Keypad_Intialize()
{
	/*Set Keypad COLUMNS as Output to put the LOW(0) and HIGH(1) signal*/
	DIO_voidSetDDR(KEYPAD_COLUMN_0, HIGH);
	DIO_voidSetDDR(KEYPAD_COLUMN_1, HIGH);
	DIO_voidSetDDR(KEYPAD_COLUMN_2, HIGH);

	/*Set Keypad ROWS as Input to detect The LOW(0) signal*/
	DIO_voidSetDDR(KEYPAD_ROW_0, LOW);
	DIO_voidSetDDR(KEYPAD_ROW_1, LOW);
	DIO_voidSetDDR(KEYPAD_ROW_2, LOW);
	DIO_voidSetDDR(KEYPAD_ROW_3, LOW);

	//Enable Pull UP Resistance
	DIO_voidSetPort(H_PORTA, KEYPAD_PULL_UP_ENABLE_MSK);
}

s8 Keypad_GetKeyPressed()
{
	u8 columnCnt = 0;
	u8 rowCnt = 0;
	for(columnCnt = KEYPAD_COLUMN_0; columnCnt <= KEYPAD_COLUMN_2; columnCnt++)
	{
		switch(columnCnt)
		{
			case KEYPAD_COLUMN_0:
				DIO_voidSetPin(KEYPAD_COLUMN_0, LOW);
				DIO_voidSetPin(KEYPAD_COLUMN_1, HIGH);
				DIO_voidSetPin(KEYPAD_COLUMN_2, HIGH);
				break;

			case KEYPAD_COLUMN_1:
				DIO_voidSetPin(KEYPAD_COLUMN_0, HIGH);
				DIO_voidSetPin(KEYPAD_COLUMN_1, LOW);
				DIO_voidSetPin(KEYPAD_COLUMN_2, HIGH);
				break;

			case KEYPAD_COLUMN_2:
				DIO_voidSetPin(KEYPAD_COLUMN_0, HIGH);
				DIO_voidSetPin(KEYPAD_COLUMN_1, HIGH);
				DIO_voidSetPin(KEYPAD_COLUMN_2, LOW);
				break;
		}//end of switch

		for(rowCnt = KEYPAD_ROW_0; rowCnt <= KEYPAD_ROW_3; rowCnt++)
		{
			if(DIO_getPinVal(rowCnt) == LOW)
			{
				switch(rowCnt)
				{
					case KEYPAD_ROW_0:
						switch(columnCnt)
						{
							case KEYPAD_COLUMN_0: return 35; //ASCII Of #
							case KEYPAD_COLUMN_1: return 0;
							case KEYPAD_COLUMN_2: return 42; //ASCII Of *
						}
						break;
					case KEYPAD_ROW_1:
						switch(columnCnt)
						{
							case KEYPAD_COLUMN_0: return 9;
							case KEYPAD_COLUMN_1: return 8;
							case KEYPAD_COLUMN_2: return 7;
						}
						break;
					case KEYPAD_ROW_2:
						switch(columnCnt)
						{
							case KEYPAD_COLUMN_0: return 6;
							case KEYPAD_COLUMN_1: return 5;
							case KEYPAD_COLUMN_2: return 4;
						}
						break;
					case KEYPAD_ROW_3:
						switch(columnCnt)
						{
							case KEYPAD_COLUMN_0: return 3;
							case KEYPAD_COLUMN_1: return 2;
							case KEYPAD_COLUMN_2: return 1;
						}
						break;
				}//end of switch

			}//end of if statement
		}//end of second for loop
	}//end of 1st for loop
	return -1;//No Key Pressed
}

void Keypad_GetKeyPressedStr(char *strPtr)
{
	if(Keypad_GetKeyPressed() > -1)
	{
		if(Keypad_GetKeyPressed() == 35)
		{
			strPtr = "*";
		}
		else if(Keypad_GetKeyPressed() == 42)
		{
			strPtr = "#";
		}
		else
		{
			itoa(Keypad_GetKeyPressed(), strPtr, 10);
		}
	}
}

