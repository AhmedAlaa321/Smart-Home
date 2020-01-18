/*
 * Temp_Sensor.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H
#include "STD_TYPES.h"

void TEMP_Initialize(void);
void TEMP_STR_READ(char *strPtr);
u8 TEMP_READ(void);
void TEMP_EnableInterrupt(void);
u8 TEMP_GetFireFlag(void);

#endif /* TEMP_SENSOR_H */
