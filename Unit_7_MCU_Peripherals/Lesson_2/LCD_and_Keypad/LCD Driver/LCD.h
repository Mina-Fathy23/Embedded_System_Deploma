/*
 * LCD.h
 *
 *  Created on: Sep 12, 2024
 *      Author: Mina Fathy
 */

#ifndef LCD_DRIVER_LCD_H_
#define LCD_DRIVER_LCD_H_

#include<avr/io.h>
#include<util/delay.h>
#include "../LIB/Utils.h"
#include "../LIB/Platform_Types.h"
#define F_CPU 1000000UL


#define LCD_PORT 			PORTA
#define LCD_DataDir_PORT 	DDRA

#define LCD_CTRL 			PORTB
#define LCD_DataDir_CTRL 	DDRB

#define RS_Switch 		1
#define RW_Switch 		2
#define Enable_Switch 	3
#define DATA_shift		0 // in 8 bit mode 0 and in 4 bit mode 4

// 8 bit mode uses D0 -> D7 to take the 8bit commands
#define EIGHT_BIT_MODE

// 4 bit mode uses D4 -> D7 to take the 8bit commands on two stages
//(Takes MS 4 bits then Command mode then LS 4 bits then Command mode AKA LCD_KICK Function)
//#define FOUR_BIT_MODE

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)


void LCD_INIT(void);
void LCD_WRITE_COMMAND(vuint8_t command);
void LCD_WRITE_CHAR(vuint8_t character);
void LCD_WRITE_STRING(char* string);
void LCD_check_lcd_isbusy(void);
void LCD_clear_screen(void);
void LCD_GOTO_XY(vuint8_t line, vuint8_t position);
void LCD_CUSTOM_CHAR(void);


#endif /* LCD_DRIVER_LCD_H_ */
