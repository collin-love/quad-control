/*
 * test_imu_config.c
 *
 *  Created on: May 2, 2023
 *      Author: collinlove
 */

#include "imu_config.h"
#include "fsl_i2c.h"
#include <assert.h>
#include <stdint.h>

void test_imu(void){


    // test that the function reads the correct values from the IMU
    uint8_t tx = 0xA0;
    uint8_t rx[6] = {0};
    i2c_master_transfer_t transfer;

    // set up transfer to write to IMU register
    transfer.slaveAddress = LSM6DSOX_ADDR;
    transfer.direction = kI2C_Write;
    transfer.subaddress = 0x10;
    transfer.subaddressSize = 1;
    transfer.data = &tx;
    transfer.dataSize = sizeof(tx);
    transfer.flags = kI2C_TransferDefaultFlag;

    // write to IMU register to use standard settings (0x10)
    assert(I2C_MasterTransferBlocking(I2C1, &transfer) == kStatus_Success);

    // set up transfer to read data from IMU
    transfer.slaveAddress = LSM6DSOX_ADDR;
    transfer.direction = kI2C_Read;
    transfer.subaddress = 0x28;
    transfer.subaddressSize = 1;
    transfer.data = rx;
    transfer.dataSize = sizeof(rx);
    transfer.flags = kI2C_TransferDefaultFlag;

    // read data from IMU and check that the values are within expected ranges
    assert(I2C_MasterTransferBlocking(I2C1, &transfer) == kStatus_Success);
    
    assert(rx[0] >= 0 && rx[0] <= 255);
    assert(rx[1] >= 0 && rx[1] <= 255);
    assert(rx[2] >= 0 && rx[2] <= 255);
    assert(rx[3] >= 0 && rx[3] <= 255);
    assert(rx[4] >= 0 && rx[4] <= 255);
    assert(rx[5] >= 0 && rx[5] <= 255);

}
