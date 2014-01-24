#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "serveur.h"
#include "protocoles.h"
#include "lis331hh.h"

pthread_mutex_t mon_mutex;
	
int main(int argc, char *argv[])
{

	pthread_mutex_init(&mon_mutex, NULL);
	
	struct api_tcp_ip ma_struct1;
	ma_struct1.protocole = (void *)mon_protocole;
    ma_struct1.s_port = 1234;
	
	struct api_tcp_ip ma_struct2;
	ma_struct2.protocole = (void *)protocole_http;
    ma_struct2.s_port = 1235;
	
	pthread_t t1;
	pthread_t t2;
	
	pthread_create(&t1,NULL,mon_serveur,(void *)&ma_struct1);
	pthread_create(&t2,NULL,mon_serveur,(void *)&ma_struct2);
	
	while(1);
	
	pthread_mutex_destroy(&mon_mutex);
	
	return 0;
}
