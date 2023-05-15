/*
 * i2c_config.h
 *
 *  Created on: Apr 26, 2023
 *      Author: collinlove
 */

#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_

#include <stdint.h>
#include "fsl_i2c.h"

#define I2C_BAUDRATE 100000 // 115200

/* Initialize i2c for use */
void i2c_init(void);

#endif /* I2C_CONFIG_H_ */
