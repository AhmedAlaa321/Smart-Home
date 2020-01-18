/*
 * DIO.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#include "BIT_MATH.h"
#include "DIO_REG.h"
#include "DIO.h"
#define PORTS_RANGE 8

void DIO_voidSetDDR(H_PINS pinIndex, u8 directionStatus)
{
	switch(pinIndex)
	{

		//Don't use pinVal directly cause we need it at statements cause we need it at specific conditions
		case 0 ... 7: if(directionStatus == HIGH)
					  {
					      SET_BIT(DDRD, pinIndex);
					  }
					  else if(directionStatus == LOW)
					  {
						  CLEAR_BIT(DDRD, pinIndex);
					  }
					  else
					  {
						  //Error on LCD
					  }
					  break;

		case 8 ... 15: if(directionStatus == HIGH)
					   {
					      SET_BIT(DDRC, (pinIndex-PORTS_RANGE));
					   }
					   else if(directionStatus == LOW)
					   {
						  CLEAR_BIT(DDRC, (pinIndex-PORTS_RANGE));
					   }
					   else
					   {
						  //Error on LCD
					   }
					   break;

		case 16 ... 23: if(directionStatus == HIGH)
					    {
						  SET_BIT(DDRB, (pinIndex-(2*PORTS_RANGE)));
					    }
					    else if(directionStatus == LOW)
					    {
					      CLEAR_BIT(DDRB, (pinIndex-(2*PORTS_RANGE)));
				     	}
					    else
					    {
						  //Error on LCD
					    }
						break;

		case 24 ... 31: if(directionStatus == HIGH)
					    {
					      SET_BIT(DDRA, (pinIndex-(3*PORTS_RANGE)));
					    }
					    else if(directionStatus == LOW)
					    {
					      CLEAR_BIT(DDRA, (pinIndex-(3*PORTS_RANGE)));
					    }
					    else
					    {
						  //Error on LCD
					    }
						break;
		}
}

void DIO_voidSetPort(H_PORTS port, u8 portVal)
{
	switch(port)
	{
		case H_PORTA: PORTA = portVal;
					 break;

		case H_PORTB: PORTB = portVal;
					 break;

		case H_PORTC: PORTC = portVal;
					 break;

		case H_PORTD: PORTD = portVal;
					 break;
	}
}

void DIO_voidSetPin(H_PINS pinIndex, u8 pinVal)
{
	switch(pinIndex)
	{
		//Don't use pinVal directly cause we need it at statements cause we need it at specific conditions
		case 0 ... 7: if(pinVal == HIGH)
					  {
					      SET_BIT(PORTD, pinIndex);
					  }
					  else if(pinVal == LOW)
					  {
						  CLEAR_BIT(PORTD, pinIndex);
					  }
					  else
					  {
						  //Error on LCD
					  }
					  break;

		case 8 ... 15: if(pinVal == HIGH)
					   {
					      SET_BIT(PORTC, (pinIndex-PORTS_RANGE));
					   }
					   else if(pinVal == LOW)
					   {
						  CLEAR_BIT(PORTC, (pinIndex-PORTS_RANGE));
					   }
					   else
					   {
						  //Error on LCD
					   }
					   break;

		case 16 ... 23: if(pinVal == HIGH)
					    {
						  SET_BIT(PORTB, (pinIndex-(2*PORTS_RANGE)));
					    }
					    else if(pinVal == LOW)
					    {
					      CLEAR_BIT(PORTB, (pinIndex-(2*PORTS_RANGE)));
				     	}
					    else
					    {
						  //Error on LCD
					    }
						break;

		case 24 ... 31: if(pinVal == HIGH)
					    {
					      SET_BIT(PORTA, (pinIndex-(3*PORTS_RANGE)));
					    }
					    else if(pinVal == LOW)
					    {
					      CLEAR_BIT(PORTA, (pinIndex-(3*PORTS_RANGE)));
					    }
					    else
					    {
						  //Error on LCD
					    }
						break;
		}
}

u8 DIO_getPortVal(H_PORTS port)
{
	u8 pinVal = 0;
	switch(port)
	{
		case H_PORTA: pinVal = PINA;
					  break;

		case H_PORTB: pinVal = PINB;
					  break;

		case H_PORTC: pinVal = PINC;
					  break;

		case H_PORTD: pinVal = PIND;
					  break;
	}
	return pinVal;
}

u8 DIO_getPinVal(H_PINS pinIndex)
{
    u8 pinVal = 0;
    switch(pinIndex)
	{
    	case 0 ... 7: pinVal = GET_BIT(PIND, pinIndex);
    				  break;

    	case 8 ... 15: pinVal = GET_BIT(PINC, (pinIndex-PORTS_RANGE));
    				   break;

    	case 16 ... 23: pinVal = GET_BIT(PINB, (pinIndex-(2*PORTS_RANGE)));
    			  	    break;

    	case 24 ... 31: pinVal = GET_BIT(PINA, (pinIndex-(3*PORTS_RANGE)));
    				    break;
	}
    return pinVal;
}
