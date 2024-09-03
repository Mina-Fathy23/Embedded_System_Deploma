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


#include "stdint.h"
#include "Platform_Types.h"
// register address

#define PortA_BASE 	0x40010800
#define RCC_BASE	0x40021000

#define GPIOA_CRH		*((vuint32_t*)(PortA_BASE + 0x04))
#define GPIOA_ODR		*((vuint32_t*)(PortA_BASE + 0x0C))
#define RCC_APB2ENR		*((vuint32_t*)(RCC_BASE   + 0x18))



int main(void)
{
	//	Bit 2 IOPAEN: IO port A clock enable
	//	 Set and cleared by software.
	//	 0: IO port A clock disabled
	//	 1: IO port A clock enabled

	RCC_APB2ENR |= 1 << 2;

	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

	while(1)
	{
		GPIOA_ODR |= 1 << 13;			//set bit 13
		//R_ODR->pin.pin13= 1;
		for(int i = 0;  i < 10000; i++);
		GPIOA_ODR &= ~(1 << 13);	 	//clear bit 13
		//R_ODR->pin.pin13= 0;
		for(int i = 0;  i < 100000; i++);

	}
	return 0;
}
