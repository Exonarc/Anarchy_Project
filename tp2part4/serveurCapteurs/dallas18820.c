#include "dallas18820.h"


float readTemp (void){

FILE * fichier;
char * contenu;
int dimension;
float temperature = 0;
float div = 10;
int i = 0;
int j;

fichier = fopen(CHEMIN,"r");

fseek(fichier,0L,SEEK_END);
dimension = ftell(fichier);
rewind(fichier);

contenu = (char*)malloc(sizeof(char)*dimension);
fread(contenu, sizeof(char), dimension, fichier);

while (contenu[i]!='t')
{
	i++;
}

i = i+2;
j = i+5;

for (;i<j;i++)
{
	temperature = temperature + (contenu[i]-48)*div;
	div=div/10;
}

free(contenu);
fclose(fichier);
return temperature;
}
