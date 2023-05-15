/*
 * test_pwm_config.c
 *
 *  Created on: May 2, 2023
 *      Author: collinlove
 */

#include "pwm_config.h"
#include "test_pwm_config.h"
#include <assert.h>
#include <stdint.h>
#include <MKL25Z4.h>

void delay(int delay){
    while(delay != 0){
        delay--;
    }
}

void test_pwm1(void) {
    
    // test 0
    pwm_write(0, 0, 0, 0);
    assert(TPM2->CONTROLS[0].CnV == 0);
    assert(TPM2->CONTROLS[1].CnV == 0);
    assert(TPM0->CONTROLS[0].CnV == 0);
    assert(TPM0->CONTROLS[1].CnV == 0);

}

void test_pwm2(){
    
    // test max uint16_t value (65535)
    pwm_write(UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX);
    assert(TPM2->CONTROLS[0].CnV == UINT16_MAX);
    assert(TPM2->CONTROLS[1].CnV == UINT16_MAX);
    assert(TPM0->CONTROLS[0].CnV == UINT16_MAX);
    assert(TPM0->CONTROLS[1].CnV == UINT16_MAX);

}

void test_pwm3(){
    
    // test various
    pwm_write(1234, 5678, 9011, 45015);
    assert(TPM2->CONTROLS[0].CnV == 1234);
    assert(TPM2->CONTROLS[1].CnV == 5678);
    assert(TPM0->CONTROLS[0].CnV == 9011);
    assert(TPM0->CONTROLS[1].CnV == 45015);

}

void test_pwm4(){
    
    // edge case 2: Set motor values to UINT16_MAX - 1
    pwm_write(UINT16_MAX - 1, UINT16_MAX - 1, UINT16_MAX - 1, UINT16_MAX - 1);
    assert(TPM2->CONTROLS[0].CnV == (UINT16_MAX - 1));
    assert(TPM2->CONTROLS[1].CnV == (UINT16_MAX - 1));
    assert(TPM0->CONTROLS[0].CnV == (UINT16_MAX - 1));
    assert(TPM0->CONTROLS[1].CnV == (UINT16_MAX - 1));

}

void test_pwm(){
    
    // test all    
    test_pwm1();
    delay(BLINK_DELAY);
    test_pwm2();
    delay(BLINK_DELAY);
    test_pwm3();
    delay(BLINK_DELAY);
    test_pwm4();

}