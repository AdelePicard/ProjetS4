#ifndef FONCTIONSUTILES_H
#define FONCTIONSUTILES_H

int nombreLignes (FILE* f);
void header (FILE* f_in, FILE* f_out, char* filename);
void copie(FILE* f_in, FILE* f_out);
char* niemeLigne(FILE* f, int n);

#endif
