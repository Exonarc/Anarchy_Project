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
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(640,640);
	window = glutCreateWindow("Infra.-Info. 2013/2014");
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
		case 27:
			exit(0);
		default:
			break;
	}
}

void visible(int vis)
{
    if (vis == GLUT_VISIBLE) glutIdleFunc(idle);
    else glutIdleFunc(NULL);
}