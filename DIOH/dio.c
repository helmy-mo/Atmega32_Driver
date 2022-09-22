/*
 * dio.c
 *
 *  Created on: Feb 25, 2020
 *      Author: helmy_
 */
#include "dio_reg.h"
#include "DIO_Types.h"
#include "bit_math.h"
#include "dio.h"

void DIO_SetPortdirection(DIO_PORT_ID Port_Id ,DIO_Direction Direction)
{
	if (output == Direction)
	{
		switch(Port_Id)
		{
		case PORTA: DDRA_Reg= 0xff;break;
		case PORTB: DDRB_Reg= 0xff;break;
		case PORTC: DDRC_Reg= 0xff;break;
		case PORTD: DDRD_Reg= 0xff;break;

		}

	}
	else if(input == Direction)
	{
			switch(Port_Id)
			{
			case PORTA:DDRA_Reg = 0x00;break;
			case PORTB:DDRB_Reg = 0x00;break;
			case PORTC:DDRC_Reg = 0x00;break;
			case PORTD:DDRD_Reg = 0x00;break;
			}
	}
}

void DIO_SetPortValue(DIO_PORT_ID Port_Id,unsigned char value)
{
	switch(Port_Id)
			{
			case PORTA: PORTA_Reg= value;break;
			case PORTB: PORTB_Reg= value;break;
			case PORTC: PORTC_Reg= value;break;
			case PORTD: PORTD_Reg= value;break;
			}

};
void DIO_SetBinDirection(DIO_PORT_ID Port_Id,DIO_PORT_ID pin_id,DIO_Direction Direction)
{
	if(Port_Id <= PORTD && pin_id<=pin7)
{	if ( output == Direction )
{
	switch(Port_Id)
				{
				case PORTA: SET_BIT(DDRA_Reg,pin_id);break;
				case PORTB: SET_BIT(DDRB_Reg,pin_id);break;
				case PORTC: SET_BIT(DDRC_Reg,pin_id);break;
				case PORTD: SET_BIT(DDRD_Reg,pin_id);break;
				}
}
       else if(input == Direction )
	{
	switch(Port_Id)
			{
			case PORTA : CLEAR_BIT(DDRA_Reg,pin_id) ; break;
			case PORTB : CLEAR_BIT(DDRB_Reg,pin_id) ; break;
			case PORTC : CLEAR_BIT(DDRC_Reg,pin_id) ; break;
			case PORTD : CLEAR_BIT(DDRD_Reg,pin_id) ; break;
			}

}

}
}
void DIO_SetPinValue(DIO_PORT_ID Port_Id,DIO_PORT_ID pin_id,DIO_Value value)
{
	if(Port_Id <= PORTD && pin_id<=pin7)
	{
if(value == HIGH)
{switch(Port_Id)
{
case PORTA: SET_BIT(PORTA_Reg,pin_id);break;
case PORTB: SET_BIT(PORTB_Reg,pin_id);break;
case PORTC: SET_BIT(PORTC_Reg,pin_id);break;
case PORTD: SET_BIT(PORTD_Reg,pin_id);break;
}}
else if(value == LOW)
{
	switch(Port_Id)
{
case PORTA: CLEAR_BIT(PORTA_Reg,pin_id);break;
case PORTB: CLEAR_BIT(PORTB_Reg,pin_id);break;
case PORTC: CLEAR_BIT(PORTC_Reg,pin_id);break;
case PORTD: CLEAR_BIT(PORTD_Reg,pin_id);break;
}
}
}};
DIO_Value DIO_GetPinValue(DIO_PORT_ID Port_Id,DIO_PORT_ID pin_id)
	{DIO_Value val;

		if(Port_Id <= PORTD && pin_id<=pin7)
		{		switch (Port_Id)
			{   case PORTA : val = GET_BIT(PINA_Reg,pin_id);break;
				case PORTB : val = GET_BIT(PINB_Reg,pin_id);break;
				case PORTC : val = GET_BIT(PINC_Reg,pin_id);break;
				case PORTD : val = GET_BIT(PIND_Reg,pin_id);break;
			}
		}
		return val;
	}







