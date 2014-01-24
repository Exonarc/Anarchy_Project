#ifndef _SERVEUR_H
#define _SERVEUR_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

void * mon_serveur(void *);

struct api_tcp_ip
{
	int socket_p;
	int socket_s;
	struct sockaddr_in s_addr;
	struct sockaddr_in c_addr;	
	socklen_t          s_addr_len;
	socklen_t          c_addr_len;
	unsigned int s_port;
	const char * s_ip;
	void (* protocole)(int);
};

#endif
     
