/*
 *  gl_tool.h
 *  wsc
 *
 *  Created by Mathieu Porez on 14/10/10.
 *  Copyright 2010 EMN. All rights reserved.
 *
 */

#ifndef _GL_TOOL_M_H
#define _GL_TOOL_M_H

#include <math.h>
#include <Gl/glut.h>
#include "gl_draw_idle_fun.h"

extern double theta_view;			// Variable globale définissant azimut de la vue 3D;
extern double psi_view;				// Variable globale définissant l'élévation de la vue 3D;
extern double zoom_ratio;	
extern int window;

void glToolStartGlut(int argc, char *argv[]);
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void visible(int vis);

#endif