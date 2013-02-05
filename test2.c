#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>


void afficherAide()
{
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
	printf("-m : afficher les différences entre les fichiers archivés et les fichiers existants\n");
}

//~ void creerArchive(const char* nomFichier)
//~ {
	//~ 
	//~ FILE* fopen(const char* 
//~ }

int main (int argc, char **argv)
     {
       int hflag = 0; int tflag = 0; int xflag = 0; int dflag = 0;
       int vflag = 0; int rflag = 0; int fflag = 0; int mflag = 0;
       int cflag = 0; int uflag = 0; int zflag = 0; int sparseflag = 0;
       
       int index;
       int c;
     
       opterr = 1;
     
       while ((c = getopt (argc, argv, "hvctruxfzdm:sparse:")) != -1)
       {
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
           

         if (tflag==1)
			{
				while(argc>1)
				{
					printf(argv[argc]);
					printf("\n");
					argc --;
				}
				
			}
				
     
       //~ printf ("hflag = %d, vflag = %d, cflag = %d, tflag = %d,"
                //~ "rflag = %d, uflag = %d, xflag = %d, fflag = %d,"
                //~ "zflag = %d, dflag = %d, mflag = %d",
               //~ hflag, vflag, cflag, tflag, rflag, uflag, xflag, fflag,
                 //~ zflag, dflag, mflag);
     //~ 
       //~ for (index = optind; index < argc; index++)
         //~ printf ("Non-option argument %s\n", argv[index]);
		//~ printf("\n");       
	return 0;
     }
}
