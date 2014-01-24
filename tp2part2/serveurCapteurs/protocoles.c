/*
 *  protocoles.c
 *  
 *
 *  Created by mathieu porez on 24/10/12.
 *  Copyright 2012 emn. All rights reserved.
 *
 */

#include "protocoles.h"

void protocole_acc(int socket_s)
{
	float a[3];
	int dim;
	char message [256];
	acc_power_on();
	a[0] = acc_read_acceleration(XAXIS);
	a[1] = acc_read_acceleration(YAXIS);
	a[2] = acc_read_acceleration(ZAXIS);
	dim = sprintf(message,"Ax = %f, Ay = %f, Az = %f",a[0],a[1],a[2]);
	printf("%s",message);
	message[dim] = 0;
	send(socket_s , message, dim, 0);
}

void protocole_temp(int socket_s)
{
	float temperature;
	char message[256];
	int dim;
	
	temperature = readTemp();
	dim = sprintf(message,"T = %f degrees\n",temperature);
	printf("%s",message);
	
	message[dim] = 0;
	send(socket_s , message, dim, 0);
}

void mon_protocole(int socket_s)
{
	struct Table_repartition ma_table[] = 
	{
		{"RunACC", OnRunACC},
		{"IdleACC", OnIdleACC},
		{"GetACC", OnGetACC},
		{"GetACCReg", OnGetACCReg},
		{"SetACCReg", OnSetACCReg},
		{"GetTEMP", OnGetTEMP}
	};
	
	int dim ;
	char message[128];
	int i = 0;
	int cmd = -1;
	u_char com_len;
	char commande [128];
	u_char param_len;
	char parametres [128];
	u_char rep_len;
	char reponse[256];

	while((dim = recv(socket_s, message , 128 , 0)) != 0){
		message[dim] = 0;

		com_len = (u_char) (message[0]);//enlever "-48" dans le cas 1 et 3
		memcpy(commande,message+1,com_len);
		commande[com_len]=0;
		param_len = (u_char) (message[com_len+1]);//ici aussi :)
		memcpy(parametres,message+com_len+2,param_len);
		parametres[param_len]=0;	
		for(i=0;i<6;i++)
		{
			if(strcmp(ma_table[i].commande, commande)==0)
			{
				ma_table[i].pFonction(param_len, parametres, &rep_len, reponse);
			}
		}
		
		send(socket_s , reponse, rep_len, 0);	
	}
}

void OnRunACC(u_char param_len, const char * parametres, u_char * rep_len, char * reponse)
{
	if(acc_power_on())
	{
		*rep_len = sprintf(reponse,"%c",0);
	}
	else
	{
		*rep_len = sprintf(reponse,"%c",200);
	}
}

void OnIdleACC(u_char param_len, const char * parametres, u_char * rep_len, char * reponse)
{
	if(acc_power_off())
	{
		*rep_len = sprintf(reponse,"%c",0);
	}
	else
	{
		*rep_len = sprintf(reponse,"%c",201);
	}
}

void OnGetACC(u_char param_len, const char * parametres, u_char * rep_len, char * reponse)
{
	char axe = (*parametres)-48;
	float acc = acc_read_acceleration(axe);
	*rep_len = sprintf(reponse,"%f",acc);
	if ((*rep_len) <= 0)
	{
		*rep_len = sprintf(reponse,"%c",202);
	}
}

void OnGetACCReg(u_char param_len, const char * parametres, u_char * rep_len, char * reponse)
{
	if(acc_read_register(*parametres,reponse))
	{
		*rep_len = strlen(reponse);
	}
	else
	{
		*rep_len = sprintf(reponse,"%c",203);
	}	
}

void OnSetACCReg(u_char param_len, const char * parametres, u_char * rep_len, char * reponse)
{
	char param1,param2;
	sscanf(parametres,"%c,%c",&param1,&param2);
	if(acc_write_register(param1,param2))
	{
		*rep_len = sprintf(reponse,"%c",0);
	}
	else
	{
		*rep_len = sprintf(reponse,"%c",204);
	}	
}

void OnGetTEMP(u_char param_len, const char * parametres, u_char * rep_len, char * reponse)
{
	*rep_len = sprintf(reponse,"%f",readTemp());
	if (*rep_len < 0)
	{
		*rep_len = sprintf(reponse,"%c",205);
	}
}