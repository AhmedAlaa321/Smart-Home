/*
 * main.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#include "STD_TYPES.h"
#include "util/delay.h"
#include "stdlib.h"
#include <string.h>
#include "LED.h"
#include "LCD.h"
#include "UART.h"
#include "SERVO.h"
#include "BUZZER.h"
#include "Keypad.h"
#include "DC_MOTOR.h"
#include "TEMP_SENSOR.h"
#define PASSWORD_SIZE  4
#define PASSWORD 2411
char tempRead[5] = "";

void intializeDrivers(void);
void wirelessControl(void);
u8 checkPassword(void);
void DOOR_OPEN(void);
void DOOR_CLOSE(void);
void FAN_OPEN(void);
void FAN_CLOSE(void);
void closeAll(void);
void checkFireFlag(void);
void delay(u16 duration);
void keypad_CopyKeyPressed(char *strPtr, u8 passwordSize);

int main()
{
	intializeDrivers();
	closeAll();
	TEMP_EnableInterrupt();
	LCD_WriteStringXY((u8*)"ENTER PASSWORD", 0, 0);
	checkFireFlag();
	delay(1000);
	while(1)
	{
		checkFireFlag();
		if(checkPassword())
		{
			LCD_Clear();
			LCD_WriteStringXY((u8*)"WELCOME HOME", 0, 0);
			checkFireFlag();
			delay(1000);

			LCD_Clear();
			LCD_WriteStringXY((u8*)"Opening DOOR", 0, 0);
			DOOR_OPEN();
			checkFireFlag();
			delay(3000);

			LCD_Clear();
			LCD_WriteStringXY((u8*)"Closing DOOR", 0, 0);
			DOOR_CLOSE();
			checkFireFlag();
			delay(500);


			LCD_Clear();
			LCD_WriteStringXY((u8*)"Illuminate LEDs", 0, 0);
			LED_ON(LED_CHANNEL_0);
			checkFireFlag();
			delay(1000);
			LED_ON(LED_CHANNEL_1);
			checkFireFlag();
			delay(1000);
			LED_ON(LED_CHANNEL_2);
			checkFireFlag();
			delay(1000);

			LCD_Clear();
			LCD_WriteStringXY((u8*)"Opening FAN", 0, 0);
			FAN_OPEN();
			checkFireFlag();
			delay(1000);
			LCD_WriteStringXY((u8*)"Closing FAN", 0, 0);
			FAN_CLOSE();

			//LOOPING TO NOT ASK PASSWORD AGAIN
			while(1)
			{
				checkFireFlag();
			}
		}
		else
		{
			LCD_Clear();
			LCD_WriteStringXY((u8*)"WRONG PASSWORD", 0, 0);
			LCD_WriteStringXY((u8*)"TRY AGAIN!", 0, 1);
			delay(1000);
		}
	}//end of 1st while

}

void intializeDrivers(void)
{
	LED_Initialize();
	LCD_Initialize();
	UART_Initialize();
	SERVO_Initialize();
	BUZZER_Initialize();
	Keypad_Intialize();
	DC_MOTOR_Initialize();
	TEMP_Initialize();
}

void wirelessControl(void)
{
	switch(UART_Read())
	{
		case 1: LED_ON(LED_CHANNEL_0);
				break;

		case 2: LED_OFF(LED_CHANNEL_0);
				break;

		case 3: LED_ON(LED_CHANNEL_1);
				break;

		case 4: LED_OFF(LED_CHANNEL_1);
				break;

		case 5: LED_ON(LED_CHANNEL_2);
				break;

		case 6: LED_OFF(LED_CHANNEL_2);
				break;

		case 7: BUZZER_ON();
				break;

		case 8: BUZZER_OFF();
				break;

		case 9: SERVO_ON(); //OPEN DOOR
				break;

		case 10: SERVO_OFF(); //CLOSE DOOR
				 break;

		case 11: DC_MOTOR_ON(); //TURN FAN ON
				 break;

		case 12: DC_MOTOR_OFF(); //TURN FAN OFF
				 break;

		case 13: LCD_WriteString((u8*) "Testing ESPI");
				 break;

		case 14: LCD_Clear();
	}
}

void keypad_CopyKeyPressed(char *strPtr, u8 passwordSize)
{
	u8 sizeCnt = 0;

	LCD_Clear();
	LCD_WriteStringXY((u8*)"PASSWORD :", 0, 0);
	for(sizeCnt = 0; sizeCnt < passwordSize; /*EMPTY INCERMENT*/)
	{
		if(Keypad_GetKeyPressed() > -1)
		{
			if(Keypad_GetKeyPressed() == 35)
			{
				strcat(&strPtr[sizeCnt], "*");
			}
			else if(Keypad_GetKeyPressed() == 42)
			{
				strcat(&strPtr[sizeCnt], "#");
			}
			else
			{
				Keypad_GetKeyPressedStr(&strPtr[sizeCnt]);
			}
			LCD_WriteStringXY((u8*)strPtr, 0, 1);
			delay(100);
			sizeCnt++;
		}
	}
}

u8 checkPassword(void)
{
	u8 HOME_PASSWORD[PASSWORD_SIZE] = "";
	itoa(PASSWORD, (char*)HOME_PASSWORD, 10);
	LCD_Clear();
	u8 passElement = 0;
	char enteredPassword[PASSWORD_SIZE] = "";

	/*Save entered password into array*/
	keypad_CopyKeyPressed(enteredPassword, PASSWORD_SIZE);
	/*Compare between entered password and saved password*/
	for(passElement = 0; passElement < PASSWORD_SIZE; /*EMPTY INCERMENT*/)
	{
		if(HOME_PASSWORD[passElement] == enteredPassword[passElement])
		{
			passElement++;
		}
		else
		{
			return 0;
		}
	}

	return 1;
}

void DOOR_OPEN(void)
{
	SERVO_ON();
}

void DOOR_CLOSE(void)
{
	SERVO_OFF();
}

void FAN_OPEN(void)
{
	DC_MOTOR_ON();
}

void FAN_CLOSE(void)
{
	DC_MOTOR_OFF();
}

void closeAll(void)
{
	LED_OFF(LED_CHANNEL_0);
	LED_OFF(LED_CHANNEL_1);
	LED_OFF(LED_CHANNEL_2);
	SERVO_OFF();
	DC_MOTOR_OFF();
	BUZZER_OFF();
	LCD_Clear();
}

void checkFireFlag(void)
{
	delay(100);
	if(TEMP_GetFireFlag())
	{
		BUZZER_ON();
		LCD_Clear();
		LCD_WriteStringXY((u8*)"Opening FAN HOT!", 0, 0);
		FAN_OPEN();
		delay(1000);
		LCD_Clear();
		LCD_WriteStringXY((u8*)"TEMP READ = ", 0, 0);
		while(TEMP_GetFireFlag())
		{
			TEMP_STR_READ(tempRead);
			LCD_WriteStringXY((u8*)tempRead, 0, 1);
			delay(100);
		}
		LCD_Clear();
		LCD_WriteStringXY((u8*)"Closing BUZZER", 0, 0);
		LCD_WriteStringXY((u8*)"Closing FAN", 0, 1);
		FAN_CLOSE();
		BUZZER_OFF();
		delay(1000);
		LCD_Clear();
	}
}

void delay(u16 duration)
{
	_delay_ms(duration);
}
