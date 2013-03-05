#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "affichage.h"
#include "fonctionsUtiles.h"
#include "compression.h"


 

   
int main (int argc, char **argv)
{
	   int tflag = 0; int xflag = 0; int dflag = 0;
       int vflag = 0; int rflag = 0; int fflag = 0; int mflag = 0;
       int cflag = 0; int uflag = 0; int zflag = 0; int sparseflag = 0;
       
       int index;
       int c;
     
       opterr = 0;
       
// Pour gérer les options     
       while((c = getopt (argc, argv, "h:f:cf:r:vtuxzdm:sparse:")) != -1)
       {
		   int nb=1;
         switch (c)
           {
           case 'h':
				afficherAide();
				break;
           case 'v':
				vflag = 1;
				break;
           case 'c':
				cflag = 1;
				break;
           case 't':
				tflag = 1;
				break;
           case 'r':
				rflag = 1;
				break;
           case 'u':
				uflag = 1;
				break;
           case 'x':
				xflag = 1;
				break;
           case 'f':
				fflag = 1;
                break;
           case 'z':
				compression(argv[argc-1]);
				break;
           case 'd':
				dflag = 1;
				break;
           case 'm':
				mflag = 1;
				break;
           default:
           fprintf(stderr, "Error\n");
            exit(EXIT_FAILURE);
           }        				        
     }
     
//-z : pour compresser une archive
     //~ if (zflag == 1)
     //~ {
		//~ 
		//~ 
//~ 
//~ 
	 //~ }
	 
//-c : pour créer une archive à partir d'une liste de fichier
//-f : pour indiquer le nom du fichier archive
	 if (cflag == 1 && fflag == 1)
	 {
		 int nb=2;
		 int nb_ligne = 0;
		 FILE *f_in;	
		 time_t date;
		 if ((f_in = fopen(argv[argc-1],"w")) == NULL)
		{
			fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",argv[argc-1]);
		}
		 while (nb<argc-1 && argc>1 )
		 {
			 FILE *f_out;
			if ((f_out = fopen(argv[nb],"r")) == NULL)
			{
				fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",argv[nb]);
			}
			nb_ligne = nombreLignes(f_out);
			char ligne[90];
			fgets(ligne, 90, f_out);
			fputs(argv[nb],f_in);
			fputc('\n',f_in);
			char nbLigne [10];
			snprintf(nbLigne, 10, "%i", nb_ligne);
			fputs(nbLigne,f_in);
			fputc('\n',f_in);
			date = time(NULL);
			fputs( ctime(&date),f_in);
			fputc('\n',f_in);
			if ((f_out = fopen(argv[nb],"r")) == NULL)
			{
				fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",argv[nb]);
			}
			while (!feof(f_out))
			{
				fputs(ligne, f_in);
				fgets(ligne, 90, f_out);
			}
			fputc('\n',f_in);
			fclose(f_out);
			nb++;
		 }
		fclose(f_in);		
	 }
	 
// -r : pour ajouter de nouveaux fichiers
	 if (rflag==1)
	 {
		 int nb=2;
		 int nb_ligne = 0;
		 FILE *f_in;
		 time_t date;
		 if ((f_in = fopen(argv[argc-1],"a")) == NULL)
		{
			fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",argv[argc-1]);
		}
		 while (nb<argc-1 && argc>1 )
		 {
			 FILE *f_out;
			if ((f_out = fopen(argv[nb],"r")) == NULL)
			{
				fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",argv[nb]);
			}
			nb_ligne = nombreLignes(f_out);
			char ligne[90];
			fgets(ligne, 90, f_out);
			fputs(argv[nb],f_in);
			fputc('\n',f_in);
			char nbLigne [10];
			snprintf(nbLigne, 10, "%i", nb_ligne);
			fputs(nbLigne,f_in);
			fputc('\n',f_in);
			date = time(NULL);
			fputs( ctime(&date),f_in);
			fputc('\n',f_in);
			if ((f_out = fopen(argv[nb],"r")) == NULL)
			{
				fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",argv[nb]);
			}
			while (!feof(f_out))
			{
				fputs(ligne, f_in);
				fgets(ligne, 90, f_out);
			}
			fputc('\n',f_in);
			fclose(f_out);
			nb++;
		 }
		fclose(f_in);	
	 }
	 
// -u : pour mettre à jour l'archive si les fichiers lités sont plus récents que ceux archivés	 
	 if (uflag==1)
	 {	
		 /*FILE *f_in1;
		 int nb=2;
		 if ((f_in1 = fopen(argv[argc-1],"a")) == NULL)
		{
			fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",argv[argc-1]);
		}
		while (EOF != (c = fgetc(f_in1)))
		{
			char* nbL;
			int ligne = 0;
			int ma_ligne = 2;
			int taille;
			char* dateIn;
			char* dateOut;

			if ('\n' == c)
            {
				if(ligne == 1)
					//nbL = fgets(ligne, 90, f_in1);
                if (ligne == ma_ligne)
                   break;
                ligne++;
            }
        

        if (ligne == ma_ligne)
        {
         //dateIn = fgets(ligne, 90, f_in1);
        }
		
			while (nb<argc-1 && argc>1 )
			{ 	FILE *f_out;
			fclose(f_out);
			nb++;
			}
		}
		fclose(f_in1);	*/	
	 } 
     return 0;
}


