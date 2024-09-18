/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STM32_F103C6_GPIO_drivers.h"
#include "STM32F103x6.h"
#include "STM32_F103C6_EXTI_drivers.h"
#include "LCD.h"
#include "keypad.h"
#include "Seven_Segmant.h"

extern char Seven_Seg_DISPLAY[10];

void Clock_init()
{
	//Enable Clock GPIOA
	RCC_GPIOA_CLK_EN();

	//Enable IOPBEN : IO port B clock enable
	RCC_GPIOB_CLK_EN();
}

/*
void GPIO_init()
{
	GPIO_PinConfig_t PinConfig;

	//A1 Set as Input Floating
	PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinConfig);

	//B1 Set as output Pull & Push
	PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(GPIOB, &PinConfig);


	//A13 Set as Input Floating
	PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinConfig);

	//B13 Set as output Pull & Push
	PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(GPIOB, &PinConfig);
}
 */

void wait(int x)
{
	uint32_t i, j;
	for (i = 0; i < x; i++)
		for (j = 0; j < 255; j++)
			;
}

int main(void)
{
	Clock_init();
	LCD_INIT();

	LCD_WRITE_STRING("Hey");
	wait(100);
	LCD_clear_screen();

	Seven_Seg_Init();
	uint8 LCD_DISPLAY[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char pressed_key;

	for (uint8 i = 0; i < 10; i++)
	{
		LCD_WRITE_CHAR(LCD_DISPLAY[i]);
		Seven_Seg_Write_Num(Seven_Seg_DISPLAY[i]); /* write data on to the LED port */
		wait(100);
		/* wait for 1 second */
	}

	LCD_clear_screen();
	KEYPAD_Init();
	LCD_WRITE_STRING("Keypad is ready");
	wait(30);
	LCD_clear_screen();

	while(1)
	{
		pressed_key = KEYPAD_GetChar();
		switch(pressed_key)
		{
		case 'C':
			LCD_clear_screen();
			break;
		case 'N':
			break;
		default:
			LCD_WRITE_CHAR(pressed_key);
			break;
		}
	}
	return 0;
}
