/*
 * LCDCONFIG.h
 *
 *  Created on: Jul 10, 2020
 *      Author: Helmy
 */

#ifndef LCDCONFIG_H_
#define LCDCONFIG_H_

#define RS 0
#define RW 1
#define E 2
#define FunctionSet_8Bit 	0b00111000
#define FunctionSet_8Bit_F10 	0b00111100

#define FunctionSet_4bit    0b00100100
#define DisplayON 			0b00001110
#define DisplayOFF 			0b00001010
#define DisplayClear 		0b00000001
#define EntryModeSet	 	0b00000110
#define EntryModeSetARC 	0b00000101

#define PORTCONTROL PORTC
#define PORTDATA PORTD



#endif /* LCDCONFIG_H_ */
