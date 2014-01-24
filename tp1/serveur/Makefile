all: main

main: main.o serveur.o

	gcc -o main main.o serveur.o -lwsock32 -LC:\MinGW\lib
	
main.o:

	gcc -o main.o -c main.c
	
serveur.o:

	gcc -o serveur.o -c serveur.c 
	
clean:
 
	@del *.o
	@del main.exe