CC = gcc
EXEC = tp2
CFLAGS = -Wall -g -O2


all: $(EXEC)

$(EXEC): serveur.o protocoles.o lis331hh.o dallas18820.o main.o 

	$(CC) -o $(EXEC) -pthread main.o serveur.o protocoles.o lis331hh.o dallas18820.o

serveur.o:

	$(CC) -o serveur.o -c serveur.c $(CFLAGS)
	
protocoles.o:

	$(CC) -o protocoles.o -c protocoles.c $(CFLAGS)
	
lis331hh.o:

	$(CC) -o lis331hh.o -c lis331hh.c $(CFLAGS)
	
dallas18820.o:

	$(CC) -o dallas18820.o -c dallas18820.c $(CFLAGS)

main.o:

	$(CC) -o main.o -c main.c $(CFLAGS)
		
clean:

	@rm -rf *.o 
	@rm -rf $(EXEC)
	