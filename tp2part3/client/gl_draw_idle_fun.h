/*
 *  gl_draw_idle_fun.h
 *  
 *
 *  Created by mathieu porez on 15/01/13.
 *  Copyright 2013 emn. All rights reserved.
 *
 */

#ifndef _GL_DRAW_IDLE_FUN_H
#define _GL_DRAW_IDLE_FUN_H

#include <stdlib.h>
#include <math.h>
#include <Gl/glut.h>
#include "gl_tool.h"
#include "client.h"

extern int window;
extern float acc[3];				// Variable globale contenant les accélérations mesurées;
extern float temp;
struct tcp_ip ma_struct;

struct point{
	float x;
	float y;
	float z;
};

// draw est la fonction appelée par Glut pour actualiser le dessin se trouvant dans la fenêtre graphique;
void draw(void);

// idle est la fonction appelée par Glut quand ce dernier est en mode IDLE (inactif);
void idle(void);

#endif