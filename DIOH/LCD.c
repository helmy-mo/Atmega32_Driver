/*
 * LCD.c
 *
 *  Created on: Jul 10, 2020
 *      Author: Helmy
 */
/* Description ! 16x2 Character LCD for chip LMB161A
 *
 */
/********************************** Header Files INCLUSIONS ****************************/
#include <avr/delay.h>
#include "dio.h"
#include "LCDCONFIG.h"
#include"STD_TYPES.h"

/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7(4bit)  |
 |        PD6|---------------->|D6(4bit)  |
 |        PD5|---------------->|D5(4bit)  |
 |        PD4|---------------->|D4(4bit)  |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PC2|---------------->|E         |
 |        PC1|---------------->|RW        |
 |        PC0|---------------->|RS        |
 -----------                   ----------
 */
void LCD_Vid_SendCommand(unsigned char command)
{
DIO_SetPinValue(PORTCONTROL,RS,LOW);
DIO_SetPinValue(PORTCONTROL,RW,LOW);
DIO_SetPinValue(PORTCONTROL,E,HIGH);
_delay_ms(2);
DIO_SetPortValue(PORTDATA,command);
DIO_SetPinValue(PORTCONTROL,E,LOW);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,HIGH);
}

void LCD_Vid_SendChar(unsigned char Data)
{
	DIO_SetPinValue(PORTCONTROL,RS,HIGH);
	DIO_SetPinValue(PORTCONTROL,RW,LOW);
	DIO_SetPinValue(PORTCONTROL,E,HIGH);
	DIO_SetPortValue(PORTDATA,Data);
	DIO_SetPinValue(PORTCONTROL,E,LOW);
	_delay_ms(2);
	DIO_SetPinValue(PORTCONTROL,E,HIGH);


}
void LCD_Vid_8BitInit(void)
{DIO_SetBinDirection(PORTCONTROL,RS,output);
DIO_SetBinDirection(PORTCONTROL,RW,output);
DIO_SetBinDirection(PORTCONTROL,E,output);
DIO_SetPortdirection(PORTDATA,output);
_delay_ms(30);
LCD_Vid_SendCommand(FunctionSet_8Bit);
_delay_ms(2);
LCD_Vid_SendCommand(DisplayON);
_delay_ms(2);
LCD_Vid_SendCommand(DisplayClear);
_delay_ms(2);
LCD_Vid_SendCommand(EntryModeSet);
}
void LCD_Vid_SendCommand4Bit_test(unsigned char command)
{int x;
DIO_SetPinValue(PORTCONTROL,RS,LOW);
DIO_SetPinValue(PORTCONTROL,RW,LOW);
//x=command>>4;
//x=x&0x0f;
x=command;
x=x&0xf0;
DIO_SetPortValue(PORTDATA,x);

DIO_SetPinValue(PORTCONTROL,E,HIGH);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,LOW);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,HIGH);

DIO_SetPortValue(PORTDATA,x);


DIO_SetPinValue(PORTCONTROL,E,HIGH);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,LOW);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,HIGH);


//*****************************************
x=command<<4;
x=x&0xf0;
DIO_SetPortValue(PORTDATA,x);
DIO_SetPinValue(PORTCONTROL,E,HIGH);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,LOW);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,HIGH);
}

void LCD_Vid_SendCommand4Bit(unsigned char command)
{int x;
DIO_SetPinValue(PORTCONTROL,RS,LOW);
DIO_SetPinValue(PORTCONTROL,RW,LOW);

x=command;
x=x&0xf0;
DIO_SetPortValue(PORTDATA,x);

DIO_SetPinValue(PORTCONTROL,E,HIGH);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,LOW);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,HIGH);



//*****************************************
x=command<<4;
x=x&0xf0;
DIO_SetPortValue(PORTDATA,x);

DIO_SetPinValue(PORTCONTROL,E,HIGH);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,LOW);
_delay_ms(2);
DIO_SetPinValue(PORTCONTROL,E,HIGH);
}

void LCD_Vid_SendChar4Bit(unsigned char Data)
{int x;
	DIO_SetPinValue(PORTCONTROL,RS,HIGH);
	DIO_SetPinValue(PORTCONTROL,RW,LOW);
	x=Data;
	x=x&0xf0;
	DIO_SetPortValue(PORTDATA,x);
	DIO_SetPinValue(PORTCONTROL,E,HIGH);
	_delay_ms(2);
	DIO_SetPinValue(PORTCONTROL,E,LOW);
	_delay_ms(2);
	DIO_SetPinValue(PORTCONTROL,E,HIGH);

	//*****************************************
	x=Data<<4;
	x=x&0xf0;
		DIO_SetPortValue(PORTDATA,x);
	DIO_SetPinValue(PORTCONTROL,E,HIGH);
	_delay_ms(2);
	DIO_SetPinValue(PORTCONTROL,E,LOW);
	_delay_ms(2);
	DIO_SetPinValue(PORTCONTROL,E,HIGH);

}

void LCD_Vid_4BitInit(void)
{
DIO_SetBinDirection(PORTCONTROL,RS,output);
DIO_SetBinDirection(PORTCONTROL,RW,output);
DIO_SetBinDirection(PORTCONTROL,E,output);
DIO_SetPortValue(PORTDATA,output);
_delay_ms(30);
LCD_Vid_SendCommand4Bit_test(FunctionSet_4bit);
_delay_ms(2);
LCD_Vid_SendCommand4Bit(DisplayON);
_delay_ms(2);
LCD_Vid_SendCommand4Bit(DisplayClear);
_delay_ms(2);
LCD_Vid_SendCommand4Bit(EntryModeSet);

}
void LCD_goToRowColumn(unsigned char row,unsigned char col)
{
	unsigned char Address;

	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		case 2:
				Address=col+0x10;
				break;
		case 3:
				Address=col+0x50;
				break;
	}
	/* to write to a specific address in the LCD
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_Vid_SendCommand(Address | 0x80);
}
void lcd_write_num(uint32_t x)
{
	uint32_t y=1;
	if(x==0)
	{
		LCD_Vid_SendChar('0');

	}
	if(x<0)
	{
		LCD_Vid_SendChar('-');
		x=x*-1;
	}
	while(x!=0)
	{
		y=(y*10)+(x%10);
				x=(x/10);
	}
	while (y!=1)
	{
		LCD_Vid_SendChar((y%10)+48);
		y=y/10;
	}

}
void LCD_voidWriteString(unsigned char * str)
{
	while(*str !='\0'){
		LCD_Vid_SendChar(*str++);}
}

void LCD_intgerToString(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* 10 for decimal */
   LCD_voidWriteString(buff);
}








