/*
 * imu_config.h
 *
 *  Created on: Apr 30, 2023
 *      Author: collinlove
 */

#ifndef IMU_CONFIG_H_
#define IMU_CONFIG_H_

#include <stdint.h>

#define LSM6DSOX_ADDR 0x6A
#define LIS3MDL_ADDR 0x1C
#define GRAVITY_CONVERSION 16.3840

extern uint8_t rx[6];

/* Read IMU Data into 'rx' buffer */
void imu_read(void);

/* Write from 'tx' buffer */
void imu_write();

/* Convert and filter IMU readings */
void imu_clean();

#endif /* IMU_CONFIG_H_ */
