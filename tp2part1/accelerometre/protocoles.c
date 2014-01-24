/*
 *  protocoles.c
 *  
 *
 *  Created by mathieu porez on 24/10/12.
 *  Copyright 2012 emn. All rights reserved.
 *
 */

#include "protocoles.h"

void protocole_acc(int socket_s)
{
	float a[3];
	int dim;
	char message [256];
	acc_power_on();
	a[0] = acc_read_acceleration(XAXIS);
	a[1] = acc_read_acceleration(YAXIS);
	a[2] = acc_read_acceleration(ZAXIS);
	//printf("Ax = %f, Ay = %f, Az = %f\n",a[0],a[1],a[2]);
	dim = sprintf(message,"Ax = %f, Ay = %f, Az = %f",a[0],a[1],a[2]);
	printf("%s",message);
	message[dim] = 0;
	send(socket_s , message, dim, 0);
}

void protocole_temp(int socket_s)
{
	float temperature;
	char message[256];
	int dim;
	
	temperature = readTemp();
	dim = sprintf(message,"T = %f degrees\n",temperature);
	printf("%s",message);
	
	message[dim] = 0;
	send(socket_s , message, dim, 0);
}