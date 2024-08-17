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

#include "Platform_Types.h"
// register address

#define GPIO_PORTF_BASE 		0x40025000

#define SYSCTL_RCGC2_R 			*((vuint32_t*)(0x400FE108))
#define GPIO_PORTF_DIR_R		*((vuint32_t*)(GPIO_PORTF_BASE + 0x400))
#define GPIO_PORTF_DEN_R		*((vuint32_t*)(GPIO_PORTF_BASE + 0x51C))
#define GPIO_PORTF_DATA_R		*((vuint32_t*)(GPIO_PORTF_BASE + 0x3FC))




int main(void)
{
	SYSCTL_RCGC2_R = 0x20;
	//delay to make sure GPIOF is up and running
	vuint32_t delay_count;
	for(delay_count = 0; delay_count < 200; delay_count++);
	
	GPIO_PORTF_DIR_R |= 1 << 3; //Dir of Pin 3 is set as output
	GPIO_PORTF_DEN_R |= 1 << 3;	//Pin 3 is Enabled
	

	while(1)
	{
		GPIO_PORTF_DATA_R |= 1 << 3;			//set bit 3
		for(delay_count = 0; delay_count < 100000; delay_count++);
		GPIO_PORTF_DATA_R &= ~(1 << 3);	 	//clear bit 3
		for(delay_count = 0; delay_count < 100000; delay_count++);

	}
	return 0;
}