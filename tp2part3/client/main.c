#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>
#include "client.h"
#include "gl_tool.h"
#include "gl_draw_idle_fun.h"


double theta_view=0.0;			// Variable globale définissant azimut de la vue 3D;
double psi_view=-M_PI/2.0;		// Variable globale définissant l'élévation de la vue 3D;
double zoom_ratio=0.5;			// Variable globale définisannt le ratio de zoom;
float acc[3];
float temp;
struct tcp_ip ma_struct;
int window;

int main(int argc, char *argv[])
{
	
	// 3- Initialisation du client;
	ma_struct.ServeurPort = 1234;
	ma_struct.ServeurIp = "192.168.17.105"; //192.168.17.111
	ma_struct.ServeurAddr.sin_family = AF_INET;
	ma_struct.ServeurAddr.sin_port = htons(1234);
	ma_struct.ServeurAddr.sin_addr.s_addr = inet_addr(ma_struct.ServeurIp);
	
	Init(&ma_struct);

	// 4- Connexion au serveur;
	Start(&ma_struct);	
	
	// 5- Mise en fonction du capteur;
	char message [128];
	int dim;
	// dim = sprintf(message,"%d%s%d%s",6,"RunACC",0,"");
	message[0] = 6;
	message[1] = 'R';
	message[2] = 'u';
	message[3] = 'n';
	message[4] = 'A';
	message[5] = 'C';
	message[6] = 'C';
	message[7] = 0;
	
	Set(&ma_struct, message, 8);
	dim = Get(&ma_struct, message, 128);
	message[dim] = 0;
	
	glToolStartGlut(argc, argv); // Initialisation et mise en fonction de Glut;
	
	// 6- Arret du client;
	Stop(&ma_struct);
	return 0;
}


