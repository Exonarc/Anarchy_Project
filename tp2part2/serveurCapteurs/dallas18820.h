#ifndef _DALLAS18820_
#define _DALLAS18820_

#include<stdio.h>
#include<stdlib.h>

#define CHEMIN "/sys/bus/w1/devices/28-000003820428/w1_slave"

float readTemp ( void );
	
#endif