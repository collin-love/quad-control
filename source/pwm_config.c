/*
 * pwm_config.c
 *
 *  Created on: Apr 26, 2023
 *      Author: collinlove
 */

#include "pwm_config.h"
#include "MKL25Z4.h"

void pwm_init(){
    // Initialize 4 GPIO Pins to Write PWM Signal
    
    // allow clock access to port c
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	
    // pin control register clear
	PORTC->PCR[0] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[1] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[2] &= ~PORT_PCR_MUX_MASK;
    PORTC->PCR[3] &= ~PORT_PCR_MUX_MASK;

    // pin control register mux (PTC1, PTC2, PTC3, PTC4)
    PORTC->PCR[0] |= PORT_PCR_MUX(4);
    PORTC->PCR[1] |= PORT_PCR_MUX(4);
    PORTC->PCR[2] |= PORT_PCR_MUX(4);
    PORTC->PCR[3] |= PORT_PCR_MUX(4);

    // configure TPM
    SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;
    SIM->SCGC6 |= SIM_SCGC6_TPM2_MASK;

    // set clock source (48MHz)
    SIM->SOPT2 |= (SIM_SOPT2_TPMSRC(1) | SIM_SOPT2_PLLFLLSEL_MASK);

    // load counter/mod
    TPM0->MOD = PWM_PERIOD - 1; // (48000)
    TPM2->MOD = PWM_PERIOD - 1; // (48000)

    // set TPM count direction up, prescale by 2
    TPM0->SC = TPM_SC_PS(1);
    TPM2->SC = TPM_SC_PS(1);

    // continue in debug mode
    TPM0->CONF |= TPM_CONF_DBGMODE(3);
    TPM2->CONF |= TPM_CONF_DBGMODE(3);
    
    // channel 1 edge-aligned
    TPM0->CONTROLS[0].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
    TPM0->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
    TPM2->CONTROLS[0].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
    TPM2->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;

    // set initial duty cycle
    TPM0->CONTROLS[1].CnV = 0;
    TPM2->CONTROLS[0].CnV = 0;
    TPM2->CONTROLS[1].CnV = 0;

    // start TPM
    TPM0->SC |= TPM_SC_CMOD(1);
    TPM2->SC |= TPM_SC_CMOD(1);
}

void pwm_write(uint16_t motor1, uint16_t motor2, uint16_t motor3, uint16_t motor4){
    // write pwm signal to each motor (PTC1, PTC2, PTC3, PTC4)
    
    // set 1st motor PWM value
    TPM2->CONTROLS[0].CnV = motor1;    
    // set 2nd motor PWM value
    TPM2->CONTROLS[1].CnV = motor2;
    // set 3rd motor PWM value
    TPM0->CONTROLS[0].CnV = motor3;
    // set 4th motor PWM value
    TPM0->CONTROLS[1].CnV = motor4;

}

void pwm_test(uint16_t motor){

    // set motor PWM value
    TPM2->CONTROLS[0].CnV = motor;    

}