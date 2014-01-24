#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "serveur.h"
#include "protocoles.h"
#include "lis331hh.h"


int main(int argc, char *argv[])
{
	struct api_tcp_ip ma_struct;
	
	//ma_struct.protocole = (void *)protocole_acc;
	//ma_struct.protocole = (void *)protocole_temp;
	ma_struct.protocole = (void *)mon_protocole;
	
	// pthread_t t1;
	// pthread_create(&t1,NULL,mon_serveur,(void *)ma_struct);
	// pthread_join(t1,NULL);
	mon_serveur((void*) &ma_struct);
	return 0;
}
