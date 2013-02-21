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

	char ligne[90];
	int nb_ligne;
	while (!feof(f))
	{	fgets(ligne, 90, f);
		++nb_ligne;
	}
	fclose(f);
	return nb_ligne;
}

