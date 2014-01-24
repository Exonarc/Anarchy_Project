/* main.c
 * Created by vincent crettez on 18/11/2013
 * copyright vincent crettez 2013 
 */ 

#include "serveur.h"

int Init(struct tcp_ip* serveur)
{	
	WSAStartup(MAKEWORD(2,2), &serveur->WsaData) ;
	return 0;
}

int Start(struct tcp_ip* serveur)
{
	serveur->s = socket( AF_INET, SOCK_STREAM , IPPROTO_TCP );
	bind(serveur->s,(struct sockaddr*)&serveur->ServeurAddr, sizeof(struct sockaddr));
	listen(serveur->s, 5);
	int a = sizeof(struct sockaddr);
	serveur->p = accept(serveur->s, (struct sockaddr* )(&serveur->ClientAddr), &a);
	return 0;
}

int Stop(struct tcp_ip* serveur)
{
	shutdown(serveur->s, 2);
	closesocket(serveur->s);
	WSACleanup();
	return 0;
}

int Set(struct tcp_ip* serveur,char* message , int dim)
{
	return send( serveur->p , message , dim , 0);
}

int Get(struct tcp_ip* serveur,char* message , int dim)
{
	return recv(serveur->p , message , dim , 0);
}
