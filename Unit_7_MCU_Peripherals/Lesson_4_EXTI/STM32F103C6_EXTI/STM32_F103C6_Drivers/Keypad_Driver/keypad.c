/*
 * keypad.c
 *
 *  Created on: Sep 12, 2024
 *      Author: Mina Fathy
 */

#include "keypad.h"



vuint8_t keypad_R[4] = {R0, R1, R2, R3}; //rows of the keypad
vuint8_t keypad_C[4] = {C0, C1, C2, C3}; //columns
char keypad_character[4][4] = {
		{'7', '8', '9', '/'},
		{'4', '5', '6', 'X'},
		{'1', '2', '3', '-'},
		{'C', '0', '=', '+'}  };

/**================================================================
 * @Fn				- KEYPAD_Init
 * @breif			- Initializes Keypads' Port
 * @param [in]		- None
 * @retval			- None
 * Note				- None
 */
void KEYPAD_Init()
{
	/*	KEYPAD_DataDir &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
	KEYPAD_DataDir |=  ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
	KEYPAD_PORT = 0xFF;
	 */

	GPIO_PinConfig_t PinCfg;

	//Set PIN R0 >> R3 Set as Output Pull-Push
	PinCfg.GPIO_PinNumber = R0;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = R1;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = R2;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = R3;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	//=========================================================

	//Set C0 >> C3 as Output Push-Pull
	PinCfg.GPIO_PinNumber = C0;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = C1;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = C2;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = C3;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	//SET Keypad Port to Logic 1
	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);

}

/**================================================================
 * @Fn				- KEYPAD_GetChar
 * @breif			- Checks for the pressed button
 * @param [in]		- None
 * @retval			- the pressed button as ASCII Code char
 * Note				- None
 */
char KEYPAD_GetChar()
{
	vuint8_t i, j;
	for(i = 0; i < 4; i++)
	{
		//KEYPAD_PORT |= ((1 << keypad_C[0]) | (1 << keypad_C[1]) |(1 << keypad_C[2]) | (1 << keypad_C[3]));
		//ClearBit(KEYPAD_PORT, keypad_C[i]);

		//SET C0 >> C3 to Logic 1
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_C[0], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_C[1], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_C[2], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_C[3], GPIO_PIN_SET);

		//Clear C[i] to Logic 0
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_C[i], GPIO_PIN_RESET);

		for(j = 0; j < 4; j++)
		{
			if(!MCAL_GPIO_ReadPin(KEYPAD_PORT, keypad_R[j]))
			{
				while(!MCAL_GPIO_ReadPin(KEYPAD_PORT, keypad_R[j]))
				{
					//Will Still pressed DO Noting
				}
				return keypad_character[j][i];
			}
		}
	}
	return 'N';
}


