OPTIONS=-Wall -Wextra -g
CC=gcc
exec_TP1:TP1_Sudoku.o fonctions.o
	${CC} -o exec_TP1 fonctions.o TP1_Sudoku.o -g
fonctions.o:fonctions.c fonctions.h
	${CC} ${OPTIONS} fonctions.c -c
TP1_Sudoku.o:fonctions.h TP1_Sudoku.c
	${CC} ${OPTIONS} TP1_Sudoku.c -c
clean:
	rm -f fonctions.o TP1_Sudoku.o *.gch
