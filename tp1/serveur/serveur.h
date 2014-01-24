/* main.c
 * Created by vincent crettez on 18/11/2013
 * copyright vincent crettez 2013 
 */ 

#ifndef H_SERVEUR
#define H_SERVEUR
#include <winsock2.h>
#include <stdio.h>

struct tcp_ip{
	SOCKET s;
	SOCKET p;
	SOCKADDR_IN ServeurAddr;
	SOCKADDR_IN ClientAddr;
	WSADATA WsaData;
	int ServeurPort;
	const char * ServeurIp;
};

int Init(struct tcp_ip *);
int Start(struct tcp_ip*);
int Stop(struct tcp_ip*);
int Set(struct tcp_ip*,char* message , int dim);
int Get(struct tcp_ip*,char* message , int dim);
 
#endif