CC = gcc
CFLAGS = -g -Wall -pedantic -ansi
OBJ = main.o setting.o readFile.o LinkedList.o check.o writeusr.o
EXEC = program

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -g -o  $(EXEC)

main.o : main.c main.h setting.h readFile.h check.h
	$(CC) -c main.c $(CFLAGS) 

setting.o : setting.c setting.h readFile.h
	$(CC) -c setting.c $(CFLAGS)

readFile.o : readFile.c readFile.h setting.h LinkedList.h
	$(CC) -c readFile.c $(CFLAGS)

writeusr.o : writeusr.c writeusr.h
	$(CC) -c writeusr.c $(CFLAGS)

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) -c LinkedList.c $(CFLAGS)

check.o : check.c check.h
	$(CC) -c check.c $(CFLAGS)
clean :
	rm -f $(EXEC) $(OBJ)
