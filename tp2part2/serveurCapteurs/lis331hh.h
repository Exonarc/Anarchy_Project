/*
 *  lis331hh.h
 *  
 *
 *  Created by mathieu porez on 24/10/12.
 *  Copyright 2012 emn. All rights reserved.
 *
 */

#ifndef _LIS331HH_H
#define _LIS331HH_H

#define LIS331HH_PORT "/dev/i2c-3"
#define LIS331HH_ADDR 0x18

#define LIS331HH_CTRL_REG1 0x20
#define LIS331HH_CTRL_REG2 0x21
#define LIS331HH_CTRL_REG3 0X22
#define LIS331HH_CTRL_REG4 0x23
#define LIS331HH_CTRL_REG5 0x24
#define LIS331HH_HP_FILTER_RESET 0x25
#define LIS331HH_REFERENCE 0x26
#define LIS331HH_STATUS_REG 0x27
#define LIS331HH_OUT_X_L 0x28
#define LIS331HH_OUT_X_H 0x29
#define LIS331HH_OUT_Y_L 0x2A
#define LIS331HH_OUT_Y_H 0x2B
#define LIS331HH_OUT_Z_L 0x2C
#define LIS331HH_OUT_Z_H 0x2D
#define LIS331HH_INT1_CFG 0x30
#define LIS331HH_INT1_SOURCE 0x31
#define LIS331HH_INT1_THS 0x32
#define LIS331HH_INT1_DURATION 0x33
#define LIS331HH_INT2_CFG 0x34
#define LIS331HH_INT2_SOURCE 0x35
#define LIS331HH_INT2_THS 0x36
#define LIS331HH_INT2_DURATION 0x37

#define XAXIS 0
#define YAXIS 1
#define ZAXIS 2

#define LIS331HH_ACC_CONV 0.001796

#include <fcntl.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdio.h>

int acc_power_on(void);
int acc_power_off(void);
float acc_read_acceleration(char axis);
int acc_read_register(char reg, char * val);
int acc_write_register(char reg, char val);

#endif


