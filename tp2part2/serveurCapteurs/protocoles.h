/*
 *  protocoles.h
 *  
 *
 *  Created by mathieu porez on 24/10/12.
 *  Copyright 2012 emn. All rights reserved.
 *
 */

#ifndef _PROTOCOLES_H
#define _PROTOCOLES_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "lis331hh.h"
#include "dallas18820.h"

typedef void (*Fonction) (u_char, const char *, u_char*, char *);
struct Table_repartition{
	char * commande;
	Fonction pFonction;
};

void protocole_acc(int);
void protocole_temp(int);
void mon_protocole(int);

void OnRunACC(u_char, const char *, u_char *, char *); 
void OnIdleACC(u_char, const char *, u_char *, char *); 
void OnGetACC(u_char, const char *, u_char *, char *); 
void OnGetACCReg(u_char, const char *, u_char *, char *); 
void OnSetACCReg(u_char, const char *, u_char *, char *); 
void OnGetTEMP(u_char, const char *, u_char *, char *); 

#endif