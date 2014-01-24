#ifndef _CLIENT_H
#define _CLIENT_H

#include <winsock2.h>
#include <stdio.h>

// 1- déclaration des variables et fonctions relatives au fonctionnement du client TCP-IP; 
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