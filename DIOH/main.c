/*
 * main.c
 *
 *  Created on: Jun 21, 2020
 *      Author: Helmy
 */

#define F_CPU 8000000
#include "avr/delay.h"
#include"DIO_Types.h"
#include"bit_math.h"
#include"dio.h"
#include"dio_reg.h"
#include"LCD.h"

int main()
{DIO_SetBinDirection(PORTB, 0, input);
DIO_SetBinDirection(PORTB, 1, input);
DIO_SetBinDirection(PORTB,2,input);
DIO_SetBinDirection(PORTB,3,output);
DIO_SetBinDirection(PORTB,4,output);
while(1){

if(DIO_GetPinValue(PORTB, 0)==0&&DIO_GetPinValue(PORTB, 1)==1&&DIO_GetPinValue(PORTB, 2)==0)

{DIO_SetPinValue(PORTB,pin3,LOW);
DIO_SetPinValue(PORTB,pin4,HIGH);
DIO_SetPinValue(PORTB,pin5,LOW);
	DIO_SetPinValue(PORTB,pin6,HIGH);
LCD_Vid_SendChar()('A');
}

else if ((DIO_GetPinValue(PORTB, 0)==1&&DIO_GetPinValue(PORTB, 1)==0&&DIO_GetPinValue(PORTB, 2)==0)||(DIO_GetPinValue(PORTB, 0)==1&&DIO_GetPinValue(PORTB, 1)==1&&DIO_GetPinValue(PORTB, 2)==0))

{DIO_SetPinValue(PORTB,pin3,LOW);
DIO_SetPinValue(PORTB,pin4,HIGH);
	DIO_SetPinValue(PORTB,pin5,LOW);
	DIO_SetPinValue(PORTB,pin6,LOW);
LCD_Vid_SendChar('B');
}

else if ((DIO_GetPinValue(PORTB, 0)==0&&DIO_GetPinValue(PORTB, 1)==0&&DIO_GetPinValue(PORTB, 2)==1)||(DIO_GetPinValue(PORTB, 0)==0&&DIO_GetPinValue(PORTB, 1)==1&&DIO_GetPinValue(PORTB, 2)==1))
{DIO_SetPinValue(PORTB,pin5,LOW);
DIO_SetPinValue(PORTB,pin6,HIGH);
DIO_SetPinValue(PORTB,pin3,LOW);
DIO_SetPinValue(PORTB,pin4,LOW);
LCD_Vid_SendChar('C');
}
else
{DIO_SetPinValue(PORTB,pin3,LOW);
DIO_SetPinValue(PORTB,pin4,LOW);
DIO_SetPinValue(PORTB,pin5,LOW);
	DIO_SetPinValue(PORTB,pin6,LOW);
LCD_Vid_SendChar('D');
}}}

