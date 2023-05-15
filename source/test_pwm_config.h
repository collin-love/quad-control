/*
 * test_pwm_config.h
 *
 *  Created on: May 2, 2023
 *      Author: collinlove
 */

#ifndef TEST_PWM_CONFIG_H_
#define TEST_PWM_CONFIG_H_

#define BLINK_DELAY 10000
#define LAG_DELAY 1000000

/* Basic delay function */
void delay(int delay);

/* Wrapper test function for sending PWM signal to motors */
void test_pwm(void);

// Unit Tests
void test_pwm1(void);

// Unit Tests
void test_pwm2(void);

// Unit Tests
void test_pwm3(void);

// Unit Tests
void test_pwm4(void);

#endif /* TEST_PWM_CONFIG_H_ */
