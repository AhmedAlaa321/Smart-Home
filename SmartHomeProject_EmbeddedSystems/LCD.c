/*
 * LCD.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#include "BIT_MATH.h"
#include <util\delay.h>
#include "DIO.h"
#include "LCD_CFG.h"
#include "LCD.h"

/* LCD NOTES */
/* EN >> inform LCD there is data gonna be send
 * D0 > D7 >> Data output
 * RS -> Register Select (CMD/ Data)
 * RW -> READ = 1/ WRITE = 0
 * A/K Additional resist control strength of illumination
 * */

static void LCD_WritePin(u8 data)
{
	#if (LCD_MODE_PIN == LCD_MODE_8)
		DIO_voidSetPin(LCD_D0, GET_BIT(data, 0));
		DIO_voidSetPin(LCD_D1, GET_BIT(data, 1));
		DIO_voidSetPin(LCD_D2, GET_BIT(data, 2));
		DIO_voidSetPin(LCD_D3, GET_BIT(data, 3));
		DIO_voidSetPin(LCD_D4, GET_BIT(data, 4));
		DIO_voidSetPin(LCD_D5, GET_BIT(data, 5));
		DIO_voidSetPin(LCD_D6, GET_BIT(data, 6));
		DIO_voidSetPin(LCD_D7, GET_BIT(data, 7));

	#elif (LCD_MODE_PIN == LCD_MODE_4)
		//in mode 4 we need to send data on 2 pulses
		DIO_voidSetPin(LCD_D4, GET_BIT(data, 4));
		DIO_voidSetPin(LCD_D5, GET_BIT(data, 5));
		DIO_voidSetPin(LCD_D6, GET_BIT(data, 6));
		DIO_voidSetPin(LCD_D7, GET_BIT(data, 7));

		/*First Pulse*/
		DIO_voidSetPin(LCD_E, HIGH);
		_delay_ms(1);
		DIO_voidSetPin(LCD_E, LOW);

		DIO_voidSetPin(LCD_D4, GET_BIT(data, 0));
		DIO_voidSetPin(LCD_D5, GET_BIT(data, 1));
		DIO_voidSetPin(LCD_D6, GET_BIT(data, 2));
		DIO_voidSetPin(LCD_D7, GET_BIT(data, 3));

	#else
		//ERROR
	#endif
	/*Second Pulse*/
	DIO_voidSetPin(LCD_E, HIGH);
	_delay_ms(1);
	DIO_voidSetPin(LCD_E, LOW);
	/*square pulse*/
}

static void LCD_WriteCMD(u8 CMD)
{
	DIO_voidSetPin(LCD_RS, LOW); //RS = 0 Write command
	DIO_voidSetPin(LCD_RW, LOW);
	LCD_WritePin(CMD);
}

static void LCD_WriteData(u8 data)
{
	DIO_voidSetPin(LCD_RS, HIGH); //RS = 1 write data
	DIO_voidSetPin(LCD_RW, LOW);
	LCD_WritePin(data);
}

void LCD_Initialize()
{
	DIO_voidSetDDR(LCD_E, HIGH);
	DIO_voidSetDDR(LCD_RS, HIGH);
	DIO_voidSetDDR(LCD_RW, HIGH);

	/*we send data on mode 8 or 4 according to which LCD supports*/
	#if(LCD_MODE_PIN == LCD_MODE_8)
		//setDirection Output
		DIO_voidSetDDR(LCD_D0, HIGH);
		DIO_voidSetDDR(LCD_D1, HIGH);
		DIO_voidSetDDR(LCD_D2, HIGH);
		DIO_voidSetDDR(LCD_D3, HIGH);
		DIO_voidSetDDR(LCD_D4, HIGH);
		DIO_voidSetDDR(LCD_D5, HIGH);
		DIO_voidSetDDR(LCD_D6, HIGH);
		DIO_voidSetDDR(LCD_D7, HIGH);

		LCD_WriteCMD(LCD_8_MODE_CMD);

	#elif(LCD_MODE_PIN == LCD_MODE_4)
		DIO_voidSetDDR(LCD_D4, HIGH);
		DIO_voidSetDDR(LCD_D5, HIGH);
		DIO_voidSetDDR(LCD_D6, HIGH);
		DIO_voidSetDDR(LCD_D7, HIGH);

	/*to send data on 4 mode we need to write three addresses*/
		LCD_WriteCMD(LCD_4_MODE_CMD_SEQ1);
		LCD_WriteCMD(LCD_4_MODE_CMD_SEQ2);
		LCD_WriteCMD(LCD_4_MODE_CMD_SEQ3);

	#else
		//ERROR
	#endif
	LCD_WriteCMD(LCD_DISPLAY_CMD);
	LCD_WriteCMD(LCD_CLEAR_CMD);
	_delay_ms(3);
}

void LCD_Clear()
{
	LCD_WriteCMD(LCD_CLEAR_CMD);
}

void LCD_Shift(u8 columnShift, u8 rowShift)
{
	LCD_WriteCMD(COLUMN_ZERO + columnShift + (ROW_ZERO * rowShift));
}

void LCD_WriteString(u8 *str)
{
	u8 charCnt = 0;
	while(str[charCnt] != '\0')
	{
		LCD_WriteData(str[charCnt++]);
	}
}

void LCD_WriteStringXY(u8 *str, u8 columnShift, u8 rowShift)
{
	LCD_Shift(columnShift, rowShift);
	LCD_WriteString(str);
}
