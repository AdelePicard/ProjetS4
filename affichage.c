#include <stdio.h>
#include <stdlib.h>

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
