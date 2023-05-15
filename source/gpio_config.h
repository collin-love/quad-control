/*
 * gpio_config.h
 *
 *  Created on: Apr 26, 2023
 *      Author: collinlove
 */

#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

#include <stdint.h>

#define I2C_GPIO_SCL_PIN  1
#define I2C_GPIO_SDA_PIN  0
#define I2C_MUX 6

/* Initialize GPIO SDA and SCL Pins for IMU */
void gpio_init_imu();

#endif /* GPIO_CONFIG_H_ */
