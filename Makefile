CC=g++
CFLAGS=-Wall -g

all: input_gen main convergence

player.o: player.cpp
	$(CC) $(CFLAGS) -c player.cpp

main: main.cpp player.o
	$(CC) $(CFLAGS) player.o main.cpp -o main

input_gen: input_gen.cpp
	$(CC) $(CFLAGS) input_gen.cpp -o input_gen

convergence: convergence.cpp player.o
	$(CC) $(CFLAGS) player.o convergence.cpp -o convergence

clean:
	rm -rf *.o
