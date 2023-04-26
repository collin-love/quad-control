# quad-control

Drivers necessary to read IMU (Inertial Measurement Unit) and control ESC's (Electronic Speed Controllers) on hobby quadcopter. All thats left is the control law! (Based around the NXP FRDM-KL25Z MCU)

Main file is 'quad-control.c', this is where the main logic is located.

## Description: 

This repository provides a quick way to test out various control algorithms to fly a hobby quadcopter. Contained here are the necessary drivers so you can quickly get up and running with your testing without having to worry about the nitty-gritty. This software IS hardware dependent.

## Required Components

## Wiring / System Setup

![plot]()

## Terminal Output

Below is a screenshot of an example terminal output for this program.

![plot]()

## Files (source dir contains all unique files)

    -- quad-control.c (application entry point, initiates communication pipeline from IMU to Motors)

    -- gpio_config.c (all functions created to configure Gen Purpose I/O pins on FRDM-KL25Z)
    -- gpio_config.h (header file with brief description of functions)

    -- i2c_config.c (all functions created to configure i2c communication on FRDM-KL25Z)
    -- i2c_config.h (header file with brief description of functions)

    -- pwm_config.c (all functions created to configure PWM on FRDM-KL25Z to drive motors)
    -- pwm_config.h (header file with brief description of functions)

## To download the repo

    -- git clone "https://github.com/collin-love/quad-control"