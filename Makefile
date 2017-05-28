CC=gcc
CFLAGS=-Wall -Iinclude

all: teeny

clean:
	rm -rf src/*.o

teeny: src/header.o src/request.o

src/header.o:
	$(CC) $(CFLAGS) -c src/header.c -o src/header.o

src/request.o:
	$(CC) $(CFLAGS) -c src/request.c -o src/request.o
