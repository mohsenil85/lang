CC = gcc
all:	main

main: main.o repl.o parse.o
	$(CC) main.o repl.o parse.o -o main
	
main.o:
	$(CC) -c main.c

repl.o: parse.o
	$(CC) -c repl.c
	
parse.o:
	$(CC) -c parse.c

clean:
	rm -rf *.o
	rm main
