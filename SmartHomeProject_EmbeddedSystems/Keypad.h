/*
 * Keypad.h
 *
 *  Created on: Oct 1, 2019
 *      Author: MahmoudGamal
 */

#ifndef KEYPAD_H
#define KEYPAD_H
#include "STD_TYPES.h"

#define KEYPAD_PULL_UP_ENABLE_MSK 0b11110000

void Keypad_Intialize(void);
void Keypad_GetKeyPressedStr(char *strPtr);
s8 Keypad_GetKeyPressed(void);

#endif /* KEYPAD_H_ */
