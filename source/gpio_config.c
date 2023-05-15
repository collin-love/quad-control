/*
 * gpio_config.c
 *
 *  Created on: Apr 26, 2023
 *      Author: collinlove
 */

#include "gpio_config.h"
#include <fsl_gpio.h>
#include <fsl_port.h>
#include <MKL25Z4.h>

void gpio_init_imu(){
    
    // set clock for porte
    SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
    // set port e0 for SDA
    PORTE->PCR[I2C_GPIO_SDA_PIN] |= PORT_PCR_MUX(I2C_MUX); 
    // set port e1 for SCL
    PORTE->PCR[I2C_GPIO_SCL_PIN] |= PORT_PCR_MUX(I2C_MUX); 
    // set port e0 to pull up
    PORTE->PCR[I2C_GPIO_SDA_PIN] |= PORT_PCR_PE_MASK;
    // set port e1 to pull up
    PORTE->PCR[I2C_GPIO_SDA_PIN] |= PORT_PCR_PE_MASK;

}

