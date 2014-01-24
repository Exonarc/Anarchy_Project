/*
 *  lis331hh.c
 *  
 *
 *  Created by mathieu porez on 24/10/12.
 *  Copyright 2012 emn. All rights reserved.
 *
 */

#include "lis331hh.h"

int acc_power_on(void)
{
	int fd;
	char mess[2];
	mess[0]=LIS331HH_CTRL_REG1;
	mess[1]=0x27;
	fd=open(LIS331HH_PORT, O_RDWR);
	if (fd == NULL)
	{
		return 0;
	}
	ioctl(fd,I2C_SLAVE,LIS331HH_ADDR);
	write(fd,mess,2);
	close(fd);
	return 1;
}

void acc_power_off(void)
{
	int fd;
	char mess[2];
	mess[0]=LIS331HH_CTRL_REG1;
	mess[1]=0x07;
	fd=open(LIS331HH_PORT, O_RDWR);
	ioctl(fd,I2C_SLAVE,LIS331HH_ADDR);
	write(fd,mess,2);
	close(fd);
}

int acc_read_register(char reg, char * val)
{
	int fd;
	fd=open(LIS331HH_PORT, O_RDWR);
	if (fd == NULL)
	{
		return 0;
	}
	ioctl(fd,I2C_SLAVE,LIS331HH_ADDR);
	write(fd,&reg,1);
	read(fd,val,1);
	close(fd);
	return 1;
}

int acc_write_register(char reg, char val)
{
	int fd;
	char mess[2];
	mess[0]=reg;
	mess[1]=val;
	fd=open(LIS331HH_PORT, O_RDWR);
	if (fd == NULL)
	{
		return 0;
	}
	ioctl(fd,I2C_SLAVE,LIS331HH_ADDR);
	write(fd,mess,2);
	close(fd);
	return 1;
}

float acc_read_acceleration(char axis)
{
	char buffh, buffl;
	int acc_integer;
	float acc_float;
	
	switch (axis) {
		case XAXIS:
			acc_read_register(LIS331HH_OUT_X_H, &buffh);
			acc_read_register(LIS331HH_OUT_X_L, &buffl);
			break;
		case YAXIS:
			acc_read_register(LIS331HH_OUT_Y_H, &buffh);
			acc_read_register(LIS331HH_OUT_Y_L, &buffl);
			break;
		case ZAXIS:
			acc_read_register(LIS331HH_OUT_Z_H, &buffh);
			acc_read_register(LIS331HH_OUT_Z_L, &buffl);
			break;
		default:
			break;
	}	
	acc_integer=(buffh<<8)+buffl;
	if(acc_integer>32768)
	{
		acc_integer-=65536;
	}
	acc_float =  LIS331HH_ACC_CONV * acc_integer;
	return acc_float;
}

