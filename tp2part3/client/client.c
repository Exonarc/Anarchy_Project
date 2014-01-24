#include "client.h"


// 2- définition des fonctions relatives au fonctionnement du client TCP-IP; 
int Init(struct tcp_ip* client)
{	
	WSAStartup(MAKEWORD(2,2), &client->WsaData) ;
	return 0;
}

int Start(struct tcp_ip* client)
{
	client->s = socket( AF_INET, SOCK_STREAM , IPPROTO_TCP );
	if (client->s != -1)
		if (connect ( client->s , (struct sockaddr* )(&client->ServeurAddr) , sizeof(struct sockaddr) )==-1)
			printf("Connection failed \n");
		else
			printf("Connection succeed \n");
	else
		printf("Socket failed");
	return 0;
}

int Stop(struct tcp_ip* client)
{
	shutdown(client->s, 2);
	closesocket(client->s);
	WSACleanup();
	return 0;
}

int Set(struct tcp_ip* client,char* message , int dim)
{
	return send( client->s , message , dim , 0);
}

int Get(struct tcp_ip* client,char* message , int dim)
{
	return recv(client->s , message , dim , 0);
}

