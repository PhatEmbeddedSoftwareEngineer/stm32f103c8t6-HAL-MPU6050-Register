/*
 * i2c.h
 *
 *  Created on: Jul 1, 2024
 *      Author: phat
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "main.h"

extern I2C_HandleTypeDef hi2c1;

class initI2C
{
public:
	void MX_I2C1_Init(void);
	void HAL_I2C_MspInit(I2C_HandleTypeDef* i2cHandle);
	void HAL_I2C_MspDeInit(I2C_HandleTypeDef* i2cHandle);
};

extern initI2C _i2c;



#endif /* INC_I2C_H_ */
