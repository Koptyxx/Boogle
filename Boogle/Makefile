CC = gcc
CFLAGS = -Wall -ansi -pedantic
option = -lm -lncurses

Boogle: main.o grille.o mot.o affichage.o dictionnaire.o
	$(CC) -o $@ $^ $(CFLAGS) $(option)

grille.o: grille.c include.h mot.h

affichage.o: affichage.c include.h

mot.o: mot.c include.h

dictionnaire.o: dictionnaire.c include.h

%o: %.c

clear:
	rm *.o
	rm Boogle