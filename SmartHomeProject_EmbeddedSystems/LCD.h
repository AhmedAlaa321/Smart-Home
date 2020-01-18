/*
 * LCD.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef LCD_H
#define LCD_H
#include"STD_TYPES.h"

#define COLUMN_ZERO 0x80 // 0x80 first panel on LCD
#define ROW_ZERO 0x40

#define LCD_CLEAR_CMD 0x01
#define LCD_DISPLAY_CMD 0X0E

#define LCD_8_MODE_CMD 0x38 //MODE 8 PINS
#define LCD_4_MODE_CMD_SEQ1 0x23 //MODE 4 PINS
#define LCD_4_MODE_CMD_SEQ2 0x22 //MODE 4 PINS
#define LCD_4_MODE_CMD_SEQ3 0x28 //MODE 4 PINS
//#define F_CPU 16000000UL

void LCD_Initialize(void);
void LCD_Shift(u8 columnShift, u8 rowShift);
void LCD_WriteString(u8 *str);
void LCD_Clear(void);
void LCD_WriteStringXY(u8 *str, u8 columnShift, u8 rowShift);

#endif // LCD_H
