#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "fonctionsUtiles.h"

int nombreLignes (FILE* f) {

	//char ligne[90];
	int nb_ligne = 0;
	int c;

	while((c = fgetc(f)) != EOF){
		if(c == '\n')
			nb_ligne=nb_ligne+1;
	fclose(f);
	return nb_ligne;
	}
}

void header (FILE* f_in, FILE* f_out, char* filename){
	time_t date;
	int nb_ligne = 0;
	char ligne[90];
	nb_ligne = nombreLignes(f_out);
	fgets(ligne, 90, f_out);
	fputc('#',f_in);
	fputc('\n',f_in);
	fputs(filename,f_in);
	fputc('\n',f_in);
	char nbLigne [10];
	snprintf(nbLigne, 10, "%i", nb_ligne);
	fputs(nbLigne,f_in);
	fputc('\n',f_in);
	date = time(NULL);
	fputs( ctime(&date),f_in);
	fputc('\n',f_in);
}


void copie(FILE* f_in, FILE* f_out){
	char ligne[90];
	while (!feof(f_out))
	{
		fputs(ligne, f_in);
		fgets(ligne, 90, f_out);
	}
	fputc('\n',f_in);
}


char* niemeLigne(FILE* f, int n){
	
	int nb_ligne = 0;
	char ligne[90];
	int c ;
	

   
   while (fgets(ligne, 90, f) != NULL)
   {
	   if (nb_ligne == n)
			printf('\t%s',(char*)ligne);
	   else
			nb_ligne=nb_ligne+1;
		
	}


}
