/*
 *  gl_draw_idle_fun.c
 *  
 *
 *  Created by mathieu porez on 15/01/13.
 *  Copyright 2013 emn. All rights reserved.
 *
 */

#include "gl_draw_idle_fun.h"

void draw(void)
{ 	
	double P[3]={0.0,0.0,0.0};
	double u[3]={1.0,0.0,0.0};
	double theta = 0.0;
	
	// Effacement du buffer graphique de travail;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	// Les deux faces des polygones utilisés sont visibles et représentées en mode filaire;
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);		
	
	
	// 8- calcul de l'orientation de la carte;
	// 9- calcul de la transformation u, theta;
	
	// dessin dans la fenêtre 3D d'un paralépipède représentant la carte BagleBone;
	glToolDrawBody(u,theta,P,0.25,0.25,0.25,0.0,0.0,0.0,0);
	
	// permutation des buffer graphique;
	glutSwapBuffers();
}


void idle(void)
{
	// 7- mesure des accélérations mesurées par le capteur
	char message[128];
	int dim;
	Start(&ma_struct);
	
	//axis x
	// dim = sprintf(message,"%d%s%d%s",6,"GetACC",1,"0");
	// Set(&ma_struct, message, dim);
	message[0] = 6;
	message[1] = 'G';
	message[2] = 'e';
	message[3] = 't';
	message[4] = 'A';
	message[5] = 'C';
	message[6] = 'C';
	message[7] = 1;
	message[8] = '0';
	
	Set(&ma_struct, message, 9);
	dim = Get(&ma_struct, message, 128);
	message[dim] = 0;
	
	acc[0] = atof(message);
	Start(&ma_struct);
	
	//axis y
	// dim = sprintf(message,"%d%s%d%s",6,"GetACC",1,"1");
	// Set(&ma_struct, message, dim);
	message[0] = 6;
	message[1] = 'G';
	message[2] = 'e';
	message[3] = 't';
	message[4] = 'A';
	message[5] = 'C';
	message[6] = 'C';
	message[7] = 1;
	message[8] = '1';
	
	Set(&ma_struct, message, 9);
	dim = Get(&ma_struct, message, 128);
	message[dim] = 0;
	
	acc[1] = atof(message);	
	Start(&ma_struct);
	
	//axis z
	// dim = sprintf(message,"%d%s%d%c",6,"GetACC",1,'2');
	// message[dim] = 0;
	// Set(&ma_struct, message, dim);
	
	message[0] = 6;
	message[1] = 'G';
	message[2] = 'e';
	message[3] = 't';
	message[4] = 'A';
	message[5] = 'C';
	message[6] = 'C';
	message[7] = 1;
	message[8] = '2';
	Set(&ma_struct, message, 9);
	
	dim = Get(&ma_struct, message, 128);
	message[dim] = 0;
	
	acc[2] = atof(message);
	printf("Ax = %f, Ay = %f, Az = %f\n",acc[0],acc[1],acc[2]);

	// Emission d'un évenement de mise à jour du dessin;
	glutPostRedisplay();
}


