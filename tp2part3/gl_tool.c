/*
 *  gl_tool.c
 *  wsc
 *
 *  Created by Mathieu Porez on 14/10/10.
 *  Copyright 2010 EMN. All rights reserved.
 *
 */

#include "gl_tool.h"

void glToolStartGlut(int argc, char *argv[])
{
	int window;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(640,640);
	window=glutCreateWindow("Infra.-Info. 2012/2013");
	glutReshapeFunc(reshape);
	glutDisplayFunc(draw);
	glutKeyboardFunc(keyboard);
	glutVisibilityFunc(visible);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(1.0,1.0,1.0,0); 
	glutMainLoop();
}

void glToolDrawCube(double L, double l, double h, double a, double b, double c)
{
	glPushMatrix();
	glBegin(GL_QUADS);
	
	glColor3d(0,1,0);
	glVertex3d(-0.499*L+a,-0.499*l+b,-0.499*h+c);
	glVertex3d(0.499*L+a,-0.499*l+b,-0.499*h+c);
	glVertex3d(0.499*L+a,-0.499*l+b, 0.499*h+c);
	glVertex3d(-0.499*L+a,-0.499*l+b, 0.499*h+c);
	
	glColor3d(0,1,0);
	glVertex3d(0.499*L+a,-0.499*l+b,-0.499*h+c);
	glVertex3d(0.499*L+a, 0.499*l+b,-0.499*h+c);
	glVertex3d(0.499*L+a, 0.499*l+b, 0.499*h+c);
	glVertex3d(0.499*L+a,-0.499*l+b, 0.499*h+c);
	
	glColor3d(0,1,0);
	glVertex3d(0.499*L+a, 0.499*l+b,-0.499*h+c);
	glVertex3d(-0.499*L+a, 0.499*l+b,-0.499*h+c);
	glVertex3d(-0.499*L+a, 0.499*l+b, 0.499*h+c);
	glVertex3d(0.499*L+a, 0.499*l+b, 0.499*h+c);
	
	glColor3d(0,1,0);
	glVertex3d(-0.499*L+a, 0.499*l+b,-0.499*h+c);
	glVertex3d(-0.499*L+a,-0.499*l+b,-0.499*h+c);
	glVertex3d(-0.499*L+a,-0.499*l+b, 0.499*h+c);
	glVertex3d(-0.499*L+a, 0.499*l+b, 0.499*h+c);
	
	glColor3d(0,1,0);
	glVertex3d(-0.499*L+a,-0.499*l+b, 0.499*h+c);
	glVertex3d(0.499*L+a,-0.499*l+b, 0.499*h+c);
	glVertex3d(0.499*L+a, 0.499*l+b, 0.499*h+c);
	glVertex3d(-0.499*L+a, 0.499*l+b, 0.499*h+c);
	
	glColor3d(0,1,0);
	glVertex3d(-0.499*L+a, 0.499*l+b,-0.499*h+c);
	glVertex3d(0.499*L+a, 0.499*l+b,-0.499*h+c);
	glVertex3d(0.499*L+a,-0.499*l+b,-0.499*h+c);
	glVertex3d(-0.499*L+a,-0.499*l+b,-0.499*h+c);
	
	glEnd();
	glPopMatrix();
}

void glToolDrawAxe(double * u, double theta, double * P, double h, unsigned int color)
{
	glPushMatrix();
	glTranslated(P[0], P[1], P[2]);
	glRotatef(theta, u[0], u[1], u[2]);
	glBegin(GL_LINES);
	glColor3d(1.0,0.0,0.0);
	glVertex3d(0.0, 0.0, 0.75*h);
	glVertex3d(0.0, 0.0, -0.75*h);
	glEnd();
	glPopMatrix();
}

void glToolDrawFrame(double scale)
{
	glBegin(GL_LINES);
	glColor3d(0.0,0.0,1.0);
	glVertex3d(0.0,0.0,0.0);
	glVertex3d(scale,0.0,0.0);
	glVertex3d(0.0,0.0,0.0);
	glVertex3d(0.0,scale,0.0);
	glVertex3d(0.0,0.0,0.0);
	glVertex3d(0.0,0.0,scale);
	glEnd();
}


void glToolDrawBody(double * u, double theta, double * P, double L, double l, double h, double a, double b, double c, unsigned int color)
{
	if (L==0.0)
	{
		return;
	}
	else
	{
		glPushMatrix();
		glTranslated(P[0], P[1], P[2]);
		glRotatef(theta, u[0], u[1], u[2]);
		glToolDrawCube(L,l,h,a,b,c);
		glPopMatrix();
	}
}

void reshape(int width, int height)
{ 	 
	float ratio ;
	float h= (float)height;
	float w= (float)width;
	if(h == 0) h = 1;
	ratio = 1.0*w/h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45,ratio,0.001,2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,-zoom_ratio,0.0, 
		      0.0,0.0,0.0,
			  0.0,0.0,1.0);
} 	 

void keyboard (unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'q':	
			psi_view=psi_view-1.0*M_PI/180.0;
			break;
		case 'd':
			psi_view=psi_view+1.0*M_PI/180.0;
			break;
		case 'z':	
			theta_view=theta_view-1.0*M_PI/180.0;
			break;
		case 'x':
			theta_view=theta_view+1.0*M_PI/180.0;
			break;
		case 'p':	
			zoom_ratio=zoom_ratio+0.01;
			break;
		case 'm':
			zoom_ratio=zoom_ratio-0.01;
			break;
		case 27:
			exit(0);
		default:
			break;
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(zoom_ratio*cos(theta_view)*cos(psi_view),zoom_ratio*cos(theta_view)*sin(psi_view),-zoom_ratio*sin(theta_view), 
			  0.0,0.0,0.0,
			  sin(theta_view)*cos(psi_view),sin(theta_view)*sin(psi_view),cos(theta_view));
}

void visible(int vis)
{
    if (vis == GLUT_VISIBLE) glutIdleFunc(idle);
    else glutIdleFunc(NULL);
}