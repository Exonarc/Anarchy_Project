/* main.c
 * Created by vincent crettez on 18/11/2013
 * copyright vincent crettez 2013 
 */ 

#include "client.h"

int main (int argc, char *argv[])
{
	struct tcp_ip ma_struct;
	char message[256];
	int dim;
	
	ma_struct.ServeurPort = 1234;
	ma_struct.ServeurIp = "192.168.17.105"; //192.168.17.111
	ma_struct.ServeurAddr.sin_family = AF_INET;
	ma_struct.ServeurAddr.sin_port = htons(1234);
	ma_struct.ServeurAddr.sin_addr.s_addr = inet_addr(ma_struct.ServeurIp);
	
	Init(&ma_struct);
	Start(&ma_struct);
	dim = Get(&ma_struct, message, 256);
	message[dim] =0;
	printf("%s", message);
	
	Stop(&ma_struct);
	return 0;
}

