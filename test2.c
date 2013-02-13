#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>





void afficherAide()
{			
	printf("\n");       
	printf("-h : affiche l'aide de votre commande\n");
	printf("-v : pour activer le mode verbose (affiche des détails sur l'execution)\n");
	printf("-c : pour créer une archive à partir d'une liste de fichier\n");
	printf("-t : pour lister les fichiers contenus dans une archive\n");
	printf("-r : pour ajouter de nouveaux fichiers\n");
	printf("-u : pour mettre à jour l'archive si les fichiers lités sont plus récents que ceux archivés\n");
	printf("-x : pour extraire les fichiers de l'archive\n");
	printf("-f : pour indiquer le nom du fichier archive\n");
	printf("-z : pour compresser le fichier d'archive\n");
	printf("-d : pour suprimer un fichier d'une archive\n");
	printf("-sparse : pour économiser de la place pour stocker les fichiers contenant beaucoup de zéros consécutifs\n");
	printf("-m : affciher les différences entre les fichiers archivés et les fichiers existants\n");
	printf("\n"); 
}

int nombreLignes (FILE* f) {

	char ligne[90];
	int nb_ligne;
	while (!feof(f))
	{	fgets(ligne, 90, f);
		++nb_ligne;
	}
	fclose(f);
	return nb_ligne;
}

//~ char date()
//~ {			char Date;
			 //~ time_t date;
			//~ date = time(NULL);
			//~ Date = ctime(&date);
			//~ return Date;
//~ }


     
int main (int argc, char **argv)
     {
	   int tflag = 0; int xflag = 0; int dflag = 0;
       int vflag = 0; int rflag = 0; int fflag = 0; int mflag = 0;
       int cflag = 0; int uflag = 0; int zflag = 0; int sparseflag = 0;
       
       int index;
       int c;
     
       opterr = 0;
     
       if ((c = getopt (argc, argv, "hvctruxfzdm:sparse:")) != -1)
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
				zflag = 1;
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
	 if (cflag == 1)
	 {
		 int nb=2;
		 int nb_ligne = 0;
		 FILE *f_in;
		 //time_t date;
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
			//date = time(NULL);
			//fputs( ctime(&date),f_in);
			//char Date = date();
			//fputs((char *)Date,f_in);
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
	 //~ if (rflag==1)
	 //~ {
		 //~ int nb=2;
		 //~ int nb_ligne = 0;
		 //~ FILE *f_in;
		 //~ time_t date;
		 //~ if ((f_in = fopen(argv[argc-1],"a")) == NULL)
		//~ {
			//~ fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",argv[argc-1]);
		//~ }
		 //~ while (nb<argc-1 && argc>1 )
		 //~ {
			 //~ FILE *f_out;
//~ 
			//~ nb_ligne = nombreLignes(f_out);
			//~ char ligne[90];
			//~ fgets(ligne, 90, f_out);
			//~ fputs(argv[nb],f_in);
			//~ fputc('\n',f_in);
			//~ char nbLigne [10];
			//~ snprintf(nbLigne, 10, "%i", nb_ligne);
			//~ fputs(nbLigne,f_in);
			//~ fputc('\n',f_in);
			//~ //date = time(NULL);
			//~ //fputs( ctime(&date),f_in);
			//~ fputc('\n',f_in);
			//~ if ((f_out = fopen(argv[nb],"r")) == NULL)
			//~ {
				//~ fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",argv[nb]);
			//~ }
			//~ while (!feof(f_out))
			//~ {
				//~ fputs(ligne, f_in);
				//~ fgets(ligne, 90, f_out);
			//~ }
			//~ fputc('\n',f_in);
			//~ fclose(f_out);
			//~ nb++;
		 //~ }
		//~ fclose(f_in);	
	 //~ }
	 	
	 	
	 	 if (tflag == 1)
	 {
		 int nb=2;
		FILE *f_in;
		  if ((f_in = fopen(argv[argc-1],"r")) == NULL)
		{
			fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n",argv[argc-1]);
		}
			char ligne[90];
					
			//char* nom = fgets(ligne, 90, f_in);
			//printf("%s\n", nom);
			
			//char* nbLigne = fgets(ligne, 90, f_in);
			//printf("%s\n", nbLigne);
			
			//int nbL = atoi(nbLigne);
		
			int numeroLigne=1;
			int nbL;
			
			while(!feof(f_in))
			{
				char* nom = fgets(ligne, 90, f_in);
				printf("%s\n", nom);

				char* nbLigne = fgets(ligne, 90, f_in);
				nbL = atoi(nbLigne);
				printf("%d\n", numeroLigne);
				
				numeroLigne += nbL;
				
			}
			
		
		int i;
			for ( i = 0; i < 30; i+=nbL)
			{
				

			}
		fclose(f_in);
	 }
	 
	 
     return 0;
}


