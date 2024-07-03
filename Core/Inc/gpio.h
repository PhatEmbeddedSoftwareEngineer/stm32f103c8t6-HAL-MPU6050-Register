/*
 * gpio.h
 *
 *  Created on: Jun 29, 2024
 *      Author: phat
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"

class gpio
{
private:
	const int LED = GPIO_PIN_13;
public:
	void TurnOn();
	void TurnOff();
	void Delay(int delay);
	void MX_GPIO_Init(void);
};

extern gpio _gpio;

#endif /* INC_GPIO_H_ */
