/*
 * i2c_config.c
 *
 *  Created on: Apr 26, 2023
 *      Author: collinlove
 *  
 *  Credits: Lalit Pandit, Rikita, Hari, Daanish, Alex Dean: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_8/I2C-Demo/src/i2c.c
 * 
 */

#include "i2c_config.h"
#include <fsl_i2c.h>
#include <stdio.h>
#include <MKL25Z4.h>

i2c_master_config_t i2cConfig;

void i2c_init(){

    // Get generic I2C config from SDK   
    I2C_MasterGetDefaultConfig(&i2cConfig);
    // Initialize I2C1 with Generic Config, 100k baudrate, and I2C1 Clock Source
    I2C_MasterInit(I2C1, &i2cConfig, CLOCK_GetFreq(I2C1_CLK_SRC));


}
