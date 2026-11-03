CFLAGS=-g -Wall -Wextra -Wdeclaration-after-statement -Werror=vla

xe: fonctions.o compil_sep.o
	gcc compil_sep.o fonctions.o -o exe
compil_sep.o: compil_sep.c fonctions.h
	gcc -c compil_sep.c
fonctions.o: fonctions.c fonctions.h
	gcc -c fonctions.c
