all: main

main: main.o client.o

	gcc -o main main.o client.o -lwsock32 -LC:\MinGW\lib
	
main.o:

	gcc -o main.o -c main.c
	
client.o:

	gcc -o client.o -c client.c 
	
clean:
 
	@del *.o
	@del main.exe