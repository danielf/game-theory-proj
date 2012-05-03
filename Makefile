CC=g++
CFLAGS=-Wall -g

all: input_gen

player.o: player.cpp
	$(CC) $(CFLAGS) -c player.cpp

main: main.cpp player.o
	$(CC) $(CFLAGS) player.o main.cpp -o main

input_gen: input_gen.cpp
	$(CC) $(CFLAGS) input_gen.cpp -o input_gen

clean:
	rm -rf *.o
