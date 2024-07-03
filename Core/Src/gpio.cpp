/*
 * gpio.cpp
 *
 *  Created on: Jun 29, 2024
 *      Author: phat
 */


#include "gpio.h"

void gpio::TurnOn()
{
	HAL_GPIO_WritePin(GPIOC, LED, GPIO_PIN_SET);
}

void gpio::TurnOff()
{
	HAL_GPIO_WritePin(GPIOC, LED, GPIO_PIN_RESET);
}

void gpio::Delay(int delay)
{
	HAL_Delay(delay);
}

void gpio::MX_GPIO_Init()
{
	/* GPIO Ports Clock Enable */
	//__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
}

gpio _gpio;
