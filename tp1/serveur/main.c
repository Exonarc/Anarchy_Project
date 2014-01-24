/* main.c
 * Created by vincent crettez on 18/11/2013
 * copyright vincent crettez 2013 
 */ 

#include "serveur.h"

int main (int argc, char *argv[])
{
	struct tcp_ip ma_struct;
	
	ma_struct.ServeurPort = 1234;
	ma_struct.ServeurIp = "127.0.0.1";
	ma_struct.ServeurAddr.sin_family = AF_INET;
	ma_struct.ServeurAddr.sin_port = htons(1234);
	ma_struct.ServeurAddr.sin_addr.s_addr = INADDR_ANY;
	
	Init(&ma_struct);
	Start(&ma_struct);
	char message  [64] ;
	Get(&ma_struct, message, 64);
	message[11]=0;
	printf("%s", message);
	Set(&ma_struct,message,11);
	//Stop(&ma_struct);
	
	return 0;
}

