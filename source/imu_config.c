/*
 * imu_config.c
 *
 *  Created on: Apr 30, 2023
 *      Author: collinlove
 */

#include "imu_config.h"
#include "i2c_config.h"

uint8_t tx = 0xA0;
uint8_t rx[6] = {0};
int16_t ax, ay, az, ax_dot, ay_dot, az_dot;
uint8_t test;

i2c_master_transfer_t transfer;

void imu_read(){

    // Read x, y, z, x', y', z' from IMU
    transfer.slaveAddress = LSM6DSOX_ADDR;
    transfer.direction = kI2C_Read;
    transfer.subaddress = 0x28; //0x0F; // whoami register
    transfer.subaddressSize = 1;
    transfer.data = rx;
    transfer.dataSize = sizeof(rx);
    transfer.flags = kI2C_TransferCompleteFlag;
    I2C_MasterTransferBlocking(I2C1, &transfer);

    // Clean Data Before Return
    imu_clean();

}

void imu_write(){

    // Write to IMU register to use standard settings (0x10)
    transfer.slaveAddress = LSM6DSOX_ADDR;
    transfer.direction = kI2C_Write;
    transfer.subaddress = 0x10;
    transfer.subaddressSize = 1;
    transfer.data = &tx;
    transfer.dataSize = 1;
    transfer.flags = kI2C_TransferCompleteFlag;
    I2C_MasterTransferBlocking(I2C1, &transfer);

}

void imu_clean(){

    // process accelerometer data
    ax     = (uint16_t)rx[0];
    ay     = (uint16_t)rx[2];
    az     = (uint16_t)rx[4];
    ax_dot = (uint16_t)rx[1];
    ay_dot = (uint16_t)rx[3];
    az_dot = (uint16_t)rx[5];

    // convert raw data to acceleration in g
    float ax_g     = (float)ax / GRAVITY_CONVERSION;
    float ay_g     = (float)ay / GRAVITY_CONVERSION;
    float az_g     = (float)az / GRAVITY_CONVERSION;
    float ax_dot_g = (float)ax / GRAVITY_CONVERSION;
    float ay_dot_g = (float)ay / GRAVITY_CONVERSION;
    float az_dot_g = (float)az / GRAVITY_CONVERSION;

    // return data in SI units
    rx[0] = (uint8_t)ax_g;
    rx[1] = (uint8_t)ay_g;
    rx[2] = (uint8_t)az_g;
    rx[3] = (uint8_t)ax_dot_g;
    rx[4] = (uint8_t)ay_dot_g;
    rx[5] = (uint8_t)az_dot_g;

}
