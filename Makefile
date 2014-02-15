CC = gcc
all:	main

main: main.o parser.o
	$(CC) main.o parser.o -o main
	
main.o:
	$(CC) -c main.c

parser.o:
	$(CC) -c parser.c

clean:
	rm -rf *.o
	rm main
