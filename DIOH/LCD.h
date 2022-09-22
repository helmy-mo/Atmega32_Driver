/*
 * LCD.h
 *
 *  Created on: Jul 10, 2020
 *      Author: Helmy
 */

#ifndef LCD_H_
#define LCD_H_
void LCD_Vid_8BitInit(void);
void LCD_Vid_SendChar(unsigned char Data);
void LCD_Vid_SendCommand(unsigned char command);
void LCD_Vid_4BitInit(void);
void LCD_Vid_SendChar4Bit(unsigned char Data);
void LCD_Vid_SendCommand4Bit(unsigned char command);
void LCD_Vid_SendCommand4Bit_test(unsigned char command);
void LCD_goToRowColumn(unsigned char row,unsigned char col);
void lcd_write_num(uint32_t x);
void LCD_voidWriteString(unsigned char * str);
void LCD_intgerToString(int data);

#endif /* LCD_H_ */
