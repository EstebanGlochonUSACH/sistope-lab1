FLAGS = -Wall

main: lab1.c funciones.o
	gcc $(FLAGS) -o lab1 lab1.c funciones.o

funciones.o: funciones.c
	gcc -c $(FLAGS) funciones.c

clear:
	rm -f *.o lab1
