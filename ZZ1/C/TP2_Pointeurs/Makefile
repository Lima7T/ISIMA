OPTIONS=-Wall -Wextra -g
CC=gcc
exec_TP2:TP2_Pointeurs.o fonctions.o
	${CC} -o exec_TP2 fonctions.o TP2_Pointeurs.o -g
fonctions.o:fonctions.c fonctions.h
	${CC} ${OPTIONS} fonctions.c -c
TP2_Pointeurs.o:fonctions.h TP2_Pointeurs.c
	${CC} ${OPTIONS} TP2_Pointeurs.c -c
clean:
	rm -f fonctions.o TP2_Pointeurs.o *.gch
