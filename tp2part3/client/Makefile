CC = gcc
EXEC = client.exe
CFLAGS = -Wall -g
#LIB =  "C:\MinGW\lib\libwsock32.a" "lib\libopengl32.a" "lib\libglu32.a" "lib\libglut32.a"
LIB = -lwsock32 -LC:\TP2IA3\tp2part3\client\lib -lopengl32 -lglu32 -lglut32

all: $(EXEC)

$(EXEC): client.o gl_tool.o gl_draw_idle_fun.o main.o

	$(CC) -o $(EXEC) main.o client.o gl_tool.o gl_draw_idle_fun.o $(LIB)

client.o:

	$(CC) -o client.o -c client.c $(CFLAGS)
	
gl_tool.o : 

	$(CC) -o gl_tool.o  -c gl_tool.c $(CFLAGS)

gl_draw_idle_fun.o : 

	$(CC) -o gl_draw_idle_fun.o  -c gl_draw_idle_fun.c $(CFLAGS)

main.o:

	$(CC) -o main.o -c main.c $(CFLAGS)
		
clean:

	@del *.o 
	@del $(EXEC)
	