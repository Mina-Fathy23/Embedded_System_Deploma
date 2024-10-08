/*
 * STM32F103x6.h
 *
 *  Created on: Sep 16, 2024
 *      Author: Mina Fathy
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//----------------------------
//Includes
//----------------------------

#include <stdlib.h>
#include "Platform_Types.h"
#include "Utils.h"

//----------------------------
//Base addresses for Memories
//----------------------------

#define Flash_Memory_BASE						0x08000000UL
#define System_Memory_BASE						0x1FFFF000UL
#define SRAM_Memory_BASE						0x20000000UL

#define Peripherals_BASE						0x40000000UL

#define Cortex_M3_Internal_Peripherals_BASE		0xE0000000UL

//----------------------------
//Base addresses for AHB Peripherals
//----------------------------

//RCC
#define RCC_BASE								0x40021000UL

//----------------------------
//Base addresses for APB2 Peripherals
//----------------------------

//GPIO
//A,B Fully included in LQFP48 Package
#define GPIOA_Base								0x40010800UL
#define GPIOB_Base								0x40010C00UL

//C,D Partially included in LQFP48 Package
#define GPIOC_Base								0x40011000UL
#define GPIOD_Base								0x40011400UL

//E not included in LQFP48 Package
#define GPIOE_Base								0x40011800UL

//EXTI
#define EXTI_Base								0x40010400UL

//AFIO
#define AFIO_Base								0x40010000UL

//----------------------------
//Base addresses for APB1 Peripherals
//----------------------------


//======================================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef	struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypedDef;

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
			 uint32_t Reserved0; //0x18
	volatile uint32_t MAPR2;	 //0x1C
}AFIO_TypedDef;

//=======================================================================================================

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA				((GPIO_TypeDef *)GPIOA_Base)
#define GPIOB				((GPIO_TypeDef *)GPIOB_Base)
#define GPIOC				((GPIO_TypeDef *)GPIOC_Base)
#define GPIOD				((GPIO_TypeDef *)GPIOD_Base)
#define GPIOE				((GPIO_TypeDef *)GPIOE_Base)

#define RCC					((RCC_TypeDef *)RCC_BASE)

#define EXTI				((EXTI_TypedDef *)EXTI_Base)

#define AFIO				((AFIO_TypedDef *)AFIO_Base)

//========================================================================================================

//-*-*-*-*-*-*-*-*-*-*-*
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |= 1 << 2)
#define RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |= 1 << 3)
#define RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |= 1 << 4)
#define RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |= 1 << 5)
#define RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |= 1 << 6)

#define RCC_AFIO_CLK_EN()	(RCC->APB2ENR |= 1 << 0)

//=========================================================================================================

//-*-*-*-*-*-*-*-*-*-*-*
//IVT
//-*-*-*-*-*-*-*-*-*-*-*
//EXTI
#define EXTI0_IRQ			6
#define EXTI1_IRQ			7
#define EXTI2_IRQ			8
#define EXTI3_IRQ			9
#define EXTI4_IRQ			10
#define EXTI5_IRQ			23
#define EXTI6_IRQ			23
#define EXTI7_IRQ			23
#define EXTI8_IRQ			23
#define EXTI9_IRQ			23
#define EXTI10_IRQ			40
#define EXTI11_IRQ			40
#define EXTI12_IRQ			40
#define EXTI13_IRQ			40
#define EXTI14_IRQ			40
#define EXTI15_IRQ			40

#endif /* INC_STM32F103X6_H_ */
