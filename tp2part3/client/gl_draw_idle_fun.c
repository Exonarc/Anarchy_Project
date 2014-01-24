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
	float a = 0.1; 
	struct point p[8] = {{-a,-a,a},{-a,a,a},{a,a,a},{a,-a,a},{-a,-a,-a},{-a,a,-a},{a,a,-a},{a,-a,-a}};
	int f[6][4] = {{0,1,2,3},{3,2,6,7},{4,5,6,7},{0,1,5,4},{1,5,6,2},{0,4,7,3}};
	int i;
	int j;
	float g = 9.8;
	
	//calcul couleur
	float r = 0.1*temp-2.5;
	float b = -0.1*temp+3.5;
		
	// Effacement du buffer graphique de travail;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	// Les deux faces des polygones utilisés sont visibles et représentées en mode filaire;
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	

	// 8- calcul de l'orientation de la carte;
	float theta1 = asin(acc[1]/g)*180/3.14;
	//float theta2 = asin(acc[0]/(g*cos(theta1)))*180/3.14;
	float theta2 = atan(acc[0]/acc[2])*180/3.14;
	
	// 9- calcul de la transformation u, theta;
	glLoadIdentity();
	gluLookAt(0.0,-zoom_ratio,0.0, 
		      0.0,0.0,0.0,
			  0.0,0.0,1.0);
	glRotatef(theta1,0.0,1.0,0.0);
	glRotatef(theta2,1.0,0.0,0.0);
	
    // 10- dessiner le cube;
	glBegin(GL_QUADS);
	glColor3f(r,0.5,b);
	for (i=0; i<6; i++){
		for(j=0; j<4; j++){
			glVertex3f(p[f[i][j]].x,p[f[i][j]].y,p[f[i][j]].z);
		}
	}
	glEnd();
	glFlush();
	
	// permutation des buffer graphique;
	glutSwapBuffers();
}


void idle(void)
{
	// 7- mesure des accélérations mesurées par le capteur
	char message[128];
	int dim;
	
	//axis x
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
	sscanf(message,"%f",&acc[0]);
	
	//axis y
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
	sscanf(message,"%f",&acc[1]);
	
	//axis z
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
	sscanf(message,"%f",&acc[2]);
	
	//temperature
	message[0] = 7;
	message[1] = 'G';
	message[2] = 'e';
	message[3] = 't';
	message[4] = 'T';
	message[5] = 'E';
	message[6] = 'M';
	message[7] = 'P';
	
	Set(&ma_struct, message, 8);
	dim = Get(&ma_struct, message, 128);
	message[dim] = 0;
	sscanf(message,"%f",&temp);

	//printf("Ax = %f, Ay = %f, Az = %f , T = %f\n",acc[0],acc[1],acc[2],temp);

	// Emission d'un évenement de mise à jour du dessin;
	glutSetWindow(window);
	glutPostRedisplay();
}