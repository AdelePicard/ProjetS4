CC=gcc

a.out: affichage.o fonctionsUtiles.o compression.o main.o
	$(CC) -o a.out affichage.o fonctionsUtiles.o compression.o main.o 

affichage.o: affichage.c affichage.h
	$(CC) -o affichage.o -c affichage.c 
	
fonctionsUtiles.o: fonctionsUtiles.c fonctionsUtiles.h
	$(CC) -o fonctionsUtiles.o -c fonctionsUtiles.c
		
compression.o: compression.c compression.h
	$(CC) -o compression.o -c compression.c
	
main.o: main.c affichage.h fonctionsUtiles.h compression.h
	$(CC) -o main.o -c main.c 

clean:
	rm -rf *.o

