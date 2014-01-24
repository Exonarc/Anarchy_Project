/* main.c
 * Created by vincent crettez on 18/11/2013
 * copyright vincent crettez 2013 
 */ 

#include "client.h"

int main (int argc, char *argv[])
{
	struct tcp_ip ma_struct;
	char message [128];
	char com_len;
	char param_len;
	char commande[16];
	char parametres[64];
	
//cas 1
	//rentrez à la main la commande
	
	message[0] = 7;
	message[1] = 'G';
	message[2] = 'e';
	message[3] = 't';
	message[4] = 'T';
	message[5] = 'E';
	message[6] = 'M';
	message[7] = 'P';
	message[8] = 0;
	
	char reponse[256];
	int dim;
	int i=0;
	
	ma_struct.ServeurPort = 1234;
	ma_struct.ServeurIp = "192.168.17.105"; //192.168.17.111
	ma_struct.ServeurAddr.sin_family = AF_INET;
	ma_struct.ServeurAddr.sin_port = htons(1234);
	ma_struct.ServeurAddr.sin_addr.s_addr = inet_addr(ma_struct.ServeurIp);
	
	Init(&ma_struct);
	Start(&ma_struct);
	
//cas 2
	// printf("Entrez votre commande : \n");
	// scanf("%s",message); //marche que si la taille <10
	
//cas3
	// printf("Entrez la taille de la commande : \n");
	// scanf("%c",&com_len);
	// getchar();
	// printf("Entrez la commande : \n");
	// scanf("%s",commande);
	// getchar();
	// printf("Entrez la taille des paramètres: \n");
	// scanf("%c",&param_len);
	// getchar();
	// printf("Entrez les paramètres : \n");
	// scanf("%s",parametres);
	// dim = sprintf(message,"%c%s%c%s",com_len,commande,param_len,parametres);
	// message[dim] = 0;
	
	dim = strlen(message);
	Set(&ma_struct, message, dim);
	dim = Get(&ma_struct, message, 256);
	message[dim] =0;
	printf("%s", message);
	
	Stop(&ma_struct);
	return 0;
}

