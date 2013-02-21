CC=gcc

a.out: affichage.o fonctionsUtiles.o optionCF.o main.o
	$(CC) -o a.out affichage.o fonctionsUtiles.o optionCF.o main.o 

affichage.o: affichage.c affichage.h
	$(CC) -o affichage.o -c affichage.c 
	
fonctionsUtiles.o: fonctionsUtiles.c fonctionsUtiles.h
	$(CC) -o fonctionsUtiles.o -c fonctionsUtiles.c
		
optionCF.o: optionCF.c fonctionsUtiles.h optionCF.h
	$(CC) -o optionCF.o -c optionCF.c
	
main.o: main.c affichage.h fonctionsUtiles.h optionCF.h
	$(CC) -o main.o -c main.c 

clean:
	rm -rf *.o

