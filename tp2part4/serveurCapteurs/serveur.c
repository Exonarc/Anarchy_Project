#include "serveur.h"

void * mon_serveur(void * input)
{
	int i=1;
	struct api_tcp_ip * serveur = (struct api_tcp_ip *) input;
	
	
	serveur->s_ip = "192.168.17.105";
	serveur->s_addr.sin_family = AF_INET;
	serveur->s_addr.sin_port = htons(serveur->s_port);
	serveur->s_addr.sin_addr.s_addr = INADDR_ANY;
	serveur->s_addr_len = sizeof(struct sockaddr_in);
	serveur->c_addr_len = sizeof(struct sockaddr_in);
	
	serveur->socket_p = socket( AF_INET, SOCK_STREAM , IPPROTO_TCP );
	bind(serveur->socket_p,(struct sockaddr*)&serveur->s_addr, sizeof(struct sockaddr));
	
	while(1)
	{
		listen(serveur->socket_p, 5);
		serveur->socket_s = accept(serveur->socket_p, (struct sockaddr* )(&serveur->c_addr), &(serveur->c_addr_len));
		setsockopt(serveur->socket_s, IPPROTO_TCP, 0x0001, (char*) &i,sizeof(i)); /* time out = inf */
		signal(SIGPIPE, SIG_IGN); /* Signal broken Pipe = off */
		printf("Client connecté (%d). IP: %s\n",serveur->s_port,inet_ntoa(serveur->c_addr.sin_addr));
		serveur->protocole(serveur->socket_s);
		shutdown(serveur->socket_s,2);
		close(serveur->socket_s);
		printf("Client déconnecté\n");
	}
	
	shutdown(serveur->socket_p,2);
	close(serveur->socket_p);
}
