/*
 * DIO_REG.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef REGISTERS_H
#define REGISTERS_H

/*GROUP A Register*/
//(*((u8*)0x3B)) content of pointer with u8 type
#define PORTA (*((volatile u8*)0x3B))
#define DDRA  (*((volatile u8*)0x3A))
#define PINA  (*((volatile u8*)0x39))


/*GROUP B Register*/
#define PORTB (*((volatile u8*)0x38))
#define DDRB  (*((volatile u8*)0x37))
#define PINB  (*((volatile u8*)0x36))


/*GROUP C Register*/
#define PORTC (*((volatile u8*)0x35))
#define DDRC  (*((volatile u8*)0x34))
#define PINC  (*((volatile u8*)0x33))


/*GROUP D Register*/
#define PORTD (*((volatile u8*)0x32))
#define DDRD  (*((volatile u8*)0x31))
#define PIND  (*((volatile u8*)0x30))

#endif
