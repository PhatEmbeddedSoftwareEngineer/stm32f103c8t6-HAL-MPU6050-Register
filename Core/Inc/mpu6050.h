/*
 * mpu6050.h
 *
 *  Created on: Jul 1, 2024
 *      Author: phat
 */

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include <stdint.h>
#include "i2c.h"


#define RAD_TO_DEG 57.295779513082320876798154814105

/* address hex register*/

#define WHO_AM_I_REG 0x75
#define PWR_MGMT_1_REG 0x6B
#define SMPLRT_DIV_REG 0x19
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_CONFIG_REG 0x1B
#define GYRO_XOUT_H_REG 0x43


// address i2c mpu6050 is 0xD0
#define MPU6050_ADDR 0xD0



// MPU6050 structure

typedef struct
{
	int16_t Accel_X_RAW;
	int16_t Accel_Y_RAW;
	int16_t Accel_Z_RAW;

	double Ax;
	double Ay;
	double Az;

	int16_t Gyro_X_RAW;
	int16_t Gyro_Y_RAW;
	int16_t Gyro_Z_RAW;

	double Gx;
	double Gy;
	double Gz;

	float Temperature;

	double KalmanAngleX;
	double KalmanAngleY;


}MPU6050_t;


// Kalman structure
typedef struct {
    double Q_angle;
    double Q_bias;
    double R_measure;
    double angle;
    double bias;
    double P[2][2];
} Kalman_t;

class mpu6050
{
private:
	MPU6050_t Mpu6050;
	Kalman_t kalmanX,kalmanY;
	const uint16_t i2c_timeout = 100;
	const double Accel_Z_corrector = 14418.0;
	uint32_t timer;
public:
	mpu6050();
	uint8_t MPU6050_Init(I2C_HandleTypeDef *I2Cx);

	void MPU6050_Read_Accel(I2C_HandleTypeDef *I2Cx, MPU6050_t *DataStruct);

	void MPU6050_Read_Gyro(I2C_HandleTypeDef *I2Cx, MPU6050_t *DataStruct);

	void MPU6050_Read_Temp(I2C_HandleTypeDef *I2Cx, MPU6050_t *DataStruct);

	void MPU6050_Read_All(I2C_HandleTypeDef *I2Cx, MPU6050_t *DataStruct);

	double Kalman_getAngle(Kalman_t *Kalman, double newAngle, double newRate, double dt);

};

extern mpu6050 _mpu;




#endif /* INC_MPU6050_H_ */
