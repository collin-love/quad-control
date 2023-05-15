/*
 * pwm_config.h
 *
 *  Created on: Apr 26, 2023
 *      Author: collinlove
 */

#ifndef PWM_CONFIG_H_
#define PWM_CONFIG_H_

#include <stdint.h>

#define PWM_PERIOD 48000
#define PWM_TEST_VAL 125

/* Initialize Pins () to write PWM signals to Logic Stepper */
void pwm_init(void);

/* Write to each of the four motors a pwm value */
void pwm_write(uint16_t motor1, uint16_t motor2, uint16_t motor3, uint16_t motor4);

/* Write to one motor a pwm value */
void pwm_test(uint16_t motor);

#endif /* PWM_CONFIG_H_ */
