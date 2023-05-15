/*
 * Copyright 2016-2023 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    quad-control.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

#include "i2c_config.h"
#include "gpio_config.h"
#include "imu_config.h"
#include "pwm_config.h"
#include "test_pwm_config.h"
#include "test_imu_config.h"

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    /* Initialize SDA and SCL Pins as GPIO for IMU */
    gpio_init_imu();

    /* Initializations for IRQ's, I2C, PWM*/
    i2c_init();

    /* Test PWM to all four Motors */
    pwm_init();

    /* Test Functions */
    test_pwm();
    test_imu();

    /* Test Print */
    PRINTF("Welcome to Quad-Control!\r\n");
    delay(BLINK_DELAY); // slight lag to adjust to terminal output

    /* Main Logic - Read From IMU and Write PWM to Motors */
    while(1) {

        imu_write();
        imu_read();
        delay(LAG_DELAY);
        PRINTF("\r\nRecieved data| ax: %d,ay: %d,az: %d,ax_dot: %d,ay_dot: %d,az_dot: %d\r\n", rx[0], rx[1], rx[2], rx[3], rx[4], rx[5]);
        /* 
         * --------- INSERT CONTROL LAW HERE ------------
         *                                              |
         *         TO GET IMU MEASUREMENTS USE:         |
         *                                              |
         *               - imu_read()                   |
         *               - imu_clean()                  |
         *                                              |
         *    SEE 'rx' buffer for x, y, z, x', y', z'   |
         *                                              |
         *      TO SEND PWM SIGNAL TO MOTORS USE:       |
         *                                              |
         *  '1,2,3,4' Represent PWM Signal to ea. motor |
         *                                              |
         *           - tpm_write(1, 2, 3, 4)            |
         *                                              |
         * --------- INSERT CONTROL LAW HERE ------------
         */
        
        /* Write PWM Signal to Motors */
    	pwm_write(PWM_TEST_VAL, PWM_TEST_VAL, PWM_TEST_VAL, PWM_TEST_VAL);
        delay(LAG_DELAY);
        PRINTF("\r\nCurrent Motor PWM Values: M1: %d, M2: %d, M3: %d, M4: %d\r\n", TPM0->CONTROLS[0].CnV, TPM0->CONTROLS[1].CnV, TPM2->CONTROLS[0].CnV, TPM2->CONTROLS[1].CnV);

    }

    return 0 ;
}
